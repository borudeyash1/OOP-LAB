/*Design a C++ Class ‘Complex ‘ with data members for real
and imaginary part. Provide default and parameterized
constructors. Write a program to perform arithmetic
operations of two complex numbers using operator
overloading (using either member functions or friend
functions)..*/
#include <iostream>
using namespace std;

class Complex {
    int real, imaginary;

public:
    Complex(int r = 0, int i = 0) {
        real = r;
        imaginary = i;
    }
    // Display function
    void display() {
        if (imaginary >= 0)
            cout << real << " + " << imaginary << "i" << endl;
        else
            cout << real << " - " << -imaginary << "i" << endl;
    }

    // Operator overloading
    Complex operator+(Complex &b);
    friend Complex operator-(Complex &a, Complex &b);
    Complex operator*(Complex &b);
    Complex operator/(Complex &b);
};

// Addition
Complex Complex::operator+(Complex &b) {
    return Complex(real + b.real, imaginary + b.imaginary);
}

// Subtraction
Complex operator-(Complex &a, Complex &b) {
    return Complex(a.real - b.real, a.imaginary - b.imaginary);
}

// Multiplication
Complex Complex::operator*(Complex &b) {
    int real_part = (real * b.real) - (imaginary * b.imaginary);
    int imaginary_part = (real * b.imaginary) + (imaginary * b.real);
    return Complex(real_part, imaginary_part);
}

// Division
Complex Complex::operator/(Complex &b) {
    int denominator = b.real * b.real + b.imaginary * b.imaginary;
    if (denominator == 0) {
        throw runtime_error("Division by zero!");
    }
    int real_part = (real * b.real + imaginary * b.imaginary) / denominator;
    int imaginary_part = (imaginary * b.real - real * b.imaginary) / denominator;
    return Complex(real_part, imaginary_part);
}

int main() {
    Complex a, b, result;
    int r1, i1, r2, i2;
    int choice = 0;

    // Input of the numbers
    cout << "Enter the real and imaginary part of the first complex number (a): ";
    cin >> r1 >> i1;
    a = Complex(r1, i1);

    cout << "Enter the real and imaginary part of the second complex number (b): ";
    cin >> r2 >> i2;
    b = Complex(r2, i2);

    do {
        // Switch case
        cout << "\nChoose the operation to perform on complex numbers:\n";
        cout << "1. Addition\n";
        cout << "2. Subtraction\n";
        cout << "3. Multiplication\n";
        cout << "4. Division\n";
        cout << "5. Exit\n";
        cin >> choice;

        switch (choice) {
        case 1:
            result = a + b;
            cout << "Result of addition: ";
            result.display();
            break;

        case 2:
            result = a - b;
            cout << "Result of subtraction: ";
            result.display();
            break;

        case 3:
            result = a * b;
            cout << "Result of multiplication: ";
            result.display();
            break;

        case 4:
            try {
                result = a / b;
                cout << "Result of division: ";
                result.display();
            } catch (runtime_error &e) {
                cout << e.what() << endl;
            }
            break;

        case 5:
            cout << "Exiting..." << endl;
            break;

        default:
            cout << "Invalid input! Please try again." << endl;
        }
    } while (choice != 5);

    return 0;
}
