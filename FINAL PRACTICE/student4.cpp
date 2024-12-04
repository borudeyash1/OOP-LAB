#include <iostream>
using namespace std;

class Marks {
public:
    string name, rno, subject, subcode;
    int CIA1 = 0, CIA2 = 0, CIA3 = 0, IA = 0, MiniProject = 0, UE = 0,Total = 0;

    virtual void GetMarks() {
        cout << "Enter the name of the student: ";
        cin >> name;
        cout << "Enter the roll number of the student: ";
        cin >> rno;
        cout << "Enter the subject of the student: ";
        cin >> subject;
        cout << "Enter the subject code of the student: ";
        cin >> subcode;
    }

    virtual void DisplayMarks() {
        
        // Displaying header
        cout << "Name\tRoll Number\tSubject\t\tSubject Code\tCIA1\tCIA2\tCIA3\tMini Project\tIA\tUE\tTotal\n";
        // Displaying values in order
        cout << name << "\t" << rno << "\t\t" << subject << "\t" << subcode     << "\t\t"
             << CIA1 << "\t" << CIA2 << "\t " << CIA3    << "\t" << MiniProject << "\t\t" << IA << "\t" << UE << Total << endl;
    }
};

class CIA : public Marks {
public:
    void GetMarks() override {
        Marks::GetMarks();
        cout << "Enter the CIA1 marks of the student (Out of 20): ";
        cin >> CIA1;
        cout << "Enter the CIA2 marks of the student (Out of 20): ";
        cin >> CIA2;
        cout << "Enter the CIA3 marks of the student (Out of 20): ";
        cin >> CIA3;
        cout << "Enter the Mini Project marks of the student (Out of 20): ";
        cin >> MiniProject;
        IA = ((CIA1 + CIA2 + CIA3) / 3) + MiniProject;
        cout << "Enter the University Examination marks of the student (Out of 60): ";
        cin >> UE;
        Total = IA + UE;
    }
};

int main() {
    CIA c1;
    int choice;
    do {
        cout << "1. Input Marks\n2. Display Marks\n3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
        case 1:
            c1.GetMarks();
            break;
        case 2:
            c1.DisplayMarks();
            break;
        case 3:
            cout << "Exiting program...\n";
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
            break;
        }
    } while (choice != 3);

    return 0;
}
