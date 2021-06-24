//
//  main.cpp
//  10_28 HW#7
/*
 Author: Joshua McDonald
 Compiler: GNU GCC
 Date: 10/26/2020

 Purpose of program: The purpose of this program is to prompt user for accident statistics by polarity
 and then either read back that data, or interpellate that data to find either the safest or least safe area
*/


#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

// prototype functions for declaration
int getChoice();
void getAccidentStats(double &, double &, double &, double &);
void findSafest(double , double , double , double );
void findLeastSafe(double , double , double , double );
void displayAll(double, double, double, double);

int getChoice() // function for prompting user for choice and passing it back to the main function
{
    int menuChoice;
    cout << "\nMenu" << endl;
    cout << "----" << endl;

    cout << "1->Display safest region, 2->Display least safe region, 3->Display all" << endl;
    cin >> menuChoice;
    cout << "You entered " << menuChoice << endl;

    if (menuChoice == 1 || menuChoice == 2 || menuChoice == 3) // validates correct menu input
    {
        return menuChoice;
    }
    else
    {
        return -1;
    }
}

void getAccidentStats(double & accidentStatN, double & accidentStatS, double & accidentStatE, double & accidentStatW) // function for prompting user for initial accident values by region and then passing them back to the main function
{
    // begins prompt for user to input data
    cout << "Enter the accident stats for the North region: ";
    cin >> accidentStatN;
    if (accidentStatN >= 0.000 && accidentStatN <= 1.000) // verifies correct input
    {
        cout << "Accident stats entered for the North region is " << accidentStatN << endl;
        cout << "Enter the accident stats for the South region: ";
        cin >> accidentStatS;

        if (accidentStatS >= 0.000 && accidentStatS <= 1.000) // verifies correct input
        {
            cout << "Accident stats entered for the South region is " << accidentStatS << endl;
            cout << "Enter the accident stats for the East region: ";
            cin >> accidentStatE;

            if (accidentStatE >= 0.000 && accidentStatE <= 1.000) // verifies correct input
            {
                cout << "Accident stats entered for the East region is " << accidentStatE << endl;
                cout << "Enter the accident stats for the West region: ";
                cin >> accidentStatW;

                if (accidentStatW >= 0.000 && accidentStatW <= 1.000) // verifies correct input
                {
                    cout << "Accident stats entered for the West region is " << accidentStatW << endl;
                }
                else // errors out user
                {
                    cout << "Accident stats must be between 0 and 1" << endl;
                    exit (EXIT_FAILURE);
                }
            }
            else // errors out user
            {
                cout << "Accident stats must be between 0 and 1" << endl;
                exit (EXIT_FAILURE);
            }
        }
        else // errors out user
        {
            cout << "Accident stats must be between 0 and 1" << endl;
            exit (EXIT_FAILURE);
        }
    }
    else // errors out user
    {
        cout << "Accident stats must be between 0 and 1" << endl;
        exit (EXIT_FAILURE);
    }
}

void findSafest(double accidentStatN, double accidentStatS, double accidentStatE, double accidentStatW) // function determines safest region and then prints it out to the user
{
    // declares temp variables to compare to assign to passed back values
    double lowest = accidentStatN;
    string region = "north";

    if (accidentStatS < lowest)
    {
        lowest = accidentStatS;
        region = "south";
    }
    if (accidentStatE < lowest)
    {
        lowest = accidentStatE;
        region = "east";
    }
    if (accidentStatW < lowest)
    {
        lowest = accidentStatW;
        region = "west";
    }

    // prints out safest region to user
    cout << "Region " << region << " is the safest, with " << lowest
         << " accidents per capita" << endl;
}

void findLeastSafe(double accidentStatN, double accidentStatS, double accidentStatE, double accidentStatW) // function determines least safe region and prints it out to the user
{
    // declares temp variables to compare to assign to passed back values
    double highest = accidentStatN;
    string region = "north";

    if (accidentStatS > highest)
    {
        highest = accidentStatS;
        region = "south";
    }
    if (accidentStatE > highest)
    {
        highest = accidentStatE;
        region = "east";
    }
    if (accidentStatW > highest)
    {
        highest = accidentStatW;
        region = "west";
    }

    // prints out least safe region to user
    cout << "Region " << region << " is the least safe, with " << highest
         << " accidents per capita" << endl;
}

void displayAll(double accidentStatN, double accidentStatS, double accidentStatE, double accidentStatW) // function displays all region statistics from passed on values from main
{
    // prints out user inputs back to user
    cout << "North region has " << accidentStatN << " accidents per capita" << endl;
    cout << "South region has " << accidentStatS << " accidents per capita" << endl;
    cout << "East region has " << accidentStatE << " accidents per capita" << endl;
    cout << "West region has " << accidentStatW << " accidents per capita" << endl;
}

int main() // main program function
{
    // declaration of all values for pass back values
    double regionStatN,
           regionStatS,
           regionStatE,
           regionStatW;
    int userChoice;

    getAccidentStats(regionStatN, regionStatS, regionStatE, regionStatW);
    userChoice = getChoice(); // sets userChoice for menu and calls getChoice to determine user menu choice

    switch(userChoice) // checks for user input
    {
    case 1:
        findSafest(regionStatN, regionStatS, regionStatE, regionStatW); // calls findSafest
        break;
    case 2:
        findLeastSafe(regionStatN, regionStatS, regionStatE, regionStatW); // calls findLeastSafe
        break;
    case 3:
        displayAll(regionStatN, regionStatS, regionStatE, regionStatW); // calls displayAll
        break;
    default:
        cout << "Invalid choice" << endl;
        break;
    }

    cout << "Exiting\n";

    return 0;
}
