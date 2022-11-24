#pragma once
namespace Sim_Capycity {
	enum BuildingType { empty, Wasserkraft, Windkraft, Solar };
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
		BuildingType** buildingAreaArr;
		int areaWidth, areaLength;
		int temp;
		BuildingType bType;
		int bWidth, bLength;
		int posX, posY;
		bool fitting;
	};
}
