//to create a function template for selction sort that can sort array of different type(integer,float ,character).It should take inputs,sorts and outputs integer array nad a float array.
#include<iostream>
#define MAX 50
using namespace std;
int n,i,j;
template<class T>
void selsort(T a[MAX],int n){
    T temp;

    cout<<"Enter the number of elements\n";
    cin>>n;
    cout<<"Enter the"<<n<<" array elemets\n";
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(i=0;i<n;i++){
        for(j=i+1;j<n;j++){
            if(a[i]>a[j]){
            temp = a[i];
            a[i] = a[j];
            a[j] =  temp;
            }
        }
    }
    cout<<"Sorted array is: ";
    for(int i=0;i<n;i++)
    {
        cout << " " <<a[i];
    }
    
}

int main(){
    int n;
    int a[10];
    float b[10];
    char c[10];

    

    while(true){
        cout<<"---Template selection sort-----\n";
        cout<<"1.Selection sorting of  integer array\n";
        cout<<"2.Selection sorting of float array\n";
        cout<<"3.Selection sorting of character array\n";
        cout<<"4.Exit\n";
        int ch;
        cout<<"Enter a choice\n";
        cin>>ch;

        switch(ch){
            case 1:
            selsort(a,n);
            break;
            case 2:
            selsort(b,n);
            break;
            case 3:
            selsort(c,n);
            break;
            case 4:
            cout<<"EXITING....."; 
            break;
        }
    }
}

