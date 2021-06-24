// 10_26_local

/*
1. Scope:
Local variables are defined inside a function
They follow the usual scope rules and therefore
are not accessible outside the function

The other functions may have distinct variables with the
same name

Parameters are essentially local variables defined at the
very beginning of the function (in the parameter list)

2. Lifetime:
When a function is called, its local variables and parameters
are created
When a function ends, its local variables and parameters are
destroyed -> Any value stored in them is lost
One way to save the info is through the return statement

Static local variables are local variables (have local scope),
but a different lifetime: they are not destroyed when the function
ends

Static local variables are initialized to zero by default
Initialization of a static local variable (explicit or by default
is done only the first time the function is called)
*/

#include <iostream>

void addArg(double);
void addArgStatic(double);

using namespace std;

int main()
{
    double res = 1000; // res is a local variable

    cout << "Inside main, res = " << res << endl;

    addArg(10);
    addArg(10);
    addArg(10);

    cout << "Back from addArg, res = " << res << endl;

    cout << endl << "Now call addArgStatic" << endl;
    addArgStatic(10);
    addArgStatic(10);
    addArgStatic(10);

    return 0;
}

void addArg(double x)
{
    double res = 500; // res is a local variable
    cout << "Entered addArg, res = " << res << endl;
    res = res + x;
    cout << "Exiting addArg, res = " << res << endl;
}

void addArgStatic(double x)
{
    static double res = 500; // res is a static local variable
    // This initialization is done only the 1st time the
    // function is called
    cout << "Entered addArgStatic, res = " << res << endl;
    res = res + x;
    cout << "Exiting addArgStatic, res = " << res << endl;
}
