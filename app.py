import os
import hashlib
import base64
import psycopg2
import psycopg2.extras
from flask import Flask, request, jsonify, render_template_string
from dotenv import load_dotenv

load_dotenv()

app = Flask(__name__)
PORT = int(os.environ.get("PORT", 3001))

# Database configuration
POSTGRES_HOST = os.environ.get("POSTGRES_HOST") or os.environ.get("DB_HOST") or os.environ.get("DATABASE_HOST") or "localhost"
POSTGRES_PORT = int(os.environ.get("POSTGRES_PORT") or os.environ.get("DB_PORT") or os.environ.get("DATABASE_PORT") or 5432)
POSTGRES_USER = os.environ.get("POSTGRES_USER") or os.environ.get("DB_USER") or os.environ.get("DATABASE_USER") or "postgres"
POSTGRES_PASSWORD = os.environ.get("POSTGRES_PASSWORD") or os.environ.get("DB_PASSWORD") or os.environ.get("DATABASE_PASSWORD") or ""
POSTGRES_DB = os.environ.get("POSTGRES_DB") or os.environ.get("DB_NAME") or os.environ.get("DATABASE_NAME") or os.environ.get("DB_DATABASE") or "preview_db"

def get_db_connection():
    return psycopg2.connect(
        host=POSTGRES_HOST,
        port=POSTGRES_PORT,
        user=POSTGRES_USER,
        password=POSTGRES_PASSWORD,
        database=POSTGRES_DB,
        cursor_factory=psycopg2.extras.RealDictCursor
    )

# Initialize database tables
def init_db():
    try:
        # Create database if not exists
        conn = psycopg2.connect(
            host=POSTGRES_HOST,
            port=POSTGRES_PORT,
            user=POSTGRES_USER,
            password=POSTGRES_PASSWORD,
            database="postgres"
        )
        conn.autocommit = True
        cursor = conn.cursor()
        cursor.execute(f"SELECT 1 FROM pg_catalog.pg_database WHERE datname = '{POSTGRES_DB}'")
        exists = cursor.fetchone()
        if not exists:
            cursor.execute(f'CREATE DATABASE "{POSTGRES_DB}"')
        conn.close()

        # Connect to target db to create tables
        conn = get_db_connection()
        conn.autocommit = True
        cursor = conn.cursor()
        cursor.execute("""
            CREATE TABLE IF NOT EXISTS users (
                id SERIAL PRIMARY KEY,
                username VARCHAR(255) UNIQUE NOT NULL,
                password VARCHAR(255) NOT NULL
            )
        """)
        cursor.execute("""
            CREATE TABLE IF NOT EXISTS items (
                id SERIAL PRIMARY KEY,
                name VARCHAR(255) NOT NULL,
                description TEXT,
                status VARCHAR(50) DEFAULT 'Active',
                owner VARCHAR(255) DEFAULT 'Anonymous',
                created_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP
            )
        """)
        conn.close()
        print("[DATABASE] Initialization completed successfully.")
    except Exception as e:
        print("[DATABASE] Initialization warning:", str(e))

init_db()

def hash_password(password):
    return hashlib.sha256(password.encode()).hexdigest()

@app.route("/api/auth/register", methods=["POST"])
def register():
    data = request.get_json() or {}
    username = data.get("username")
    password = data.get("password")
    if not username or not password:
        return jsonify({"error": "Username and password are required."}), 400
    try:
        conn = get_db_connection()
        cursor = conn.cursor()
        cursor.execute("SELECT id FROM users WHERE username = %s", (username,))
        if cursor.fetchone():
            conn.close()
            return jsonify({"error": "Username already exists."}), 400
        hashed = hash_password(password)
        cursor.execute("INSERT INTO users (username, password) VALUES (%s, %s)", (username, hashed))
        conn.commit()
        conn.close()
        return jsonify({"message": "User registered successfully."}), 201
    except Exception as e:
        return jsonify({"error": str(e)}), 500

