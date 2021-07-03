#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <math.h>
#include <string>
#include "Complex.h"
using namespace std;

Complex::Complex()
{
	this->realValue = 0;
	this->imaginaryValue = 0;
}
Complex::Complex(double r)
{
	this->realValue = r;
	this->imaginaryValue = 0;
}
Complex::Complex(double r, double i)
{
	this->realValue = r;
	this->imaginaryValue = i;
}

double Complex::real()
{
	return this->realValue;
}
double Complex::imag()
{
	return this->imaginaryValue;
}
double Complex::norm()
{
	return sqrt(this->realValue * this->realValue + this->imaginaryValue * this->imaginaryValue);
}
double real(Complex c)
{
	return c.realValue;
}
double imag(Complex c)
{
	return c.imaginaryValue;
}
double norm(Complex c)
{
	return sqrt(c.realValue * c.realValue + c.imaginaryValue * c.imaginaryValue);
}
bool operator == (const Complex& c1, const Complex& c2)
{
	if (c1.realValue == c2.realValue && c1.imaginaryValue == c2.imaginaryValue)
	{
		return true;
	}
	else
	{
		return false;
	}
}
const Complex operator + (const Complex& c1, const Complex& c2)
{
	double allReal = c1.realValue + c2.realValue;
	double allimag = c1.imaginaryValue + c2.imaginaryValue;
	Complex c(allReal, allimag);
	return c;
}
const Complex operator + (const Complex& c1, double c2)
{
	double allReal = c1.realValue + c2;
	Complex c(allReal, c1.imaginaryValue);
	return c;
}
const Complex operator - (const Complex& c1, const Complex& c2)
{
	double allReal = c1.realValue - c2.realValue;
	double allimag = c1.imaginaryValue - c2.imaginaryValue;
	Complex c(allReal, allimag);
	return c;
}
const Complex operator - (const Complex& c1, double c2)
{
	double allReal = c1.realValue - c2;
	Complex c(allReal, c1.imaginaryValue);
	return c;
}
const Complex operator * (const Complex& c1, const Complex& c2)
{
	double allReal = c1.realValue * c2.realValue - c1.imaginaryValue * c2.imaginaryValue;
	double allimag = c1.imaginaryValue*c2.realValue +  c2.imaginaryValue * c1.realValue;
	Complex c(allReal, allimag);
	return c;
}
const Complex operator * (const Complex& c1, double c2)
{
	Complex c(c1.realValue*c2, c1.imaginaryValue*c2);
	return c;
}
const Complex operator / (const Complex& c1, const Complex& c2)
{
	Complex c;
	if (c2.realValue != 0 || c2.imaginaryValue != 0)
	{
		double mom = c2.realValue * c2.realValue + c2.imaginaryValue * c2.imaginaryValue;
		Complex c3 = c2;
		c3.imaginaryValue = -1 * c2.imaginaryValue;
		c = c1 * c3;
		Complex c4(c.realValue / mom, c.imaginaryValue / mom);
		return  c4;
	}
	else
	{
		return c;
	}
}
istream& operator >> (istream& inputStream, Complex& c)
{
	char text[100] = {};
	char str_for_c[10];
	inputStream >> text >> text >> c.realValue >> text >> text ; // a = b + c*i;
	c.imaginaryValue = atof(strncpy(str_for_c,text,strlen(text)-2));
	return inputStream;	
}
ostream& operator<<(ostream& strm, const Complex& c) {
	return strm << c.realValue << " + " << c.imaginaryValue << "*i" << "\n";
} 