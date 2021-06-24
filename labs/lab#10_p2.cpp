//
//  lesson10part1.cpp
//  11_22 LAB#10
/*
 Author: Joshua McDonald
 Compiler: GNU GCC
 Date: 11/22/2020

 Purpose of program: The purpose of this program is to 1) take in data from
 a file 2) convert it into a row column vector  3) interpellate that data
 into outputted values to the user

*/

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <vector>

using namespace std;

// global variable
int m = 5;

// prototype declarations
void readFile(vector<vector<double>> &, int &, string);
void average(vector<vector<double>>, int);
void columnAverage(vector<vector<double>>, int);
void smallest(vector<vector<double>>, int);
void display(vector<vector<double>>, int);

void readFile(vector<vector<double>> & values, int & MAX_ROWS, string filename) // main read function for opening user file and apply logic chains
{
    // temp vars for this function for pass through
    int i = 0;
    int j = 0;
    int ticker = 0;
    ifstream file;
    ifstream blank;
    double temp;

    file.open(filename); // opens main file
    blank.open(filename); // opens comparison file
    if(!file && !blank) // errors out user if inputed file does not exist
    {
        cout << "File \"" << filename << "\" could not be opened" << endl;
        file.close(); // closes main file
        blank.close(); // closes comparison file

        exit (EXIT_FAILURE); // errors out and ends program
    }

    file.seekg(0, ios::end); // targets end of file
    if (file.tellg() == 0) // checks if there is any data at the end of the file
    {
        file.close(); // closes main file
        blank.close(); // closes comparison file
        cout << "The input file \"" << filename << "\" did not contain any data" << endl;
        exit (EXIT_FAILURE); // errors out and ends program
    }
    file.seekg(0, ios::beg); // re-targets beginning of file

    while (!blank.eof()) // checks how many rows file has with comparison file
    {
        ticker++;
        blank >> temp >> temp >> temp >> temp >> temp;
    }
    ticker--;

    for (i = 0; i <= ticker; i++) // runs until i is > row value determined by comparison file
    {
        file >> values[i][j] >> values[i][j+1] >> values[i][j+2]
             >> values[i][j+3] >> values[i][j+4];
        MAX_ROWS++;
    }

    file.close(); // closes main file
    blank.close(); // closes comparison file
}

void average(vector<vector<double>> values, int MAX_ROWS) // function takes average of entire function with passed values
{
    // temp vars for function
    double average = 0.0;
    int i = 0;
    int j = 0;

    for (i = 0; i < MAX_ROWS; i++) // runs loop adding every value of original passed vector
    {
        average = average + values[i][j] + values[i][j+1] + values[i][j+2] +
                  values[i][j+3] + values[i][j+4];
    }
    average = average / (MAX_ROWS * 5);

    cout << "Average for all values is " << fixed << setprecision(2)
         << average << endl;
}

void columnAverage(vector<vector<double>> values, int MAX_ROWS) // function takes individual column averages with passed values
{
    // temp vars for function
    vector<vector<double>> columnAverageVec(1, vector<double> (m));
    double columnAverage = 0.0;


    for (int i = 0; i < m; i++) // runs loop adding individual columns together
    {
        for (int j = 0; j < MAX_ROWS; j++)
        {
            columnAverage = columnAverage + values[j][i];
        }
        columnAverage = columnAverage / MAX_ROWS;
        cout << "Average for column " << i << " is " << fixed << setprecision(2)
             << columnAverage << endl;
        columnAverage = 0.0;
    }
}

void smallest(vector<vector<double>> values, int MAX_ROWS) // function finds smallest value in each individual row with passed values
{
    // temp vars for function
    int i = 0;
    int j = 0;
    int k = 0;
    double smallest = values[i][k];

    for (i = 0; i < MAX_ROWS; i++) // runs loop for each row and printing lowest determined value in each row
    {
        k++;
        for (j = 0; j < m; j++)
        {
            if (smallest > values[i][j])
            {
                smallest = values[i][j];
            }
        }

        cout << "Smallest value for row " << i << " is " << fixed
             << setprecision(2) << smallest << endl;
        if (i == MAX_ROWS - 1)
        {
            break;
        }
        smallest = values[k][0];
    }
}

void display(vector<vector<double>> values, int MAX_ROWS) // starts display header for user and calls other secondary void(display) functions for output
{
    cout << "Processing " << MAX_ROWS << " rows, and " << m << " columns" << endl;

    average(values, MAX_ROWS);
    columnAverage(values, MAX_ROWS);
    smallest(values, MAX_ROWS);
}

int main() // main program function
{
    int n = 30;
    vector<vector<double>> values(n, vector<double> (m));
    int MAX_ROWS = -1;
    string filename;

    cout << "Enter input file name" << endl;
    cin >> filename;

    readFile(values, MAX_ROWS, filename); // calls readFile to populate vector from user inputed file
    display(values, MAX_ROWS); // calls display to display values from passed values

    return 0;
}
