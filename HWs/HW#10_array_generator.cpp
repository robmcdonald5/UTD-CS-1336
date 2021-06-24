//
//  main.cpp
//  11_28 HW#10-PART1
/*
 Author: Joshua McDonald
 Compiler: GNU GCC
 Date: 11/23/2020

 Purpose of program: The purpose of this program is to populate an array with the
 data values of a user inputed value. After the array is populated it will then
 output calculated values based on these results if the file is valid
*/
/*

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// prototype declarations
int populateArrays(string, int[], string[], double[], const int, int &);
void display(int[], string[], double[], int);
void lowestAndHighest(int[], string[], double[], int);
void displayWithInput(int[], string[], double[], int);

int populateArrays(string filename, int netIDArray[], string majorArray[], double gpaArray[],
                   const int MAX_ARRAY_SIZE, int & arraySize) // function populates array with user inputed file and returns 0 if file is valid and 1 if the file does not exist
{
    // temp vars for function
    ifstream file;
    ifstream comp;
    int tempInt;
    string tempString;
    double tempDouble;

    file.open(filename); // opens main file
    comp.open(filename); // opens comparison file

    if (!file && !comp) // errors out and returns 1 if file does not exist
    {
        file.close();
        comp.close();

        return 1;
    }

    file.seekg(0, ios::end); // targets end of file
    if (file.tellg() == 0) // checks if there is any data at the end of the file
    {
        file.close(); // closes main file
        comp.close(); // closes comparison file
        cout << "File has no data" << endl;

        exit (EXIT_FAILURE);
    }
    file.seekg(0, ios::beg); // re-targets beginning of file

    while (!comp.eof()) // iterates until reaching end of comp file to determine array length
    {
        arraySize++;
        comp >> tempInt >> tempString >> tempDouble;
    }
    arraySize--;
    if (arraySize > MAX_ARRAY_SIZE) // checks to see if array size is out of bounds, if so correct bounding to max possible bound value
    {
        arraySize = MAX_ARRAY_SIZE;
    }

    for (int i = 0; i < arraySize; i++) // loops over three different arrays populating them until at end of previously determined array length
    {
        file >> netIDArray[i] >> majorArray[i] >> gpaArray[i];
    }
    file.close(); // closes main file
    comp.close(); // closes comparison file

    return 0;
}

void display(int netIDArray[], string majorArray[], double gpaArray[], int arraySize) // main display function creating output header and call for other secondary display functions
{
    // temp vars for function
    int i;
    int j;

    // start of display header
    cout << "Number of records = " << arraySize << endl << endl;
    cout << "******\nPart 1\n******" << endl;

    cout << "NetID array\n-----------\n";
    j = 3;
    for (i = 0; i < arraySize; i++) // displays all netIDArray values in sets of 3
    {
        if (i == arraySize - 1)
        {
            cout << "netIDArray[" << i << "] = " << netIDArray[i] << endl;
            break;
        }

        if ((i % 3) == 0)
        {
            cout << "netIDArray[" << i << "] = " << netIDArray[i] << ", ";
        }
        else if ((j % 2) != 0)
        {
            cout << "netIDArray[" << i << "] = " << netIDArray[i] << ", ";
            j = 2;
        }
        else if ((j % 2) == 0)
        {
            cout << "netIDArray[" << i << "] = " << netIDArray[i] << endl;
            j = 3;
        }
    }

    cout << endl << "Major array\n-----------\n";
    j = 3;
    for (i = 0; i < arraySize; i++) // displays all majorArray values in sets of 3
    {
        if (i == arraySize - 1)
        {
            cout << "majorArray[" << i << "] = " << majorArray[i] << endl;
            break;
        }

        if ((i % 3) == 0)
        {
            cout << "majorArray[" << i << "] = " << majorArray[i] << ", ";
        }
        else if ((j % 2) != 0)
        {
            cout << "majorArray[" << i << "] = " << majorArray[i] << ", ";
            j = 2;
        }
        else if ((j % 2) == 0)
        {
            cout << "majorArray[" << i << "] = " << majorArray[i] << endl;
            j = 3;
        }
    }

    cout << endl << "GPA array\n---------\n";
    j = 3;
    for (i = 0; i < arraySize; i++) // displays all gpaArray values in sets of 3
    {
        if (i == arraySize - 1)
        {
            cout << "gpaArray[" << i << "] = " << gpaArray[i] << endl;
            break;
        }

        if ((i % 3) == 0)
        {
            cout << "gpaArray[" << i << "] = " << gpaArray[i] << ", ";
        }
        else if ((j % 2) != 0)
        {
            cout << "gpaArray[" << i << "] = " << gpaArray[i] << ", ";
            j = 2;
        }
        else if ((j % 2) == 0)
        {
            cout << "gpaArray[" << i << "] = " << gpaArray[i] << endl;
            j = 3;
        }
    }
    cout << endl;
}

void lowestAndHighest(int netIDArray[], string majorArray[], double gpaArray[], int arraySize) // function displays lowest and highest arrays correlating with GPA
{
    // temp vars for function
    int lowestAddress = 0;
    int highestAddress = 0;
    double comparisonGPA_L = gpaArray[0];
    double comparisonGPA_H = gpaArray[0];

    for (int i = 0; i < arraySize; i++) // finds lowest and highest gpa and assigns them to their associated addresses within the 3 main arrays
    {
        if (gpaArray[i] < comparisonGPA_L)
        {
            comparisonGPA_L = gpaArray[i];
            lowestAddress = i;
        }
        if (gpaArray[i] > comparisonGPA_H)
        {
            comparisonGPA_H = gpaArray[i];
            highestAddress = i;
        }
    }

    // highest/lowest display header
    cout << "Lowest GPA\n----------\n";
    cout << "NetID is " << netIDArray[lowestAddress] << ", major is " << majorArray[lowestAddress]
         << ", GPA = " << gpaArray[lowestAddress] << endl << endl;

    cout << "Highest GPA\n-----------\n";
    cout << "NetID is " << netIDArray[highestAddress] << ", major is " << majorArray[highestAddress]
         << ", GPA = " << gpaArray[highestAddress] << endl << endl;
}

void displayWithInput(int netIDArray[], string majorArray[], double gpaArray[], int arraySize) // function prompts user input for ID to compare to existing IDs within array and then outputs looping until canceled
{
    // temp vars for function
    int loop = 0;
    int maxLoop = 0;
    int netID;

    // display header
    cout << "Search on student's netID\n-------------------------\n";

    while (loop == 0) // main loop for prompting user
    {
        cout << "Input student's netID, -1 to quit: ";
        cin >> netID;

        if (netID == -1)
        {
            break;
        }

        maxLoop = 0;
        for (int i = 0; i < arraySize; i++) // secondary loop for iterating over netIDArray for validation
        {
            maxLoop++;
            if (netIDArray[i] == netID)
            {
                cout << "NetID is " << netIDArray[i] << ", major is " << majorArray[i]
                     << ", GPA = " << gpaArray[i] << endl << endl;
                i = 100;
            }
            if (maxLoop == arraySize)
            {
                cout << "NetID not found" << endl << endl;
                i = 100;
            }
        }
    }
}

int main() // main program function
{
    const int MAX_ARRAY_SIZE = 15;
    int netIDArray[MAX_ARRAY_SIZE];
    int arraySize = 0;
    string majorArray[MAX_ARRAY_SIZE];
    double gpaArray[MAX_ARRAY_SIZE];
    string filename;

    // starts prompt for user to input a chosen file
    cout << "Enter file name: ";
    cin >> filename;

    if (populateArrays(filename, netIDArray, majorArray, gpaArray, MAX_ARRAY_SIZE, arraySize) == 1) // checks if populateArrays call displays return that is not the default return
    {
        cout << "Failed to open file";

        exit (EXIT_FAILURE);
    }

    display(netIDArray, majorArray, gpaArray, arraySize); // calls display function to output main display header
    lowestAndHighest(netIDArray, majorArray, gpaArray, arraySize); // calls lowestAndHighest to output lowest and highest values associated with GPA array
    displayWithInput(netIDArray, majorArray, gpaArray, arraySize); // calls displayWithInput to prompt user to input an ID for comparison and output if valid

    return 0;
}
*/

