#include <iostream>
#include <string>
#include "HotDogStand.h"
using namespace std;

int HotDogStand::totalSellAmount = 0; // 在處理static的variable時，需要在該headerfile.cpp那邊去告訴她初始值為多少
HotDogStand::HotDogStand(string id)
{
	standId = id;
	hotdDogSellAmount = 0;
}
HotDogStand::HotDogStand(string id, int amount)
{
	standId = id;
	hotdDogSellAmount = amount;
	totalSellAmount += amount;
}
void HotDogStand::justSold()
{
	hotdDogSellAmount++;
	totalSellAmount++;
}
void HotDogStand::print()
{
	cout << standId << " " << hotdDogSellAmount << endl;
}
int HotDogStand::thisStandSoldAmount()
{
	return hotdDogSellAmount;
}
int HotDogStand::allStandSoldAmount()
{
	return totalSellAmount;
}
