//
//  lesson7part2.cpp
//  11_01 lab#7
/*
 Author: Joshua McDonald
 Compiler: GNU GCC
 Date: 10/26/2020

 Purpose of program: The purpose of this program is to prompt user for banking info regarding an account
 and then display said info with the addition of a calculated future value.
*/

#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

// prototype functions for declaration
double futureValue(double, double, int);
void read(double &, double &, double &, int &);
void display(double, double, int);

double futureValue(double presentValue, double interestRate, int months) // calculates future value with passed back values
{
    double futureValueCalc = presentValue * (pow(1 + interestRate, months)); // calculates future value for pass back

    return futureValueCalc;
}

void read(double & presentValueRead, double & futureValueRead, double & interestRateRead, int & monthsRead) // function for reading user results
{
    cout << "Enter present value" << endl;
    cout << "Enter monthly interest rate" << endl;
    cout << "Enter months" << endl;
    cin >> presentValueRead;
    cin >> interestRateRead;
    cin >> monthsRead;

    if (presentValueRead <= 0.00 || interestRateRead <= 0.000 || monthsRead <= 0)  // checks for invalid input
    {
        cout << fixed << setprecision(2) << presentValueRead << " " << fixed << setprecision(3)
             << interestRateRead << " " << monthsRead << endl;
        cout << "One or more of the above values are not greater than zero" << endl;
        exit (EXIT_FAILURE); // errors out user and ends program
    }
    else // moves forward with program if no illegal values were inputed
    {
        interestRateRead = interestRateRead * 0.01; // reduces percentage rate by a power of 2 for the presentValue function to work correctly
        futureValueRead = futureValue(presentValueRead, interestRateRead, monthsRead); // defines future value through call to futureValue function
    }
}

void display(double futureValueDisplay, double presentValueDisplay, double interestRateDisplay, int monthsDisplay) // function for displaying end results
{
    interestRateDisplay = interestRateDisplay * 100.000; // undoes % reduction of interest rate for final display

    // displays final results to user
    cout << "      " << "Future Value" << "     " << "Present Value" << "  "
         << "Monthly Interest" << "    " << "Months" << endl;
    cout << right << setw(18) << fixed << setprecision(2) << futureValueDisplay << right << setw(18) << presentValueDisplay
         << right << setw(18) << fixed << setprecision(3) << interestRateDisplay << right << setw(10) << monthsDisplay << endl;
}

int main() // main function of the program
{
    // declared all necessary variables for future pass back
    double presentValue,
           futureValue,
           interestRate;
    int months;

    read(presentValue, futureValue, interestRate, months); // calls main read function to get input from the user
    display(futureValue, presentValue, interestRate, months); // calls main display function to output data passed back from the main read function

    return 0;
}
