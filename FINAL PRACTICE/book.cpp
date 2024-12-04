/*Design a Book Library System where you can manage books
and stored the book information such as title, author,
publisher, price. Derive the Two classes from Book class
such as student and Teacher class ,accept the details of
student and Teacher in respective class also create issue
function in both the classes and display the details of book
as well as  student /Teacher. */
#include <iostream>
using namespace std;

class Book
{
    string title, author, publisher, price;

public:
    void getdata()
    {
        cout << "Enter Title of the book ";
        cin >> title;
        cout << "Enter the author of Book";
        cin >> author;
        cout << "Enter the publisher of the book";
        cin >> publisher;
        cout << "Enter the price of the book";
        cin >> price;
    }
    void display()
    {
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "Publisher: " << publisher << endl;
        cout << "Price: " << price << endl;
    }
};
class Student : public Book
{
public:
    string sname, rno, semail;
    void getdata()
    {
        cout << "Enter the student name: ";
        cin >> sname;
        cout << "Enter the Roll no:";
        cin >> rno;
        cout << "Enter student's email";
        cin >> semail;
        Book::getdata();
    }
    void display()
    {
        cout << "Student name: " << sname << endl;
        cout << "Roll no: " << rno << endl;
        cout << "Student's email: " << semail << endl;
        Book::display();
    }
};
class Teacher : public Book
{
public:
    string tname, sub, temail;
    void getdata()
    {
        cout << "Enter the Teacher name: ";
        cin >> tname;
        cout << "Enter Subject of Teacher:";
        cin >> sub;
        cout << "Enter teacher's email";
        cin >> temail;
        Book::getdata();
    }
    void display()
    {
        cout << "Teacher name: " << tname << endl;
        cout << "Teacher's subject: " << sub << endl;
        cout << "Teacher's email: " << temail << endl;
        Book::display();
    }
};
int main()
{
    // creating objects
    Student s;
    Teacher t;
    int choice;
    // menu
    do{
    cout << "----Book library system----\n";
    cout << "1.Get Student info\n";
    cout << "2.Get Teacher info\n";
    cout << "3.Display Student info\n";
    cout << "4.Display Teacher info\n";
    
    cin >> choice;
    switch (choice)
    {
    case 1:
        s.getdata();
        break;
    case 2:
        t.getdata();
        break;
    case 3:
        s.display();
        break;
    case 4:
        t.display();
        break;
    default:
        break;
    }
    }while(choice!=4);
    return 0;
}
