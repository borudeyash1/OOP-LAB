//to create a function template for selction sort that can sort array of different type(integer,float ,character).It should take inputs,sorts and outputs integer array nad a float array.
#include <iostream>
#define MAX 50
using namespace std;

// Function template for selection sort
template <class T>
void selectionSort(T arr[], int n) {
    // Selection sort algorithm
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i; // Index of the minimum element
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j; // Update index of the minimum element
            }
        }
        // Swap the found minimum element with the first element
        T temp = arr[minIndex];
        arr[minIndex] = arr[i];
        arr[i] = temp;
    }
}

int main() {
    int n;
    int a[MAX]; // Integer array
    float b[MAX]; // Float array
    char c[MAX]; // Character array

    cout << "Enter number of array elements (max " << MAX << "): ";
    cin >> n;

    // Ensure n does not exceed MAX
    if (n > MAX) {
        cout << "Exceeded maximum size." << endl;
        return 1;
    }

    while (true) {
        cout << "---Template Selection Sort-----\n";
        cout << "1. Selection sorting of integer array\n";
        cout << "2. Selection sorting of float array\n";
        cout << "3. Selection sorting of character array\n";
        cout << "4. Exit\n";
        
        int ch;
        cout << "Enter a choice: ";
        cin >> ch;

        switch (ch) {
            case 1:
                cout << "Enter the " << n << " integer array elements:\n";
                for (int i = 0; i < n; i++) {
                    cin >> a[i];
                }
                selectionSort(a, n);
                cout << "Sorted integer array is: ";
                for (int i = 0; i < n; i++) {
                    cout << a[i] << " ";
                }
                cout << endl;
                break;

            case 2:
                cout << "Enter the " << n << " float array elements:\n";
                for (int i = 0; i < n; i++) {
                    cin >> b[i];
                }
                selectionSort(b, n);
                cout << "Sorted float array is: ";
                for (int i = 0; i < n; i++) {
                    cout << b[i] << " ";
                }
                cout << endl;
                break;

            case 3:
                cout << "Enter the " << n << " character array elements:\n";
                for (int i = 0; i < n; i++) {
                    cin >> c[i];
                }
                selectionSort(c, n);
                cout << "Sorted character array is: ";
                for (int i = 0; i < n; i++) {
                    cout << c[i] << " ";
                }
                cout << endl;
                break;

            case 4:
                cout << "EXITING....." << endl;
                return 0;

            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }
}
