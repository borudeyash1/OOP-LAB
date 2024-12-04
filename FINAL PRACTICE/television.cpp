/*Create a C++ class named Television that has data members 
to hold the model number and the screen size in inches, and 
the price. Member functions include overloaded insertion 
and extraction operators. If more than four digits are entered 
for the model, if the screen size is smaller than 12 or greater 
than 70 inches, or if the price is negative or over $5000 then 
throw an integer. Write a main() function that instantiates a 
television object, allows user to enter data and displays the 
data members .If an exception is caught, replace all the data 
member values with zero values.*/

#include <iostream>
using namespace std;

class Television {
    int mno;  // Model number
    int sz;   // Screen size
    double pz; // Price

public:
    // Overloaded extraction operator for input
    friend istream &operator>>(istream &input, Television &tv) {
        cout << "Enter model number of television: ";
        input >> tv.mno;
        cout << "Enter screen size of television (in inches): ";
        input >> tv.sz;
        cout << "Enter price of television: ";
        input >> tv.pz;

        try {
            if (tv.mno > 9999 || tv.mno < 0) {
                throw 1; // Invalid model number
            }
            if (tv.sz < 12 || tv.sz > 70) {
                throw 2; // Invalid screen size
            }
            if (tv.pz < 0 || tv.pz > 5000) {
                throw 3; // Invalid price
            }
        } catch (int e) {
            cout << "Exception caught: Invalid input values. All values set to 0." << endl;
            tv.mno = 0;
            tv.sz = 0;
            tv.pz = 0;
        }

        return input;
    }

    // Overloaded insertion operator for output
    friend ostream &operator<<(ostream &output, const Television &tv) {
        output << "Model number of television: " << tv.mno << endl;
        output << "Size of television: " << tv.sz << " inches" << endl;
        output << "Price of television: $" << tv.pz << endl;
        return output;
    }
};

int main() {
    Television tv;

    cin >> tv; // Input data
    cout << tv; // Display data

    return 0;
}