//developing an oop in in c++ to create  a database of personal information system 
//containing the following information
//name,dob,blood group,height,weight,insurance no.,contact no.,telephone no.,driving licence no.
//construct the database with suitabble member functions
//for initializing and destroying the data using constructor,default constructor,parameterized constructor,copy constructor
//destructor,static data member and member fuction,friend function,inline finction and dynamic memory allocation operation new and delete 

#include <iostream>
#include <cstring>
using namespace std;
int n;

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
	
    friend void display(PersonalInfo[],int);
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
}y[10];

// Initialize static member
int PersonalInfo::count = 0;
        cout << "------------------------------------------Category Information---------------------------------------------------\n";
void display(PersonalInfo p[],int i){

    cout<<"\n";
    for(i=0;i<n;i++)
    cout<<p[i].name<<"\t"<<p[i].dob<<"\t"<<p[i].bg<<"\t"<<p[i].height<<"\t"<<p[i].weight<<"\t"<<p[i].insNo<<"\t"<<p[i].contactNo<<"\t"<<p[i].tn<<"\t"<<p[i].dlNo<<"\t"<<endl;}
int main()
{
    PersonalInfo person;
    int choice,i;
    cout<<"Enter the number of records";
    cin>>n;

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
        for(i=0;i<n;i++)
        	{
        	y[i].input();
        	}
            
            break;
        case 2:
        	cout << "Name\t"<<"DOB\t"<<"Blood Group\t"<<"Height\t"<<"Weight\t"<<"Insurance No\t"<<"Contact No\t"<<"Telephone No\t"<<"Driving LicenseNo\t"<<endl;
           display(y,i);
    		
            
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
