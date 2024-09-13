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
                                                               // Default constructor
    PersonalInfo()
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

    // Static member function
    static int getCount()
    {
        return count;
    }

    // Friend function
    friend void display(const PersonalInfo &p);

    // Inline function for setting height and weight
    inline void setHeight(float h) { height = h; }
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
void display(const PersonalInfo &p)
{
    cout << "Name: " << p.name << endl;
    cout << "DOB: " << p.dob << endl;
    cout << "Blood Group: " << p.bg << endl;
    cout << "Height: " << p.height << endl;
    cout << "Weight: " << p.weight << endl;
    cout << "Insurance No.: " << p.insNo << endl;
    cout << "Contact No.: " << p.contactNo << endl;
    cout << "Telephone No.: " << p.tn << endl;
    cout << "Driving License No.: " << p.dlNo << endl;
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
