#include <iostream>
using namespace std;

// Function template for selection sort
template <typename T>
void selectionSort(T arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        T temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
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
    cout << "Enter the number of elements for the integer array: ";
    cin >> n;
    int intArr[n];
    cout << "Enter the " << n << " elements for the integer array: ";
    for (int i = 0; i < n; i++) {
        cin >> intArr[i];
    }

    cout << "Original integer array: ";
    display(intArr, n);

    selectionSort(intArr, n);
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

    selectionSort(floatArr, n); 
    cout << "Sorted float array: ";
    display(floatArr, n);

    return 0;
}
