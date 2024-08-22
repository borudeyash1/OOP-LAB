#include <iostream>
using namespace std;

class Bank
{
    string name;
    int accno;
    double balance;
    bool isAccountActive;
    string password;

public:
    Bank(string n, int a, double b, string pass)
    {
        name = n;
        accno = a;
        balance = b;
        isAccountActive = true;
        this->password = pass;
    }
    void deposit()
    {
        if (!isAccountActive)
        {
            cout << "Account is inactive .Cannot deposit,please visit your bank." << endl;
            return;
        }
        double amount;
        string pass;
        cout << "Enter your password:";
        cin >> pass;
        if (pass == this->password && pass.length() == 6)
        {
            cout << "Enter the amount to deposit:";
            cin >> amount;
            balance += amount;
            cout << "Deposit successful .New balance: " << balance << endl;
        }
        else
        {
            cout << "Invalid Password.Transaction cancelled." << endl;
        }
    }

    void withdraw()
    {
        if (!isAccountActive)
        {
            cout << "Account is inactive.Cannot withdraw." << endl;
            return;
        }
        double amount;
        string pass;
        cout << "Enter your password: ";
        cin >> pass;
        if (pass == this->password && pass.length() == 6)
        {
            cout << "Enter the amount to withdraw: ";
            cin >> amount;
            if (amount > balance)
            {
                cout << "Insufficient bakance" << endl;
            }
            else
            {
                balance -= amount;
                cout << "Withdrawal successsful .New balance: " << balance << endl;
            }
        }
        else
        {
            cout << "Invalid password.Transaction cancelled." << endl;
        }
    }

    void display()
    {
        string pass;
        if (!isAccountActive)
        {
            cout << "Account is inactive." << endl;
            return;
        }

        cout << "Name:" << name << endl;
        cout << "Accno:" << accno << endl;
        cout << "Balance:" << endl;
        {
            cout << "Enter your password to displau balance(to exit enter 0): ";
            cin >> pass;
            if (pass == this->password && pass.length() == 6)
            {
                cout << "Balance: " << balance << endl;
            }
            else
            {
                if (pass!="0")
                {
                    cout << "Invalid password.Transaction cancelled." << endl;
                }
                cout << "Exiting....";
            }
        }
    }
    void deleteAccount()
    {
        if (!isAccountActive)
        {
            cout << "Account is already inactive." << endl;
            return;
        }
        string pass;
        cout << "Enter your 6 digit password: ";
        cin >> pass;
        if (pass == this->password && pass.length() == 6)
        {
            cout << "Are you sure you want to delete your account?" << endl;
            char choice;
            cin >> choice;
            if (choice == 'y' || choice == 'Y')
            {
                isAccountActive = false;
                cout << "Account deleted successfully." << endl;
            }
            else
            {
                cout << "Account deletion cancelled." << endl;
            }
        }
        else
        {
            cout << "Invlaid password.Transaction cancelled." << endl;
        }
    }
};

int main()
{
    string name;
    int accno;
    double balance;
    string pass;
    cout << "Enter your name:";
    cin >> name;
    cout << "Enter your accno: ";
    cin >> accno;
    cout << "ENte your initial balance";
    cin >> balance;

    Bank b(name, accno, balance, pass);
    int choice;
    while (true)
    {
        cout << "\n1.Deposit \n2.Withdraw \n3.Didplay Account details\n4.Delete account\n5.Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            b.deposit();
            break;
        case 2:
            b.withdraw();
            break;
        case 3:
            b.display();
            break;
        case 4:
            b.deleteAccount();
            break;
        case 5:
            exit(0);
            break;
        default:
            cout << "Invalid choice. Transaction cancelled." << endl;
        }
    }
    return 0;
}