#include<iostream>
using namespace std;

int main(){
    // Creating an array 
    char array[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'};

    // Print the number of elements in the array
    cout << "Number of elements: " << sizeof(array) / sizeof(array[0]) << endl;
    //finding the element at 4th position
    cout << "Number of elements: " << array[4] << endl;
    //finding the element at 0th position
    cout << "Number of elements: " << array[0] << endl;
    cout << "elements in array : "; 
    for( int i=0;i<sizeof(array)/sizeof(array[0]);i++){
        cout << array[i] << " ";
    }

    return 0;
}