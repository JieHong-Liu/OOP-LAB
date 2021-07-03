#pragma once
class PrimeNumber {
public:
	PrimeNumber();
	PrimeNumber(int _value);
	int get();
	PrimeNumber& operator ++ ();
	PrimeNumber operator ++(int); // postfix
	PrimeNumber& operator --();
	PrimeNumber operator --(int);
private:
	int value;
	int is_Prime(int st);
};