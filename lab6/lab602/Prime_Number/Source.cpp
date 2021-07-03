#include <iostream>
#include "PrimeNumber.h"
using namespace std;
int main()
{
	PrimeNumber p1, p2(13),p3(19),p4(19);
	PrimeNumber a = ++p1;
	PrimeNumber b = p2++;
	PrimeNumber c = --p3;
	PrimeNumber d = p4--;
	cout << a.get() << endl;
	cout << p1.get() << endl;

	cout << b.get() << endl;
	cout << p2.get() << endl;

	cout << c.get() << endl;
	cout << p3.get() << endl;

	cout << d.get() << endl;
	cout << p4.get() << endl;
	return 0;
}
