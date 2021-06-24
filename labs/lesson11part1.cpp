//
//  lesson10part1.cpp
//  11_22 LAB#11
/*
 Author: Joshua McDonald
 Compiler: GNU GCC
 Date: 11/22/2020

 Purpose of program:
*/

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

// global variable
const int MAX_ROWS = 21;

bool readSquare(vector<vector<double>> &, int &, string);
bool validateSquare();
void displayMagicSquare();

bool readSquare(vector<vector<double>> & values, int & SET_COLUMNS, string filename)
{
    file.open(filename);

    if (!file)
    {
        return false;
    }

    for (int i = 0; i < )
}

bool validateSquare()
{

}

void displayMagicSquare()
{

}

int main()
{
    const int MAX_COLUMNS = 30;
    vector<vector<double>> values(MAX_COLUMNS, vector<double> (MAX_ROWS));
    string filename;
    int SET_COLUMNS;

    cout << "Enter input file name" << endl;
    cin >> filename;

    if (readSquare(values, SET_COLUMNS, filename));
    {
        if (validateSquare())
        {
            cout << "Valid magic square" << endl;
        }
        else
        {
            cout << "Invalid magic square" << endl;
        }
    }
    else
    {
        cout << "File could not be opened" << endl;

        exit (EXIT_FAILURE);
    }

    return 0;
}
