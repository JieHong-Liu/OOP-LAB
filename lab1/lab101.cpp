#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
    cout << fixed << setprecision(2);
    double n;
    cin >> n;
    double guess = n / 2;
    double old_guess = 0;
    double r;
    while (guess - old_guess > 0.01 || old_guess - guess > 0.01)
    {
        old_guess = guess;
        r = n / guess;
        guess = (guess + r) / 2;
    }
    cout << guess;
    return 0;
}