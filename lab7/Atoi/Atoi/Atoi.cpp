#include "Atoi.h"
#include <math.h>
Atoi::Atoi()
{
	this->beTran = "";
}
Atoi::Atoi(string s)
{
	this->beTran = s;
}
void Atoi::SetString(string s)
{
	this->beTran = s;
}
string Atoi::GetString()
{
	return this->beTran;
}
int Atoi::Length()
{
	if(this->beTran.at(0) == '-')
	{
		return this->beTran.length() - 1 ;
	}
	else
	{
		return this->beTran.length();
	}
}
int Atoi::IsDigital()
{
	if (this->beTran.at(0) != '-')
	{
		for (int i = 0; i < this->beTran.length(); i++)
		{
			if ((this->beTran).at(i) < '0' || (this->beTran).at(i) > '9')
			{
				return 0;
			}
		}
		return 1;
	}
	else
	{
		for (int i = 1; i < this->beTran.length(); i++)
		{
			if ((this->beTran).at(i) < '0' || (this->beTran).at(i) > '9')
			{
				cout << "the char this->beTran.at(" << i << ") = "<< this->beTran.at(i) << "is invalid" << endl;
				return 0;
			}
		}
		return 1;
	}

}
int Atoi::StringToInteger()
{
	int ans = 0;
	bool negative = false;
	if (this->beTran.at(0) == '-')
	{
		negative = true;
	}
	else
	{
		negative = false;
	}
	//cout << "The num is " << negative << endl;
	if (negative == true)
	{
		string newstr = this->beTran.substr(1, (this->beTran.length() - 1)); // 從index = 1開始複製到結束
		this->beTran = newstr;
	}
	//delete 0 
	while (this->beTran.at(0) == '0')
	{
		string newstr = this->beTran.substr(1,(this->beTran.length()-1)); // 從index = 1開始複製到結束
		this->beTran = newstr;
	}

	// 520 = 5 * 10 ^ 2 + 2 * 10 ^ 1 + 0 * 10 ^ 0
	for (int i = 0; i < this->beTran.length(); i++)
	{
		ans = ans + (this->beTran.at(i) - '0') * pow(10.0, (this->beTran.length() - 1 - i)); // - '0'是從ascii轉成int
	}
	//cout << "The returning ans is " << ans << endl;
	if (negative == true)
	{
		return ans * -1;
	}
	else
	{
		return ans;
	}
}
