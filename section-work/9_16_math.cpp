// 9_16_math

#include <iostream>
#include <cmath> // math functions
#include <cstdlib> // rand()
#include <ctime> // time()

using namespace std;

int main()
{
    double x;
    unsigned int seed;

    cout << "Enter an argument for cosine: ";
    cin >> x;
    cout << "Cosine is " << cos(x) << endl;

    cout << endl;
    cout << rand() << endl;
    cout << rand() << endl;
    cout << rand() << endl;
    cout << rand() << endl;
    cout << rand() << endl;

    // Use seed
    cout << endl << "Enter the seed: ";
    cin >> seed;
    // seed = time(0);
    cout << "Seed is " << seed << endl;
    srand(seed);

    // Example of dice
    cout << endl;
    int r1 = rand() % 6 + 1;
    int r2 = rand() % 6 + 1;
    int r3 = rand() % 6 + 1;
    int r4 = rand() % 6 + 1;

    cout << r1 << endl << r2 << endl << r3 << endl << r4 << endl;

    return 0;
}
