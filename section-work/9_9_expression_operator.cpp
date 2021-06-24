// 9_9_expression_operator
/*
An expression is anything that evaluates to a value
Examples:
A literal, 5 or 10.7
A variable, score1
Some combination of variable(s) and literal(s) using
mathematical operators: (score1 + score2)/2

In complex expressions with multiple operators, the order in
which you apply the operators matters.
C++ follows the 3 tiers rule
The programmer can always override  with parens
In the case of nested parens, the innermost parens are evaluated
first
*/


#include <iostream>

using namespace std;

int main()
{
    double score1,
           score2;

    cout << "Enter the 1st score: ";
    cin >> score1;
    cout << "Value entered is " << score1 << endl;

    cout << "Enter the 2nd score: ";
    cin >> score2;
    cout << "Value entered is " << score2 << endl;

    cout << "Total is " << score1 + score2 << endl;

    // Order of operations matters, override with parens
    cout << "score1 + score2/2 = " << score1 + score2/2 << endl;
    cout << "(score1 + score2) / 2 = " << (score1 + score2) / 2 << endl;

    // Unary negation
    cout << "-5 * -3 is " << -5 * -3 << endl;

    return 0;
}
