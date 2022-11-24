#pragma once
#include "Sim_BuildingArea.h"
namespace Sim_Capycity {
	class Sim_Menu
	{
	public:
		Sim_Menu();
		~Sim_Menu();

		bool printMenu(Sim_BuildingArea& area);

	private:
		int input;
	};
}
