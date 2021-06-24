// 11_02_for_loop

/*
Syntax of for loop is for(initialization; test; update)
Start by executing initialization, then test. If test is true,
execute the loop, then do the update and test again. As long as
test is true, stay in the loop. When test becomes false, exit the
loop.

for-loop is a pretest loop, because test is evaluated before
loop execution

May have multiple statements in the initialization, separated
by commas
May have multiple statements in the update, separated
by commas

Any or all of the initialization, test and update may be omitted
If the test part is omitted, it evaluates to true

May define a new variable(s) in the initialization. The scope of the
variable(s) is the for loop
Commonly used when the number of iterations is known
In most cases, the for loop and while loop are equivalent options
to implement the same logic

*/

#include <iostream>

using namespace std;

int main()
{
    int numEmployees;
    int numIterations = 0;
    const int MAX_REATTEMPTS = 3;
    int emplCount;
    double hours, rate, salary, totalWages;

    // Use while loop for input validation
    cout << "Enter number of employees: ";
    cin >> numEmployees;
    cout << endl;

    while(numEmployees <= 0 && numIterations < MAX_REATTEMPTS)
    {
        cout << "Enter number of employees: ";
        cin >> numEmployees;
        cout << endl;
        numIterations++;
    }

    if (numEmployees <= 0)
    {
        cout << "Too many attempts, give up" << endl;
    }
    else
    {
        emplCount = 0;
        while (emplCount < numEmployees)
        {
            cout << "Enter hours and rate: ";
            cin >> hours >> rate;
            salary = hours * rate;
            cout << "Salary is " << salary << endl;
            emplCount++;
        }
    } // end case input is valid

    cout << endl << "Using for loop" << endl;
    totalWages = 0;
    for (emplCount = 0; emplCount < numEmployees; emplCount++)
    {
            cout << "Enter hours and rate: ";
            cin >> hours >> rate;
            salary = hours * rate;
            cout << "Salary is " << salary << endl;
            totalWages += salary;
    }
    cout << "Total wages is " << totalWages << endl;

    // Can omit any or all of the initialization, test and update
    /*for (; ; )
    {
        cout << "Ha" << endl;
    } */

    return 0;
}
