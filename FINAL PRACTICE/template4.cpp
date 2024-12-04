#include <iostream>
using namespace std;

// Template function for swapping values
template <class T>
void swapValues(T &a, T &b) {
    T temp = a;
    a = b;
    b = temp;
}

int main() {
    // Swapping integers
    int a, b;
    cout << "Enter the value of a and b: ";
    cin >> a >> b;
    swapValues(a, b);
    cout << "The swapped values of a and b are: " << a << " " << b << endl;

    // Swapping floats
    float c, d;
    cout << "Enter the value of c and d: ";
    cin >> c >> d;
    swapValues(c, d);
    cout << "The swapped values of c and d are: " << c << " " << d << endl;

    // Swapping doubles
    double e, f;
    cout << "Enter the value of e and f: ";
    cin >> e >> f;
    swapValues(e, f);
    cout << "The swapped values of e and f are: " << e << " " << f << endl;

    // Swapping characters
    char g, h;
    cout << "Enter the value of g and h: ";
    cin >> g >> h;
    swapValues(g, h);
    cout << "The swapped values of g and h are: " << g << " " << h << endl;

    return 0;
}
