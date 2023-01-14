#pragma once
#include "Building.h"
using namespace Build;

namespace Sim_Capycity {
	//enum BuildingType { empty, Wasserkraft, Windkraft, Solar };
	class Blueprint
	{
	public:
		Blueprint(string name, int length, int width);
		~Blueprint();

		void newBuilding();

		bool testBuilding();

		void deleteArea();

		void printBuildingPlan();

		void countAllBuildings();

		float calculateEfficiency();

		bool isEqualTo(Blueprint b);

		string getName();
		
		static int id;
		Building*** buildingAreaArr;

	private:
		string name;
		int areaWidth, areaLength;
		int temp;
		int bWidth, bLength;
		int posX, posY;
		bool fitting;
		bool retry;
		Wasserkraft tempW;
		Windkraft tempX;
		Solar tempS;
		int w_count = 0;
		int o_count = 0;
		int x_count = 0;
		int s_count = 0;
	};
}
