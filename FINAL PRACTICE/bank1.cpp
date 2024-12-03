#include <iostream>
using namespace std;

class Bank {
public:
    string name, IFSC, branch;

    void getdata() {
        cout << "Enter the name of the bank: ";
        cin >> name;
        cout << "Enter the IFSC code of the bank: ";
        cin >> IFSC;
        cout << "Enter the branch of the bank: ";
        cin >> branch;
    }
};

class Manager : public Bank {
public:
    string managerName;

    void getdata() {
        cout << "Enter the name of the manager: ";
        cin >> managerName;
        cout << "Enter the IFSC code of the manager's branch: ";
        cin >> IFSC;
        cout << "Enter the branch of the manager: ";
        cin >> branch;
    }

    void display() {
        cout << "Manager Details:\n";
        cout << "Name: " << managerName << endl;
        cout << "Branch: " << branch << endl;
        cout << "IFSC: " << IFSC << endl;
    }
};

class Cashier : public Bank {
public:
    string cashierName;

    void getdata() {
        cout << "Enter the name of the cashier: ";
        cin >> cashierName;
        cout << "Enter the IFSC code of the cashier's branch: ";
        cin >> IFSC;
        cout << "Enter the branch of the cashier: ";
        cin >> branch;
    }

    void display() {
        cout << "Cashier Details:\n";
        cout << "Name: " << cashierName << endl;
        cout << "Branch: " << branch << endl;
        cout << "IFSC: " << IFSC << endl;
    }
};

int main() {
    int choice;
    Manager m;
    Cashier c;

    do {
        cout << "\n1. Input Manager Details\n";
        cout << "2. Input Cashier Details\n";
        cout << "3. Display Manager Details\n";
        cout << "4. Display Cashier Details\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            m.getdata();
            break;
        case 2:
            c.getdata();
            break;
        case 3:
            m.display();
            break;
        case 4:
            c.display();
            break;
        case 5:
            cout << "Exiting program...\n";
            break;
        default:
            cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 5);

    return 0;
}
