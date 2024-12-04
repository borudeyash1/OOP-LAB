/*Write a C++ program for  function template to find the 
maximum of two numbers and Minimum of Two numbers. */
#include<iostream>
using namespace std;

//Function template for finding maximum
template<typename T>
T findMax(T a, T b){
    return (a > b) ? a:b;
}
template<typename T>
T findMin(T a, T b){
    return (a < b) ? a:b;
}

int main(){
    int choice;
    cout << "Choose data type";
    do{
    cout << "\n1.Integer \n2. Float \n3.Character\n";
    cin>>choice;

    
    switch(choice)
    {
        case 1:{
            int x,y;
            cout<<"Enter two integers: ";
            cin >> x >> y;
            cout << "Maximum: " <<findMax(x, y) <<endl;
            cout << "Minimum: " <<findMin(x, y) <<endl;
            break;
        }
        case 2:{
            float x,y;
            cout<<"Enter two Float values: ";
            cin >> x >> y;
            cout << "Maximum: " <<findMax(x, y) <<endl;
            cout << "Minimum: " <<findMin(x, y) <<endl;
            break;
        }
        case 3:{
            char x,y;
            cout<<"Enter two characters: ";
            cin >> x >> y;
            cout << "Maximum: " <<findMax(x, y) <<endl;
            cout << "Minimum: " <<findMin(x, y) <<endl;
            break;
        }
        case 4:
        cout<<"Exitting.....";
        exit(0);
        default:
        cout<<"Invalid choice.Please enter a valid choice.";
        exit(0);

    }
    }while(choice!=4);
    return 0;
}
