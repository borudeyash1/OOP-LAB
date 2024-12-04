/*Write a class template Bubble Sort. Write a program that 
inputs, sorts and outputs an integer array and a float array */
#include<iostream>
using namespace std;
template <typename T>
void bubblesort(T arr[], int n){
    for(int i = 0; i < n - 1; i++){
        for(int j = 0; j < n - i - 1; j++){
            if(arr[j] > arr[j + 1]){
                T temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Function template for displaying array
template <typename T>
void display(T arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int n;

    // Input and processing for integer array
    cout<< "Enter the number of elements for the integer array: ";
    cin >> n;
    int intArr[n];
    cout<< "Enter the " << n << " elements for the integer array: ";
    for (int i = 0; i < n; i++) {
        cin >> intArr[i];
    }

    cout << "Original integer array: ";
    display(intArr, n);

    bubblesort(intArr, n);
    cout << "Sorted integer array: ";
    display(intArr, n);

    // Input and processing for float array
    cout << "Enter the number of elements for the float array: ";
    cin >> n;
    float floatArr[n];
    cout << "Enter the " << n << " elements for the float array: ";
    for (int i = 0; i < n; i++) {
        cin >> floatArr[i];
    }

    cout << "Original float array: ";
    display(floatArr, n);

    bubblesort(floatArr, n); 
    cout << "Sorted float array: ";
    display(floatArr, n);

    return 0;
}
