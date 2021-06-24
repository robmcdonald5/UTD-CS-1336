// 10_19_return

/*
The return statement can be used to exit a function and
return to the calling function

return can be put anywhere in a function, statements that
follow the return will not be executed -> can be used to
prevent abnormal termination of program

To return a value, use "return expr;"
If the function returns nothing (void), you can use "return;"

Ways to use a value returned by a function:
1. cout
2. assign to a variable
3. use in an expression
*/

#include <iostream>

using namespace std;

void div(double, double);
double calcAverage(double, double);

int main()
{
    double num, denom, res;

    cout << "Enter a numerator and a denominator: " << endl;
    cin >> num >> denom;
    div(num, denom);

    // Ways to use a value returned by a function
    // Way #1: use in cout
    cout << "The average is " << calcAverage(num, denom) << endl;

    // Way #2: Assign to a variable and later use the variable
    res = calcAverage(num, denom);
    cout << "Square of the average is " << res * res << endl;

    // Way #3: Use an expression
    cout << "Square of the average is " <<
         calcAverage(num, denom) * calcAverage(num, denom) << endl;

    return 0;
}

void div(double x, double y)
{
    if (y == 0.0)
    {
        cout << "Cannot divide by zero" << endl;
        return; // To prevent division by zero (abornomal
        // termination of program
    }
    cout << "The quotient is " << x / y << endl;
    return; // Optional, since we are at the last
    // }, and the functions returns void
}

double calcAverage(double x, double y)
{
    return (x + y) / 2;
}
