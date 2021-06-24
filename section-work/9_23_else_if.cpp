// 9_23_else_if

#include <iostream>
#include <string>

using namespace std;

int main()
{
    const double A_SCORE = 3.7,
                 B_SCORE = 3.2,
                 C_SCORE = 2.7,
                 D_SCORE = 2.2;
    double gpa;
    char grade;
    string netID;

    cout << "Enter the GPA: ";
    cin >> gpa;
    cout << "Enter the netID: ";
    cin >> netID;

    // nested if
    if (gpa >= A_SCORE)
        grade = 'A';
    else // grade is less than A
    {
        if (gpa >= B_SCORE) // 1st level of nesting
            grade = 'B'; // grade is less than B
        else
        {
            if (gpa >= C_SCORE) // 2nd level of nesting
                grade = 'C';
            else // grade is less than C
            {
                if (gpa >= D_SCORE) // 3rd level of nesting
                    grade = 'D';
                else // grade is less than D
                    grade = 'F';
            } // end of grade is less than C
        } // end of grade is less than B
    } // end of grade is less than A

    // if/else if
    if (gpa >= A_SCORE)
        grade = 'A';
    else if (gpa >= B_SCORE)
        grade = 'B';
    else if (gpa >= C_SCORE)
        grade = 'C';
    else if (gpa >= D_SCORE)
        grade = 'D';
    else // grade is less than D
        grade = 'F';

    cout << "Student's netID is " << netID << ", GPA is "
    << gpa << ", grade is " << grade << endl;

    return 0;
}
