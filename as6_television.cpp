#include <iostream>
using namespace std;

class television {
    int mn, pz, sz;

public:
    friend ostream &operator<<(ostream &vout, television &t);
    friend istream &operator>>(istream &vin, television &t);
};

istream &operator>>(istream &vin, television &t) {
    cout << "-----------TELEVISION SHOP------------\n";
    cout << "Enter the model number: ";
    vin >> t.mn;

    cout << "Available Sizes (in inches):\n";
    cout << "12 inches to  70 inches\n";
    cout << "Choose a size from the above options: ";
    vin >> t.sz;

    cout << "Enter the price: ";
    vin >> t.pz;

    try {
        if (t.mn > 9999 || (t.sz >= 12 ||  t.sz <= 70) || t.pz < 0 || t.pz > 100000) {
            throw 1;
        }
    } catch (int e) {
        cout << "Exception caught: Invalid input values. All values set to 0." << endl;
        t.sz = 0;
        t.pz = 0;
        t.mn = 0;
    }
    return vin;
}

ostream &operator<<(ostream &vout, television &t) {
    vout << "Model number: " << t.mn << endl;
    vout << "Size: " << t.sz << " inches" << endl;
    vout << "Price: $" << t.pz << endl;
    return vout;
}

int main() {
    television tv;
    int choice;

    while (true) {
        cout << "1. Enter Television Details\n";
        cout << "2. Display Television Details\n";
        cout << "3. Exit\n";
        cout << "Choose an option: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cin >> tv;
                break;
            case 2:
                cout << tv;
                break;
            case 3:
                return 0;  // Exits the program
            default:
                cout << "Invalid choice. Please try again.\n";
                break;
        }
    }

    return 0;
}
