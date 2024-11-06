#include <iostream>
using namespace std;

const int MAX_SUBJECTS = 10; // Define a maximum number of subjects

class Student {
public:
    int roll;
    string prn, name;

    void get() {
        cout << "Enter the roll no., name, and PRN of the student: ";
        cin >> roll >> name >> prn;
    }

    void display() const {
        cout << "Name of Student: " << name << endl;
        cout << "Roll No. of Student: " << roll << endl;
        cout << "PRN of Student: " << prn << endl;
    }
};

class Test : virtual public Student {
protected:
    int n; // Number of subjects
    string subname[MAX_SUBJECTS];
    int cia[MAX_SUBJECTS], endsem[MAX_SUBJECTS];

public:
    void getm() {
        cout << "Enter the number of subjects (up to " << MAX_SUBJECTS << "): ";
        cin >> n;
        if (n > MAX_SUBJECTS) {
            cout << "Exceeding maximum number of subjects. Setting to " << MAX_SUBJECTS << ".\n";
            n = MAX_SUBJECTS;
        }

        for (int i = 0; i < n; i++) {
            cout << "Enter the subject name: ";
            cin >> subname[i];
            cout << "Enter the CIA and END SEM marks for " << subname[i] << ": ";
            cin >> cia[i] >> endsem[i];
        }
    }

    void displayT() const {
        cout << "\nSubject-wise Marks:\n";
        for (int i = 0; i < n; i++) {
            cout << subname[i] << "\tCIA: " << cia[i] << "\tEnd Sem: " << endsem[i] << endl;
        }
    }
};

class Sports : virtual public Student {
    string spname, spgrade;

public:
    void getsp() {
        cout << "Enter Sport name: ";
        cin >> spname;
        cout << "Enter Sport grade: ";
        cin >> spgrade;
    }

    void displayG() const {
        cout << "\nSport: " << spname << "\tGrade: " << spgrade << endl;
    }
};

class Result : public Test, public Sports {
public:
    void displayAll() const {
        display();
        displayG();
        displayT();
    }
};

int main() {
    int ch;
    int studentCount;

    cout << "Enter the number of students: ";
    cin >> studentCount;

    Result students[studentCount]; // Use array instead of vector

    while (true) {
        cout << "\nMenu:\n1. Accept\n2. Display\n3. Exit\n";
        cout << "Enter your choice: ";
        cin >> ch;

        switch (ch) {
            case 1:
                for (int i = 0; i < studentCount; i++) {
                    cout << "\nStudent " << i + 1 << " Details:\n";
                    students[i].get();
                    students[i].getm();
                    students[i].getsp();
                }
                break;

            case 2:
                for (int i = 0; i < studentCount; i++) {
                    cout << "\nDisplaying Details of Student " << i + 1 << ":\n";
                    students[i].displayAll();
                }
                break;

            case 3:
                cout << "Exiting...!!\n";
                return 0;

            default:
                cout << "Enter valid input (1/2/3)\n";
        }
    }
}