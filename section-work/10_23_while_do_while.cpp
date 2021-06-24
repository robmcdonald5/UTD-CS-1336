// 10_23_while_do_while

/*
While(expr) is the first type of loop
It's a pretest loop, because (expr) is tested before
any execution of the loop. If expr is true, the loop is
executed. If it's false, the loop is exited
The loop may never be executed

Can use the while loop for input validation

do-while is the second type of loop
It's a post-test loop, because the loop is executed once
before the expr is tested. If the expr is true, the loop is
executed. If it's false, the loop is exited.

Example of use: menu

Don't forget the semi-colon after (expr)
*/

#include <iostream>

using namespace std;

int main()
{
    int numEmployees;
    int numIterations = 0;
    const int MAX_REATTEMPTS = 3;
    int emplCount;
    double hours, rate, salary;
    int choice;

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

    // do-while
    do
    {
        cout << endl << "Make your choice: 1->Chicken, 2->Beef, 3->Vegan, 4->Quit: ";
        cin >> choice;
        cout << "Your choice is " << choice << endl;
    }while(choice != 4); // Don't forget semi-colon

    return 0;
}
