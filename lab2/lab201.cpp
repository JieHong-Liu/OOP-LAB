#include <iostream>
using namespace std;
int main()
{
    int num;
    int total = 0;
    cin >> num;
    int *array = new int[num]; // 動態宣告陣列的方法
    for (int i = 0; i < num; i++)
    {
        cin >> array[i];
        total += array[i];
    }
    double average = (double)total / (double)num;
    double sd, difference;
    double total_difference = 0;
    for (int i = 0; i < num; i++)
    {
        difference = array[i] - average;
        double product = difference * difference;
        total_difference += product;
    }
    sd = total_difference / (double)num;
    cout << "Average: " << average << "\t"
         << "Standard deviation: " << sqrt(sd) << endl;
    return 0;
}