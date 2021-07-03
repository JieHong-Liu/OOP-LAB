#pragma once
using namespace std;
class Complex 
{
public:
	Complex();
	Complex(double r);
	Complex(double r, double i);

	double real();
	double imag();
	double norm();
	friend double real(Complex c);
	friend double imag(Complex c);
	friend double norm(Complex c);
	friend bool operator == (const Complex& c1, const Complex& c2);
	friend const Complex operator + (const Complex& c1, const Complex& c2);
	friend const Complex operator + (const Complex& c1, double c2);
	friend const Complex operator - (const Complex& c1, const Complex& c2);
	friend const Complex operator - (const Complex& c1, double c2);
	friend const Complex operator * (const Complex& c1, const Complex& c2);
	friend const Complex operator * (const Complex& c1, double c2);
	friend const Complex operator / (const Complex& c1, const Complex& c2);
	friend istream& operator >> (istream& inputStream, Complex& c);
	friend ostream& operator<<(ostream& outputSteam, const Complex& c);

private:
	double realValue;
	double imaginaryValue;
};