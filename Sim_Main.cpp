#include <iostream>
#include <cstdlib>
#include "Sim_BuildingArea.h"
#include "Sim_Menu.h"
using namespace std;
using namespace Sim_Capycity;

int main(int argc, char* argv[]) {
	int arg1 = strtol(argv[1], nullptr, 10);
	int arg2 = strtol(argv[2], nullptr, 10);
	//int arg1 = 15;
	//int arg2 = 20;
	Sim_BuildingArea buildingArea = Sim_BuildingArea(arg1, arg2);
	Sim_Menu menu = Sim_Menu();
	bool running = true;
	while (running) {
		running = menu.printMenu(buildingArea);
	}
}
