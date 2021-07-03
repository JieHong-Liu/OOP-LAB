#include "Template.h"
#include <iostream>
using namespace std;

int main()
{
	int i1, i2;
	double d1, d2;
	float f1, f2;
	char c1, c2;
	i1 = 10; i2 = 20;
	cout << "Absolute value of 10 - 20 is " << absoluteValue(i1, i2) << endl;

	d1 = 5.5; d2 = 3.1;
	cout << "Absolute value of 5.5 - 3.1 is " << absoluteValue(d1, d2) << endl;

	f1 = 1.1; f2 = 2.2;
	cout << "Absolute value of 1.1 - 2.2 is " << absoluteValue(f1, f2) << endl;

	c1 = 'A', c2 = 'C';
	cout << "Absolute value of A - C is " << absoluteValue(c1, c2) << endl;
	return 0;
}

/**
 *output : 
 *Absolute value of 10 - 20 is 10
 *Absolute value of 5.5 - 3.1 is 2.4
 *Absolute value of 1.1 - 2.2 is 1.1
 *Absolute value of A - C is 2
 */