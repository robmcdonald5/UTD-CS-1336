// 9_2_integer_division

#include <iostream>

using namespace std;

int main()
{
    int minutes;

    // Integer division
    cout << "13/5 = " << 13/5 << endl;
    cout << "13.0/5 = " << 13.0/5 << endl;
    cout << "13/5.0 = " << 13/5.0 << endl;
    cout << "13.0/5.0 = " << 13.0/5.0 << endl;

    int myInt1 = 92,
        myInt2 = 7;
    cout << "MyInt1/myInt2 = " << myInt1/myInt2 << endl;

    double myDouble1 = 92.0,
            myDouble2 = 7.0;
    cout << "myDouble1/myDouble2 = " << myDouble1/myDouble2 << endl;

    // Modulus
    cout << "13 % 5 = " << 13 % 5 << endl;

    // cout << "13.0 % 5 = " << 13.0 % 5 << endl; // This won't compile

    // Example use
    cout << "\nEnter number of minutes: ";
    cin >> minutes;
    cout << minutes << " minutes = " << minutes / 60
         << " hours, " << minutes % 60 << " minutes";

    return 0;
}
