// 9_28_menu_check_input

#include <iostream>

using namespace std;

int main()
{
    int choice;

    cout << "Menu, enter your choice:" << endl;
    cout << "1 - Chicken" << endl;
    cout << "2 - Beef" << endl;
    cout << "3 - Fish" << endl;
    cout << "4 - Vegan" << endl;

    cin >> choice;

    if (choice == 1)
        cout << "You chose chicken" << endl;
    else if (choice == 2)
        cout << "You chose beef" << endl;
    else if (choice == 3)
        cout << "You chose fish" << endl;
    else if (choice == 4)
        cout << "You chose vegan" << endl;
    else // Trailing else to catch invalid choice
        cout << "Invalid choice" << endl;

    return 0;
}
