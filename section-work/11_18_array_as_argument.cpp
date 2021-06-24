// 11_18_array_as_argument

/*
Parallel arrays: 2 or more arrays having the same number of
elements, where elements at the same subscript are related
The arrays may be of different type

When an array is passed as argument to a function, the array name
is passed to the function. The array name is the array address.

The function operates (reads/writes) on the original array ->
changes made by the function are made to the original array

If the function needs to know the number of elements, you need
to provide it in an additional argument

If the function is not supposed to modify the array, a good
practice is to put const next to the array in the parameter list
*/

#include <iostream>
#include <iomanip>

using namespace std;

void printArrayDouble(const double [], int); // The function
// is not supposed to modify the array
double calcTotal(const double[], int); // The function
// is not supposed to modify the array
void resetArray(double[], int, double);

int main()
{
    const int SIZE = 4;
    int hours [SIZE];
    double rate[SIZE];
    double wage[SIZE];

    for (int i = 0; i < SIZE; i++)
    {
        cout << "Enter hours and rate for employee #"
             << (i + 1) << ": ";
        cin >> hours[i] >> rate[i];
    }

    for (int i = 0; i < SIZE; i++)
    {
        wage[i] = rate[i] * hours[i];
    }

    // Call function to print array
    cout << endl << "Content of wage array" << endl;
    printArrayDouble(wage, SIZE);

    // Call function to calculate total
    cout << endl << "Total of wages is "
         << calcTotal(wage, SIZE) << endl;

    resetArray(wage, SIZE, 1000000);
    cout << endl << "Content of wage array" << endl;
    printArrayDouble(wage, SIZE);

    return 0;
}

void printArrayDouble(const double arr[], int arraySize)
{
    cout << fixed << setprecision(2);
    for (int i = 0; i < arraySize; i++)
    {
        cout << arr[i] << endl;
    }
}

double calcTotal(const double arr[], int arraySize)
{
    double total = 0;
    for (int i = 0; i < arraySize; i++)
    {
        total += arr[i];
    }

    return total;
}

void resetArray(double arr[], int arraySize, double val)
{
    for (int i = 0; i < arraySize; i++)
    {
        arr[i] = val;
    }
}
