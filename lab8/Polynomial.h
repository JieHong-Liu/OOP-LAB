#pragma once
class Polynomial
{
public:
    // constuctor
    Polynomial();
    Polynomial(double *param, int size);
    // copy constructor
    Polynomial(const Polynomial &poly);
    // destructor
    ~Polynomial();
    int mySize();
    friend const Polynomial operator+(const Polynomial &poly1, const Polynomial &poly2);
    friend const Polynomial operator+(const Polynomial &poly1, double c);
    friend const Polynomial operator+(double c, const Polynomial &poly1);
    friend const Polynomial operator-(const Polynomial &poly1, const Polynomial &poly2);
    friend const Polynomial operator*(const Polynomial &poly1, const Polynomial &poly2);
    friend const Polynomial operator*(double c, const Polynomial &poly1);

    Polynomial &operator=(const Polynomial &poly1);
    friend double evaluate(const Polynomial &poly, const double &var);
    double &operator[](int index);

private:
    double *parameter;
    int size;
};
