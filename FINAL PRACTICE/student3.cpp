/*Create a class student ,Derive two classes from student class 
such as Test class (which accept test details such as CIA 
Marks and End sem Marks ,Subject Details)  and Sport class 
(which accept Sport name and Sport Grade).By  using these 
two classes (Test and Sport) derive the class Result which 
display the all details of students. Use the concept of Virtual 
Base class.*/
#include<iostream>
using namespace std;
class Student{
    protected:
    string name,rno;
    public:
    //virtual base class
    
    virtual void getdata(){
        cout<<"Enter the name of the student: ";
        cin>>name;
        cout<<"Enter the roll number of the student: ";
        cin>>rno;

    }
    virtual void display(){
        cout<<"Name: "<<name<<endl;
        cout<<"Roll Number: "<<rno<<endl;
        }

};
class Test:public Student{
    protected:
    int cia,endsem;
    public:
    void getdata(){
        cout<<"Enter the CIA marks of the student: ";
        cin>>cia;
        cout<<"Enter the End Semester marks of the student: ";
        cin>>endsem;
    }
    void display(){
        cout<<"CIA Marks: "<<cia<<endl;
        cout<<"End Semester Marks: "<<endsem<<endl;
    }


};
class Sports:public Student{
    protected:
    int cia,endsem;
    public:
    void getdata(){
        //getting data od sports 
        cout<<"Enter the Sports name of the student: ";
        cin>>name;
        cout<<"Enter the Sports marks of the student: ";
        cin>>endsem;
    }
    void display(){
        cout<<"Sports Name: "<<name<<endl;
        cout<<"Sports Marks: "<<endsem<<endl;
    }



};

int main(){
    int choice;
    //creating objects
    Test t1;
    Sports s1;
    //switch case using do while  loop
    do{
        cout<<"Enter the choice: "<<endl;
        cout<<"1. Test"<<endl;
        cout<<"2. Sports"<<endl;
        cout<<"3.Display Test Details"<<endl;
        cout<<"4.Display Sports Details"<<endl;
        cout<<"5.Exit"<<endl;
        cin>>choice;
        switch(choice){
            case 1:
            t1.getdata();
            break;
            case 2:
            s1.getdata();
            break;
            case 3:
            t1.display();
            break;
            case 4:
            s1.display();
            break;
            case 5:
            exit(0);
            break;
            default:
            cout<<"Invalid choice"<<endl;
        }
    }while(choice!=5);
        
    
    return 0;
}
Can you make like template<class >