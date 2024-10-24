/*
Problem Defination ; design a C++ class complex with data member for real and imaginary part provide default and parameterized constructor  write a program to perform  arithmetic operation of two complex number using operator overloading (using either member function or friend function).

Date: 11/09/2024
Name: Borude Yash Ambadas 
Batch: AS1
*/

#include <iostream>
using namespace std;

class Complex
{
private:
    double real, imaginary;

public:
    // Parameterized Constructor
    Complex(double r = 0, double img = 0)
    {
        real = r;
        imaginary = img;
    }

    // Display function
    void display() const
    {
        if (imaginary >= 0)
            cout << real << " + " << imaginary << "i" << endl;
        else
            cout << real << " - " << -imaginary << "i" << endl;
    }

    // Operator Overloading
    Complex operator+(const Complex &s);
    friend Complex operator-(const Complex &s, const Complex &ss);
    Complex operator*(const Complex &s);
    Complex operator/(const Complex &s);
};

// Addition
Complex Complex::operator+(const Complex &c2)
{
    return Complex(real + c2.real, imaginary + c2.imaginary);
}

// Subtraction
Complex operator-(const Complex &c1, const Complex &c2)
{
    return Complex(c1.real - c2.real, c1.imaginary - c2.imaginary);
}

// Multiplication
Complex Complex::operator*(const Complex &c2)
{
    double real_part = (real * c2.real) - (imaginary * c2.imaginary);
    double imaginary_part = (real * c2.imaginary) + (imaginary * c2.real);
    return Complex(real_part, imaginary_part);
}

// Division
Complex Complex::operator/(const Complex &c2)
{
    double denominator = c2.real * c2.real + c2.imaginary * c2.imaginary;
    if (denominator == 0)
    {
        throw runtime_error("Division by zero!");
    }
    double real_part = (real * c2.real + imaginary * c2.imaginary) / denominator;
    double imaginary_part = (imaginary * c2.real - real * c2.imaginary) / denominator;
    return Complex(real_part, imaginary_part);
}

int main()
{
    Complex c1, c2, result;
    double r1, i1, r2, i2;
    int choice = 0;

    // Input two complex numbers
    cout << "Enter the real and imaginary part of the first complex number: ";
    cin >> r1 >> i1;
    c1 = Complex(r1, i1);

    cout << "Enter the real and imaginary part of the second complex number: ";
    cin >> r2 >> i2;
    c2 = Complex(r2, i2);

    // While Loop
    while (choice != 5)
    {
        // Switch case for operation selection
        cout << "Choose the operation to perform on complex numbers:\n";
        cout << "1. Addition\n";
        cout << "2. Subtraction\n";
        cout << "3. Multiplication\n";
        cout << "4. Division\n";
        cout << "5. Exit\n";
        cin >> choice;

        switch (choice)
        {
        case 1:
            result = c1 + c2;
            cout << "Result of Addition: ";
            result.display();
            break;
        case 2:
            result = c1 - c2;
            cout << "Result of Subtraction: ";
            result.display();
            break;
        case 3:
            result = c1 * c2;
            cout << "Result of Multiplication: ";
            result.display();
            break;
        case 4:
            try
            {
                result = c1 / c2;
                cout << "Result of Division: ";
                result.display();
            }
            catch (runtime_error &e)
            {
                cout << e.what() << endl;
            }
            break;
        case 5:
            cout << "Exiting...." << endl;
            break;
        default:
            cout << "Invalid choice!" << endl;
            break;
        }
    }

    return 0;
}