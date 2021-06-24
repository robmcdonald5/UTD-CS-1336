// 9_30_true_false

/*
True and false are represented as 1 and 0 resp.

Zero and non-zero evaluate to false and true resp.

Do not confuse = with ==
When if (x = num) is executed
1) perform the assignment
2) evaluate the true/false value of (x = num)
The value is num
It is true if num is non-zero, false if num is zero
If you use = for comparison, you will have a logic error
But you may be loved by all the other employees!
*/



#include <iostream>

using namespace std;

int main()
{
    int x = 5,
        y = 10,
        jobGrade;
    bool result;

    // True and false are represented as 1 and 0 resp.
    result = x <= y;
    cout << "Value of result is " << result << endl;
    cout << "Value of (x > 6) is " << (x > 6) << endl;

    // Zero and non-zero evaluate to false and true resp.
    cout << endl;
    result = true;
    cout << "Value of result is " << result << endl;

    result = false;
    cout << "Value of result is " << result << endl;

    result = 3.1416;
    cout << "Value of result is " << result << endl;

    cout << endl;
    if (3.1416)
        cout << "3.1416 is true" << endl;
    else
        cout << "3.1416 is false" << endl;

    result = 0;
    cout << "Value of result is " << result << endl;

    if (0)
        cout << "0 is true" << endl;
    else
        cout << "0 is false" << endl;

    // Do not confuse = with ==
    cout << "Enter your job grade: ";
    cin >> jobGrade;
    cout << "Job grade entered is " << jobGrade << endl;

    if (jobGrade == 10)
        cout << "Your job grade is " << jobGrade <<
             ", you get a bonus" << endl;
    else
        cout << "Your job grade is " << jobGrade <<
             ", you don't get a bonus" << endl;

    // Now with one =
    if (jobGrade = 10)
        cout << "Your job grade is " << jobGrade <<
             ", you get a bonus" << endl;
    else
        cout << "Your job grade is " << jobGrade <<
             ", you don't get a bonus" << endl;

    return 0;
}
