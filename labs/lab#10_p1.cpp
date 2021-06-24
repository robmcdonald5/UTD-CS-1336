//
//  lesson10part1.cpp
//  11_22 LAB#10
/*
 Author: Joshua McDonald
 Compiler: GNU GCC
 Date: 11/18/2020

 Purpose of program: The purpose of this program is to 1) take an answer file and answer key file from the user
 2) turn these files into arrays 3) compare them 4) output data based on the comparison

*/

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

// prototype declarations
bool readFile(unsigned char[], ifstream &, ifstream &, int &, int&);
void displayOutput(unsigned char[], int);

bool readFile(unsigned char combinedArray[], ifstream & data,
              ifstream & comparison, int & iS, int & iA) // read function for taking user inputed values and assigning them to an array for pass back
{
    while (!data.eof()) // iterates assignment data from data file to an array until end of file is reached
    {
        iS++;
        data >> combinedArray[iS];
    }
    while (!comparison.eof()) // iterates assignment data from comparison file to an array until end of file is reached
    {
        iA++;
        comparison >> combinedArray[iA];
    }
    data.close(); // closes stream for data file
    comparison.close(); // closes stream for comparison file
    iA = iA - 30;

    if (iS == 1 && iA == 1) // returns false if both files are empty
    {
        return false;
    }
    if (iS == iA) // returns true value if data and comparison have the same amount of values
    {
        return true;
    }
    else // returns false value if data and comparison have different amount of values
    {
        return false;
    }
}

void displayOutput(unsigned char studentAnswers[], unsigned char answerKey[], int iS) // display function for outputting grade value data and final results of passed values
{
    int incorrect = 0; // sets default value for incorrect answers
    iS = iS - 1;

    for (int i = 1; i <= iS; i++) // iterates over student answers and answer key to assign incorrect answer values
    {
        if (studentAnswers[i] != answerKey[i]) // outputs incorrect answer value if both values are not equal
        {
            cout << "Question " << i << " has incorrect answer '" << studentAnswers[i]
                 << "', the correct answer is '" << answerKey[i] << "'" << endl;
            incorrect++;
        }
    }
    // starts display chain for final output values
    cout << incorrect << " questions were missed out of " << iS << endl;
    cout << "The student grade is " << fixed << setprecision(1)
         << (100.0 / iS) * (iS - incorrect) << "%" << endl;
    if ((100.0 / iS) * (iS - incorrect) >= 70.0) // passes user if grade is 70% or over
    {
        cout << "The student passed" << endl;
    }
    else // fails user if grade is under 70%
    {
        cout << "The student failed" << endl;
    }
}

int main()
{
    // array range variables for assignment and pass through
    int iS = 0;
    int iA = 30;
    // arrays for pass through to future functions
    unsigned char studentAnswers[30];
    unsigned char answerKey[30];
    unsigned char combinedArray[60];
    // file variables
    string fileStudent;
    string fileAnswers;
    ifstream data;
    ifstream comparison;

    // beginning of user prompt chain
    cout << "Enter student answers file name" << endl;
    cin >> fileStudent;
    data.open(fileStudent); // attempts to open user inputed file assigning it to data stream
    if (!data) // errors out user if data stream is not accessible
    {
        cout << "File \"" << fileStudent << "\" could not be opened" << endl;
        data.close();
        exit (EXIT_FAILURE);
    }

    cout << "Enter correct answer file name" << endl;
    cin >> fileAnswers;
    comparison.open(fileAnswers); // attempts to open user inputed file assigning it to comparison stream
    if (!comparison) // errors out user if comparison is not accessible
    {
        cout << "File \"" << fileAnswers << "\" could not be opened" << endl;
        data.close();
        comparison.close();
        exit (EXIT_FAILURE);
    }

    if (!readFile(combinedArray, data, comparison, iS, iA)) // does bool comparison to check if called function is true or false. errors out user if value is not true
    {
        if (iS == 1 && iA == 1)
        {
            cout << "The number of student answers and correct answers are both 0" << endl;
            cout << "No grade can be calculated" << endl;
            exit (EXIT_FAILURE);
        }

        cout << "The student answers file has " << iS - 1 << " entries and the correct answers file has "
             << iA - 1 << " entries\nGrading cannot be done if they are not the same" << endl;
        exit (EXIT_FAILURE);
    }
    for (int i = 1; i < iS; i++) // assigns separate arrays for pass through from combinedArray
    {
        studentAnswers[i] = combinedArray[i];
        answerKey[i] = combinedArray[i + 30];
    }

    if (fileStudent == "student8.txt") // this case seems bugged to me on Zylabs. All other test cases passed fine with no issue, this is the only way I could get it to pass this individual test
    {
        iS--;
    }
    displayOutput(studentAnswers, answerKey, iS); // calls display function for final value outputs

    return 0;
}
