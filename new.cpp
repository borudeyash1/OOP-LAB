// design a cpp class "complex" with data member for real and imaginary part.provide default and parameterized constructor.
// Write a program to perform arithmetic operation of two complex numbers using operator overloading(using eother member function or friend function.
#incldue < iostream>
using namespace std;

class complex
{

private:
    float real, img;

public:
    complex()
    {
        real = 0;
        img = 0;
    }
    complex(int real, int img)
    {
        real = 0;
        img = 0;
    }
    void getnumber()
    {
        cout << "Enter the real part";
        cin >> real;
        cout << "Enter the imaginary part";
        cin >> img;
    }

    void display()
    {
        if (img > 0)
        {
            cout << real << "+" << img << endl;
        }
        else
        {
            cout << real << img << endl;
        }
    }

    complex operator+(complex)
    {
        c3.real = c1.real + c2.real;
        c3.img = c1.img + c2.img;
        return c3;
    }
    complex operator-(complex)
    {
        c3.real = c1.real - c2.real;
        c3.img = c1.img - c2.img;
        return c3;
    }
    complex operator*(complex)
    {
        c3.real = (c1.real * c2.real) + (c1.img * c2.img);
        c3.img = (c1.real * c2.img) + (c1.img * c2.real);
        return c3;
    }
    complex operator/(complex)
    {
        c3.real = ((c1.real * c2.real) + (c1.img * c2.img)) / ((c2.real * c2.real) + (c2.img * c2.real));
        c3.img = (c1.real * c2.img) + (c1.img * c2.real);
        / ((c2.real * c2.real) + (c2.img * c2.real));
        return c3;
    }
} c1, c2, c3;


int main()
{
    int ch;
    while(ch!=5)
    {
        
    }

}
