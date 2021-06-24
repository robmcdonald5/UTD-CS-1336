// 10_23_increment_decrement
/*
Increment/decrement operators increment and decrement a variable resp.

You are allowed to increment/decrement only a variable
(something that has a memory location)

- Prefix: When used in an expression, the increment/decrement
operator is applied before the expression is evaluated
(example of cout, assignment, relational below)

- Prefix: When used in an expression, the increment/decrement
operator is applied after the expression is evaluated
(example of cout, assignment, relational below)
*/
#include <iostream>

using namespace std;

int main()
{
    int num1 = 5, num2 = 10, num, x;

    // Basic increment/decrement
    cout << "num1 is " << num1 << endl;
    cout << "Now execute num1++" << endl;
    num1++;
    cout << "After num1++, num1 is " << num1 << endl;

    // Increment/decrement with cout
    cout << endl << "num1 is " << num1 << endl;
    cout << "Next we cout << ++num1" << endl;
    cout << ++num1 << endl; // Prefix increment
    cout << "After cout << ++num1, num1 is " << num1 << endl;

    cout << "Next we cout << num1++" << endl;
    cout << num1++ << endl; // Postfix increment
    cout << "After cout << num1++, num1 is " << num1 << endl;


    cout << endl << "num2 is " << num2 << endl;
    cout << "Next we cout << --num2" << endl;
    cout << --num2 << endl; // Prefix decrement
    cout << "After cout << --num2, num2 is " << num2 << endl;

    cout << "Next we cout << num2--" << endl;
    cout << num2-- << endl; // Postfix decrement
    cout << "After cout << num2--, num2 is " << num1 << endl;

    // Increment/decrement with assignment
    cout << endl << "num1 is " << num1 << endl;
    cout << "Now execute x = num1++" << endl;
    x = num1++; // Postfix increment
    cout << "After x = num1++, x is " << x << ", num1 is "
         << num1 << endl;
    cout << "Now execute x = ++num1" << endl;
    x = ++num1; // Prefix increment
    cout << "After x = ++num1, x is " << x << ", num1 is "
         << num1 << endl;
    cout << endl << "num2 is " << num2 << endl;
    cout << "Now execute x = num2--" << endl;
    x = num2--; // Postfix decrement
    cout << "After x = num2--, x is " << x << ", num2 is "
         << num2 << endl;
    cout << "Now execute x = --num2" << endl;
    x = --num2; // Prefix decrement
    cout << "After x = --num2, x is " << x << ", num2 is "
         << num2 << endl;

    // Increment/decrement with rational operator
    num = 4;
    cout << endl << "num is " << num << endl;
    if (++num == 5)
        cout << "++num is equal to 5" << endl;
    else
        cout << "++num is not equal to 5" << endl;
        cout << "After if (++num ==5), num is " << num << endl;

    num = 4;
    cout << endl << "num is " << num << endl;
    if (num++ == 5)
        cout << "num++ is equal to 5" << endl;
    else
        cout << "num++ is not equal to 5" << endl;
        cout << "After if (num++ ==5), num is " << num << endl;

    // res = (num1 + num2)++; // This won't compile
    // (num1+ num2) has no memory location


    return 0;
}
