//
//  main.cpp
//  11_08 LAB#8
/*
 Author: Joshua McDonald
 Compiler: GNU GCC
 Date: 11/07/2020

 Purpose of program: This program prompts users for a range of numbers
 and then iteratively loops from lowest to highest displaying the ASCII
 code of those numbers.

*/

#include <iostream>
#include <iomanip>

using namespace std;

void userInput(double &, double &, double &);
double* baseArray(int &, double, double, double);
double* toCelsius(int, double, double, double);
double* toKelvin(int, double, double, double);
void* displayResults(int, double, double, double);

void userInput(double & firstInput, double & secondInput, double & thirdInput)
{
    if (firstInput > secondInput || thirdInput <= 0)
    {
        cout << "Starting temperature must be <= ending temperature and increment must be > 0" << endl;
    }

    cin >> firstInput >> secondInput >> thirdInput;
}

double* baseArray(int & i, double firstInput, double secondInput, double thirdInput)
{
    double range = firstInput;
    double fahrenheitResult[i];

    while (range <= secondInput)
    {
        fahrenheitResult[i] = range;
        range = range + thirdInput;
        i++;
    }

    return fahrenheitResult;
}

double* toCelsius(int i, double fahrenheit)
{
    int iC = 1;
    double celsiusResult[iC];

    while (iC <= i)
    {
        //celsiusResult[iC] = (fahrenheit[iC] - 32.0) / 1.8;
        iC++;
    }

    return celsiusResult;
}

double* toKelvin(int i, double fahrenheit)
{
    int iK = 1;
    double kelvinResult[iK];

    for (iK; iK <= i; iK++)
    {
        //kelvinResult[iK] = (fahrenheit[iK] - 32.0) / 1.8;
        iK++;
    }

    return kelvinResult;
}

void* displayResults(int i, double fahrenheit, double celsius, double kelvin)
{
    int iR = 1;

    cout << "        Fahrenheit           Celsius            Kelvin" << endl;

    while (iR <= i)
    {
        cout << fixed << setprecision(4) << right << setw(5) << fahrenheit[i]
             << right << setw(10) << celsius[i] << right << setw(15)
             << kelvin[i] << endl;
        iR++;
    }
}

int main()
{
    double firstInput = 1,
           secondInput = 2,
           thirdInput = 1;
    int i = 1;

    userInput(firstInput, secondInput, thirdInput);
    while (firstInput < secondInput || thirdInput <= 0)
    {
        userInput(firstInput, secondInput, thirdInput);
    }

    double* fahrenheit = baseArray(i, firstInput, secondInput, thirdInput);
    double* celsius = toCelsius(i, fahrenheit);
    double* kelvin = toKelvin(i, fahrenheit);

    //displayResults(i, fahrenheit, celsius, kelvin);

    return 0;
}
