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

using namespace std;

// prototype declarations
void userInput(unsigned int &, unsigned int &);
void displayResults(unsigned int, unsigned int);

void userInput(unsigned int & lowerVal, unsigned int & upperVal) // user input function for passing back values to main function
{
    if (lowerVal < 32 || lowerVal > 126 || upperVal < 32 || upperVal > 126 || lowerVal > upperVal) // errors out user and asks for new value if input is not within range 32-126 inclusive
    {
        cout << "Values must be in range 32 to 126 inclusive" << endl;
    }
    // user value prompt
    cout << "Enter lower and upper values" << endl;
    cin >> lowerVal >> upperVal;
}

void displayResults(unsigned int lowerVal, unsigned int upperVal) // result output display function
{
    // temporary loop functions
    int loop = 0,
        indentation = 0,
        staticRange = upperVal - lowerVal;

    cout << "Characters for ASCII values between " << lowerVal << " and "
         << upperVal << endl;

    // start of menu
    cout << "----+----+----+----+\n";
    for (int range = upperVal - lowerVal; range != -1; --range) // iteratively looping menu
    {
        cout << static_cast<unsigned char>(lowerVal); // displays current ASCII code in the iterative loop
        //cout << "(INDENTATION = " << indentation << ")"; //debug
        lowerVal = ++lowerVal;
        if (loop == 0) // upper part of indentation loop
        {
            if (indentation == 19 || indentation == 39 || indentation == 59 || indentation == 79) // checks if indentation is necessary
            {
                cout << endl;
                //cout << "(INDENTATION HAPPENED)" << endl; // debug
            }
            if (indentation == staticRange - 1) // ends loop if indentation iteration is = to the range
            {
                loop = 1; // ends loop
            }
            ++indentation; // adds 1 val to iteration
        }
    }
    cout << "\n----+----+----+----+\n";
}

int main() // main function
{
    // unsigned variables for pass back with below functions
    unsigned int lowerVal = 32,
                 upperVal = 126;

    userInput(lowerVal, upperVal); // calls function for pass back of sent values
    while (lowerVal < 32 || lowerVal > 126 || upperVal < 32 || upperVal > 126 || lowerVal > upperVal) // checks if passed back values are valid, if not re-calls the read function
    {
        userInput(lowerVal, upperVal);
    }

    displayResults(lowerVal, upperVal); // calls display function with valid user inputs

    return 0;
}
