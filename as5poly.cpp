#include <iostream>
using namespace std;

class Person
{
public:
    int id, salary;
    string name, deg;

    // Pure virtual functions to make Person an abstract class
    virtual void accept() = 0;
    virtual void display() = 0;
};

// Doctor class inheriting from Person
class Doctor : public Person
{
public:
    void accept()
    {
        cout << "Enter Doctor's ID: ";
        cin >> id;
        cout << "Enter Doctor's Name: ";
        cin >> name;
        cout << "Enter Doctor's Designation: ";
        cin >> deg;
        cout << "Enter Doctor's Salary: ";
        cin >> salary;
    }

    void display()
    {
        cout << "\nDoctor's ID: " << id << "\nName: " << name
             << "\nDesignation: " << deg << "\nSalary: " << salary << endl;
    }
};

// AStaff class inheriting from Person
class AStaff : public Person
{
public:
    void accept()
    {
        cout << "Enter Administrative Staff's ID: ";
        cin >> id;
        cout << "Enter Administrative Staff's Name: ";
        cin >> name;
        cout << "Enter Administrative Staff's Designation: ";
        cin >> deg;
        cout << "Enter Administrative Staff's Salary: ";
        cin >> salary;
    }

    void display()
    {
        cout << "\nAdministrative Staff's ID: " << id << "\nName: " << name
             << "\nDesignation: " << deg << "\nSalary: " << salary << endl;
    }
};

// Nurse class inheriting from Person
class Nurse : public Person
{
public:
    void accept()
    {
        cout << "Enter Nurse's ID: ";
        cin >> id;
        cout << "Enter Nurse's Name: ";
        cin >> name;
        cout << "Enter Nurse's Designation: ";
        cin >> deg;
        cout << "Enter Nurse's Salary: ";
        cin >> salary;
    }

    void display()
    {
        cout << "\nNurse's ID: " << id << "\nName: " << name
             << "\nDesignation: " << deg << "\nSalary: " << salary << endl;
    }
};

// Patient class inheriting from Person
class Patient : public Person
{
public:
    int bill;

    void accept()
    {
        cout << "Enter Patient's ID: ";
        cin >> id;
        cout << "Enter Patient's Name: ";
        cin >> name;
        cout << "Enter Patient's Bill Amount: ";
        cin >> bill;
    }

    void display()
    {
        cout << "\nPatient's ID: " << id << "\nName: " << name
             << "\nBill: " << bill << endl;
    }
};

// Main function to create and display various persons
int main()
{
    // Polymorphism in action with an array of Person pointers
    Person *people[4];

    people[0] = new Doctor();
    people[1] = new AStaff();
    people[2] = new Nurse();
    people[3] = new Patient();

    // Accept details for each type of person
    for (int i = 0; i < 4; ++i)
    {
        people[i]->accept();
    }

    // Display details for each type of person
    for (int i = 0; i < 4; ++i)
    {
        people[i]->display();
    }

    // Cleanup dynamically allocated memory
    for (int i = 0; i < 4; ++i)
    {
        delete people[i];
    }

    return 0;
}