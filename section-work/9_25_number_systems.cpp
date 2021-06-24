// 9_25_number_systems
/*
The base value in cin and cout is 10 by default (decimal)
For ints only: you can set the base value to 16 (hex) or 8 (octal)
or back to 10, for cin and cout

Can also declare literals in hex (prepend 0x) or octal (prepend 0)
*/
#include <iostream>

using namespace std;

int main()
{
    int num;

    // To read a value in hex
    cout << "Read value in hex" << endl;
    cin >> hex; // reserved keyword, tells cin to use base 16(hex)
    cout << "Enter value in hex: ";
    cin >> num;
    cout << "Value in decimal is " << num << endl;
    cin >> dec; // reserved keyword, tells cin to use base 10(decimal)
    cout << "Enter value in decimal: ";
    cin >> num;
    cout << "Value in decimal is " << num << endl;

    // To print in hex
    cout << endl << "Print value in hex" << endl;
    cout << hex; // tells cout to use base 16
    cout << "Value in hex is " << num << endl;
    cout << dec; // tells cout to use base 10
    cout << "Value in decimal is " << num << endl;

    // Declare litearls in hex or octal (octal = base 8)
    num = 0x10; // hex number
    cout << endl << "0x10 in decimal is " << num << endl;
    num = 010; // octal number
    cout << "010 in decimal is " << num << endl;

    return 0;
}
