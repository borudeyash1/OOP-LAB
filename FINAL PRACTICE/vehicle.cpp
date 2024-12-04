/*A rich Businessman  want to store the information of his 
different vehicle develop a program for same. Create a class 
named Vehicle with two data member named mileage and 
price. Create its two subclasses: Car with data members to 
store ownership cost, warranty (by years), seating capacity 
and fuel type (diesel or petrol). Bike with data members to 
store the number of cylinders, number of gears, cooling 
type(air, liquid or oil), wheel type(alloys or spokes) and fuel 
tank size(in inches). Display the details of Car and Bike.*/
#include<iostream>
using namespace std;
class Vehicle{
    string milege, price;
    public:
    void getdata(){
        cout<<"Enter the milege";
        cin>>milege;
        cout<<"Enter the price: ";
        cin>>price;
    }
    void display(){
        cout<<"Milege"<<milege;
        cout<<"Price"<<price;

    }
};
class Car:public Vehicle{
    public:
    string ocost,warranty,capacity,fuel;
    void accept(){
        cout<<"Enter ownership cost(in Rupees)";
        cin>>ocost;
        cout<<"Enter warranty of Car(in years)";
        cin>>warranty;
        cout<<"Enter seating capacity of car(4,5,6,7)";
        cin>>capacity;
        cout<<"Enter the fuel type of car(petrol,diesel,CNG,electric)";
        cin>>fuel;
        Vehicle::getdata();
    }
    void display(){
        cout<<"ownership cost: "<<ocost<<endl;       
        cout<<"warranty of Car: "<<warranty<<endl;
        cout<<"seating capacity: "<<capacity<<endl;
        cout<<"fuel type of car: "<<fuel<<endl;
        Vehicle::display();
    }

};
class Bike:public Vehicle{
    public:
    string cylinder,gears,cooling,wheel,fuel;
    void accept(){
        cout<<"Enter the number of cylinders";
        cin>>cylinder;
        cout<<"Enter  number of gears)";
        cin>>gears;
        cout<<"Enter cooling type(air, liquid or oil)";
        cin>>cooling;
        cout<<"Enter the wheel type(alloys or spokes) ";
        cin>>wheel;
        cout<<"Enter the fuel tank size";
        cin>>fuel;
        Vehicle::getdata();
    }
    void display(){
        cout<<"number of cylinders: "<<cylinder<<endl;       
        cout<<"number of gears: "<<gears<<endl;
        cout<<"cooling type: "<<cooling<<endl;
        cout<<"wheel type: "<<wheel<<endl;
        cout<<"fuel tank size: "<<fuel<<endl;
        Vehicle::display();
    }

};
int main(){
    //creating objects
    Car c;
    Bike b;
    int choice;
    do{
        //menu
        cout<<"1.Enter car details\n2,Enter bike details\n3.Display car details\n4.Display bike details";
        cout<<"\nEnter your choice";
        cin>>choice;
        switch(choice)
        {
            case 1:
            c.accept();
            break;
            case 2:
            b.accept();
            break;
            case 3:
            c.display();
            case 4:
            b.display();
            case 5:
            cout<<"Exiting.....";
            exit(0);
            default:
            cout<<"Invalid choice!";
            exit(0);
        }

    }while(choice!=5);
return 0;
}