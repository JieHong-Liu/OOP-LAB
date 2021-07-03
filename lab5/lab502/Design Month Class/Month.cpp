#include<iostream>
#include"Month.h"
// for constuctor
char month_list[12][4] =
{
	"Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec"
};
Month::Month()
{
	month = 1;
}
Month::Month(char first, char second, char third)
{
	month = 1;
	for (int i = 0; i < 12; i++)
	{
		if (first == month_list[i][0] && (second == month_list[i][1]) && (third == month_list[i][2]))
		{
			month = i + 1;
			break;
		}
	}
}
Month::Month(int monthInt)
{
	if (monthInt > 12 || monthInt < 1)
	{
		month = 1;
	}
	else
	{
		month = monthInt;
	}
}
// member functions
void Month::inputInt()
{
	std::cin >> month;
}
void Month::inputStr()
{
	char first, second, third;
	std::cin >> first >> second >> third;
	// find the month
	for (int i = 0; i < 12; i++)
	{
		if (first == month_list[i][0] && (second == month_list[i][1]) && (third == month_list[i][2]))
		{
			month = i + 1;
			break;
		}
	}
}
void Month::outputStr()
{
	std::cout << month_list[month - 1] ;
}
void Month::outputInt()
{
	std::cout << month ;
}
Month Month::nextMonth()
{
	return Month(month + 1);
}