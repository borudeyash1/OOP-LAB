/*write the C++ code for the following statements which create
a student class with data members such as rollno, name and
address with suitable members functions. The class Test
which is derived using Student class which accept the test
marks of 3 subjects and display the total of marks. */
#include <iostream>
using namespace std;
class Student
{
    string name, rno, add;

public:
    void accept()
    {
        cout << "Enter your name: ";
        cin >> name;
        cout << "Enter your roll number: ";
        cin >> rno;
        cout << "Enter your address";
        cin >> add;
    }
    void display()
    {
        cout << "Name" << name << endl;
        cout << "Roll number" << rno << endl;
        cout << "Address" << add << endl;
    }
};
class Test : public Student
{
public:
    string sub1, sub2, sub3, m1, m2, m3;
    void accept()
    {
        Student::accept();
        cout << "Enter the 1st Subject name: ";
        cin >> sub1;
        cout << "Enter the 1st Subject Marks: ";
        cin >> m1;
        cout << "Enter the 2nd Subject name: ";
        cin >> sub2;
        cout << "Enter the 2nd Subject name Marks: ";
        cin >> m2;
        cout << "Enter the 3rd Subject name: ";
        cin >> sub3;
        cout << "Enter the 3rd Subject Marks: ";
        cin >> m3;
    }
    void display()
    {
        Student::display();
        cout << "Subject name\t" << "Marks\n";
        cout << sub1 << "\t\t" << m1 << endl;
        cout << sub2 << "\t\t" << m2 << endl;
        cout << sub3 << "\t\t" << m3 << endl;
    }
};
int main()
{
    Test t;
    int choice;
    do
    {
        cout << "----STUDENT MARKSHEET-----\n";
        cout << "1.Accept Marks\n";
        cout << "2.Display Marks\n";
        cout << "Enter your choice\n";
        cin >> choice;

        switch (choice)
        {
        case 1:
            t.accept();
            cout << "Data entered successfully";
            break;

        case 2:
            t.display();
            break;
        case 3:
            cout << "Exiting.....";
            break;
        default:
            cout << "Invalid choice: ";
            exit(0);
        }
        
            
    }while (choice != 3);
    return 0;
}