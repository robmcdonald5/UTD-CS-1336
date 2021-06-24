// 11_4_sentinel_nested_loop

/*
A sentinel is a special value to indicate end of data
The special value must be different from a valid value
It's useful when the user doesn't know upfront how many
times a loop will iterate

A nested loop is a loop within a loop
Any combination is possible: for within a for, while within
a while, for within a while, etc.
*/

#include <iostream>

using namespace std;

int main()
{
    const int MY_SENTINEL = -1;
    int hours;
    double rate;
    const double MIN_RATE = 10, MAX_RATE = 500;

    cout << "Enter the number of hours, " << MY_SENTINEL
         << " when done: ";
    cin >> hours;

    while(hours != MY_SENTINEL)
    {
        cout << "Enter the rate: ";
        cin >> rate;
        while (rate < MIN_RATE || rate > MAX_RATE)
        {
            cout << "Invalid value, please reenter: ";
            cin >> rate;
        }
        cout << "Salary is " << hours * rate << endl;

        cout << "Enter the number of hours, " << MY_SENTINEL
             << " when done: ";
        cin >> hours;
    }

    return 0;
}
