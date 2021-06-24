// 11_16_array_processing

/*
Going out of bounds: when your subscript is outside the valid
range. Compiler will not give a compilation error
Effect is unpredictable: program may freeze, crash, have elusive
bugs, etc.

An array name is the address of the array
For an array of chars, cout << arrName will print the chars
in the array until it finds a null terminator
A proper C-string is an array of chars with a null terminator
It's legal to have an array of chars without a null terminator
For an array of non-chars, cout << arrName will print the starting
address of the array

To print the content of an array, use a loop to print the
elements one by one
Use a loop to calculate the average, find lowest/highest value

Partially filled array: when you don't know what size you need,
you can oversize the array. The array may be partially filled.
You need to maintain a counter a variable to track the number
of actual items in the array
*/
#include <iostream>

using namespace std;

int main()
{
    // Going out of bounds
    const int ARR_SIZE = 5;
    int arr[ARR_SIZE];

    for (int i = 0; i < ARR_SIZE; i++)
    {
        arr[i] = 500;
    }

    for (int i = 0; i < ARR_SIZE; i++)
    {
        cout << arr[i] << " ";
    }

    /* Example of going out of bounds
    for (int i = 0; i < ARR_SIZE + 10000; i++)
    {
        arr[i] = 500;
    }

    for (int i = 0; i < ARR_SIZE + 10000; i++)
    {
        cout << arr[i] << " ";
    }*/

    // print array name

    int arr1[] = {9, 8, 7};
    char arr2[] = {'H', 'e', 'n', 'r', 'y', '\0'};
    char arr3[] = "Henry";

    cout << endl;
    cout << "cout char array2 name: " << arr2 << endl;
    cout << "cout char array3 name: " << arr3 << endl;
    cout << "cout non-char array name: " << arr1 << endl;

    // Partially filled array
    const int SIZE = 4;
    double scores2[SIZE];
    int myIndex = 0;
    double score;

    cout << endl << "Enter a score, -1 if done: ";
    cin >> score;
    while (score != -1 && myIndex < SIZE)
    {
        scores2[myIndex] = score;
        cout << endl << "Enter a score, -1 if done: ";
        cin >> score;
        myIndex++;
    }

    cout << endl << "Content of scores array" << endl;
    for (int i = 0; i < myIndex; i++) // myIndex is a counter variable
        cout << scores2[i] << endl;

    return 0;
}
