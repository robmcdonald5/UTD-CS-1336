//
//  main.cpp
//  11_18 LAB#9
/*
 Author: Joshua McDonald
 Compiler: GNU GCC
 Date: 11/13/2020

 Purpose of program: The purpose of this program is to read from the user inputed file
 and output both calculated values from those values and which of those values are invalid.

*/

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

// prototype declarations
void readInput(ifstream &, double &);
void displayOutput(int, int, int, double);

void readInput(ifstream & file, double & data) // main read function
{
    file >> data; // iteratively assigns new values to data for pass back
}

void displayOutput(int totalValues, int invalidValues, int validValues, double averageValidValues) // main display function
{
    // beginning display header
    cout << "Total values: " << totalValues << endl;
    cout << "Invalid values: " << invalidValues << endl;
    cout << "Valid values: " << validValues << endl;

    if (totalValues == invalidValues) // errors out if no valid values in average calculation
    {
        cout << "An average cannot be calculated" << endl;
    }
    else // runs if average calculation has at least 1 valid value
    {
        cout << "Average of valid values: " << fixed << setprecision(4) << averageValidValues << endl;
    }
}

int main() // main function for program
{
    // temp vars for assignment and pass back
    int totalValues = 0;
    int invalidValues = 0;
    int validValues = 0;
    double averageValidValues = 0.0;
    double tempAverageValidValues = 0.0;

    // vars for file input and outputs
    string fileName;
    double data;
    ifstream file;

    // function header prompt input
    cout << "Enter input file name" << endl;
    cin >> fileName;

    file.open(fileName); // tries to open inputed file name

    if(file) // checks if program file exists
    {
        cout << "Reading from file \"" << fileName << "\"" << endl; // verifies what file is being read

        file.seekg(0, ios::end); // targets end of file
        if (file.tellg() == 0) // checks if there is any data at the end of the file
        {
            exit (EXIT_FAILURE); // errors out and ends program
        }
        file.seekg(0, ios::beg); // re-targets beginning of the file

        ofstream outputfile("invalid-values.txt"); // opens stream for outputting invalid values

        while(!file.eof()) // loops while not at the end of current file being read
        {
            readInput(file, data); // calls function to read current iteration of opened file for pass back
            tempAverageValidValues = data;
            if(!file.eof()) // runs if not at the end of the currently opened file
            {
                if(data < 0.0000 || data > 105.0000) // runs if current data value is invalid
                {
                    outputfile << fixed << setprecision(5) << data << endl;

                    invalidValues++;
                }
                else // runs if current data values are valid
                {
                    validValues++;
                    averageValidValues = averageValidValues + data;
                }
                totalValues++;
            }
        }
        averageValidValues = averageValidValues / static_cast<double>(validValues); // sets final average to pass to future function

        displayOutput(totalValues, invalidValues, validValues, averageValidValues); // calls display function with passed back values

        outputfile.close(); // closes output file

        file.close(); // closes main read file
    }

    else // errors out user if file selected is not available
    {
        cout << "File \"" << fileName << "\" could not be opened" << endl;

        exit (EXIT_FAILURE);
    }

    return 0;
}
