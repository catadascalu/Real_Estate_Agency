#include "REA.h"

Dwelling REA::addDwelling(std::string type, double price, bool isProf)
{
	Dwelling d = Dwelling(type, price, isProf);
	this->builds.push_back(d);
	std::vector<Client*> interested = this->getInterestedClients(d);
	for (auto c : interested)
	{
		std::string str = c->toString();
		cout << str << endl;
	}
	return d;
}

void REA::addC(Client * c)
{
	this->clients.push_back(c);
}

int REA::getPosition(std::string name)
{
	for (int i = 0; i < this->clients.size(); i++)
	{
		if (name == this->clients.at(i)->getName())
		{
			return i;
		}
	}
}

void REA::removeClient(std::string name)
{
	int pos = this->getPosition(name);
	this->clients.erase(this->clients.begin() + pos);
}

std::vector<Client*> REA::getInterestedClients(Dwelling & d)
{
	std::vector<Client*> interested;
	if (this->clients.size() == 0)
		return interested;
	for (auto c : this->clients)
	{
		if (c->isInterested(d))
		{
			interested.push_back(c);
		}
	}
	return interested;
}

void REA::writeToFile(std::string filename)
{
	ofstream file(filename);
	if (file.is_open())
	{
		for (auto c : this->clients)
		{
			file << c<<endl;
		}
	}
}
