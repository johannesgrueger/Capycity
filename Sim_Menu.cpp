#include "Sim_Menu.h"
#include <iostream>
using namespace std; 
using namespace Sim_Capycity;

Sim_Menu::Sim_Menu(int initLength, int initWidth)
{
	blueprintList.emplace_back(Blueprint("initBlueprint", initLength, initWidth));

}

Sim_Menu::~Sim_Menu()
{
}

bool Sim_Menu::printMenu() {
	int menuInput;
	cout << "#########" << endl << "1: create new Blueprint" << endl << "2: choose Blueprint" <<endl << "3: print all Blueprints" << endl << "4: end program" << endl << "#########" << endl;
	cin >> menuInput;
	cout << endl;

	switch (menuInput) {
	case 1: createNewBlueprint(); break;
	case 2: chooseBlueprint(); break;
	case 3: printAllBlueprints(); break;
	case 4: cout << "shutdown..." << endl; return false;
	default: cout << "invalid input, try again!" << endl; break;
	}
	return true;
}

void Sim_Menu::createNewBlueprint() {
	int length;
	int width;
	string name;
	cout << "Type in name of new Blueprint: " << endl;
	cin >> name;
	cout << "Type in length of new Blueprint: " << endl;
	cin >> length;
	cout << "Type in width of new Blueprint: " << endl;
	cin >> width;
	blueprintList.emplace_back(Blueprint(name, length, width));
}

void Sim_Menu::chooseBlueprint() {
	sortBlueprintList();
	cout << "all available Blueprints: " << endl;
	string tempString;
	float tempFloat = 0.0f;
	for(Blueprint b : blueprintList)
	{
		tempString = b.getName();
		tempFloat = b.calculateEfficiency();
		cout << "Blueprint 1: " << tempString << ", Efficiency K: " << tempFloat << endl;
	}
	int inputBlueprintNumber;
	cout << "Type in Blueprint-Number:" << endl;
	cin >> inputBlueprintNumber;
	lastCalledBlueprintID = blueprintList.at(inputBlueprintNumber - 1).id;

	bool running = true;
	while (running) {
		running = printBlueprintMenu(blueprintList.at(inputBlueprintNumber));
	}
}

void Sim_Menu::printAllBlueprints() {
	sortBlueprintList();
	for (vector<Blueprint>::iterator i = blueprintList.begin(); i != blueprintList.end(); i++)
	{
		cout << "- _ - _ - _ - _ - _ - _ - _ - _" << endl;
		cout << i->getName() << endl;
		i->printBuildingPlan();
	}
	cout << "- _ - _ - _ - _ - _ - _ - _ - _" << endl;
	cout << endl << endl;
}


void Sim_Menu::sortBlueprintList() {
	auto sortBlueprintLambda = [](Blueprint b1, Blueprint b2) {return (b1.calculateEfficiency() < b2.calculateEfficiency()); };
	
	std::sort(blueprintList.begin(), blueprintList.end(), sortBlueprintLambda);

	/*Blueprint tempB = Blueprint("temp", 1, 1);
	for (size_t i = 0; i < blueprintList.size(); i++)
	{
		for (size_t j = 0; j < blueprintList.size() - 1; j++) {
			if (blueprintList.at(j).calculateEfficiency() > blueprintList.at(j + 1).calculateEfficiency()) {
				tempB = blueprintList.at(j);
				blueprintList.at(j) = blueprintList.at(j + 1);
				blueprintList.at(j + 1) = tempB;
			}
		}
	}*/
}

bool Sim_Menu::checkEquality() {
	
	bool equal = false;
	int input;
	bool deleteB = false;
	for (vector<Blueprint>::iterator i = blueprintList.begin(); i != blueprintList.end(); i++)
	{
		for (vector<Blueprint>::iterator j = i+1; j != blueprintList.end(); j++)
		{
			if (i->isEqualTo(*j)) {
				equal = true;
				if (equal) {
					int retry = false;
					do {
						cout << "Your Blueprint is equal to one that's already existing. It will be deleted" << endl << "Proceed? (0: yes, 1: no)" << endl;
						cin >> input;
						switch (input) {
						case 0: deleteB = true; break;
						case 1: deleteB = false; break;
						default: retry = true; cout << "invalid input, retry" << endl;
						}
						break;
					} while (retry);
				}
				if (equal)
					break;
			}
			if (equal)
				break;
		}
		if (equal)
			break;

	}

	return deleteB;

}

bool Sim_Menu::printBlueprintMenu(Blueprint& area)
{
	cout << "*********" << endl << "1: set new Building" << endl << "2: delete Area" << endl << "3: print BuildingArea" << endl << "4: leave Blueprint " << area.getName() << endl << "*********" << endl;
	cin >> input;
	cout << endl;

	switch (input) {
	case 1: area.newBuilding(); break;
	case 2: area.deleteArea(); break;
	case 3: area.printBuildingPlan(); break;
	case 4: if (checkEquality()) {
			for (vector<Blueprint>::iterator i = blueprintList.begin(); i != blueprintList.end(); i++)
			{
				if (i->id == lastCalledBlueprintID) {
					blueprintList.erase(i);
					cout << ">> deleted" << endl << endl;
				}
			}
				cout << "leaving ..." << endl; return false;
			}
	default: cout << "invalid input, try again!" << endl; break;
	}
	return true;
}
