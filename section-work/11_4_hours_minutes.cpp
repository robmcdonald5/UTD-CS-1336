#include <iostream>

using namespace std;

int main()
{
    for (int hour = 0; hour < 12; hour++)
    {
        for(int minute = 0; minute < 60; minute++)
        {
            cout << "Time is " << hour << ":"
                 << minute << endl;
        }
    }
    return 0;
}
