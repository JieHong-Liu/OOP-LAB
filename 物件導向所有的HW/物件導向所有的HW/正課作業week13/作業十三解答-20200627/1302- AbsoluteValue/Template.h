#pragma once
#include <iostream>

template <class T>
T absoluteValue(const T&v1, const T&v2) {
	return abs(v1 - v2);
}

//�ѨM�r���۴�
int absoluteValue(const char&v1, const char&v2) {
	return abs(v1 - v2);
}
