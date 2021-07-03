// Template Binary Search
// Author: hsuan-wei Liao

#include <iostream>
#include <string>

using namespace std;

template<class T>
void RecBinarySearch(const T a[], int first, int last, T key, bool& found, int& location);
// Precondition: 
// Type T must support three operators = == and >.
// a[first] through a[last] are sorted in ascending order.
// Postcondition: 
// If key is not one of the values a[first] through a[last], then found == false.
// Otherwise a[location] == key and found == true.

template<class T>
void ItrBinarySearch(const T a[], int first, int last, T key, bool& found, int& location);
// Precondition: 
// Type T must support three operators = == and >.
// a[first] through a[last] are sorted in ascending order.
// Postcondition:
// If key is not one of the values a[first] through a[last], then found == false.
// Otherwise a[location] == key and found == true.

int main()
{
	const int ARRAY_SIZE = 8;
	const int finalIndex = ARRAY_SIZE - 1;

	int count = 0;
	cin >> count;
	for (; count >= 1; count--)
	{
		int i;
		int a[] = { 15, 33, 45, 46, 49, 59, 70, 81 }; // Sample: 1, 2, 3, 4, 10, 25, 29, 100 | Answer: 15, 33, 45, 46, 49, 59, 70, 81
		// Test int
		cout << "\nArray contains:\n";
		for (i = 0; i < ARRAY_SIZE; i++)
		{
			cout << a[i] << " ";
		}
		cout << endl;
		int keyInt, location;
		bool found;
		cout << "Enter number to be located: ";
		cin >> keyInt;

		cout << "Testing Template Iterative Binary Search\n";
		ItrBinarySearch(a, 0, finalIndex, keyInt, found, location);
		if (found)
			cout << keyInt << " is in index location " << location << endl;
		else
			cout << keyInt << " is not in the array." << endl;


		cout << "Testing Template Recursive Binary Search\n";
		RecBinarySearch(a, 0, finalIndex, keyInt, found, location);
		if (found)
			cout << keyInt << " is in index location " << location << endl;
		else
			cout << keyInt << " is not in the array." << endl;

		// Test string
		string b[] = { "aaa", "abc", "ahh", "bde", "bee", "ccc", "feg", "hee" }; // Sample: "aa", "ab", "ah", "bd", "be", "cc", "fe", "zk" | Answer: "aaa", "abc", "ahh", "bde", "bee", "ccc", "feg", "hee"
		string keyString;
		cout << "\nArray contains:\n";
		for (i = 0; i < ARRAY_SIZE; i++)
		{
			cout << b[i] << " ";
		}
		cout << endl;
		cout << "Enter number to be located: ";
		cin >> keyString;

		cout << "Testing Template Iterative Binary Search\n";
		ItrBinarySearch(b, 0, finalIndex, keyString, found, location);
		if (found)
			cout << keyString << " is in index location " << location << endl;
		else
			cout << keyString << " is not in the array." << endl;


		cout << "Testing Template Recursive Binary Search\n";
		RecBinarySearch(b, 0, finalIndex, keyString, found, location);
		if (found)
			cout << keyString << " is in index location " << location << endl;
		else
			cout << keyString << " is not in the array." << endl;

		// Test double
		double c[] = { 3.3 , 6.6 , 8.8 , 9.9 , 11.1 , 15.1 , 16.1 , 20.2 }; // Sample: 0.3 , 5.6 , 7.8 , 10.9 , 123.5 , 150.1 , 197.1 , 2019.2 | Answer: 3.3 , 6.6 , 8.8 , 9.9 , 11.1 , 15.1 , 16.1 , 20.2
		double keyDouble;
		cout << "\nArray contains:\n";
		for (i = 0; i < ARRAY_SIZE; i++)
		{
			cout << c[i] << " ";
		}
		cout << endl;
		cout << "Enter number to be located: ";
		cin >> keyDouble;

		cout << "Testing Template Iterative Binary Search\n";
		ItrBinarySearch(c, 0, finalIndex, keyDouble, found, location);
		if (found)
			cout << keyDouble << " is in index location " << location << endl;
		else
			cout << keyDouble << " is not in the array." << endl;


		cout << "Testing Template Recursive Binary Search\n";
		RecBinarySearch(c, 0, finalIndex, keyDouble, found, location);
		if (found)
			cout << keyDouble << " is in index location " << location << endl;
		else
			cout << keyDouble << " is not in the array." << endl;
	}
	system("pause");
	return 0;
}

template<class T>
void RecBinarySearch(const T a[], int first, int last, T key, bool& found, int& location)
{
	int mid;
	if (first > last)
	{
		found = false;
	}
	else
	{
		mid = (first + last) / 2;
		if (key == a[mid])     // T must support ==
		{
			found = true;
			location = mid;
		}
		else if (a[mid] > key) // T must support >
		{
			RecBinarySearch(a, first, mid - 1, key, found, location);
		}
		else if (key > a[mid])   // Changed to avoid requiring >
		{
			RecBinarySearch(a, mid + 1, last, key, found, location);
		}
	}
}

template<class T>
void ItrBinarySearch(const T a[], int first, int low, T key, bool& found, int& location)
{
	int mid;
	found = false;
	while ((first <= low) && !found)
	{
		mid = (first + low) / 2;

		if (key == a[mid]) // T must support ==
		{
			found = true;
			location = mid;
		}
		else if (a[mid] > key) // T must support >
		{
			low = mid - 1;
		}
		else if (key > a[mid])  // Changed to avoid requiring >
		{
			first = mid + 1;
		}
	}
}
