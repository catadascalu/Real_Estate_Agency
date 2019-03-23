#pragma once
#include<iostream>
#include<string>
#include "Dwelling.h"

using namespace std;

class Client
{
protected:
	std::string name;
	double salary;
public:
	Client(std::string n, double s) : name(n), salary(s) {}
	std::string getName() const { return this->name; }
	virtual double totalIncome();
	virtual std::string toString();
	virtual bool isInterested(Dwelling& d) = 0;
	friend std::ostream& operator<<(std::ostream& os, Client* c);
	virtual ~Client() {}
};

class NormalClient : public Client
{
public:
	NormalClient(std::string n, double s) :Client(n, s) {}
	bool isInterested(Dwelling& d);
};

class WealthyClient :public Client
{
private:
	double moneyFromInvestments;
public:
	WealthyClient(std::string n, double s, double m) : Client(n, s), moneyFromInvestments(m) {}
	double totalIncome() override;
	std::string toString() override;
	bool isInterested(Dwelling& d);
};