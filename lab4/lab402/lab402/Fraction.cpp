#include <iostream>
#include <iomanip>
#include "Fraction.h"
using namespace std;

void Fraction::setNumerator(int num) 
{
	numerator = num;
}

void Fraction::setDenominator(int den)
{
	denominator = den;
}

void Fraction::getDouble()
{
	cout << setprecision(6) << fixed << (double)numerator / (double)denominator << endl;
}

void Fraction::outputReducedFraction()
{
	int smaller;
	if (numerator > denominator)
	{
		smaller = denominator;
	}
	else
	{
		smaller = numerator;
	}
	// find it's GCD
	int gcd = 1;
	for (int i = 1; i <= smaller; i++)
	{
		if (numerator % i == 0 && denominator % i == 0)
		{
			gcd = i;
		}
	}
	numerator = numerator / gcd;
	denominator = denominator / gcd;
	if (denominator == 1)
	{
		cout << numerator << endl;
	}
	else
	{
		cout << numerator << '/' << denominator << endl;
	}
}