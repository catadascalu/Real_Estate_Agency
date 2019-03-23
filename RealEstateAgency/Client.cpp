#include "Client.h"

double Client::totalIncome()
{
	return this->salary;
}

std::string Client::toString()
{
	std::string str;
	str = str + "Client " + this->name + " Salary: " + std::to_string(this->salary) + " Income: " + std::to_string(this->totalIncome());
	return str;
}

double WealthyClient::totalIncome()
{
	double income;
	income = this->salary + this->moneyFromInvestments;
	return income;
}

std::string WealthyClient::toString()
{
	std::string str;
	str = str + "Wealthy client " + this->name + " Salary: " + std::to_string(this->salary) + " Income: " + std::to_string(this->totalIncome()) + " Extra money: " + std::to_string(this->moneyFromInvestments);
	return str;
}

bool WealthyClient::isInterested(Dwelling & d)
{
	double rate = d.largeBankRate();
	if (rate <= this->totalIncome() && d.getStatus() == true)
		return true;
	return false;
}

bool NormalClient::isInterested(Dwelling & d)
{
	double rate = d.normalBankRate();
	if (rate <= this->totalIncome())
		return true;
	return false;
}

std::ostream & operator<<(std::ostream & os, Client * c)
{
	std::string client = c->toString();
	os << client;
	return os;
}
