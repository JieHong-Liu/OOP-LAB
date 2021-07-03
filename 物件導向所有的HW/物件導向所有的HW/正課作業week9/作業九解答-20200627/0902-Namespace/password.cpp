#pragma once
#include"password.h"

namespace {
	string password;
	bool isValid() {
		if (password.length() < 8)return false;
		for (int i = 0; i < password.length(); i++)
			if (password[i] >= 48 && password[i] <= 57)
				return true;
		return false;
	}
}

void Authenticate::inputPassword()
{
	do
	{
		cout << "Enter your password (at least 8 characters " <<
			"and at least one non-letter)" << endl;
		cin >> password;
	} while (!isValid());
}

string Authenticate::getPassword()
{
	return password;
}
