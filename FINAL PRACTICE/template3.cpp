#include <iostream>
using namespace std;

template <typename T>
class BubbleSort {
    T *arr; // Pointer to array
    int n;  // Number of elements

public:
    // Constructor to initialize array and size
    BubbleSort(T array[], int size) {
        arr = array;
        n = size;
    }

    // Function to perform bubble sort
    void sort() {
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < n - i - 1; j++) {
                if (arr[j] > arr[j + 1]) {
                    T temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            }
        }
    }

    // Function to display the array
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

    // Create a BubbleSort object for integer array
    BubbleSort<int> intSorter(intArr, n);

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

    // Create a BubbleSort object for float array
    BubbleSort<float> floatSorter(floatArr, n);

    cout << "Original float array: ";
    floatSorter.display();

    floatSorter.sort();
    cout << "Sorted float array: ";
    floatSorter.display();

    return 0;
}
