#include <iostream>
using namespace std;
template <class T>
int ItrBinarySearch(const T a[], int first, int last, T key, bool &found, int &location)
{
    found = false;
    while (first <= last)
    {
        location = first + (last - first) / 2 ;//直接平均可能會溢位，所以用此算法
        cout << "the location is " << location << endl;
        cout << "a[location] = " << a[location] << endl;
        if (key == a[location])
        {
            found = true;
            break;
        }
        else if (key > a[location])
        {
            first = location + 1;
        }
        else if (key < a[location])
        {
            last = location -1 ;
        }
    }
    // if can't find the key, then return -1
    if (found)
    {
        return location;
    }
    else
    {
        return -1;
    }
}
template <class T>
int RecBinarySearch(const T a[], int first, int last, T key, bool &found, int &location)
{
    if (found)
    {
        return location;
    }
    else if (first <= last)
    {
        location = first + (last - first) / 2;//直接平均可能會溢位，所以用此算法
        if (key == a[location])
        {
            found = true;
        }
        else if (key > a[location])
        {
            first = location + 1;
        }
        else if (key < a[location])
        {
            last = location - 1;
        }
        RecBinarySearch(a, first, last, key, found, location);
    }
    else
    {
        return -1;
    }
}
