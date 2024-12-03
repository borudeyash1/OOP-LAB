/*Create a classes SBI_Bank and HDFC_Bank which accept 
bank details such as bank name,IFSC code ,branch etc. 
Derive the class from it Customer from these two and  accept 
the details and display it. */
#include <iostream>
using namespace std;
class Bank {
    protected:
        string name, IFSC, branch;
    public:
        void getdata() {
            cout << "Enter the name of the bank: ";
            cin >> name;
            cout << "Enter the IFSC code of the bank: ";
            cin >> IFSC;
            cout << "Enter the branch of the bank: ";
            cin >> branch;
        }
        void display() {
            cout << "Bank Details:\n";
            cout << "Name: " << name << endl;
            cout << "IFSC: " << IFSC << endl;
            cout << "Branch: " << branch << endl;
        }
};
class Customer : public Bank {
    protected:
        string customerName, customerAddress;
    public:
        void getdata() {
        Bank::getdata();
        cout << "Enter the name of the customer: ";
        cin >> customerName;
        cout << "Enter the address of the customer: ";
        cin >> customerAddress;
    }
    void display() {
        cout << "Customer Details:\n";
        cout << "Name: " << customerName << endl;
        cout << "Address: " << customerAddress << endl;
        cout << "Bank Details:\n";
        cout << "Name: " << name << endl;
        cout << "IFSC: " << IFSC << endl;
        cout << "Branch: " << branch << endl;
    }
};

int main() {
    //objects
    Customer c1, c2;
    //switch case 
    int choice;
    do {
        cout << "\n1. Input Customer Details\n";
        cout << "2. Display Customer Details\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                c1.getdata();
                break;
            case 2:
                c1.display();
                break;
            case 3:
            cout << "Displaying Bank Details...\n";
                break;
            case 4:
            cout<<"Displaying Customer Details...\n";
                break;
            case 5:
                cout << "Exiting program...\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 5);
    
    return 0;
}