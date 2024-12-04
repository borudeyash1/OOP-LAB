/*Create a C++ program to create a class bank account system 
with a withdrawal feature. The program should allow users 
to specify a withdrawal amount and check if sufficient funds 
are available. If the requested withdrawal amount exceeds 
the account balance, the program should throw an exception 
to notify the user of insufficient funds. */
#include<iostream>
using namespace std;
class Bank{
    string name,accno;
    int amount,balance,newbalance;
    public:
    void accept(){
        cout<<"Enter your account holder name: ";
        cin>>name;
        cout<<"Enter your Account number: ";
        cin>>accno;
        balance = 1000;   //minimum balance
        
    }
    void deposit(){
        cout<<"Enter amount to be deposited: ";
        cin>>amount;
        newbalance=balance + amount;
        cout<<"New balance: "<<newbalance<<endl;
    }
    void withdraw(){
        cout<<"Enter withdrawal amount: ";
        cin>>amount;
        newbalance = balance -amount;
        try{
            if(amount>=balance)
            {
                throw "Exception caught,cannot withdraw";
            }
            else{
                
                cout<<"Withdrawal successful! New balance: "<<newbalance<<endl;
            }
        }catch(int amount)
        {
            cout<<"Amount should not be grater than balance";
        }
        
    }

};
int main(){
    Bank b;
    int choice;

    do{
    cout<<"1.Accept\n2.Deposit\n3.Withdraw\nMinimum balance is Rs.1000\n";
    cout<<"Enter your choice";
    cin>>choice;
    switch (choice)
    {
    case 1:
    b.accept();
        break;
    case 2:
    b.deposit();    
    case 3:
    b.withdraw();
    break;    
    default:
    cout<<"Invalid Choice!";
        break;
    }
}while(choice!=3);
}
