// 10_5_function

#include <iostream>

using namespace std;

/*
A function is a module of code that performs a task
The module is packaged in a block of code and given a name

To execute the task, call the function by its name

A function definition contains
1. Return type: put void if the function returns nothing
2. name: Must follow the same naming rules as for variables.
Good practice is to choose meaningful names
3. parameter list: list the variables that contain data passed
to the function (could be empty)
4. body: statements that make up the function

Function header: first line of function definition

*/

void printHeader() // This line is a function
{
    cout << "Hello, welcome to this program" << endl;
}
double calcAverage(int x, int y, int z)
{
    double res;
    res = (x + y + z) / 3.0;
    return res;
}

int getValue()
{
    int val;
    cout << "Enter a value: ";
    cin >> val;
    return val;
}

void printResult(double avg)
{
    cout << "Result of average calculation is " << avg
         << endl;
}

int main()
{
    int val1,
        val2,
        val3;
    double average;

    // Print welcome message
    printHeader(); // Function call

    // Prompt for 3 values
    val1 = getValue(); // Function call
    val2 = getValue();
    val3 = getValue();

    // Calculate thh average
    average = (val1 + val2 + val3) / 3.0;

    // Print result
    printResult(average);

    return 0;
}
