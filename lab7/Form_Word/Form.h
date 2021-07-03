#pragma once
#include <iostream>
using namespace std;
class Form {
	void SetInputWord(string inputWord);
	void ProcessInputWord();
	void SetFileName(string fileName);
	void Load_CompareWord();
	void PrintFoundWords();
private:
	string word;
};