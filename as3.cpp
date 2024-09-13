//developing an oop in in c++ to create  a database of personal information system 
//containing the following information
//name,dob,blood group,height,weight,insurance no.,contact no.,telephone no.,driving licence no.
//construct the database with suitabble member functions
//for initializing and destroying the data using constructor,default constructor,parameterized constructor,copy constructor
//,destructor,static data member and member fuction,friend function,inline finction and dynamic memory allocation operation new and delete

#include <iostream>
#include <cstring>
using namespace std;

int n;

class PersonalInfo {
private:
    char name[100], dob[15], bg[5], insNo[20], contactNo[15], tn[15], dlNo[20];
    float height, weight;
    static int count;

public:
    PersonalInfo() {                         // Default constructor
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
    PersonalInfo(const char *n, const char *d, const char *b, float h, float w, const char *i, const char *c, const char *t, const char *dl) {
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
    PersonalInfo(const PersonalInfo &p) {
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
    ~PersonalInfo() {
        count--;
    }

    static int getCount() {
        return count;
    }

    // Friend functions
    friend void display(PersonalInfo[], int);
    friend void updateProfile(PersonalInfo[], int, const char*);
    friend void deleteProfile(PersonalInfo[], int, const char*);

    // Function to set height and weight
    void setHeightWeight(float h, float w) {
        height = h;
        weight = w;
    }

    // Inline function to set weight
    inline void setWeight(float w) {
        weight = w;
    }

    // Function to take input from user
    void input() {
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

    // Function to display personal information
    void displayInfo() const {
        cout << name << "\t" << dob << "\t" << bg << "\t" << height << "\t" << weight << "\t"
             << insNo << "\t" << contactNo << "\t" << tn << "\t" << dlNo << endl;
    }

    // Function to compare insurance number
    bool compareInsNo(const char *i) const {
        return strcmp(insNo, i) == 0;
    }
};

// Initialize static member
int PersonalInfo::count = 0;

// Function to display personal information
void display(PersonalInfo p[], int n) {
    cout << "------------------------------------------Category Information---------------------------------------------------\n";
    cout << "Name\tDOB\tBlood Group\tHeight\tWeight\tInsurance No\tContact No\tTelephone No\tDriving License No\n";
    for (int i = 0; i < n; i++) {
        p[i].displayInfo();
    }
}

// Function to update a profile
void updateProfile(PersonalInfo p[], int n, const char *insNo) {
    for (int i = 0; i < n; i++) {
        if (p[i].compareInsNo(insNo)) {
            cout << "Updating profile with Insurance Number " << insNo << endl;
            p[i].input(); // Take new input for updating the profile
            return;
        }
    }
    cout << "Profile with Insurance Number " << insNo << " not found." << endl;
}

// Function to delete a profile
void deleteProfile(PersonalInfo p[], int &n, const char *insNo) {
    int i;
    for (i = 0; i < n; i++) {
        if (p[i].compareInsNo(insNo)) {
            break;
        }
    }

    if (i == n) {
        cout << "Profile with Insurance Number " << insNo << " not found." << endl;
        return;
    }

    for (int j = i; j < n - 1; j++) {
        p[j] = p[j + 1];
    }
    n--;
    cout << "Profile with Insurance Number " << insNo << " deleted." << endl;
}

int main() {
    PersonalInfo person[10];
    int choice = 0, i;
    char insNo[20];

    cout << "Enter the number of records: ";
    cin >> n;

    while (choice != 4) {
        cout << "\n--- Personal Information System ---\n";
        cout << "1. Add Personal Information\n";
        cout << "2. Display Personal Information\n";
        cout << "3. Update Profile\n";
        cout << "4. Delete Profile\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                for (i = 0; i < n; i++) {
                    person[i].input();
                }
                break;

            case 2:
                display(person, n);
                break;

            case 3:
                cout << "Enter Insurance Number to update: ";
                cin >> insNo;
                updateProfile(person, n, insNo); 
                break;

            case 4:
                cout << "Enter Insurance Number to delete: ";
                cin >> insNo;
                deleteProfile(person, n, insNo); 
                break;

            case 5:
                cout << "Exiting the program.\n";
                break;

            default:
                cout << "Invalid choice! Please try again.\n";
        }
    }

    cout << "Total number of persons: " << PersonalInfo::getCount() << endl;

    return 0;
}