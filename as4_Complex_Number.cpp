#include <iostream>
using namespace std;

class Complex
{
    int real, img;

public:
    Complex()
    {
        real = 0;
        img = 0;
    }

    Complex(int real, int img)
    {
        this->real = real;
        this->img = img;
    }

    void getnumber()
    {
        cout << "Enter the real part of no.: ";
        cin >> real;
        cout << "Enter the imaginary part of no.: ";
        cin >> img;
    }
    void display()
    {
        if (img > 0)
        {
            cout << real << " + " << img;
        }
        else
        {
            cout << real << " - " << img;
        }
    }

    Complex operator+(Complex)
    {
        C3.real = C1.real + C2.real;
        C3.img = C1.img + C2.img;
        return C3;
    }

    Complex operator-(Complex)
    {
        C3.real = C1.real - C2.real;
        C3.img = C1.img - C2.img;
        return C3;
    }
    Complex operator*(Complex)
    {
        C3.real = (C1.real * C2.real) + (C1.img * C2.img);
        C3.img = (C1.img + C2.real) + (C1.real * C2.img);
        return C3;
    }
    Complex operator/(Complex)
    {
        C3.real = ((C1.real * C2.real) + (C1.img * C2.img)) / ((C2.real * C2.real) + (C2.img * C2.img));
        C3.img = ((C1.img + C2.real) + (C1.real * C2.img)) / ((C2.real * C2.real) + (C2.img * C2.img));
        return C3;
    }

} C1, C2, C3;

int main()
{

    int ch;
    while (ch != 7)
    {
        cout << "\n1. Accept\n2. Display\n3. Deposit\n4. Withdraw\n5. Check Balance\n6. Exit\n";
        cout << "Enter your choice: ";
        cin >> ch;
    }
}
