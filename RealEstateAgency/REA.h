#pragma once
#include "Client.h"
#include<fstream>
#include<vector>

using namespace std;

class REA
{
private:
	std::vector<Client*> clients;
	std::vector<Dwelling> builds;
public:
	REA() {}
	REA(std::vector<Client*> c, std::vector<Dwelling> d) : clients(c), builds(d) {}
	std::vector<Client*> getClients() const { return this->clients; }
	std::vector<Dwelling> getBuilds() const { return this->builds; }
	Dwelling addDwelling(std::string type, double price, bool isProf);
	void addC(Client* c);

	int getPosition(std::string name);
	void removeClient(std::string name);
	std::vector<Client*> getInterestedClients(Dwelling& d);
	void writeToFile(std::string filename);
	~REA() {
		for (auto c : this->clients)
			delete c;
	}
};