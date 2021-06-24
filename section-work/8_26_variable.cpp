// 8_26_variable

/*
#include is a preprocessor directive to ask the preprocessor to replace
the line with the content of a file
Data can be handled as variables or literals
A variable is a container that can hold data. It has a memory location
New data can be reassigned to the same container. e.g. intVariable = 7;
To read or change the content, use the variable name, e.g. cout << intVariable;
A variable must be defined before it can be used
A literal is data that is fixed and cannot change.
Identifiers are programmer-defined names for variables and other things, e.g. intVariable
You have a lot of freedom to choose the identifiers. Rules are:
1. Cannot use a C++ key word
2. First character of the name can only be a letter ot underscore
3. Remaining characters can be a letter, underscore or digit
Good practice: should choose a name that represents the purpose of the variable
*/

#include <iostream>
#include <string>

using namespace std;

int main()
{
    int intVariable;

    intVariable = 5; // 5 is a litearl
    cout << "Value of intVariable is " << intVariable << endl;

    intVariable = 7;
    cout << "Value of intVariable is " << intVariable << endl;

    char charVariable;

    charVariable = '%';
    cout << "Character is " << charVariable << endl;

    charVariable = 'A';
    cout << "Character is " << charVariable << endl;

    string message = "Hello world";
    cout << message << endl;

    message = "Bye";
    cout << message;

    return 0;
}
