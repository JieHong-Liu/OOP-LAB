#include <iostream>
#include "Point.h"
#include <math.h>
Point::Point() // Constructor
{
	vertical = 0;
	horizontal = 0;
}
void Point::Set(int v, int h)
{
	vertical = v;
	horizontal = h;
}
void Point::Move(int x, int y)
{
	vertical = vertical + x;
	horizontal = horizontal + y;
}
void Point::Rotate()
{
	int tmp = vertical;
	vertical = horizontal;
	horizontal = -1 * tmp;
}
int Point::RetrieveVertical()
{
	return vertical;
}
int Point::RetrieveHorizontal()
{
	return horizontal;
}
