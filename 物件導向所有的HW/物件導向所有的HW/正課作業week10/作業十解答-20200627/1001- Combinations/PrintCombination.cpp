#include "PrintCombination.h"

void PrintCombination(int* arrayPtr, const int& m, const int& n)
{
	int* subset = new int[n] {0};
	Combination(arrayPtr, subset, 0, 0, m, n);
	if (subset != NULL) delete[] subset;
}

void Combination(const int set[], int subset[], const int& index, const int& size, const int& m, const int& n)
{
	if (size == n) // base case
		Print(subset, n);
	else
	{
		if (index >= m) return; // base case
		subset[size] = set[index];
		Combination(set, subset, index + 1, size + 1, m, n);
		Combination(set, subset, index + 1, size, m, n);
	}
}

void Print(int ary[], const unsigned int& size)
{
	for (unsigned int i = 0; i < size; ++i)
		cout << ary[i] << " ";
	cout << endl;
}