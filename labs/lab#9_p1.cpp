//
//  main.cpp
//  11_18 LAB#9
/*
 Author: Joshua McDonald
 Compiler: GNU GCC
 Date: 11/13/2020

 Purpose of program: The purpose of this program is to read in sales data from a file and
 then output finalized data in a new file named "saleschart.txt".

*/

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

// prototype declarations
void readInput(ifstream &, long long int &, unsigned int &);
void displayOutput(ofstream &, long long int data, unsigned int);

void readInput(ifstream & file, long long int & data, unsigned int & store) // main read function for program
{
    file >> store >> data; // targets lines of currently selected file in iterations
}

void displayOutput(ofstream & file, long long int data, unsigned int store) // main display function for program
{
    file << "\nStore" << right << setw(3) << store << ": ";

    for(int i = 1; i <= data / 5000; i++) // loops cout for * increments
    {
        file << "*";
    }
}

int main() // main function for the program
{
    string fileName; // declares string assignment variable for selected file
    long long int data; // long long int for assignment within file
    unsigned int store; // unsigned int for assignment within file
    ifstream file; // file logic chain declaration

    cout << "Enter input file name" << endl;
    cin >> fileName;

    file.open(fileName); // tries to open inputed file name

    if(file) // checks if program file exists
    {
        file.seekg(0, ios::end); // targets end of file
        if (file.tellg() == 0) // checks if there is any data at the end of the file
        {
            exit (EXIT_FAILURE); // errors out and ends program
        }
        file.seekg(0, ios::beg); // re-targets beginning of the file

        ofstream outputfile("saleschart.txt"); // sets stream output for file to-be outputted
        // writes header for output file
        outputfile << "SALES BAR CHART";
        outputfile << "\n(Each * equals 5,000 dollars)";

        while(!file.eof()) // loops while not at the end of current file being read
        {
            readInput(file, data, store); // calls readInput to set current iterated values

            if(store < 1 || store > 99) // errors out if current iteration of store values are invalid
            {
                cout << "The store number " << store << " is not valid";

                continue;
            }

            if(data < 0) // errors out if current iteration of data values are invalid
            {
                cout << "The sales value for store " << store << " is negative" << endl;

                continue;
            }

            if(file.eof()) // breaks loop before display function call if at end of currently read file
            {
                outputfile << "\n";
                break;
            }

            displayOutput(outputfile, data, store); // calls display function with passed back values of current iteration
        }

        //cout << endl << "File is created" << endl; // debug

        outputfile.close(); // closes output file

        file.close(); // closes main read file
    }

    else // file misread error out
    {
        cout << "File \"" << fileName << "\" could not be opened" << endl;

        exit (EXIT_FAILURE); // errors out program
    }

    return 0;
}
