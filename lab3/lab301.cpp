#include <iostream>
#include <fstream>
using namespace std;
int main()
{
    fstream fp;
    fp.open("lab3.txt", ios::in);
    if (!fp.is_open())
    {
        cout << "Error with opening the file " << endl;
    }
    else
    {
        int size = 0;
        int num;
        while (!fp.eof())
        {
            size = size + 1;
            fp >> num;
        } // after getting the size of this file.
        cout << "Size: " << size << endl;
        int *array = new int[size];
        // initialize the array
        for (int i = 0; i < size; i++)
        {
            array[i] = 0;
        }
        fstream nf; // 需要重新宣告一個fstream
        nf.open("lab3.txt", ios::in);
        if (!nf.is_open())
        {
            cout << "Error with opening the file " << endl;
        }
        else
        {
            for (int i = 0; i < size; i++)
            {
                nf >> array[i];
            }
            // bubble sort
            for (int i = 0; i < size - 1; i++)
            {
                for (int j = 0; j < size - 1 - i; j++)
                {
                    if (array[j] < array[j + 1])
                    {
                        int tmp = array[j];
                        array[j] = array[j + 1];
                        array[j + 1] = tmp;
                    }
                }
            }
            cout << "N"
                 << "\t"
                 << "count" << endl;
            // show the array
            for (int i = 0; i < size; i++)
            {
                if (i == 0)
                {
                    cout << array[i] << "\t";
                    int j = i;
                    int count = 1;
                    while (array[j] == array[j + 1])
                    {
                        j++; //
                        count++;
                    }
                    cout << count << endl;
                }
                else if (array[i] != array[i - 1])
                {
                    cout << array[i] << "\t";
                    int j = i;
                    int count = 1;
                    while (array[j] == array[j + 1])
                    {
                        j++; //
                        count++;
                    }
                    cout << count << endl;
                }
            }
        }
    }

    return 0;
}