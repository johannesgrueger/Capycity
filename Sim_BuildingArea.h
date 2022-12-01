#pragma once
#include "Building.h"
namespace Sim_Capycity {
	//enum BuildingType { empty, Wasserkraft, Windkraft, Solar };
	class Sim_BuildingArea
	{
	public:
		Sim_BuildingArea(int length, int width);
		~Sim_BuildingArea();

		void newBuilding();

		bool testBuilding();

		void deleteArea();

		void printBuildingPlan();

	private:
		Building** buildingAreaArr;
		int areaWidth, areaLength;
		char temp;
		Building bLabel;
		int bWidth, bLength;
		int posX, posY;
		bool fitting;
		bool retry;
	};
}
