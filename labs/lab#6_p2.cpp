//
//  lesson6part2.cpp
//  10_25 lab#6
/*
 Author: Joshua McDonald
 Compiler: GNU GCC
 Date: 10/24/2020

 Purpose of program: This program is meant to get inputs from a user related to several banking
 equations and then passes back calculated info if no false inputs are detected
*/

#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

// prototype functions for declaration
double presentValue(double, double, int);
double futureValue(int &, double &);
double annualInterestRate(int &, double &);
int numberOfYears(int &, int &);
void displayResults(int);

double presentValue(double futureValue, double interestRate, int numberYears) // function for calculating present value
{
    double presentValue = futureValue / (pow(1 + interestRate, numberYears)); // P = F/((1+r)^n) present value equation

    return presentValue;
}

double futureValue(int & tickerOut, double & inputFutureVal) // function for getting future value from user and passing back references to display function
{
    cout << "Enter future value" << endl;
    cin >> inputFutureVal;

    if (inputFutureVal <= 0) // verifies no false input from user
    {
        cout << "The future value must be greater than zero" << endl;
        tickerOut = 1;

    }

    return inputFutureVal;
}

double annualInterestRate(int & tickerOut, double & inputInterestRate) // function for getting annual interest rate from user and passing back references to display function
{
    cout << "Enter annual interest rate" << endl;
    cin >> inputInterestRate;

    if (inputInterestRate <= 0) // verifies no false input from user
    {
        cout << "The annual interest rate must be greater than zero" << endl;
        tickerOut = 1;
    }

    return inputInterestRate;
}

int numberOfYears(int & tickerOut, int & inputYears) // function for getting number of years from user and passing back references to display function
{
    cout << "Enter number of years" << endl;
    cin >> inputYears;

    if (inputYears <= 0) // verifies no false input from user
    {
        cout << "The number of years must be greater than zero" << endl;
        tickerOut = 1;
    }

    return inputYears;
}
void displayResults(int tickerOut) // function for calling all necessary secondary math functions and displaying end results
{
    // declaring all variables for pass back in future functions
    double numF,
           numI;
    int numY;

    futureValue(tickerOut, numF); // calls futureValue function by default

    if (tickerOut == 0) // calls annualInterestRate if false input has not activated the ticker
    {
        annualInterestRate(tickerOut, numI);
    }
    if (tickerOut == 0) // calls numberOfYears if false input has not activated the ticker
    {
        numberOfYears(tickerOut, numY);
    }
    if (tickerOut == 0) // displays final results if false input has not activated the ticker
    {
        numI = numI * 0.01;
        cout << fixed << setprecision(2) << "Present value: $" << presentValue(numF, numI, numY) << endl;
        numI = numI * 100.0;
        cout << fixed << setprecision(2) << "Future value: $" << numF << endl;
        cout << fixed << setprecision(3) << "Annual interest rate: " << numI << "%" << endl;
        cout << "Years: " << numY << endl;
    }
}

int main() // main function
{
    int ticker = 0; // declaration of ticker for pass by reference in future functions
    displayResults(ticker);

    return 0;
}
