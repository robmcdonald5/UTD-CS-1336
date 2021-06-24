//
//  main.cpp
//  10_20 HW#6
/*
 Author: Joshua McDonald
 Compiler: GNU GCC
 Date: 10/13/2020

 Purpose of program: This program is designed to prompt user for with a set
 of several different menu options related to phone bill pricing and then
 executes on those options with various function calls.
*/

#include <math.h>
#include <iostream>

using namespace std;

double calcBill(); // prototype function

double calcBill(char plan, double numGigabytes) // start of secondary function
{
    // declaring all necessary variables
    const double silverPlan = 29.99,
                 goldPlan = 49.99,
                 silverExtra = 10.00,
                 goldExtra = 5.00;
    double billCalc,
           roundedGigabytes;
    // rounds numGigabytes upwards
    roundedGigabytes = ceil(numGigabytes);

    switch(plan) // start of menu calculating either Silver or Gold plan bill cost
    {
    case 83: // Silver plan calculation(ASCI for S is 83)
        if (roundedGigabytes > 4.00) // extra data
        {
            billCalc = silverPlan + (silverExtra * (roundedGigabytes - 4.00));
        }
        else // no extra data
        {
            billCalc = silverPlan;
        }
        break;
    case 71: // Gold plan calculation(ASCI for G is 71)
        if (roundedGigabytes > 8.00) // extra data
        {
            billCalc = goldPlan + (goldExtra * (roundedGigabytes - 8.00));
        }
        else // no extra data
        {
            billCalc = goldPlan;
        }
        break;
    default: // default error out
        cout << "Invalid choice\nExiting" << endl;
        break;
    }
    return billCalc; // returns calculation for user's bill
}

int main() // start of main function
{
    // declaring all necessary variables
    int choice;
    char userPlan;
    double userGigabytes;

    // beginning user prompt
    cout << "Make your choice" << endl;
    cout << "1 - Calculate bill" << endl;
    cout << "2 - Compare my plan with the other plan" << endl;
    cout << "3 - Get the pricing info for the plans" << endl;
    cout << "4 - Quit" << endl;
    cin >> choice;

    switch(choice) // start of menu attached to user prompt choices
    {
    case 1: // calculates user bill based on inputed userPlan and userGigabytes
        cout << "Enter your plan, S for silver, G for gold: ";
        cin >> userPlan;
        if (userPlan == 'S' || userPlan == 'G') // verifies a correct plan choice has been selected
        {
            cout << "How many Gigabytes did you use? ";
            cin >> userGigabytes;
            if (userGigabytes >= 0) // verifies userGigabytes is 0 or above
                {
                cout << "Your bill amount is $" << calcBill(userPlan, userGigabytes)
                     << '\n' << "Exiting" << endl;
                }
            else // errors out if userGigabytes is bellow 0
            {
                cout << "Invalid usage\nExiting" << endl; // default error out
            }
        }
        else // errors out if incorrect plan choice has been selected
        {
            cout << "Invalid plan\nExiting" << endl; // default error out
        }
        break;
    case 2: // calculates user bill based on inputed userPlan and userGigabytes, and gives alternative pricing on the other plan
        cout << "Enter your plan, S for silver, G for gold: ";
        cin >> userPlan;
        if (userPlan == 'S' || userPlan == 'G') // verifies a correct plan choice has been selected
        {
            cout << "How many Gigabytes did you use? ";
            cin >> userGigabytes;
            if (userGigabytes >= 0) // verifies userGigabytes is 0 or above
            {
                if (userPlan == 'S') // checks if plan is Silver
                {
                    cout << "Your bill amount is $" << calcBill(userPlan, userGigabytes) << endl;
                    userPlan = 'G'; // temporarily converts plan to Gold for upcoming function call
                    cout << "Your bill would have been $" << calcBill(userPlan, userGigabytes)
                         << " with the Gold plan" << '\n' << "Exiting" << endl;
                }
                else if (userPlan == 'G') // checks if plan is Gold
                {
                    cout << "Your bill amount is $" << calcBill(userPlan, userGigabytes) << endl;
                    userPlan = 'S'; // temporarily converts plan to Silver for upcoming function call
                    cout << "Your bill would have been $" << calcBill(userPlan, userGigabytes)
                         << " with the Silver plan" << '\n' << "Exiting" << endl;
                }
            }
            else // errors out if userGigabytes is bellow 0
            {
                cout << "Invalid usage\nExiting" << endl; // default error out
            }
        }
        else // errors out if incorrect plan choice has been selected
        {
            cout << "Invalid plan\nExiting" << endl; // default error out
        }
        break;
    case 3: // lists pricing options for user
        cout << "Silver Plan" << endl;
        cout << "monthly fee is $29.99, 4 Gbytes are included, charge $10 per excess Gbyte"
             << endl;
        cout << "Gold Plan" << endl;
        cout << "monthly fee is $49.99, 8 Gbytes are included, charge $5 per excess Gbyte"
             << endl;
        cout << "Exiting" << endl;
        break;
    case 4: // default exit prompt
        cout << "Exiting" << endl;
        break;
    default: // default error out
        cout << "Invalid choice\nExiting" << endl;
        break;
    }

    return 0;
}
