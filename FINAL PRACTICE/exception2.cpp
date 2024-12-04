/*Create a C++ class students program that validates student 
marks entered by a user. The program should check each 
mark to ensure it falls within the valid range (0 to 100). If 
any mark is below 0 or above 100, the program should throw 
an exception to alert the user that the input is invalid. If valid 
input is accepted then display the detail of students. */

#include <iostream>
using namespace std;

class Student {
    int roll;
    string name;
    int marks;

public:
    void getdata() {
        cout << "Enter the name of the student: ";
        cin >> name;
        cout << "Enter the roll number of the student: ";
        cin >> roll;
        cout << "Enter the marks of the student: ";
        cin >> marks;
    }

    void display() {
        try{
            if (marks < 0 || marks > 100) {
                throw marks;
            }
            else {
                cout << "Name: " << name << endl;
                cout << "Roll Number: " << roll << endl;
                cout << "Marks: " << marks << endl;
            }
        }
        catch (int marks) {
            cout << "Marks should be between 0 and 100." << endl;
        }
    }
};

int main() {
    Student s;
    s.getdata();
    s.display();
    return 0;
}