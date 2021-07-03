#pragma once
class Fraction {
public:

	void setNumerator(int num);
	void setDenominator(int den);
	void getDouble();
	void outputReducedFraction();
private:
	int numerator;
	int denominator;
};