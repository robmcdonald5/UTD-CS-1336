//
//  main.cpp
//  11_17 HW#9
/*
 Author: Joshua McDonald
 Compiler: GNU GCC
 Date: 11/14/2020

 Purpose of program: The purpose of this program is to 1) read from user inputed files
 2) check if they are on record 3) if they are not, error user out 4) if they are display
 output value correlated with either, highestSalary, lowestSalary, avgSalary.

*/

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

// declaration of global variables
ifstream file;
double firstEmp;
double secondEmp;
double outputVal;

// prototype declarations
bool highestSalary(string, double &);
bool lowestSalary(string, double &);
bool avgSalary(string, double &);

bool highestSalary(string fileName, double & outputVal) // function for reading currently selected file against highestSalary
{
    // temp var for assignment to passed back var
    double highest = 0.0;

    file.open(fileName); // tries to open inputed file name
    file.seekg(0, ios::end); // targets end of file
    if (file.tellg() == 0) // checks if there is any data at the end of the file
    {
        file.close(); // closes out file after error out

        return false;
    }
    file.seekg(0, ios::beg); // targets beginning of file just in case it was already used

    if(file) // checks if selected file can be opened
    {
        while(!file.eof()) // iterates over selected file while it is not at the end of the file
        {
            file >> firstEmp >> secondEmp; // assigns file vars to global vars

            // iterative logic chain for setting highestValue
            outputVal = firstEmp * secondEmp;
            if(outputVal > highest)
            {
                highest = outputVal;
            }
        }
        outputVal = highest;
        file.close(); // closes file before any return is made

        return true;
    }

    else // errors out user if file selected is not available
    {
        return false;
    }
}

bool lowestSalary(string fileName, double & outputVal) // function for reading currently selected file against lowestSalary
{
    // temp var for assignment to passed back var
    double lowest = 1000000.0;

    file.open(fileName); // tries to open inputed file name
    file.seekg(0, ios::end); // targets end of file
    if (file.tellg() == 0) // checks if there is any data at the end of the file
    {
        file.close(); // closes out file after error out

        return false;
    }
    file.seekg(0, ios::beg); // targets beginning of file just in case it was already used

    if(file) // checks if selected file can be opened
    {
        while(!file.eof())
        {
            file >> firstEmp >> secondEmp; // assigns file vars to global vars

            // iterative logic chain for setting lowestValue
            outputVal = firstEmp * secondEmp;
            if (outputVal < lowest)
            {
                lowest = outputVal;
            }
        }
        outputVal = lowest;
        file.close(); // closes file before any return is made

        return true;
    }

    else // errors out user if file selected is not available
    {
        return false;
    }
}

bool avgSalary(string fileName, double & outputVal) // function for reading currently selected file against avgSalary
{
    double average = 0.0;
    double loop = 1.0;

    file.open(fileName); // tries to open inputed file name
    file.seekg(0, ios::end); // targets end of file
    if (file.tellg() == 0) // checks if there is any data at the end of the file
    {
        file.close(); // closes out file after error out

        return false;
    }
    file.seekg(0, ios::beg); // targets beginning of file just in case it was already used

    if(file) // checks if selected file can be opened
    {
        while(!file.eof())
        {
            file >> firstEmp >> secondEmp; // assigns file vars to global vars

            // iterative logic chain for setting avgValue
            if(file.eof())
            {
                loop--;
                break;
            }
            outputVal = firstEmp * secondEmp;
            average = average + outputVal;
            loop++;
        }
        outputVal = average / loop;
        file.close(); // closes file before any return is made

        return true;
    }

    else // errors out user if file selected is not available
    {
        return false;
    }
}

int main()
{
    // temp var for user assignment and passes to future functions
    string fileName;

    cout << "Enter input file name: "; // highestSalary header
    cin >> fileName;
    if(highestSalary(fileName, outputVal)) // displays highestSalary if called func==true
    {
        cout << "Highest salary is " << outputVal << endl;
    }
    else // errors out if called func==false
    {
        cout << "Invalid file" << endl;
    }

    cout << "\nEnter input file name: "; // lowestSalary header
    cin >> fileName;
    if(lowestSalary(fileName, outputVal)) // displays lowestSalary if called func==true
    {
        cout << "Lowest salary is " << outputVal << endl;
    }
    else // errors out if called func==false
    {
        cout << "Invalid file" << endl;
    }

    cout << "\nEnter input file name: "; // avgSalary header
    cin >> fileName;
    if(avgSalary(fileName, outputVal)) // displays avgSalary if called func==true
    {
        cout << "Average salary is " << outputVal << endl;
    }
    else // errors out if called func==false
    {
        cout << "Invalid file" << endl;
    }

    return 0;
}
