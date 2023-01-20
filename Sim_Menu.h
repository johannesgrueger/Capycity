#pragma once
#include "Blueprint.h"
#include <vector>
using namespace std;
namespace Sim_Capycity {
	class Sim_Menu
	{
	public:
		Sim_Menu(int initLength, int initWidth);
		~Sim_Menu();

		bool printMenu();
		bool printBlueprintMenu(Blueprint& area);
		void createNewBlueprint();
		bool chooseBlueprint();
		void sortBlueprintList();
		void printAllBlueprints();
		bool checkEquality();
		bool option4BlueprintMenu();

	private:
		int input;
		vector<Blueprint> blueprintList;
		int lastCalledBlueprintID;
	};
}
