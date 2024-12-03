#include <iostream>
using namespace std;

class Student {
protected:
    string name;
    int roll;
public:
    void getdata() {
        cout << "Enter the name of the student: ";
        cin >> name;
        cout << "Enter the roll number of the student: ";
        cin >> roll;
    }
    void display() const {
        cout << "Name: " << name << endl;
        cout << "Roll Number: " << roll << endl;
    }
};

class Test : virtual public Student {
protected:
    int CIA, EndSem;
public:
    void getdata() {
        cout << "Enter the CIA marks of the student: ";
        cin >> CIA;
        cout << "Enter the End Semester marks of the student: ";
        cin >> EndSem;
    }
    void display() const {
        cout << "CIA Marks: " << CIA << endl;
        cout << "End Semester Marks: " << EndSem << endl;
    }
};

class Sport : virtual public Student {
protected:
    string sport;
    char grade;
public:
    void getdata() {
        cout << "Enter the name of the sport: ";
        cin >> sport;
        cout << "Enter the grade of the sport: ";
        cin >> grade;
    }
    void display() const {
        cout << "Sport: " << sport << endl;
        cout << "Grade: " << grade << endl;
    }
};

class Result : public Test, public Sport {
public:
    void getdata() {
        Student::getdata();  // Ensure student details are entered only once
        Test::getdata();
        Sport::getdata();
    }
    void display() const {
        Student::display();
        Test::display();
        Sport::display();
    }
};

int main() {
    Result r;
    int choice;

    do {
        cout << "\nMenu:\n";
        cout << "1. Input Student Details\n";
        cout << "2. Display Student Details\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                r.getdata();
                break;
            case 2:
                r.display();
                break;
            case 3:
                cout << "Exiting program...\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 3);

    return 0;
}
