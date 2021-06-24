//
//  lesson7part1.cpp
//  11_01 lab#7
/*
 Author: Joshua McDonald
 Compiler: GNU GCC
 Date: 10/25/2020

 Purpose of program: The purpose of this program is get user inputs regarding shipping
 amount/cost/options and then output the end shipping costs/results of those inputs
*/

#include <iostream>
#include <iomanip>

using namespace std;

// function prototypes for declaration
void readUserInput(int &, int &, int &, char &, double &);
void specialResults(int &, int &, char, double &);
void displayUserResults(int, int, double);

void readUserInput(int & tickerOut, int & inputSpoolsToOrder, int & inputSpoolsInStock, char & inputSpecialShipping, double & inputSpecialShippingCost) // function for getting all necessary user inputs for pass back to main function
{
    // begins user prompt
    cout << "Spools to be ordered" << endl;
    cin >> inputSpoolsToOrder;
    if (inputSpoolsToOrder >= 1) // start of logic chain for user input
    {
        cout << "Spools in stock" << endl;
        cin >> inputSpoolsInStock;
        if (inputSpoolsInStock >= 0) // verifies correct input
        {
            cout << "Special shipping and handling (y or n)" << endl;
            cin >> inputSpecialShipping;
            if (inputSpecialShipping == 'y') // verifies correct input
            {
                cout << "Shipping and handling amount" << endl;
                cin >> inputSpecialShippingCost;
                if (inputSpecialShippingCost < 0.0) // error out statement
                {
                    cout << "The spool shipping and handling charge must be 0.0 or more" << endl;
                    tickerOut = 1;
                }
            }
        }
        else // error out statement
        {
            cout << "Spools in stock must be 0 or more" << endl;
            tickerOut = 1;
        }
    }
    else // error out statement
    {
        cout << "Spools order must be 1 or more" << endl;
        tickerOut = 1;
    }

    // calls special results function to pass back new results which will eventually be passed to the display function
    specialResults(inputSpoolsToOrder, inputSpoolsInStock, inputSpecialShipping, inputSpecialShippingCost);
}

void specialResults(int & specialSpoolsToOrder, int & specialSpoolsInStock, char specialSpecialShipping, double & specialSpecialShippingCost) // function for calculating special results to pass back to main read function
{
    // temporary vars for assignment within this function only
    int spoolsReadyToShip,
        spoolsOnBackOrder;

    // starts logic chain for any special reassignments of temporary variables
    if (specialSpoolsToOrder == specialSpoolsInStock || specialSpoolsToOrder < specialSpoolsInStock)
    {
        spoolsReadyToShip = specialSpoolsToOrder;
        spoolsOnBackOrder = 0;
    }
    if (specialSpoolsToOrder > specialSpoolsInStock)
    {
        spoolsOnBackOrder = specialSpoolsToOrder - specialSpoolsInStock;
        spoolsReadyToShip = specialSpoolsToOrder - spoolsOnBackOrder;
    }
    if (specialSpecialShipping == 'n')
    {
        specialSpecialShippingCost = 12.99;
    }
    // reassigns temporary variables to permanent variables for pass back
    specialSpoolsToOrder = spoolsReadyToShip;
    specialSpoolsInStock = spoolsOnBackOrder;
}

void displayUserResults(int outputSpoolsToOrder, int outputSpoolsInStock, double outputSpecialShippingCost) // function for display final results to user
{
    // displays all final results from values passed back to this function
    cout << "Spools ready to ship: " << outputSpoolsToOrder << endl;
    cout << "Spools on back-order: " << outputSpoolsInStock << endl;
    cout << fixed << setprecision(2);
    cout << "Subtotal ready to ship: $" << right << setw(10)
         << outputSpoolsToOrder * 104.00 << endl;
    cout << "Shipping and handling:  $" << right << setw(10)
         << outputSpecialShippingCost * outputSpoolsToOrder << endl;
    cout << "Total shipping charges: $" << right << setw(10)
         << (outputSpoolsToOrder * 104) + (outputSpecialShippingCost * outputSpoolsToOrder) << endl;
}

int main() // main function for program
{
    // declared all necessary variables for future pass back
    int spoolsToOrder,
        spoolsInStock,
        ticker = 0; // verification ticker to make sure no bad inputs have been put in
    char specialShipping;
    double specialShippingCost;

    readUserInput(ticker, spoolsToOrder, spoolsInStock, specialShipping, specialShippingCost);
    if (ticker == 0) // outputs results if no illegal values have been input
        {
        displayUserResults(spoolsToOrder, spoolsInStock, specialShippingCost);
        }

    return 0;
}
