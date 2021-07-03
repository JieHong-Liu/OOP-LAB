#include <iostream>
#include <fstream>

using namespace std;
void getHighScores(string name[], int score[]);
int main()
{
    fstream fp;
    string name[5];
    int score[5];
    fp.open("scores.txt", ios::in);
    if (!fp.is_open())
    {
        cout << "The file is not open" << endl;
    }
    else
    {
        for (int i = 0; i < 5; i++) // 只要這樣就可讀進資料，太神啦C++
        {
            fp >> name[i];
            fp >> score[i];
        }

        getHighScores(name, score);
    }

    return 0;
}
void getHighScores(string name[], int score[])
{
    // bubble sort from biggest to smallest
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4 - i; j++)
        {
            if (score[j] < score[j + 1])
            {
                int temp = score[j];
                score[j] = score[j + 1];
                score[j + 1] = temp;
                // change the name
                string tmp = name[j];
                name[j] = name[j + 1];
                name[j + 1] = tmp;
            }
        }
    }
    for (int i = 0; i < 3; i++)
    {
        cout << name[i] << endl;
        cout << score[i] << endl;
    }
}