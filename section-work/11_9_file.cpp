// 11_9_file

/*
A file can be a text file or binary file
A file can be sequential access or random access
We focus on sequential access text files

A program interacts (read/write) with a file through a
file stream object that the programmer has to define

There are 3 types of filestream objects:
ifstream (read only) ofstream (write only),
and fstream (read/write)
We focus on ifstream and ofstream only

To do file I/O
Open the file
Use the file
Close the file

You should check the open is successful using
if(!fileStreamObjectName) or if (fileStreamObjectName.fail())

The stream extraction operator >> will return false if the read
has an error. A read when there is no data cause an error.
We can use it in a while loop to read data until the end
of the file

When while(inFile >> var) is executed, the read is actually
performed and false is returned if there is no more data
*/

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

using namespace std;

int main()
{
    string fileName;
    int netID;
    double GPA;

    // Write into a file
    ofstream outFile; // Define file stream object of type ofstream
    cout << "Enter the file name: ";
    cin >> fileName;

    outFile.open(fileName);
    if (outFile.fail())
    {
        cout << "Could not open output file\n";
        exit(EXIT_FAILURE);
    }
    else // open successful
    {
        cout << "Enter a netID to write into the file, -1 if done: ";
        cin >> netID;
        while (netID != -1)
        {
            cout << "Enter a GPA: ";
            cin >> GPA;
            outFile << netID << ' ' << GPA << endl;
            cout << "Enter a netID to write into the file, -1 if done: ";
            cin >> netID;
        } // end loop over the students
        outFile.close();
    } // end case open is successful

    // Read from a file
    ifstream inFile; // Define file stream object of type ifstream
    cout << "Enter the file name: ";
    cin >> fileName;

    inFile.open(fileName);
    if (inFile.fail())
    {
        cout << "Could not open input file\n";
        exit(EXIT_FAILURE);
    }
    else // open successful
    {
        while (inFile >> netID)
        {
            inFile >> GPA;
            cout << "netID and GPA read from file " << fileName
                 << ": " << netID << " " << GPA << endl;
        }
        inFile.close();
    } // end case open successful

    return 0;
}
