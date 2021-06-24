// 10_5_scope
/*
The scope of a variable is the part of the program where
you can access the variable

The scope begins when the variable is defined and ends at the
end of the block of code where it is defined

You can define a variable in an inner block which has the same
name as a variable in an outer block. They are different
variables (have different memory locations)
Generally, it is not recommended

When the scopes overlap, the inner block variable hides the outer
block variable
*/

#include <iostream>

using namespace std;

int main()
{
    int num; // The scope of outer block num begins here

    cout << "In outer block, enter a number to be stored in num: ";
    cin >> num;
    cout << "Value stored in num is " << num << endl;

    if (1)
    {
        int num; // The scope of inner block num begins here
        cout << "In inner block, enter another number to be stored in num: ";
        cin >> num;
        cout << "Value stored in num is " << num << endl;
    } // The scope of inner block num ends here

    cout << "Back in outer block, value stored in num is "
         << num << endl;

    return 0;
    // The scope of outer block num ends here
}
