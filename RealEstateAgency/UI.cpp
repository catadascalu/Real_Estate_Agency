#include "UI.h"
#include<Windows.h>
#include<shellapi.h>

void UI::printMenu()
{
	cout << "1 - remove a client\n";
	cout << "2 - show all clients\n";
	cout << "3 - show all dwellings\n";
	cout << "4 - add a dwelling\n";
	cout << "5 - save clients to a file\n";
	cout << "0 - exit\n";
	
}

void UI::removeClient()
{
	std::string name;
	cout << "Give name: ";
	cin >> name;
	cin.ignore();

	this->rea.removeClient(name);
}

void UI::showAllClients()
{
	if (this->rea.getClients().size() == 0)
	{
		cout << "Empty repo. " << endl;
		return;
	}

	for (auto c : this->rea.getClients())
	{
		std::string str = c->toString();
		cout << str << endl;
	}
}

void UI::showAllD()
{
	if (this->rea.getBuilds().size() == 0)
	{
		cout << "Empty repo. " << endl;
		return;
	}
	for (auto d : this->rea.getBuilds())
	{
		std::string str = d.toString();
		cout << str << endl;
	}
}

void UI::addD()
{
	std::string type;
	double price;
	std::string status;
	cout << "Enter type: ";
	cin >> type;
	cin.ignore();
	cout << "Enter price: ";
	cin >> price;
	cin.ignore();
	cout << "Is it profitable?" << endl;
	cin >> status;
	cin.ignore();
	if (status == "yes")
		this->rea.addDwelling(type, price, true);
	else
		this->rea.addDwelling(type, price, false);
}

void UI::saveToFile()
{
	this->rea.writeToFile("C:/Users/catad/source/repos/PracticalTest2/clients.txt");
	ShellExecuteA(NULL, "open", "C:/Users/catad/source/repos/PracticalTest2/clients.txt", NULL, NULL, SW_SHOWMAXIMIZED);
}

void UI::start()
{
	this->printMenu();
	int command;
	while (1)
	{
		cout << "Enter command: ";
		cin >> command;
		cin.ignore();
		if (command == 1)
		{
			this->removeClient();
		}
		else if (command == 2)
		{
			this->showAllClients();
		}
		else if (command == 3)
		{
			this->showAllD();
		}
		else if (command == 4)
		{
			this->addD();
		}
		else if (command == 5)
		{
			this->saveToFile();
		}
		else if (command == 0)
			break;
		else
			cout << "Invalid input. " << endl;
	}
}
