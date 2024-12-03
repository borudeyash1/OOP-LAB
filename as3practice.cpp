#include<iostream>

using namespace std;
class Complex{

    double real , imaginary;

    public:
    Complex(double r = 0 , double img = 0)
    {
        real = r;
        imaginary = img;
    }

    void display()
    {
        if(imaginary >= 0)
        cout << real << "+" << imaginary<< "i" << endl;
        else
        cout<<real << "-" << -imaginary <<"i" << endl;
    }

    //operator overaloading 
    Complex operator+(Complex &s);
    friend Complex operator-(Complex &s, Complex &ss);
    Complex operator*(Complex &s);
    Complex operator/(Complex &s);

};

//addition
Complex Complex :: operator+(Complex &s)
{
    return Complex(real + c2.real , imaginary + c2.imaginary);
}

//subtraction
Complex operator-(Complex &s, Complex &ss)
{

}