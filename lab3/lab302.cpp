#include <iostream>
#include <fstream>
using namespace std;
int main()
{
    string fileName;
    cout << "Please input the file name: ";
    cin >> fileName;

    fstream fp;
    fp.open(fileName, ios::in);
    if (!fp.is_open())
    {
        cout << "Error with opening the file" << endl;
    }
    else
    {
        int score;
        int grades[6] = {}; //declare with initialize
        while (!fp.eof())
        {
            fp >> score;
            grades[score]++;
        }
        for (int i = 0; i < 6; i++)
        {
            cout << grades[i] << " grade(s) of " << i << endl;
        }
    }

    return 0;
}