@app.route("/api/auth/login", methods=["POST"])
def login():
    data = request.get_json() or {}
    username = data.get("username")
    password = data.get("password")
    if not username or not password:
        return jsonify({"error": "Username and password are required."}), 400
    try:
        conn = get_db_connection()
        cursor = conn.cursor()
        cursor.execute("SELECT password FROM users WHERE username = %s", (username,))
        row = cursor.fetchone()
        conn.close()
        is_match = row and (row["password"] == hash_password(password) or row["password"] == password)
        if not row or not is_match:
            return jsonify({"error": "Invalid credentials."}), 401
        token = base64.b64encode(username.encode()).decode()
        return jsonify({"token": token, "username": username})
    except Exception as e:
        return jsonify({"error": str(e)}), 500

@app.route("/api/items", methods=["GET"])
def get_items():
    try:
        conn = get_db_connection()
        cursor = conn.cursor()
        cursor.execute("SELECT * FROM items ORDER BY id DESC")
        rows = cursor.fetchall()
        conn.close()
        for row in rows:
            if "created_at" in row and row["created_at"]:
                row["created_at"] = str(row["created_at"])
        return jsonify(rows)
    except Exception as e:
        return jsonify({"error": str(e)}), 500

@app.route("/api/items", methods=["POST"])
def create_item():
    data = request.get_json() or {}
    name = data.get("name")
    description = data.get("description", "")
    status = data.get("status", "Active")
    owner = data.get("owner", "Anonymous")
    if not name:
        return jsonify({"error": "Item name is required."}), 400
    try:
        conn = get_db_connection()
        cursor = conn.cursor()
        cursor.execute(
            "INSERT INTO items (name, description, status, owner) VALUES (%s, %s, %s, %s)",
            (name, description, status, owner)
        )
        conn.commit()
        conn.close()
        return jsonify({"message": "Item created successfully."}), 201
    except Exception as e:
        return jsonify({"error": str(e)}), 500

@app.route("/api/items/<int:item_id>", methods=["DELETE"])
def delete_item(item_id):
    try:
        conn = get_db_connection()
        cursor = conn.cursor()
        cursor.execute("DELETE FROM items WHERE id = %s", (item_id,))
        conn.commit()
        conn.close()
        return jsonify({"message": "Item deleted successfully."})
    except Exception as e:
        return jsonify({"error": str(e)}), 500

