#include <iostream>
#include <string>
#include "HotDogStand.h"
using namespace std;

int HotDogStand::totalSellAmount = 0; // �b�B�zstatic��variable�ɡA�ݭn�b��headerfile.cpp����h�i�D�o��l�Ȭ��h��
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
