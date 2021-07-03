#include <iostream>
using std::cout;
using std::endl;
template <class T>

T absoluteValue(T value1, T value2)
{
    cout << "the value1 is " << value1 << endl;
    cout << "the value2 is " << value2 << endl;
    T result;
    if (value1 > value2)
    {
        result = value1 - value2;
    }
    else
    {
        result = value2 - value1;
        cout << "the result is " << endl;
    }
    return result;
}
