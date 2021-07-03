#pragma once

class Month {
public:
	// for constuctor
	Month();
	Month(char first, char second, char third);
	Month(int monthInt);
	// member functions
	void inputInt();
	void inputStr();
	void outputStr();
	void outputInt();
	Month nextMonth();
private:
	int month;
};