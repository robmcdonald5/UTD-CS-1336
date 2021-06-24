// 10_9_pass_by_value

/*
Data sent to a function are arguments
Data received by a function are stored in parameters

Pass by value: the calling function passes the data to the
called function and the called function stores the data
parameters

C++ by default does pass by value

With pass by value, the called function only accesses a copy
of the data and any change made in the called function is made
to the parameter, the original data (argument) is not affected

The scope of a parameter is the function definition

When the data types of the argument and parameter don't match
the compiler automatically promotes/demotes the argument
to match the parameter
*/


#include <iostream>

using namespace std;

double tripleValue(double);
int mySquare(int);

int main()
{
    double x, res;

    cout << "Input x: ";
    cin >> x;

    cout << "Before I call the function, x = " << x << endl;
    res = tripleValue(x); // x is an argument
    cout << "Value returned by tripleValue is " << res << endl;
    cout << "After I returned from the function, x = "
         << x << endl;

    // Arguments are promoted/demoted to match the parameter type
    cout << "Square of " << x << " is " << mySquare(x) << endl;

    return 0;
}

double tripleValue(double x)
{
    x = 3 * x; // x is a parameter
    cout << "Inside tripleValue, x = " << x << endl;

    return x;
}

int mySquare(int num) // Scope of num begins here
{
    return num * num;
} // Scope of num ends here
