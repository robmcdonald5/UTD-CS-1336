/* PART #1
#include <iostream>
#include <iomanip> // includes library for manipulators e.g. fixed, setprecision

using namespace std;

int main()
{
    // declaration of all variables
    float testGrade1, testGrade2, testGrade3, testGrade4, testGrade5;

    // initial prompt
    cout << "Enter 5 test grades" << endl;
    cin >> testGrade1 >> testGrade2 >> testGrade3 >> testGrade4 >> testGrade5; // user input for test grades

    // final average output
    cout << fixed << setprecision(1) << "Average: " << (testGrade1 + testGrade2 + testGrade3 + testGrade4 + testGrade5) / 5 << endl;

    return 0;
}
*/

/* PART #2
#include <iostream>
#include <iomanip> // includes library for manipulators e.g. setw()

using namespace std;

int main ()
{
    // declaration of all variables
    double dollars,
           yen,
           euros,
           pesos;
    const double yenConv = 113.27,
                 eurosConv = 0.84,
                 pesosConv = 19.73;

    // USD conversion user entry
    cout << "Enter the amount in dollars" << endl;
    cin >> dollars;

    // converts USD value to alternative currencies
    yen = dollars * yenConv;
    euros = dollars * eurosConv;
    pesos = dollars * pesosConv;

    // prints each currency with associated value based of the initial USD input
    cout << right << setw(15) << "Dollars" << setw(15) << "Yen" << setw(15) << "Euros" << setw(15) << "Pesos" << endl;
    cout << right << fixed << setprecision(2) << setw(15) << dollars << setw(15) << yen << setw(15) << euros << setw(15) << pesos << endl;

    return 0;
}

*/

/* PART #3 */
#include <iostream>
#include <iomanip> // includes library for manipulators e.g.
#include <string> // allows for the use of string

using namespace std;

int main ()
{
    // declares variables
    string company;
    int shares;
    double purchasePrice, salePrice;
    const double commission = 0.035;

    // prompts user for company name (string)
    cout << "Enter the name of the company" << endl;
    getline (cin,company);
    //cout << company << endl; // debug for input

    // prompts for number of stock shares (int)
    cout << "Enter shares of stock" << endl;
    cin >> shares;
    //cout << shares << endl; // debug for number of shares

    // prompts for purchase price (double)
    cout << "Enter purchase price" << endl;
    cin >> purchasePrice;
    //cout << purchasePrice << endl; // debug for number of shares

    // prompts for sale price (double)
    cout << "Enter sale price" << endl;
    cin >> salePrice;
    cout << endl;

    // prints chosen stock and amount of shares being calculated
    cout << "Company: " << company << endl;
    cout << "Shares: " << shares << endl;
    cout << endl;

    // calculates total share price cost
    cout << "Purchase/share: " << fixed << setprecision(2) << "$" << purchasePrice << endl;
    cout << "Cost of stock: " << fixed << setprecision(2) << "$" << purchasePrice * shares << endl;
    cout << "Cost of commission: " << fixed << setprecision(2) << "$" << (purchasePrice * shares) * commission << endl;
    cout << "Total cost: " << fixed << setprecision(2) << "$" << (purchasePrice * shares) + ((purchasePrice * shares) * commission) << endl;
    cout << endl;

    // calculates and prints new share price income
    cout << "Sale/share: " << fixed << setprecision(2) << "$" << salePrice << endl;
    cout << "Income from stock: " << fixed << setprecision(2) << "$" << salePrice * shares << endl;
    cout << "Cost of commission: " << fixed << setprecision(2) << "$" << (salePrice * shares) * commission << endl;
    cout << "Total income: " << fixed << setprecision(2) << "$" << (salePrice * shares) - ((salePrice * shares) * commission) << endl;
    cout << endl;

    // calculates and prints gain or loss
    cout << "Gain or loss: " << fixed << setprecision(2) << "$" << ((salePrice * shares) - ((salePrice * shares) * commission)) - ((purchasePrice * shares) + ((purchasePrice * shares) * commission)) << endl;

    return 0;
}
