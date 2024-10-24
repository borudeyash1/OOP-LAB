#include <iostream>
#include <vector>
using namespace std;

class Student
{
public:
    int roll;
    string prn, name;
    void get()
    {
        cout << "Enter the roll no., name and prn of student: ";
        cin >> roll >> name >> prn;
    }
    void display();
};

void Student::display()
{
    cout << "Name of student : " << name << endl;
    cout << "Roll no. of student : " << roll << endl;
    cout << "PRN of student : " << prn << endl;
}

class Test : virtual public Student
{
    int n;
    vector<string> subname;
    vector<int> cia, endsem;

public:
    void getm()
    {
        cout << "Emter the no. of subjects: " << endl;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cout << "Enter the subject name: ";
            cin >> subname[i];
            cout << "Enter the CIA marks and END SEM marks of " << subname[i];
            cin >> cia[i] >> endsem[i];
        }
    }
    void displayT();
};

void Test::displayT()
{
    for (int i = 0; i < n; i++)
    {
        cout << "\n"
             << cia[i] << "\t" << endsem[i] << "\t" << endl;
    }
}

class Sports : virtual public Student
{
    string spname, spgrade;

public:
    void getsp()
    {
        cout << "Enter Sport name: ";
        cin >> spname;
        cout << "Enter aport grade: ";
        cin >> spgrade;
    }
    void displayG();
};

void Sports::displayG()
{
    cout << "\n"
         << spname << "\t" << spgrade << endl;
}

class Result : public Test, public Sports
{
public:
    void displayAll();
};

void Result::displayAll()
{
    display();
    displayG();
    displayT();
}

int main()
{
    Result R;
    ;
    int ch, n;
    while (true)
    {
        cout << "1. Accept\n2. Display\n3. Exit\n";
        cout <<"Enter your choice: ";
        cin >> ch;
        switch (ch)
        {
            case 1:
                for (int i = 0; i < n; i++)
                {
                    R.get();
                    R.getm();
                    R.getsp();
                }
                break;
            case 2:
                for (int i = 0; i < n; i++)
                {
                    R.displayAll();
                }
                break;
            case 3:
                cout << "Exiting.....!!\n";
                break;
            default:
                cout << "Enter valid input (1/2/3)";
        }
    }
    return 0;
}
