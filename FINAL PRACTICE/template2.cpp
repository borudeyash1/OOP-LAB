#include <iostream>
using namespace std;

// Class template for selection sort
template <typename T>
class SelectionSort {
    T* arr;     // Pointer to the array
    int n;      // Size of the array

public:
    // Constructor to initialize the array and its size
    SelectionSort(T arr[], int n) {
        this->arr = arr;
        this->n = n;
    }

    // Method to perform selection sort
    void sort() {
        for (int i = 0; i < n - 1; i++) {
            int minIndex = i; // Assume the current index is the minimum
            for (int j = i + 1; j < n; j++) {
                if (arr[j] < arr[minIndex]) {
                    minIndex = j; // Update the minimum index if a smaller element is found
                }
            }
            // Swap the elements
            T temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
        }
    }

    // Method to display the array
    void display() {
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

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

    // Sorting and displaying the integer array
    SelectionSort<int> intSorter(intArr, n);
    cout << "Original integer array: ";
    intSorter.display();
    intSorter.sort();
    cout << "Sorted integer array: ";
    intSorter.display();

    // Input and processing for float array
    cout << "Enter the number of elements for the float array: ";
    cin >> n;
    float floatArr[n];
    cout << "Enter the " << n << " elements for the float array: ";
    for (int i = 0; i < n; i++) {
        cin >> floatArr[i];
    }

    // Sorting and displaying the float array
    SelectionSort<float> floatSorter(floatArr, n);
    cout << "Original float array: ";
    floatSorter.display();
    floatSorter.sort();
    cout << "Sorted float array: ";
    floatSorter.display();

    return 0;
}
