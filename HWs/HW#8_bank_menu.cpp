//
//  main.cpp
//  11_04 HW#8
/*
 Author: Joshua McDonald
 Compiler: GNU GCC
 Date: 11/04/2020

 Purpose of program: The purpose of this program is to create a series of looping menus for
 the user to input data related to bank balance and check quantity inputs to that balance

*/

#include <iostream>
#include <iomanip>

using namespace std;

// prototype declarations
double getBalance();
int getNumChecks();
double calcCheckFee(int, double);
double calcMonthlyFee(double);

double getBalance() // function loops for balance amount from user 6 times then errors out if no valid input
{
    // temp var for assignment and return
    double balanceAmount;

    for (int balanceLoopStatement = 0; balanceLoopStatement == 0; balanceLoopStatement++) // initial for-loop for prelim prompt that fails self out after 1 run
    {
        cout << "Enter the account balance: ";
        cin >> balanceAmount;
        cout << "Balance entered is " << balanceAmount << resetiosflags(ios::showbase) << endl;
        if (balanceAmount >= -100.00) // returns balanceAmount ending this function if the users first input is correct
        {
            return balanceAmount;
        }
    }

    for (int balanceLoop = 0; balanceLoop <= 5; balanceLoop++) // primary failure attempt for-loop that fails out after 6th attempt
    {
        if (balanceLoop == 5)
        {
            cout << "Too many unsuccessful attempts, exiting" << endl;
            balanceLoop = 6;
            exit (EXIT_FAILURE);
        }

        cout << "Balance must be at least -$100, please reenter: ";
        cin >> balanceAmount;
        cout << "Balance entered is " << balanceAmount << endl;
        if (balanceAmount >= -100.00)
        {
            balanceLoop = 10;
        }
    } // end case input is valid

    return balanceAmount;
}

int getNumChecks() // function loops for check amounts from user 6 times then errors out if no valid input
{
    // temp var for assignment and return
    int checkAmount;

    for (int checksLoopStatement = 0; checksLoopStatement == 0; checksLoopStatement++) // initial for-loop for prelim prompt that fails self out after 1 run
    {
        cout << "Enter the number of checks (min 50, max 500): ";
        cin >> checkAmount;
        cout << "Number of checks entered is " << checkAmount << endl;
        if (checkAmount >= 50 && checkAmount <= 500) // returns checkAmount ending this function if the users first input is correct
        {
            return checkAmount;
        }
    }

    for (int checksLoop = 0; checksLoop <= 5; checksLoop++) // primary failure attempt for-loop that fails out after 6th attempt
    {
        if (checksLoop == 5)
        {
            cout << "Too many unsuccessful attempts, exiting" << endl;
            checksLoop = 6;
            exit (EXIT_FAILURE);
        }

        cout << "We do not process less than 50 checks or more than 500 checks, please reenter: ";
        cin >> checkAmount;
        cout << "Number of checks entered is " << checkAmount << endl;
        if (checkAmount >= 50 && checkAmount <= 500)
        {
            checksLoop = 10;
        }
    } // end case input is valid

    return checkAmount;
}

double calcCheckFee(int checkAmount, double balanceAmount) // function calculates check fee for main function
{
    double checkFee; // temporary double for return to main
    int roundedChecks;

    if (checkAmount == 50) // special case assignment
    {
        roundedChecks = 1;
    }
    else // default case assignment
    {
        roundedChecks = ((checkAmount - 1) / 50) + 1; // calculates necessary rounding of checks
    } // end case input is valid

    // logic chain to determine which check fee should be applied
    if (balanceAmount >= -100.00 && balanceAmount < 0.00)
    {
        checkFee = static_cast<double>(roundedChecks) * 6.00;
    }
    if (balanceAmount >= 0.00 && balanceAmount < 100.00)
    {
        checkFee = static_cast<double>(roundedChecks) * 4.00;
    }
    if (balanceAmount >= 100.00 && balanceAmount < 1000.00)
    {
        checkFee = static_cast<double>(roundedChecks) * 2.50;
    }
    if (balanceAmount >= 1000.00 && balanceAmount < 5000.00)
    {
        checkFee = static_cast<double>(roundedChecks) * 1.10;
    }
    if (balanceAmount >= 5000)
    {
        checkFee = 0.00;
    }

    return checkFee;
}

double calcMonthlyFee(double balanceAmount) // function calculates monthly fee for main function
{
    double monthlyFee; // temporary double for return to main

    // logic chain to determine which monthly fee should be applied
    if (balanceAmount >= -100.00 && balanceAmount < 0.00)
    {
        monthlyFee = 20.00;
    }
    if (balanceAmount >= 0.00 && balanceAmount < 100.00)
    {
        monthlyFee = 10.00;
    }
    if (balanceAmount >= 100.00 && balanceAmount < 1000.00)
    {
        monthlyFee = 5.00;
    }
    if (balanceAmount >= 1000.00 && balanceAmount < 5000.00)
    {
        monthlyFee = 2.00;
    }
    if (balanceAmount >= 5000)
    {
        monthlyFee = 0.00;
    }

    return monthlyFee;
}

int main()
{
    int loop = 0, // loop integer for this function
    // variables for declaration to send to called functions bellow
        choice,
        checkAmount;
    double balanceAmount,
           checkFee,
           monthlyFee,
           totalFee;

    while (loop == 0) // begins menu while loop
    {
        cout << "Menu" << endl;
        cout << "1 -> Calculate fee, 2 -> Quit" << endl;
        cin >> choice;

        if (choice == 1)
        {
            cout << fixed << setprecision(2);
            balanceAmount = getBalance(); // reassigns balanceAmount for future call and prompts user through called function
            checkAmount = getNumChecks(); // reassigns checkAmount for future call and prompts user through called function

            checkFee = calcCheckFee(checkAmount, balanceAmount); // reassigns checkFee for menu output
            monthlyFee = calcMonthlyFee(balanceAmount); // reassigns monthlyFee for menu output

            totalFee = checkFee + monthlyFee; // calculates total fee through values from previous calls

            // display outputs of menu to user
            cout << "The check fee is $" << checkFee << endl;
            cout << "The monthly fee is $" << monthlyFee << endl;
            cout << "The total fee is $" << totalFee << endl;
        }
        else if (choice == 2) // ends menu while loop if menu choice 2 is inputed
        {
            loop = 1;
        }
    } // end case input is valid

    if (loop == 1) // end of loop message
    {
        cout << "Exiting" << endl;
    }

    return 0;
}
