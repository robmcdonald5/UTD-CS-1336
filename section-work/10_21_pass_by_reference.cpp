// 10_21_pass_by_reference

/*
With pass by reference, the called function is passed by the addresses
of the arguments, and accesses directly the arguments through
the addresses

With pass by reference, the called function is able to pass back
more than 1 value -> Overcome the limitation of the return statement

Argument passed by reference must have a memory address, i.e.
it must be a variable

A reference variable is a variable passed by reference

Use ref variables when appropriate. Less safe than pass by value
*/

#include <iostream>
#include <cmath>

using namespace std;

void resetVar(int);
void resetVarByRef(int &);
void convertCoordinates(double, double,
                        double &, double &);

int main()
{
    int myInt = 100;
    double myAngle,
           myLength,
           xCoord,
           yCoord;

    resetVar(myInt);
    cout << "After resetVar, myInt = " << myInt << endl;

    resetVarByRef(myInt);
    cout << "After resetVarByRef, myInt = " << myInt << endl;

    //Example of using ref variables to pass back more than 1 value
    cout << endl << "Enter the angle and the length: ";
    cin >> myAngle >> myLength;
    cout << "Angle and length are " << myAngle << ", "
         << myLength << endl;
    convertCoordinates(myAngle, myLength, xCoord, yCoord);
    cout << "x and y coordinates are " << xCoord << ", "
         << yCoord << endl;

    return 0;
}

void resetVar(int num) // Pass by value
{
    cout << "Inside resetVar, num = " << num << endl;
    num = 0;
}

void resetVarByRef(int & num) // Pass by reference
// num is an alias for myInt
{
    cout << "Inside resetVarByRef, num = " << num << endl;
    num = 0;
}

void convertCoordinates(double angle, double length,
                        double & x, double & y)
// x and y are aliases of xCoord and yCoord resp.
{
    x = length * cos(angle);
    y = length * sin(angle);
}
