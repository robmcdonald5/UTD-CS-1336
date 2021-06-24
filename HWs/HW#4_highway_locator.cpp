//
//  main.cpp
//  9_30 HW#4
/*
 Author: Joshua McDonald
 Compiler: GNU GCC
 Date: 9/6/2020

 Purpose of program: This program is designed to prompt the user for what highway
 they are interested in and then give info about that highway. This info includes
 what type of highway it is, the direction, and whether or not it has a service
 highway.
*/

#include <iostream>

using namespace std;

int main()
{
    // declares all necessary variables
    int highwayNumber,
        serviceHighway;

    // prompts user for highway in question
    cout << "Enter the highway number: ";
    cin >> highwayNumber;

    // equates modulus of selected highway to determine if it has a service highway(primary/aux)
    serviceHighway = highwayNumber % 100;

    // starts logic chain for info about selected highway
    if (highwayNumber % 2 == 0) { // even numbers- east/west
        cout << "The highway goes east/west." << endl;
        if (serviceHighway == highwayNumber) { // primary highway chain f/ (east/west)
            cout << "I-" << highwayNumber << " is primary." << endl;
        }
        else { // auxiliary highway chain f/ (east/west)
            cout << "I-" << highwayNumber << " is auxiliary." << endl;
            cout << "The highway serves " << "I-" << serviceHighway << "." << endl;
        }
    }
    else { // odd numbers- north/south
        cout << "The highway goes north/south." << endl;
        if (serviceHighway == highwayNumber) { // primary highway chain f/ (north/south)
            cout << "I-" << highwayNumber << " is primary." << endl;
        }
        else { // auxiliary highway chain f/ (north/south)
            cout << "I-" << highwayNumber << " is auxiliary." << endl;
            cout << "The highway serves " << "I-" << serviceHighway << "." << endl;
        }
    }

    return 0;
}
