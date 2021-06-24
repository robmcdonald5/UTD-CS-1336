/* PART#2 */
#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    // declared variables
    unsigned int medium;
    double time;
    const double carbonDioxideAcc = 258.0,
                 airAcc = 331.5,
                 heliumAcc = 972.0,
                 hydrogenAcc = 1270.0;

    // prompts user to select medium for sound to travel through
    cout << "Select the medium that sound is traveling through:" << endl;
    cout << "1 Carbon Dioxide" << endl;
    cout << "2 Air" << endl;
    cout << "3 Helium" << endl;
    cout << "4 Hydrogen" << endl;
    cin >> medium;

    // starts logic chain
    if (medium >= 1 && medium <= 4) { // makes sure selection is valid
        cout << "Enter time (in seconds)" << endl;
        cin >> time;
        if ((time < 0) || (time >= 30)) { // rejects invalid times and tells user to retry
            cout << "The time must be between 0.000 and 30.000 (inclusive)" << endl;
        }
        else { // determines which medium is used
            if (medium == 1) { // carbon dioxide medium equation is executed and shown
                cout << "Carbon Dioxide: " << fixed << setprecision(3) << time << " seconds" << endl;
                cout << "Traveled " << fixed << setprecision(4) << time * carbonDioxideAcc << " meters" << endl;
            }
            else if (medium == 2) { // air medium equation is executed and shown
                cout << "Air: " << fixed << setprecision(3) << time << " seconds" << endl;
                cout << "Traveled " << fixed << setprecision(4) << time * airAcc << " meters" << endl;
            }
            else if (medium == 3) { // air medium equation is executed and shown
                cout << "Helium: " << fixed << setprecision(3) << time << " seconds" << endl;
                cout << "Traveled " << fixed << setprecision(4) << time * heliumAcc << " meters" << endl;
            }
            else if (medium == 4) { // air medium equation is executed and shown
                cout << "Hydrogen: " << fixed << setprecision(3) << time << " seconds" << endl;
                cout << "Traveled " << fixed << setprecision(4) << time * hydrogenAcc << " meters" << endl;
            }
        }
    }
    else { // ends program and tells user to retry b/c of invalid input
        cout << "The menu value is invalid. Please run the program again." << endl;
    }
    return 0;
}
