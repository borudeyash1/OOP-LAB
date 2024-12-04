#include <iostream>
using namespace std;

class Exception {
public:
    void division(int a, int b) {
        try {
            if (b == 0) {
                throw "Error: Division by zero is not allowed.";
            } else {
                cout << "The result of division is: " << a / b << endl;
            }
        } catch (char* e) {
            cout << e << endl;
        }
    }
};

int main() {
    int num1, num2;
    Exception ex;

    cout << "Enter the first number: ";
    cin >> num1;

    cout << "Enter the second number: ";
    cin >> num2;

    ex.division(num1, num2);

    return 0;
}
