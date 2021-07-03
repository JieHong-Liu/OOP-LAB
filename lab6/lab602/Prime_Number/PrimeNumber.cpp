#include "PrimeNumber.h"
#include <iostream>
using namespace std;
PrimeNumber::PrimeNumber()
{
	this->value = 1;
}
PrimeNumber::PrimeNumber(int _value)
{
	this->value = _value;
}
int PrimeNumber::get()
{
	return this->value;
}
PrimeNumber& PrimeNumber::operator ++ () // prefix
{
	int start = this->value + 1;
	while (!is_Prime(start))
	{
		start++;
	}
	this->value = start;
	return *this;
}
PrimeNumber PrimeNumber::operator ++(int _value) // postfix
{
	PrimeNumber P = *this;
	++* this;
	return P;
}
PrimeNumber& PrimeNumber::operator --() //  prefix
{
	int start = this->value - 1;
	if (start == 1)
	{
		this->value = 1;
	}
	else
	{
		while (!is_Prime(start))
		{
			start--;
		}
		this->value = start;
	}
	return *this;
}
PrimeNumber PrimeNumber::operator --(int _value) // postfix
{
	PrimeNumber P = *this;
	--* this;
	return P;
}

int PrimeNumber::is_Prime(int st)
{
	int k = 0;
	for (int i = 2; i <= st; i++)
	{
		if (st % i == 0)
		{
			k++;
		}
	}
	if (k == 1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}