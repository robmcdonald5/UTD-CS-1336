/* PART #1
#include <iostream>

using namespace std;

int main() // Calculates total tax on a 95 dollar purchase
{
    // Defines constant variables for county/state sales tax
    const double stateSalesTax = 0.06;
    const double countySalesTax = 0.02;

    // Calculation clause
    double initialPrice = 95.0; // Integer value is rated in USD
    double totalTaxPrice = (initialPrice * stateSalesTax) + (initialPrice * countySalesTax); // Calculates total state and local tax of purchase

    // Declared final input
    cout << totalTaxPrice << endl;

    return 0;
}
*/


/* PART #2
// Calculate rising ocean levels based on the estimated rate of rising (in millimeters). This
// estimated value is read from cin into variable risingLevel
//

#include <iostream>

using namespace std;

int main()
{
   double risingLevel;

   // read in the estimated rising ocean level
   cout << "Enter the estimated ocean level" << endl;
   cin >> risingLevel;

   // prints currently chosen level
   cout << "Level: " << risingLevel << endl;

   int years; // declares years integer to be used in different outputs

   // calculates and prints outputs for 'years' and 'rise'
   years = 5;
   cout << "Years: " << years << ", " << "Rise: " << years * risingLevel << endl;

   years = 10;
   cout << "Years: " << years << ", " << "Rise: " << years * risingLevel << endl;

   years = 50;
   cout << "Years: " << years << ", " << "Rise: " << years * risingLevel << endl;

   return 0;
}
*/


/* PART #3
#include <iostream>

using namespace std;

int main ()
{
    // defines characters for both the rectangle and triangle
    char atSign = '@';
    char percentSign = '%';

    // printed outputs for the rectangle
    cout << atSign << atSign << atSign << atSign << atSign << atSign << atSign << atSign << atSign << atSign << atSign << atSign << endl;
    cout << atSign << "          " << atSign << endl;
    cout << atSign << "          " << atSign << endl;
    cout << atSign << "          " << atSign << endl;
    cout << atSign << "          " << atSign << endl;
    cout << atSign << "          " << atSign << endl;
    cout << atSign << "          " << atSign << endl;
    cout << atSign << "          " << atSign << endl;
    cout << atSign << "          " << atSign << endl;
    cout << atSign << "          " << atSign << endl;
    cout << atSign << "          " << atSign << endl;
    cout << atSign << atSign << atSign << atSign << atSign << atSign << atSign << atSign << atSign << atSign << atSign << atSign << endl;

    cout << endl; // spacing for both shapes

    // printed outputs for the triangle
    cout << "      " << percentSign << endl;
    cout << "     " << percentSign << " " << percentSign << endl;
    cout << "    " << percentSign << "   " << percentSign << endl;
    cout << "   " << percentSign << "     " << percentSign << endl;
    cout << "  " << percentSign << "       " << percentSign << endl;
    cout << " " << percentSign << "         " << percentSign << endl;
    cout << percentSign << percentSign << percentSign << percentSign << percentSign << percentSign << percentSign << percentSign << percentSign << percentSign << percentSign << percentSign << percentSign << endl;

    return 0;
}
*/
