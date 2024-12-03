/*A hospital management system needs to streamline its 
operations by organizing various types of personnel and 
services. The system should manage different roles such as 
doctors, nurses, and administrative staff. Create the Different 
classes like Person, Doctor ,Nurse, Administrate Staff. Use 
the concept of Inheritance.*/
#include<iostream>
using namespace std;

class Person{
    private:
    int age;
    public:
    string name,email;
    void getdata(){
        cout<<"Enter the name of the person:";
        cin>>name;
        cout<<"Enter the age of the person:";
        cin>>age;
        cout<<"Enter the email of the person:";
        cin>>email;
    }
    void display(){
        cout<<"Name: "<<name<<endl;
        cout<<"Age: "<<age<<endl;
        cout<<"email: "<<email<<endl;

    }

};
class Doctor:public Person{
    public:
    string specialization;
    void getdata(){
        Person::getdata();
        cout<<"Enter the specialization of the doctor:";
        cin>>specialization;
    }
    void display(){
        Person::display();
        cout<<"Specialization: "<<specialization<<endl;
    }
};
class Nurse:public Person{
    public:
    string specialization;
    void getdata(){
        Person::getdata();
        cout<<"Enter the specialization of the nurse:";
        cin>>specialization;
    }
    void display(){
        Person::display();
        cout<<"Specialization: "<<specialization<<endl;
    }
};
class Astaff:public Person{
    public:
    string role;
    void getdata(){
        Person::getdata();
        cout<<"Enter the role of the astaff:";
        cin>>role;
    }
    void display(){
        Person::display();
        cout<<"Specialization: "<<role<<endl;
    }
};
int main(){
    //object making
    Doctor d1;
    Nurse n1;
    Astaff a1;
    //switch case using do while loop
    int choice;
    do{
        cout<<"Enter the choice: "<<endl;
        cout<<"1. Enter Doctor details "<<endl;
        cout<<"2. Enter Nurse details"<<endl;
        cout<<"3. Enter Astaff details"<<endl;
        cout<<"4. Display doctor details"<<endl;
        cout<<"5. Display nurse details"<<endl;
        cout<<"6. Display astaff details"<<endl;
        cout<<"7. Exit"<<endl;
        
        cin>>choice;
        switch(choice){
            case 1:
            d1.getdata();
            cout<<"Data entered successfully"<<endl;
            break;
            case 2:
            n1.getdata();
            cout<<"Data entered successfully"<<endl;
            break;
            case 3:
            a1.getdata();
            cout<<"Data entered successfully"<<endl;
            break;
            case 4:
            d1.display();
            break;
            case 5:
            n1.display();
            break;
            case 6:
            
            a1.display();
            break;
            case 7:
            cout<<"Exiting..."<<endl;
            exit(0);
            break;
            default:
            cout<<"Invalid choice"<<endl;
        }
    }while(choice!=7);
    return 0;
}


