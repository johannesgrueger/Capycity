#pragma once
#include "Blueprint.h"
namespace Sim_Capycity {
	class Sim_Menu
	{
	public:
		Sim_Menu();
		~Sim_Menu();

		bool printMenu(Blueprint& area);

	private:
		int input;
	};
}