//
//  main.cpp
//  11_28 HW#10-PART2
/*
 Author: Joshua McDonald
 Compiler: GNU GCC
 Date: 11/23/2020

 Purpose of program: The purpose of this program is to populate an array with the
 data values of a user inputed value. After the array is populated it will then
 output calculated values based on these results if the file is valid
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// prototype declarations
int populateArrays(string, int[], string[], double[], const int, int &);
void display(int[], string[], double[], int);
void lowestAndHighest(int[], string[], double[], int);
void displayWithInput(int[], string[], double[], int);

int populateArrays(string filename, int netIDArray[], string majorArray[], double gpaArray[],
                   const int MAX_ARRAY_SIZE, int & arraySize) // function populates array with user inputed file and returns 0 if file is valid and 1 if the file does not exist
{
    // temp vars for function
    ifstream file;
    ifstream comp;
    int tempInt;
    string tempString;
    double tempDouble;

    file.open(filename); // opens main file
    comp.open(filename); // opens comparison file

    if (!file && !comp) // errors out and returns 1 if file does not exist
    {
        file.close();
        comp.close();

        return 1;
    }

    file.seekg(0, ios::end); // targets end of file
    if (file.tellg() == 0) // checks if there is any data at the end of the file
    {
        file.close(); // closes main file
        comp.close(); // closes comparison file
        cout << "File has no data" << endl;

        exit (EXIT_FAILURE);
    }
    file.seekg(0, ios::beg); // re-targets beginning of file

    while (!comp.eof()) // iterates until reaching end of comp file to determine array length
    {
        arraySize++;
        comp >> tempInt >> tempString >> tempDouble;
    }
    arraySize--;
    if (arraySize > MAX_ARRAY_SIZE) // checks to see if array size is out of bounds, if so correct bounding to max possible bound value
    {
        arraySize = MAX_ARRAY_SIZE;
    }

    for (int i = 0; i < arraySize; i++) // loops over three different arrays populating them until at end of previously determined array length
    {
        file >> netIDArray[i] >> majorArray[i] >> gpaArray[i];
    }
    file.close(); // closes main file
    comp.close(); // closes comparison file

    return 0;
}

void display(int netIDArray[], string majorArray[], double gpaArray[], int arraySize) // main display function creating output header and call for other secondary display functions
{
    // temp vars for function
    int i;
    int j;

    // start of display header
    cout << "Number of records = " << arraySize << endl << endl;
    cout << "******\nPart 1\n******" << endl;

    cout << "NetID array\n-----------\n";
    j = 3;
    for (i = 0; i < arraySize; i++) // displays all netIDArray values in sets of 3
    {
        if (i == arraySize - 1)
        {
            cout << "netIDArray[" << i << "] = " << netIDArray[i] << endl;
            break;
        }

        if ((i % 3) == 0)
        {
            cout << "netIDArray[" << i << "] = " << netIDArray[i] << ", ";
        }
        else if ((j % 2) != 0)
        {
            cout << "netIDArray[" << i << "] = " << netIDArray[i] << ", ";
            j = 2;
        }
        else if ((j % 2) == 0)
        {
            cout << "netIDArray[" << i << "] = " << netIDArray[i] << endl;
            j = 3;
        }
    }

    cout << endl << "Major array\n-----------\n";
    j = 3;
    for (i = 0; i < arraySize; i++) // displays all majorArray values in sets of 3
    {
        if (i == arraySize - 1)
        {
            cout << "majorArray[" << i << "] = " << majorArray[i] << endl;
            break;
        }

        if ((i % 3) == 0)
        {
            cout << "majorArray[" << i << "] = " << majorArray[i] << ", ";
        }
        else if ((j % 2) != 0)
        {
            cout << "majorArray[" << i << "] = " << majorArray[i] << ", ";
            j = 2;
        }
        else if ((j % 2) == 0)
        {
            cout << "majorArray[" << i << "] = " << majorArray[i] << endl;
            j = 3;
        }
    }

    cout << endl << "GPA array\n---------\n";
    j = 3;
    for (i = 0; i < arraySize; i++) // displays all gpaArray values in sets of 3
    {
        if (i == arraySize - 1)
        {
            cout << "gpaArray[" << i << "] = " << gpaArray[i] << endl;
            break;
        }

        if ((i % 3) == 0)
        {
            cout << "gpaArray[" << i << "] = " << gpaArray[i] << ", ";
        }
        else if ((j % 2) != 0)
        {
            cout << "gpaArray[" << i << "] = " << gpaArray[i] << ", ";
            j = 2;
        }
        else if ((j % 2) == 0)
        {
            cout << "gpaArray[" << i << "] = " << gpaArray[i] << endl;
            j = 3;
        }
    }
    cout << endl;
}

void lowestAndHighest(int netIDArray[], string majorArray[], double gpaArray[], int arraySize) // function displays lowest and highest arrays correlating with GPA
{
    // temp vars for function
    int lowestAddress = 0;
    int highestAddress = 0;
    double comparisonGPA_L = gpaArray[0];
    double comparisonGPA_H = gpaArray[0];

    for (int i = 0; i < arraySize; i++) // finds lowest and highest gpa and assigns them to their associated addresses within the 3 main arrays
    {
        if (gpaArray[i] < comparisonGPA_L)
        {
            comparisonGPA_L = gpaArray[i];
            lowestAddress = i;
        }
        if (gpaArray[i] > comparisonGPA_H)
        {
            comparisonGPA_H = gpaArray[i];
            highestAddress = i;
        }
    }

    // highest/lowest display header
    cout << "Lowest GPA\n----------\n";
    cout << "NetID is " << netIDArray[lowestAddress] << ", major is " << majorArray[lowestAddress]
         << ", GPA = " << gpaArray[lowestAddress] << endl << endl;

    cout << "Highest GPA\n-----------\n";
    cout << "NetID is " << netIDArray[highestAddress] << ", major is " << majorArray[highestAddress]
         << ", GPA = " << gpaArray[highestAddress] << endl << endl;
}

void displayWithInput(int netIDArray[], string majorArray[], double gpaArray[], int arraySize) // function prompts user input for ID to compare to existing IDs within array and then outputs looping until canceled
{
    // temp vars for function
    int loop = 0;
    int maxLoop = 0;
    int netID;

    // display header
    cout << "Search on student's netID\n-------------------------\n";

    while (loop == 0) // main loop for prompting user
    {
        cout << "Input student's netID, -1 to quit: ";
        cin >> netID;

        if (netID == -1)
        {
            break;
        }

        maxLoop = 0;
        for (int i = 0; i < arraySize; i++) // secondary loop for iterating over netIDArray for validation
        {
            maxLoop++;
            if (netIDArray[i] == netID)
            {
                cout << "NetID is " << netIDArray[i] << ", major is " << majorArray[i]
                     << ", GPA = " << gpaArray[i] << endl << endl;
                i = 100;
            }
            if (maxLoop == arraySize)
            {
                cout << "NetID not found" << endl << endl;
                i = 100;
            }
        }
    }
}

int main() // main program function
{
    const int MAX_ARRAY_SIZE = 15;
    int netIDArray[MAX_ARRAY_SIZE];
    int arraySize = 0;
    string majorArray[MAX_ARRAY_SIZE];
    double gpaArray[MAX_ARRAY_SIZE];
    string filename;

    // starts prompt for user to input a chosen file
    cout << "Enter file name: ";
    cin >> filename;

    if (populateArrays(filename, netIDArray, majorArray, gpaArray, MAX_ARRAY_SIZE, arraySize) == 1) // checks if populateArrays call displays return that is not the default return
    {
        cout << "Failed to open file";

        exit (EXIT_FAILURE);
    }

    display(netIDArray, majorArray, gpaArray, arraySize); // calls display function to output main display header
    lowestAndHighest(netIDArray, majorArray, gpaArray, arraySize); // calls lowestAndHighest to output lowest and highest values associated with GPA array
    displayWithInput(netIDArray, majorArray, gpaArray, arraySize); // calls displayWithInput to prompt user to input an ID for comparison and output if valid

    return 0;
}
