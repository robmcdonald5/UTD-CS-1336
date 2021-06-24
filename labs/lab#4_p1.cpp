/* PART #1 */
#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    // declared variables
    double objectMass,
           weightEarth,
           weightMoon,
           weightVenus;
    const double earthAcc = 9.81,
                 moonAcc = 1.62,
                 venusAcc = 8.87;

    // prompts user for mass variable
    cout << "Enter the mass in kg" << endl;
    cin >> objectMass;

    // starts if else clause to determine if mass calculation needs to be done or not
    cout << fixed << setprecision(4) << "The mass is " << objectMass << " kg" << endl;
    if (objectMass <= 0.0) { // ends program chain and outputs error for user to see
        cout << "The mass must be greater than zero" << endl; // terminates program if invalid input
    }
    else { // continues chain calculating and outputting new masses

        // declares new masses
        weightEarth = objectMass * earthAcc;
        weightMoon = objectMass * moonAcc;
        weightVenus = objectMass * venusAcc;

        // prints new masses
        cout << "Location" << right << setw(14) << "Weight (N)" << endl;
        cout << "Earth" << right << setw(17) << weightEarth << endl;
        cout << "Moon" << right << setw(18) << weightMoon << endl;
        cout << "Venus" << right << setw(17) << weightVenus << endl;

        // extra determination clause
        if (weightEarth >= 1500) { // determines if heavy
            cout << "The object is heavy" << endl;
        }
        else if (weightEarth < 5) { // determines if light
            cout << "The object is light" << endl;
        }
    }
    return 0;
}
