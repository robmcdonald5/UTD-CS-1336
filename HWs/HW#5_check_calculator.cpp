//
//  main.cpp
//  10_07 HW#5
/*
 Author: Joshua McDonald
 Compiler: GNU GCC
 Date: 9/29/2020

 Purpose of program: This program is designed to prompt user for their balance
 and the number of checks. After user inputs are made within an acceptable range
 the program outputs the fees associated with that balance and check quantity.
*/

#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    // declared all necessary variables
    double balance,
           checkFee,
           monthlyFee,
           totalFee;
    const double FEE_1 = 6.00,
                 FEE_2 = 4.00,
                 FEE_3 = 2.50,
                 FEE_4 = 1.10,
                 FEE_5 = 0.00,
                 FEE_1M = 20.00,
                 FEE_2M = 10.00,
                 FEE_3M = 5.00,
                 FEE_4M = 2.00,
                 FEE_5M = 0.00;
    int checkQuant,
        checkQuantChange;

    // prompt for user input of balance quantity
    cout << "Enter the account balance: ";
    cin >> balance;
    cout << "Balance entered is " << balance << endl;

    // begins logic clause to determine fee amounts
    if (balance >= -100.00) // verifies enough balance
    {
        // prompt for user input of check quantity
        cout << "Enter the number of checks (min 50, max 500): ";
        cin  >> checkQuant;
        cout << "Number of checks entered is " << checkQuant << endl;

        //cout << "AMOUNT IS MORE THAN -100.00. ";//DEBUG
        if (checkQuant >= 50 && checkQuant <= 500) // verifies enough checks
        {
            checkQuantChange = ((checkQuant - 1) / 50) + 1; // rounds check amount by 50

            if (balance >= -100.00 && balance < 0.00) // $6.00 fpc & $20.00 monthly fee
            {
                //cout << "AMOUNT IS BETWEEN -100.00 and 0.00. " << endl;//DEBUG
                // calculates fee based on current balance
                checkFee = static_cast<double>(checkQuantChange) * FEE_1;
                monthlyFee = FEE_1M;
                totalFee = checkFee + monthlyFee;
            }
            else if (balance >= 0.00 && balance < 100.00) // $4.00 fpc & $10.00 monthly fee
            {
                //cout << "AMOUNT IS BETWEEN 0.00 and 100.00. " << endl;//DEBUG
                // calculates fee based on current balance
                checkFee = static_cast<double>(checkQuantChange) * FEE_2;
                monthlyFee = FEE_2M;
                totalFee = checkFee + monthlyFee;
            }
            else if (balance >= 100.00 && balance < 1000.00) // $2.50 fpc & $5.00 monthly fee
            {
                //cout << "AMOUNT IS BETWEEN 100.00 and 1000.00. " << endl;//DEBUG
                // calculates fee based on current balance
                checkFee = static_cast<double>(checkQuantChange) * FEE_3;
                monthlyFee = FEE_3M;
                totalFee = checkFee + monthlyFee;
            }
            else if (balance >= 1000.00 && balance < 5000.00) // $1.10 fpc & $2.00 monthly fee
            {
                //cout << "AMOUNT IS BETWEEN 1000.00 and 5000.00. " << endl;//DEBUG
                // calculates fee based on current balance
                checkFee = static_cast<double>(checkQuantChange) * FEE_4;
                monthlyFee = FEE_4M;
                totalFee = checkFee + monthlyFee;
            }
            else // no fees
            {
                // calculates fee based on current balance
                checkFee = FEE_5;
                monthlyFee = FEE_5M;
                totalFee = checkFee + monthlyFee;
            }
        }
        else // too little or too many checks
        {
            cout << "We do not process less than 50 checks or more than 500 checks." << endl;
        }
    }
    else // too small of a balance
    {
        cout << "Balance must be at least -$100." << endl;
    }

    if (balance >= -100.00 && checkQuant >= 50 && checkQuant <= 500) // verifies both correct quantity for balance and checks before outputting results
    {
        // fee results after calculations
        cout << fixed << setprecision(2); // sets precision parameters for final results
        cout << "The check fee is $" << static_cast<double>(checkFee) << endl;
        cout << "The monthly fee is $" << static_cast<double>(monthlyFee) << endl;
        cout << "The total fee is $" << static_cast<double>(totalFee) << endl;
    }

    return 0;
}
