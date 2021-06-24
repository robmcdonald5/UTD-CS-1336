/* HW#2 */
#include <iostream>
#include <string> // allows for the use of (string;)

using namespace std;

int main()
{
    // defines all necesary variables
    string firstName,
           lastName;

    float testScore1,
          testScore2,
          testScore3;

    // prompts user for first name
    cout << "Please enter the student's first name: ";
    cin >> firstName;
    cout << "First name entered is " << firstName << endl;

    // prompts user for last name
    cout << "Please enter the student's last name: ";
    cin >> lastName;
    cout << "Last name entered is " << lastName << endl;

    // prompts user for first test score
    cout << "Please enter the student's test 1 score: ";
    cin >> testScore1;
    cout << "Test 1 score entered is " << testScore1 << endl;

    // prompts user for second test score
    cout << "Please enter the student's test 2 score: ";
    cin >> testScore2;
    cout << "Test 2 score entered is " << testScore2 << endl;

    // prompts user for third test score
    cout << "Please enter the student's test 3 score: ";
    cin >> testScore3;
    cout << "Test 3 score entered is " << testScore3 << endl;

    // adds up test scores and averages them displaying to the user
    cout << "The test average of " << firstName << " " << lastName << " is " << (testScore1 + testScore2 + testScore3) / 3 << endl;
    return 0;
}