@app.route("/")
def home():
    db_status = "Connected"
    db_error = None
    try:
        conn = get_db_connection()
        conn.close()
    except Exception as e:
        db_status = "Error"
        db_error = str(e)

    return render_template_string("""
    <!DOCTYPE html>
    <html lang="en">
    <head>
      <meta charset="UTF-8">
      <meta name="viewport" content="width=device-width, initial-scale=1.0">
      <title>DevOps Flask Postgres Sandbox</title>
      <link href="https://fonts.googleapis.com/css2?family=Outfit:wght@300;400;600&family=JetBrains+Mono&display=swap" rel="stylesheet">
      <style>
        :root {
          --bg: #0b0f19;
          --panel: rgba(17, 24, 39, 0.7);
          --border: rgba(255, 255, 255, 0.08);
          --accent: #10b981;
          --accent-cyan: #06b6d4;
          --accent-error: #ef4444;
          --text: #f3f4f6;
          --text-muted: #9ca3af;
        }
        body {
          margin: 0;
          padding: 0;
          font-family: 'Outfit', sans-serif;
          background: var(--bg);
          color: var(--text);
          display: flex;
          justify-content: center;
          align-items: center;
          min-height: 100vh;
        }
        .container {
          background: var(--panel);
          border: 1px solid var(--border);
          border-radius: 24px;
          padding: 35px;
          width: 550px;
          box-shadow: 0 20px 50px rgba(0, 0, 0, 0.6);
          backdrop-filter: blur(20px);
        }
        h1 {
          font-size: 26px;
          font-weight: 600;
          margin-top: 0;
          margin-bottom: 5px;
          text-align: center;
          background: linear-gradient(135deg, #06b6d4, #10b981);
          -webkit-background-clip: text;
          -webkit-text-fill-color: transparent;
        }
        .subtitle {
          font-size: 13.5px;
          color: var(--text-muted);
          text-align: center;
          margin-bottom: 25px;
        }
        .status-box {
          display: flex;
          align-items: center;
          justify-content: space-between;
          padding: 12px 18px;
          background: rgba(255, 255, 255, 0.02);
          border: 1px solid var(--border);
          border-radius: 12px;
          margin-bottom: 20px;
          font-size: 13.5px;
        }
        .dot {
          width: 8px;
          height: 8px;
          border-radius: 50%;
          display: inline-block;
        }
        .dot-connected { background: var(--accent); box-shadow: 0 0 10px var(--accent); }
        .dot-connecting { background: #f59e0b; box-shadow: 0 0 10px #f59e0b; }
        .dot-error { background: var(--accent-error); box-shadow: 0 0 10px var(--accent-error); }

        .auth-card, .dashboard-card { display: none; }
        .active-view { display: block; }
        .form-group { margin-bottom: 15px; text-align: left; }
        label {
          font-size: 11px;
          font-weight: 600;
          color: var(--text-muted);
          text-transform: uppercase;
          letter-spacing: 0.06em;
          display: block;
          margin-bottom: 6px;
        }
        input, textarea, select {
          background: rgba(255, 255, 255, 0.03);
          border: 1px solid var(--border);
          border-radius: 8px;
          padding: 10px 14px;
          color: var(--text);
          outline: none;
          width: 100%;
          box-sizing: border-box;
          font-size: 14px;
        }
        .btn {
          background: linear-gradient(135deg, #06b6d4, #0891b2);
          color: white;
          border: none;
          border-radius: 8px;
          padding: 12px;
          font-weight: 600;
          cursor: pointer;
          width: 100%;
          margin-top: 10px;
        }
        .btn-delete {
          background: rgba(239, 68, 68, 0.1);
          color: #ef4444;
          border: 1px solid rgba(239, 68, 68, 0.2);
          padding: 4px 8px;
          font-size: 11px;
          border-radius: 6px;
          cursor: pointer;
        }
        .switch-auth-mode { font-size: 12.5px; color: var(--text-muted); margin-top: 15px; text-align: center; }
        .switch-auth-mode span { color: var(--accent-cyan); cursor: pointer; font-weight: 600; }
        .user-header {
          display: flex;
          justify-content: space-between;
          align-items: center;
          border-bottom: 1px solid var(--border);
          padding-bottom: 12px;
          margin-bottom: 20px;
        }
        .username-badge {
          background: rgba(6, 182, 212, 0.1);
          color: var(--accent-cyan);
          padding: 4px 10px;
          border-radius: 6px;
          font-size: 13px;
          font-weight: 600;
        }
        .logout-link { font-size: 12px; color: var(--accent-error); cursor: pointer; font-weight: 600; }
        .crud-box { display: grid; grid-template-columns: 1.2fr 1.8fr; gap: 20px; }
        .item-card {
          background: rgba(255, 255, 255, 0.02);
          border: 1px solid var(--border);
          border-radius: 12px;
          padding: 12px;
          margin-bottom: 10px;
          display: flex;
          justify-content: space-between;
          align-items: flex-start;
        }
        .item-details { display: flex; flex-direction: column; gap: 3px; }
        .item-title { font-size: 14px; font-weight: 600; }
        .item-desc { font-size: 11.5px; color: var(--text-muted); }
        .item-meta { font-size: 10px; color: var(--text-muted); font-family: 'JetBrains Mono'; margin-top: 5px; }
        .badge { font-size: 9px; font-weight: 600; padding: 2px 6px; border-radius: 4px; text-transform: uppercase; }
        .badge-active { background: rgba(16, 185, 129, 0.1); color: #34d399; border: 1px solid rgba(16, 185, 129, 0.2); }
        .badge-pending { background: rgba(245, 158, 11, 0.1); color: #fbbf24; border: 1px solid rgba(245, 158, 11, 0.2); }
        .badge-disabled { background: rgba(107, 114, 128, 0.1); color: #9ca3af; border: 1px solid rgba(107, 114, 128, 0.2); }
        .alert { padding: 10px 14px; border-radius: 8px; font-size: 13px; margin-bottom: 15px; display: none; }
        .alert-error { background: rgba(239, 68, 68, 0.1); color: #ef4444; border: 1px solid rgba(239, 68, 68, 0.2); }
        .alert-success { background: rgba(16, 185, 129, 0.1); color: #34d399; border: 1px solid rgba(16, 185, 129, 0.2); }
      </style>
    </head>
    <body>
      <div class="container">
        <h1>Flask + Postgres</h1>
        <div class="subtitle">Secure DevOps Database Sandbox Environment</div>
        
        <div class="status-box">
          <span>Database Engine (Postgres)</span>
          <span style="display:flex; align-items:center; gap:6px;">
            <span class="dot dot-{{ db_status | lower }}"></span>
            <strong>{{ db_status }}</strong>
          </span>
        </div>

        {% if db_error %}
          <div class="alert alert-error" style="display:block;"><strong>Error:</strong> {{ db_error }}</div>
        {% endif %}

        <div id="alertBox" class="alert"></div>

        <!-- 1. AUTHENTICATION SECTION -->
        <div id="authSection" class="auth-card active-view">
          <h3 id="authTitle" style="margin-top:0; color: var(--accent-cyan);">Sign In</h3>
          <form id="authForm" onsubmit="handleAuth(event)">
            <div class="form-group">
              <label>Username</label>
              <input type="text" id="username" required placeholder="e.g. admin" />
            </div>
            <div class="form-group">
              <label>Password</label>
              <input type="password" id="password" required placeholder="••••••••" />
            </div>
            <button type="submit" id="authBtn" class="btn">Sign In</button>
          </form>
          <div class="switch-auth-mode">
            <span id="authSwitchText" onclick="toggleAuthMode()">Don't have an account? Sign Up</span>
          </div>
        </div>

        <!-- 2. CRUD DASHBOARD SECTION -->
        <div id="dashboardSection" class="dashboard-card">
          <div class="user-header">
            <span class="username-badge">User: <strong id="loggedUser">admin</strong></span>
            <span class="logout-link" onclick="handleLogout()">Sign Out</span>
          </div>

          <div class="crud-box">
            <!-- Left Panel: Create Form -->
            <div style="border-right: 1px solid var(--border); padding-right: 15px;">
              <h4 style="margin-top:0; margin-bottom:15px; color: var(--accent-cyan);">New Record</h4>
              <form id="createForm" onsubmit="handleCreate(event)">
                <div class="form-group">
                  <label>Item Name</label>
                  <input type="text" id="itemName" required placeholder="e.g. Server Logs" />
                </div>
                <div class="form-group">
                  <label>Description</label>
                  <textarea id="itemDesc" rows="3" placeholder="Database metadata..."></textarea>
                </div>
                <div class="form-group">
                  <label>Status</label>
                  <select id="itemStatus">
                    <option value="Active">Active</option>
                    <option value="Pending">Pending</option>
                    <option value="Disabled">Disabled</option>
                  </select>
                </div>
                <button type="submit" class="btn" style="margin-top:5px;">Create Item</button>
              </form>
            </div>

            <!-- Right Panel: List Items -->
            <div style="max-height: 400px; overflow-y: auto; padding-left: 5px;">
              <h4 style="margin-top:0; margin-bottom:15px; color: var(--accent-cyan);">Records (Items)</h4>
              <div id="itemsContainer"></div>
            </div>
          </div>
        </div>

      </div>

      <script>
        let isSignUpMode = false;
        let token = localStorage.getItem('db_sandbox_token');
        let currentUsername = localStorage.getItem('db_sandbox_username');

        if (token) {
          showDashboard(currentUsername);
        }

        function toggleAuthMode() {
          isSignUpMode = !isSignUpMode;
          document.getElementById('authTitle').innerText = isSignUpMode ? 'Create Account' : 'Sign In';
          document.getElementById('authBtn').innerText = isSignUpMode ? 'Register' : 'Sign In';
          document.getElementById('authSwitchText').innerText = isSignUpMode ? 'Already have an account? Sign In' : "Don't have an account? Sign Up";
          clearAlert();
        }

        function showAlert(msg, isSuccess = false) {
          const box = document.getElementById('alertBox');
          box.innerText = msg;
          box.className = 'alert ' + (isSuccess ? 'alert-success' : 'alert-error');
          box.style.display = 'block';
        }

        function clearAlert() {
          document.getElementById('alertBox').style.display = 'none';
        }

        async function handleAuth(e) {
          e.preventDefault();
          clearAlert();
          const username = document.getElementById('username').value.trim();
          const password = document.getElementById('password').value;

          const endpoint = isSignUpMode ? '/api/auth/register' : '/api/auth/login';
          try {
            const res = await fetch(endpoint, {
              method: 'POST',
              headers: { 'Content-Type': 'application/json' },
              body: JSON.stringify({ username, password })
            });
            const data = await res.json();
            if (!res.ok) {
              showAlert(data.error || 'Authentication failed.');
              return;
            }

            if (isSignUpMode) {
              showAlert('Registration successful! Please login.', true);
              toggleAuthMode();
            } else {
              localStorage.setItem('db_sandbox_token', data.token);
              localStorage.setItem('db_sandbox_username', data.username);
              token = data.token;
              showDashboard(data.username);
            }
          } catch (err) {
            showAlert('Connection error.');
          }
        }

        function showDashboard(username) {
          document.getElementById('authSection').style.display = 'none';
          document.getElementById('dashboardSection').style.display = 'block';
          document.getElementById('loggedUser').innerText = username;
          loadItems();
        }

        function handleLogout() {
          localStorage.removeItem('db_sandbox_token');
          localStorage.removeItem('db_sandbox_username');
          token = null;
          document.getElementById('dashboardSection').style.display = 'none';
          document.getElementById('authSection').style.display = 'block';
          document.getElementById('authForm').reset();
          clearAlert();
        }

        async function loadItems() {
          try {
            const res = await fetch('/api/items');
            const data = await res.json();
            const container = document.getElementById('itemsContainer');
            container.innerHTML = '';
            if (data.length === 0) {
              container.innerHTML = '<div class="empty-state">No items found. Create one!</div>';
              return;
            }
            data.forEach(item => {
              container.innerHTML += `
                <div class="item-card">
                  <div class="item-details">
                    <span class="item-title">${item.name}</span>
                    <span class="item-desc">${item.description || 'No description'}</span>
                    <span class="item-meta">Owner: ${item.owner} | ${item.created_at || ''}</span>
                  </div>
                  <div style="display:flex; flex-direction:column; align-items:flex-end; gap:8px;">
                    <span class="badge badge-${item.status.toLowerCase()}">${item.status}</span>
                    <button class="btn-delete" onclick="deleteItem('${item.id}')">Delete</button>
                  </div>
                </div>
              `;
            });
          } catch (err) {
            console.error('Failed to load items:', err);
          }
        }

        async function handleCreate(e) {
          e.preventDefault();
          const name = document.getElementById('itemName').value.trim();
          const description = document.getElementById('itemDesc').value.trim();
          const status = document.getElementById('itemStatus').value;
          const owner = localStorage.getItem('db_sandbox_username') || 'Anonymous';

          try {
            const res = await fetch('/api/items', {
              method: 'POST',
              headers: { 'Content-Type': 'application/json' },
              body: JSON.stringify({ name, description, status, owner })
            });
            if (res.ok) {
              document.getElementById('createForm').reset();
              loadItems();
            } else {
              const data = await res.json();
              showAlert(data.error || 'Failed to create item.');
            }
          } catch (err) {
            showAlert('Failed to create item.');
          }
        }

        async function deleteItem(id) {
          if (!confirm('Are you sure you want to delete this record?')) return;
          try {
            const res = await fetch(`/api/items/${id}`, {
              method: 'DELETE'
            });
            if (res.ok) {
              loadItems();
            } else {
              alert('Failed to delete item.');
            }
          } catch (err) {
            alert('Error.');
          }
        }
      </script>
    </body>
    </html>
    """, db_status=db_status, db_error=db_error)

if __name__ == "__main__":
    app.run(host="0.0.0.0", port=PORT)
