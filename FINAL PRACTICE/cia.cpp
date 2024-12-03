#include <iostream>
using namespace std;

class CIA {
public:
    string name;
    int roll;
    string subject;
    int CIA1, CIA2, CIA3, MiniProject;

    void InputDetails() {
        cout << "Enter the name of the student: ";
        cin >> name;
        cout << "Enter the roll number of the student: ";
        cin >> roll;
        cout << "Enter the subject of the student: ";
        cin >> subject;
        cout << "Enter the CIA1 marks of the student: ";
        cin >> CIA1;
        cout << "Enter the CIA2 marks of the student: ";
        cin >> CIA2;
        cout << "Enter the CIA3 marks of the student: ";
        cin >> CIA3;
        cout << "Enter the Mini Project marks of the student: ";
        cin >> MiniProject;
    }

    int ComputeInternalMarks() {
        return (CIA1 + CIA2 + CIA3 + MiniProject) / 4 * 40;
    }
};

class Marks : public CIA {
public:
    int IA, UE;

    void InputAdditionalMarks() {
        cout << "Enter the Internal Assessment (IA) marks: ";
        cin >> IA;
        cout << "Enter the University Examination (UE) marks: ";
        cin >> UE;
    }

    int ComputeTotalMarks() {
        return ComputeInternalMarks() + IA + UE;
    }
};

int main() {
    Marks student;
    int choice;

    do {
        cout << "\nMenu:\n";
        cout << "1. Build Master Table\n";
        cout << "2. Display Master Table\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "\nBuilding Master Table...\n";
            student.InputDetails();
            student.InputAdditionalMarks();
            break;

        case 2:
            cout << "\nDisplaying Master Table...\n";
            cout << "Name: " << student.name << endl;
            cout << "Roll Number: " << student.roll << endl;
            cout << "Subject: " << student.subject << endl;
            cout << "Internal Marks (Scaled to 40): " << student.ComputeInternalMarks() << endl;
            cout << "IA Marks: " << student.IA << endl;
            cout << "UE Marks: " << student.UE << endl;
            cout << "Total Marks: " << student.ComputeTotalMarks() << endl;
            break;

        case 3:
            cout << "Exiting program. Goodbye!\n";
            break;

        default:
            cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 3);

    return 0;
}
