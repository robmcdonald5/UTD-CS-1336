// 9_14_overFlow_underFlow

#include <iostream>
#include <climits>

using namespace std;

int main()
{
    int myInt;

    // overflow
    myInt = INT_MAX;
    cout << "Max value of an int: " << myInt
         << ", Add 1 to the max value: " << myInt + 1 << endl;

    // underflow
    myInt = INT_MIN;
    cout << "Min value of an int: " << myInt
         << ", Subtract 1 from the min value: " << myInt - 1 << endl;

    return 0;
}
