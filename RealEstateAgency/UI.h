#pragma once
#include<iostream>
#include<string>
#include "REA.h"

class UI
{
private:
	REA & rea;
public:
	UI(REA& r) :rea(r) {}
	REA& getREA() const { return this->rea; }
	void printMenu();
	void removeClient();
	void showAllClients();
	void showAllD();
	void addD();
	void saveToFile();
	void start();
	~UI() {}
};