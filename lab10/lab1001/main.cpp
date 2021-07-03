#include <iostream>
#include <vector>
using namespace std;
#define ELEMENTS_FOR_COMBINATION 5 //i.e., C(5,4)
#define DLEMENTS_FOR_CHOICE 4
void PrintCombination(int *arrayPtr, int elements_for_combination, int dlements_for_choice);
void dfs(int *arrayPtr, vector<int> &v, int now_index, int now_layers, int dlements_for_choice, int elements_for_combination);
int main(void)
{
    int *arrayPtr = new int[ELEMENTS_FOR_COMBINATION];

    //Get all elements for combination
    for (int i = 0; i < ELEMENTS_FOR_COMBINATION; ++i)
        arrayPtr[i] = i + 1;

    PrintCombination(arrayPtr, ELEMENTS_FOR_COMBINATION, DLEMENTS_FOR_CHOICE);

    if (arrayPtr != NULL)
        delete[] arrayPtr;

    return 0;
}
void PrintCombination(int *arrayPtr, int elements_for_combination, int dlements_for_choice)
{
    vector<int> print_array;
    dfs(arrayPtr, print_array, 0, 0, dlements_for_choice, elements_for_combination);
}
void dfs(int *arrayPtr, vector<int> &print_array, int now_index, int now_layers, int dlements_for_choice, int elements_for_combination)
{
    if (now_layers == dlements_for_choice)
    {
        for (int i = 0; i < dlements_for_choice; i++)
        {
            cout << print_array[i] << "\t";
        }
        cout << endl;
        return;
    }
    for (int i = now_index; i < elements_for_combination; i++)
    {
        now_layers++;
        print_array.push_back(arrayPtr[i]);
        dfs(arrayPtr, print_array, i + 1, now_layers, dlements_for_choice, elements_for_combination);
        print_array.pop_back();
        now_layers--;
    }
}
