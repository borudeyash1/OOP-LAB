#include<iostream>
using namespace std;

const int MAX__SUBJECTS = 10;\//define  a  maximum nuber of subjects

class Student{
    public:
    int roll;
    string prn,name;

    void get(){

        cout<<"Enter the roll no. , name , and PRN of student: ";

        cin >> roll >> name >> prn;
    }
    void display() const{
        cout << "Name of student: " << name << endl;
        cout << "Roll no. of student: " << roll << endl;
        cout << "PRN of student: " << prn << endl;

    }

};

class Test : virtual public Student{
    protected:
    int n;
    