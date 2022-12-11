#include "Sim_Menu.h"
#include <iostream>
using namespace std; 
using namespace Sim_Capycity;

Sim_Menu::Sim_Menu()
{
}

Sim_Menu::~Sim_Menu()
{
}

bool Sim_Menu::printMenu(Sim_BuildingArea& area)
{
	cout << "*********" << endl << "1: set new Building" << endl << "2: delete Area" << endl << "3: print BuildingArea" << endl << "4: end Program" << endl << "*********" << endl;
	cin >> input;
	cout << endl;

	switch (input) {
	case 1: area.newBuilding(); break;
	case 2: area.deleteArea(); break;
	case 3: area.printBuildingPlan(); break;
	case 4: cout << "shutdown..." << endl; return false;
	default: cout << "invalid input, try again!" << endl; break;
	}
	return true;
}
