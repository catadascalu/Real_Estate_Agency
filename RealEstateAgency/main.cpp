#include<iostream>
#include<string>
#include<crtdbg.h>
#include "UI.h"

using namespace std;

int main()
{
	{
	REA rea = REA();
	UI ui = UI(rea);
	Client* c1 = new NormalClient("John", 1700);
	Client* c2 = new NormalClient("Anna", 1800);
	Client* c3 = new WealthyClient("Clarice", 2000, 1500);
	Client* c4 = new WealthyClient("Don", 2300, 2000);
	ui.getREA().addC(c1);
	ui.getREA().addC(c2);
	ui.getREA().addC(c3);
	ui.getREA().addC(c4);
	ui.start();
}
	_CrtDumpMemoryLeaks();
	return 0;
}