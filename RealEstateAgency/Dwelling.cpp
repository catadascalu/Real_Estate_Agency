#include "Dwelling.h"

double Dwelling::normalBankRate()
{
	double rate;
	rate = this->price / 1000;
	return rate;
}

double Dwelling::largeBankRate()
{
	double rate;
	rate = this->price / 100;
	return rate;
}

std::string Dwelling::toString()
{
	std::string status;
	if (this->isProfitable == false)
		status = "not profitable";
	else
		status = "profitable";
	std::string str;
	str = "Building type: " + this->type + " Price: " + std::to_string(this->price) + " Status: " + status;
	return str;
}
