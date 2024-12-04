/*Create a class Shape with pure virtual function
calculate_Area() which inheritance the three classes
Circle,Rectangle ,Square to calculate the area of different
geometry figure also it override the calculate_Area()
function in it.Write the C++ code for the same.*/
#include <iostream>
using namespace std;
class Shape
{
public:
    double base, height, radius, side, area;
    virtual void getdata() {}
    virtual void calculate_Area() = 0;
};
class Circle : public Shape
{
public:
    void getdata()
    {
    cout<<"Enter the radius of circle: ";
    cin>>radius;
    }
    void calculate_Area()
    {
        area = 3.14 * radius * radius;
        cout << "The area of the circle is: " << area << endl;
    }
};
class Rectangle : public Shape
{
public:
    void getdata()
    {
        cout<<"Enter the base of rectangle: ";    
        cin>>base;
        cout<<"Enter the height of rectangle: ";
        cin>>height;
    }
    void calculate_Area()
    {
        area = base * height;
        cout << "The area of the rectangle is: " << area << endl;
    }
};
class Square : public Shape
{
public:
        
    void getdata()
    {
        cout<<"Enter the side of square: ";
        cin>>side;
    }
    void calculate_Area()
    {
        area = side * side;
        cout << "The area of the square is: " << area << endl;
    }
};
int main()
{
    Circle c;
    Rectangle r;
    Square s;
    // switch case using do while loop
    int choice;
    cout << "Calculating the area of different geometry figures" << endl;
    do
    {
        cout << "1.Circle\n2.Rectangle\n3.Square\nEnter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            c.getdata();
            c.calculate_Area();
            break;
        case 2:
            r.getdata();
            r.calculate_Area();
            break;
        case 3:
            s.getdata();
            s.calculate_Area();
            break;   
        default:
            cout << "Invalid choice" << endl;
            break;
        }
    } while (choice != 4);
    return 0;
}