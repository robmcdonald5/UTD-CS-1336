// 8_31_float_bool

/*
Floating point data types hold numbers with a fractional part
e.g. 3.14159
Floating point data types are: float, double, long double
bool is a data type that has two possible values: true or false
True and false are represented in memory as 1 and 0 respectively
*/


#include <iostream>

using namespace std;

int main()
{
    // Floating point data type
    double myDouble;

    myDouble = 3.14159;
    cout << myDouble << endl;

    myDouble = 0.0314159E2; // Equivalent representation of 3.14159
    cout << myDouble << endl;

    // Bool data type
    bool myBool = true;
    cout << "Value of myBool is " << myBool << endl;

    myBool = false;
    cout << "Value of myBool is " << myBool << endl;

    return 0;
}
