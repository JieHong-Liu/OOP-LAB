#include "Polynomial.h"
#include <iostream>
#include <math.h>
using namespace std;

// constructor
Polynomial::Polynomial()
{
    this->parameter = new double{0};
    this->size = 1; // maxterm+1
}
Polynomial::Polynomial(double *param, int size)
{
    double *parame = new double[size];
    this->parameter = parame;
    for (int i = 0; i < size; i++)
    {
        this->parameter[i] = param[i];
    }
    this->size = size;
}

//copy constructor
Polynomial::Polynomial(const Polynomial &poly1)
{
    this->size = poly1.size;
    double *parame = new double[poly1.size];
    this->parameter = parame;
    for (int i = 0; i < poly1.size; i++)
    {
        this->parameter[i] = poly1.parameter[i];
    }
}

// destructor
Polynomial::~Polynomial()
{
    delete[] this->parameter;
}

int Polynomial::mySize()
{
    return this->size;
}

Polynomial &Polynomial::operator=(const Polynomial &poly1)
{
    if (this == &poly1) // �p�G�L�̬O���V�P�˪���m
    {
        return *this;
    }
    else
    {
        //delete[] this->parameter;
        double *parame = new double[poly1.size];
        this->parameter = parame;
        for (int i = 0; i < poly1.size; i++)
        {
            this->parameter[i] = poly1.parameter[i];
        }
        this->size = poly1.size;
        return *this;
    }
}

const Polynomial operator+(const Polynomial &poly1, const Polynomial &poly2)
{
    Polynomial poly;
    int tmp_size, smaller_size = 0;
    if (poly1.size > poly2.size)
    {
        tmp_size = poly1.size;
        smaller_size = poly2.size;
        poly.parameter = new double[tmp_size];
        for (int i = 0; i < tmp_size; i++)
        {
            poly.parameter[i] = poly1.parameter[i];
        }
    }
    else
    {
        tmp_size = poly2.size;
        smaller_size = poly1.size;
        poly.parameter = new double[tmp_size];

        for (int i = 0; i < tmp_size; i++)
        {
            poly.parameter[i] = poly2.parameter[i];
        }
    }
    poly.size = tmp_size;
    for (int i = 0; i < smaller_size; i++)
    {
        poly.parameter[i] = poly1.parameter[i] + poly2.parameter[i];
    }
    // check the add polynomial
    for (int i = 0; i < tmp_size; i++)
    {
        cout << poly.parameter[i] << "\t";
    }
    cout << endl;
    return poly;
}

const Polynomial operator+(const Polynomial &poly1, double c)
{
    Polynomial poly = poly1;
    poly.parameter[0] = poly1.parameter[0] + c;
    return poly;
}

const Polynomial operator+(double c, const Polynomial &poly1)
{
    Polynomial poly = poly1;
    poly.parameter[0] = poly1.parameter[0] + c;
    return poly;
}

double &Polynomial::operator[](int index)
{
    return this->parameter[index];
}

const Polynomial operator-(const Polynomial &poly1, const Polynomial &poly2)
{
    Polynomial poly;
    int tmp_size, smaller_size;
    if (poly1.size > poly2.size)
    {
        tmp_size = poly1.size;
        smaller_size = poly2.size;
        poly.parameter = new double[tmp_size];
        for (int i = 0; i < tmp_size; i++)
        {
            poly.parameter[i] = poly1.parameter[i];
        }
    }
    else
    {
        tmp_size = poly2.size;
        smaller_size = poly1.size;
        poly.parameter = new double[tmp_size];

        for (int i = 0; i < tmp_size; i++)
        {
            poly.parameter[i] = poly2.parameter[i];
        }
    }
    poly.size = tmp_size;
    for (int i = 0; i < tmp_size; i++)
    {
        poly.parameter[i] = poly1.parameter[i] - poly2.parameter[i];
    }

    return poly;
}
const Polynomial operator*(const Polynomial &poly1, const Polynomial &poly2)
{
    Polynomial poly;
    int total_size = poly1.size + poly2.size - 1;
    poly.size = total_size;

    poly.parameter = new double[total_size];
    for (int i = 0; i < poly.size; i++)
    {
        poly.parameter[i] = 0;
    }

    for (int j = 0; j < poly2.size; j++)
    {
        for (int k = 0; k < poly1.size; k++)
        {
            poly.parameter[j + k] += poly2.parameter[j] * poly1.parameter[k];
        }
        for (int l = 0; l < poly.size; l++)
        {
            cout << poly.parameter[l] << "\t";
        }
    }
    return poly;
}

const Polynomial operator*(double c, const Polynomial &poly1)
{
    Polynomial poly = poly1;
    for (int i = 0; i < poly.size; i++)
    {
        poly.parameter[i] *= c;
    }
    return poly;
}

double evaluate(const Polynomial &poly, const double &var)
{
    double ans = 0;
    for (int i = 0; i < poly.size; i++)
    {
        ans += pow(var, i) * poly.parameter[i];
    }
    return ans;
}
