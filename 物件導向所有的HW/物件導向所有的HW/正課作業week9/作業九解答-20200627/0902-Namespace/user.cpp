#include"user.h"

namespace {
	string username;
	bool isValid() {
		if (username.length() != 8)return false;
		for (int i = 0; i < 8; i++)
			if (!isalpha(username[i]))
				return false;
		return true;
	}
}

void Authenticate::inputUserName() {
	do {
		cout << "Enter your username (8 letters only)" << endl;
		cin >> username;
	} while (!isValid());
}

string Authenticate::getUserName() {
	return username;
}
