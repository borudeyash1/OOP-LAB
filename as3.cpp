//developing an oop in in c++ to create  a database of personal information system 
//containing the following information
//name,dob,blood group,height,weight,insurance no.,contact no.,telephone no.,driving licence no.
//construct the database with suitabble member functions
//for initializing and destroying the data using constructor,default constructor,parameterized constructor,copy constructor
//,destructor,static data member and member fuction,friend function,inline finction and dynamic memory allocation operation new and delete

#include <iostream>
#include <cstring>
using namespace std;

class PersonalInfo
{
private:
    char name[100], dob[15],bg[5],insNo[20],contactNo[15],tn[15],dlNo[20];      
    float height,weight;
    static int count;

public:

    PersonalInfo()                         // Default constructor
    {
        strcpy(name, "");
        strcpy(dob, "");
        strcpy(bg, "");
        height = 0.0;
        weight = 0.0;
        strcpy(insNo, "");
        strcpy(contactNo, "");
        strcpy(tn, "");
        strcpy(dlNo, "");
        count++;
    }

    // Parameterized constructor
    PersonalInfo(const char *n, const char *d, const char *b, float h, float w, const char *i, const char *c, const char *t, const char *dl)
    {
        strcpy(name, n);
        strcpy(dob, d);
        strcpy(bg, b);
        height = h;
        weight = w;
        strcpy(insNo, i);
        strcpy(contactNo, c);
        strcpy(tn, t);
        strcpy(dlNo, dl);
        count++;
    }

    // Copy constructor
    PersonalInfo(const PersonalInfo &p)
    {
        strcpy(name, p.name);
        strcpy(dob, p.dob);
        strcpy(bg, p.bg);
        height = p.height;
        weight = p.weight;
        strcpy(insNo, p.insNo);
        strcpy(contactNo, p.contactNo);
        strcpy(tn, p.tn);
        strcpy(dlNo, p.dlNo);
        count++;
    }

    // Destructor
    ~PersonalInfo()
    {
        count--;
    }

    static int getCount()
    {
        return count;
    }

    // Friend function
    friend void display(const PersonalInfo &p);

    void setHeightWeight(float h, float w)
    {
        height = h;
        weight = w;
    }
    inline void setWeight(float w) { weight = w; }
    

    // Function to take input from user
    void input()
    {
        cout << "Enter name: ";
        cin >> name;

        cout << "Enter DOB (dd-mm-yyyy): ";
        cin >> dob;

        cout << "Enter blood group: ";
        cin >> bg;

        cout << "Enter height: ";
        cin >> height;

        cout << "Enter weight: ";
        cin >> weight;

        cout << "Enter insurance number: ";
        cin >> insNo;

        cout << "Enter contact number: ";
        cin >> contactNo;

        cout << "Enter telephone number: ";
        cin >> tn;

        cout << "Enter driving license number: ";
        cin >> dlNo;
    }
};

// Initialize static member
int PersonalInfo::count = 0;

// Friend function 
void display(const PersonalInfo &p) {
    cout << "Category\tInformation\n";
    cout << "Name\t" << p.name << "\n";
    cout << "DOB\t" << p.dob << "\n";
    cout << "Blood Group\t" << p.bg << "\n";
    cout << "Height\t" << p.height << "\n";
    cout << "Weight\t" << p.weight << "\n";
    cout << "Insurance No.\t" << p.insNo << "\n";
    cout << "Contact No.\t" << p.contactNo << "\n";
    cout << "Telephone No.\t" << p.tn << "\n";
    cout << "Driving License No.\t" << p.dlNo << "\n";
}

int main()
{
    PersonalInfo person;
    int choice;

    while (choice != 4)
    {
        cout << "\n--- Personal Information System ---\n";
        cout << "1. Add Personal Information\n";
        cout << "2. Display Personal Information\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            person.input();
            break;
        case 2:
            display(person);
            break;
        case 3:
            cout << "Exiting the program.\n";
            break;
        default:
            cout << "Invalid choice! Please try again.\n";
        }
    };

    cout << "Total number of persons: " << PersonalInfo::getCount() << endl;

    return 0;
}
