/*create cpp class name television ,that has model no,screen size(in inches) and prize.Member functionn include oveloaded insersion and
extraction operator.If more than four digits are entered for the model number,if the screen size is identified smaller than 12 or grater than 70 inches,or if the price is negate
or over 5000 Dollar ,then throw and interger.Write a main funcition that instant create a television object and
allow user ti enter the data .If an exception is called,replace all data members with 0 value.*/
#include <iostream>
using namespace std;

class television
{
    int mn, pz, sz;

public:
    friend ostream &operator<<(ostream &vout, television &t);
    friend istream &operator>>(istream &vin, television &t);
};

istream &operator>>(istream &vin, television &t)
{
    cout << "-----------TELEVISION SHOP------------\n";
    cout << "Enter the model number, size, price: ";
    vin >> t.mn >> t.sz >> t.pz;

    try
    {
        if (t.mn > 9999 || (t.sz != 12 && t.sz != 14 && t.sz != 15 && t.sz != 17 && t.sz != 19 && t.sz != 22 && t.sz != 24 && t.sz != 28 && t.sz != 32 && t.sz != 40 && t.sz != 43 && t.sz != 48 && t.sz != 50 && t.sz != 55 && t.sz != 60 && t.sz != 65 && t.sz != 70) || t.pz < 0 || t.pz > 5000)
        {
            throw 1;
        }
    }
    catch (int e)
    {
        cout << "Exception caught: Invalid input values" << endl;
        t.sz = 0;
        t.pz = 0;
        t.mn = 0;
    }
    return vin;
}

ostream &operator<<(ostream &vout, television &t)
{
    vout << "Model number: " << t.mn << endl;

    vout << "Size: ";
    if (t.sz == 12)
        vout << "12 inches" << endl;
    else if (t.sz == 14)
        vout << "14 inches" << endl;
    else if (t.sz == 15)
        vout << "15 inches" << endl;
    else if (t.sz == 17)
        vout << "17 inches" << endl;
    else if (t.sz == 19)
        vout << "19 inches" << endl;
    else if (t.sz == 22)
        vout << "22 inches" << endl;
    else if (t.sz == 24)
        vout << "24 inches" << endl;
    else if (t.sz == 28)
        vout << "28 inches" << endl;
    else if (t.sz == 32)
        vout << "32 inches" << endl;
    else if (t.sz == 40)
        vout << "40 inches" << endl;
    else if (t.sz == 43)
        vout << "43 inches" << endl;
    else if (t.sz == 48)
        vout << "48 inches" << endl;
    else if (t.sz == 50)
        vout << "50 inches" << endl;
    else if (t.sz == 55)
        vout << "55 inches" << endl;
    else if (t.sz == 60)
        vout << "60 inches" << endl;
    else if (t.sz == 65)
        vout << "65 inches" << endl;
    else if (t.sz == 70)
        vout << "70 inches" << endl;
    else
        vout << "Invalid size" << endl;

    vout << "Price: $" << t.pz << endl;
    return vout;
}

int main()
{
    television tv;
    cin >> tv;
    cout << tv;
    return 0;
}