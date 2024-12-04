/*Create a class student ,Derive two classes from student class 
such as Test class (which accept test details such as CIA 
Marks and End sem Marks ,Subject Details)  and Sport class 
(which accept Sport name and Sport Grade).By  using these 
two classes (Test and Sport) derive the class Result which 
display the all details of students. Use the concept of Virtual 
Base class.*/
#include <iostream>
#include <string>
using namespace std;

template <class T>
class Student {
protected:
    string name, rno;

public:
    void getStudentDetails() {
        cout << "Enter the name of the student: ";
        cin >> name;
        cout << "Enter the roll number of the student: ";
        cin >> rno;
    }

    void displayStudentDetails() {
        cout << "Name: " << name << endl;
        cout << "Roll Number: " << rno << endl;
    }
};

template <class T>
class Test : public Student<T> {
protected:
    T cia, endsem;

public:
    void getTestDetails() {
        cout << "Enter the CIA marks of the student: ";
        cin >> cia;
        cout << "Enter the End Semester marks of the student: ";
        cin >> endsem;
    }

    void displayTestDetails() {
        cout << "CIA Marks: " << cia << endl;
        cout << "End Semester Marks: " << endsem << endl;
    }
};

template <class T>
class Sports : public Student<T> {
protected:
    string sportName;
    T sportGrade;

public:
    void getSportsDetails() {
        cout << "Enter the Sport name of the student: ";
        cin >> sportName;
        cout << "Enter the Sport grade of the student: ";
        cin >> sportGrade;
    }

    void displaySportsDetails() {
        cout << "Sport Name: " << sportName << endl;
        cout << "Sport Grade: " << sportGrade << endl;
    }
};

template <class T>
class Result : public Test<T>, public Sports<T> {
public:
    void displayResult() {
        this->displayStudentDetails();
        this->displayTestDetails();
        this->displaySportsDetails();
    }
};

int main() {
    Result<int> studentResult;
    int choice;

    do {
        cout << "Enter the choice: " << endl;
        cout << "1. Enter Student Details" << endl;
        cout << "2. Enter Test Details" << endl;
        cout << "3. Enter Sports Details" << endl;
        cout << "4. Display All Details" << endl;
        cout << "5. Exit" << endl;
        cin >> choice;

        switch (choice) {
        case 1:
            studentResult.getStudentDetails();
            break;
        case 2:
            studentResult.getTestDetails();
            break;
        case 3:
            studentResult.getSportsDetails();
            break;
        case 4:
            studentResult.displayResult();
            break;
        case 5:
            exit(0);
        default:
            cout << "Invalid choice!" << endl;
        }
    } while (choice != 5);

    return 0;
}