#include <iostream>
#include <string>
using namespace std;

class Bank
{
private:
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
            cout << "Account is inactive ,cannot deposit." << endl;
            return;
        }

        double amount;
        string pass;
        cout << "Enter the password: ";
        cin >> pass;
        if (pass == this->password && pass.length() == 6)
        {
            cout << "Enter the amount to deposit: ";
            cin >> amount;
            balance += amount;
            cout << "Deposit successful.New balance :" << balance << endl;
        }
        else
        {
            cout << "Invalid password.Transaction cancelled." << endl;
        }
    }
    void withdraw()
    {
        
    }

    void display()
    {
    }
    void deleteAccount()
    {
    }

}

int main()
{
    string name;
    int accno;
    double balance;
    string pass;
    cout << "Enter your name: ";
    cin >> name;
    cout << "Enter your account number:";
    cin >> accno;
    cout << "Enter the initial balance:";
    cin >> balance;
    cout << "Enter your 6 digit password";
    cin >> pass;

    Bank b(name, accno, balance, pass);
    int choice;
    while (true)
    {
        cout << "\n1.Deopsit\n2.Withdraw \n3.Display Account Details\n 4.Delete Account\n5.Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (true)
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
            cout << "Exiting....." << endl;
        }
    }
    return 0;
}