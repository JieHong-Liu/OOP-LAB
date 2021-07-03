#pragma once
using namespace std;
class HotDogStand 
{
public:
	// there are two constructor of this class
	HotDogStand(string id);
	HotDogStand(string id, int amount);
	void justSold();
	void print();
	int thisStandSoldAmount();
	static int allStandSoldAmount(); // for returning the static function
private:
	string standId;
	int hotdDogSellAmount;
	static int totalSellAmount ;
};
