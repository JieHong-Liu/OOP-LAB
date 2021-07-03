#include <iostream>
using namespace std;
int main()
{
    unsigned long long int seconds;
    cin >> seconds;
    unsigned long long int minutes = 0;
    unsigned long long int hours = 0;
    if (seconds >= 3600) // more than one hour
    {
        minutes = seconds / 60;
        hours = minutes / 60;
        minutes = minutes % 60;
        seconds %= 60;
        cout << hours << " hours " << minutes << " minutes and " << seconds << " seconds\n";
    }
    else if (seconds >= 60) // more than one minutes
    {
        minutes = seconds / 60;
        seconds %= 60;
        cout << minutes << " minutes and " << seconds << " seconds\n";
    }
    else
    {
        cout << seconds << " seconds\n";
    }

    return 0;
}