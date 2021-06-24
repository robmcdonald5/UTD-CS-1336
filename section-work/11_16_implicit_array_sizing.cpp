// 11_16_implicit_array_sizing
#include <iostream>

using namespace std;

int main()
{
    int testScores[] = {90, 85, 80, 75};
    int numElements = sizeof(testScores) / sizeof(int);

    for (int i = 0; i < numElements; i++)
    {
        cout << testScores[i] << endl;
    }
    return 0;
}
