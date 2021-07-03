#pragma once
#include <iostream>
using namespace std;
class Atoi {
public:
	Atoi();
	Atoi(string s);
	void SetString(string s);
	string GetString();
	int Length(); 
	int IsDigital();
	int StringToInteger();
private:
	string beTran;
};