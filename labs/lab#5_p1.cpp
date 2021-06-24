/* PART#1 */
#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    // variables defined
    unsigned int medium;
    double distance;
    const double airAcc = 1100,
                 waterAcc = 4900,
                 steelAcc = 16400;

    // prompts user to select medium type
    cout << "Select the medium that sound is traveling through:" << endl;
    cout << "1 Air" << endl << "2 Water" << endl << "3 Steel" << endl;
    cin >> medium;

    // starts switch chain checking what value was selected by the user
    switch (medium) {
        case 1: // air- chain
            cout << "Enter distance (in feet)" << endl;
            cin >> distance;
            if (distance <= 0) {
                cout << "The distance must be greater than zero" << endl;
                break;
            }
            cout << "Air: " << fixed << setprecision(4) << distance << " ft" << endl;
            cout << "Traveled for " << fixed << setprecision(4) << distance / airAcc << " seconds" << endl;
            break;
        case 2: // water- chain
            cout << "Enter distance (in feet)" << endl;
            cin >> distance;
            if (distance <= 0) {
                cout << "The distance must be greater than zero" << endl;
                break;
            }
            cout << "Water: " << fixed << setprecision(4) << distance << " ft" << endl;
            cout << "Traveled for " << fixed << setprecision(4) << distance / waterAcc << " seconds" << endl;
            break;
        case 3: // steel- chain
            cout << "Enter distance (in feet)" << endl;
            cin >> distance;
            if (distance <= 0) {
                cout << "The distance must be greater than zero" << endl;
                break;
            }
            cout << "Steel: " << fixed << setprecision(4) << distance << " ft" << endl;
            cout << "Traveled for " << fixed << setprecision(4) << distance / steelAcc << " seconds" << endl;
            break;
        default: // throws error to user if 1 of 3 values are not chosen
            cout << "The menu value is invalid. Please run the program again." << endl;
            break;
    }

    return 0;
}
