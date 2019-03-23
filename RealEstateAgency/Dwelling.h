#pragma once
#include<string>

class Dwelling
{
private:
	std::string type;
	double price;
	bool isProfitable;
public:
	Dwelling(std::string t, double p, bool s) : type(t), price(p), isProfitable(s) {}
	std::string getType() const { return this->type; }
	double getPrice() const { return this->price; }
	bool getStatus() const { return this->isProfitable; }
	double normalBankRate();
	double largeBankRate();
	std::string toString();
	~Dwelling() {}
};