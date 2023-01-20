#include <iostream>
#include <cstdlib>
#include "Blueprint.h"
#include "Sim_Menu.h"
using namespace std;
using namespace Sim_Capycity;

int main(int argc, char* argv[]) {
	int arg1 = strtol(argv[1], nullptr, 10);
	int arg2 = strtol(argv[2], nullptr, 10);
	//int arg1 = 15;
	//int arg2 = 15;
	Sim_Menu menu = Sim_Menu(arg1, arg2);
	bool running = true;
	while (running) {
		running = menu.printMenu();
	}
}
