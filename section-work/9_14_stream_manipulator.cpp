// 9_14_stream_manipulator

#include <iostream>
#include <string>
#include <iomanip> // Required for stream manipulators

using namespace std;

int main()
{
    // setw(x)

    //student 1
    double s11 = 90.0,
           s12 = 85.75,
           s13 = 95.1;
    //student 2
    double s21 = 79.123,
           s22 = 88,
           s23 = 99;

    string name1 = "Chewbacca",
           name2 = "R2D2";

    cout << "Student's name: " << name1 << ' ' << s11 << ' '
         << s12 << ' ' << s13 << endl;

    cout << "Student's name: " << name2 << ' ' << s21 << ' '
         << s22 << ' ' << s23 << endl;

    cout << "\nWith setw()" << endl;
    cout << "Student's name: " << setw(10) << name1 << setw(8) << s11 << setw(8)
         << s12 << setw(8) << s13 << endl;

    cout << "Student's name: " << setw(10) << name2 << setw(8) << s21 << setw(8)
         << s22 << setw(8) << s23 << endl;

    // showpoint
    cout << "\nShowpoint\n";
    cout << "s11 w/o showpoint is " << s11 << endl;
    cout << showpoint << "s11 with showpoint is " << s11 << endl;

    // reset showpoint
    cout << resetiosflags(ios::showpoint); // turn off the "showpoint" switch
    cout << "s11 after resetflags(showpoint) is "
         << s11 << endl;

    // setprecision(x)
    double PI = 3.14159;
    cout << "\nPI w/o setprecision: " << PI << endl;
    cout << setprecision(6) << "PI w setprecision(6): "
         << PI << endl;
    cout << setprecision(4) << "PI w setprecision(4): "
         << PI << endl;

    // setprecision(x) with fixed
    cout << fixed;
    cout << setprecision(6) << "PI w setprecision(6) with fixed: "
         << PI << endl;
    cout << setprecision(4) << "PI w setprecision(4) with fixed: "
         << PI << endl;

    // reset fixed
    cout << resetiosflags(ios::fixed);
    cout << "PI after resetflags(fixed) is " << PI << endl;

    //
    cout << "\nTest scores with setw() and setprecision(2) and fixed"
         << endl;
    cout << setprecision(2) << fixed;
    cout << "Student's name: " << setw(10) << name1 << setw(8) << s11 << setw(8)
         << s12 << setw(8) << s13 << endl;

    cout << "Student's name: " << setw(10) << name2 << setw(8) << s21 << setw(8)
         << s22 << setw(8) << s23 << endl;

    // Difference between fixed and showpoint
    double x = 90000000.0;
    cout << endl << resetiosflags(ios::fixed);
    cout << "x is " << x << endl;
    cout << fixed << "x with fixed is " << x << endl;
    cout << resetiosflags(ios::fixed);
    cout << showpoint << "x with showpoint is " << x << endl;

    return 0;
}
