/*Create a base class called 'SHAPE' having-two data 
members of type double -member function get- data( 
)to initialize base class data members - pure virtual 
member function display-area( )to compute and 
display the area of the geometrical object. Derive two 
specific classes 'TRIANGLE' and 'RECTANGLE' 
from the base class Using these three classes, design a 
program that will accept the dimension of a triangle/ 
rectangle interactively and display the area. Implement 
using C++.*/
#include<iostream>
using namespace std;
class Shape{
    public:
    double a,b;
    virtual void getdata()=0;
    virtual void displayarea()=0;


};
class Triangle:public Shape{
    public:
    void getdata(){
        cout<<"Enter the base of the triangle: ";
        cin>>a;
        cout<<"Enter the height of the triangle: ";
        cin>>b;
    }
    void displayarea(){
        double area=(a*b)/2;
        cout<<"The area of the triangle is: "<<area<<endl;
        
    }
    void display(){
        getdata();
        displayarea();
    }

};
class Rectange:public Shape{    
    public:
    void getdata(){
        cout<<"Enter the length of the rectangle: ";
        cin>>a;
        cout<<"Enter the breadth of the rectangle: ";
        cin>>b;
    }
    void displayarea(){
        double area=a*b;
        cout<<"The area of the rectangle is: "<<area<<endl;
        
    }
    void display(){
        getdata();
        displayarea();
    }

};

int main(){
    int choice;
    //objects
    Triangle t;
    Rectange r;
    //switch case statement
    do{
        cout<<"1.Triangle\n2.Rectangle\n3.Exit\n";
        cout<<"Enter your choice: ";
        cin>>choice;
        switch(choice){
            case 1:
                t.display();
                break;
            case 2:
                r.display();
                break;
            case 3:
                exit(0);
        }
    }while(choice!=3);
    
}