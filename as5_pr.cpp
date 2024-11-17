#include<iostream>
using namespace std;

class Person{

    public:
    int id,salary;
    string name, deg;

    //pure virtual functions to make Person an abstract class
    virtual void accept() = 0;
    virtual void display() = 0;
};

//doctor class inheriting fromn person
class Doctor : public Person{
    public:
    void accept()
    {
        cout<<"Enter Doctor ID";
        cin>>id;
        cout<<"Enter Doctor Name";
        cin>>name;
        cout<<"Enter Doctor's salary";
        cin>>salary;

    }
    void display()
    {
        cout<<"\nDoctor's ID: " << id <<"\nName: " << name <<"\nSalary: " << salary << endl;
        
    }
};

//Astaff class inheriting from person
class Astaff : public Person 
{
    void accept(){
        cout<<"Enter Administrative Staff ID";
        cin>>id;
        cout<<"Enter Administrative Staff Name";
        cin>>name;
        cout<<"Enter Administrative Staff's designation";
        cin>>deg;
        cout<<"Enter Administrative Staff's salary";
        cin>>salary;

    }
    void display(){
        cout<<"\nAdministrative Staff's ID: " << id <<"\nName: " << name <<"\nDesignation: " << deg <<"\nSalary: " << salary << endl;

    }
};

//nurse class inheriting form person 

class Nurse : public Person
{
    public:
    void accept()
    {
        cout << "Enter Nurse ID";
        cin >> id;
        cout << "Enter Nurse Name";
        cin >> name;
        cout << "Enter Nurse's designation";
        cin >> deg;
        cout << "Enter Nurse's salary";
        cin >> salary;
    }
    void  display(){
        cout<<"\nNurse's ID: " << id <<"\nName: " << name <<"\nDesignation: " << deg <<"\nSalary: " << salary << endl;
    }
};

class Patient : public Person{
    public:
    int bill;

    void accept(){
        cout << "Enter Patient's ID";
        cin >> id;
        cout << "Enter Patient's Name";
        cin >> name;
        cout << "Enter Patient's Bill Amount";
        cin >> bill;
    }

    void display(){
        cout<<"\nPatient's ID: " << id <<"\nName: " << name <<"\nBill: " << bill << endl;
    }
};

//Main function to create and display various persons
int main(){

    //Polymorphism in action with an array of Person pointers   
    Person *people[4];

    people[0] = new Doctor();
    people[1] = new Astaff();
    people[2] = new Nurse();
    people[3] = new Patient();
    //Accept details for each type ofn person

    for (int i = 0;i < 4;i++){
        people[i]->accept();
    }

    //Display details for each type of person 

    for(int i=0;i < 4;i++){
        people[i]->display();
    
    }



}


