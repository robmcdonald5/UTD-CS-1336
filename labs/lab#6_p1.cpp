//
//  lesson6part1.cpp
//  10_25 lab#6
/*
 Author: Joshua McDonald
 Compiler: GNU GCC
 Date: 10/23/2020

 Purpose of program: This program is meant to receive a user input in seconds of an
 object traveling and then output the distance that object would travel on earth
 and the moon
*/

#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

// function prototypes for declaration
double readSeconds(double);
double calculateEarthDistance(double);
double calculateMoonDistance(double);
void displayResults(double, double, double);

double readSeconds(double secondsEntered) // function for prompting user for input in seconds and then feeding other functions this data
{
    // declaration of math resultant variables for this scope
    double userEarthDistance,
           userMoonDistance;

    // prompts user for input in seconds
    cout << "Enter the time (in seconds)" << endl;
    cin >> secondsEntered;

    if (secondsEntered < 0) // verifies user input is 0 seconds or above
    {
        cout << "The time must be zero or more" << endl;
    }
    else // default run statement if no errors
    {
        userEarthDistance = calculateEarthDistance(secondsEntered); // calls earth distance function
        userMoonDistance = calculateMoonDistance(secondsEntered); // calls moon distance function
        displayResults(secondsEntered, userEarthDistance, userMoonDistance); // calls end result function
    }
    return 0;
}

double calculateEarthDistance(double seconds) // function for calculating travel distance for Earth
{
    const double gravityE = 9.8; // constant gravity for Earth
    double distanceE = 0.5 * gravityE * pow(seconds, 2);
    return distanceE;
}

double calculateMoonDistance(double seconds) // function for calculating travel distance for the Moon
{
    const double gravityM = 1.6; // constant gravity for the Moon
    double distanceM = 0.5 * gravityM * pow(seconds, 2);
    return distanceM;
}

void displayResults(double seconds, double earthDistance, double moonDistance) // function for displaying end results of program math
{
    // prints out results of previous prompt function + math functions
    cout << "The object traveled " << fixed << setprecision(4) << earthDistance << " meters in "
         << fixed << setprecision(2) << seconds << " seconds on Earth" << endl;
    cout << "The object traveled " << fixed << setprecision(4) << moonDistance << " meters in "
         << fixed << setprecision(2) << seconds << " seconds on the Moon" << endl;
}

int main() // main function for program
{
    double seconds;
    readSeconds(seconds);

    return 0;
}
