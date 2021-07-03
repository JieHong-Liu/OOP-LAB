#include <iostream>
using namespace std;
int main()
{
    string input_str;
    cin >> input_str;

    int width = 1;
    cout << "the input string is " << input_str << endl;
    cout << input_str.size() << endl;

    while (input_str.size() >= (width * width))
    {
        width++;
    } // determine the width

    cout << "width: " << width << endl;
    for (int i = 0; i < width; i++)
    {
        int index = i;
        for (int j = 0; j < width; j++)
        {
            cout << input_str[index];
            index = index + (width);
        }
        cout << endl;
    }

    return 0;
}