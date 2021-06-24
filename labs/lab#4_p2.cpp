/* PART #2 */
#include <iostream>
using namespace std;

int main()
{
    // declaration of all variables
    long long int days,
                  hours,
                  minutes,
                  seconds;

    // prompts user for input of seconds
    cout << "Enter seconds" << endl;
    cin >> seconds;
    cout << "Total seconds: " << seconds << endl;

    // starts logic chain
    if (seconds <= 0) { // makes sure input value is over 0
        cout << "\nTotal seconds must be greater than zero" << endl;
    }

    else { //

        // calculates total and remainders of seconds into days, hours, minutes, seconds
        days = seconds / 86400; // 86400 seconds in a day
        seconds = seconds % 86400;
        hours = seconds / 3600; // 3600 seconds in an hour
        seconds = seconds % 3600;
        minutes = seconds / 60; // 60 seconds in a minute
        seconds = seconds % 60;

        cout << '\n';
        if (days != 0) {
            cout << days << " day(s)" << endl;
        }
        if (hours != 0) {
            cout << hours << " hour(s)" << endl;
        }
        if (minutes != 0) {
            cout << minutes << " minute(s)" << endl;
        }
        if (seconds != 0) {
            cout << seconds << " second(s)" << endl;
        }
    }
    return 0;
}
