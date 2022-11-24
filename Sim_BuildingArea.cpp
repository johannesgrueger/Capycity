#include "Sim_BuildingArea.h"
#include <iostream>

using namespace Sim_Capycity;
using namespace std;

Sim_BuildingArea::Sim_BuildingArea(int length, int width)
{
	areaLength = length;
	areaWidth = width;
	buildingAreaArr = new BuildingType*[areaLength];
	for (size_t i = 0; i < areaLength; i++)
	{
		buildingAreaArr[i] = new BuildingType[areaWidth];
	}
	for (size_t i = 0; i < areaLength; i++)
	{
		for (size_t j = 0; j < areaWidth; j++)
		{
			buildingAreaArr[i][j] = BuildingType(0);
		}
	}
}

Sim_BuildingArea::~Sim_BuildingArea()
{
	delete[] buildingAreaArr;
}

void Sim_BuildingArea::newBuilding()
{
	cout << "Please insert Building Type (1='Wasserkraft', 2='Windkraft', 3='Solar'):" << endl;
	cin >> temp;
	bType = BuildingType(temp);
	cout << "Please insert Position (posY): " << endl;
	cin >> posY;
	cout << "Please insert Position (posX): " << endl;
	cin >> posX;
	cout << "Please insert Building Width: " << endl;
	cin >> bWidth;
	cout << "Please insert Building Length: " << endl;
	cin >> bLength;

	if (testBuilding()) {
		for (size_t i = posY; i < posY + bLength; i++)
		{
			for (size_t j = posX; j < posX + bWidth; j++)
			{
				buildingAreaArr[i][j] = bType;
			}
		}
		cout << "Building created!" << endl;
	}
	else {
		cout << "Error: Building doesn't fit in Plan!" << endl;
	}
}


bool Sim_BuildingArea::testBuilding()
{
	fitting = true;
	if (bType < 1 || bType > 3) {
		cout << "invalid Input!" << endl;
		fitting = false;
	}
	if (posX + bWidth > areaWidth) {
		fitting = false;
	}
	if (posY + bLength > areaLength) {
		fitting = false;
	}
	if (fitting) {
		for (size_t i = posY; i < posY + bLength; i++)
		{
			for (size_t j = posX; j < posX + bWidth; j++)
			{
				if (buildingAreaArr[i][j] != BuildingType(0))
					fitting = false;
				if (!fitting)
					break;
			}
			if (!fitting)
				break;
		}
	}
	return fitting;
}

void Sim_BuildingArea::deleteArea()
{
	cout << "Please insert Position (posY):" << endl;
	cin >> posY;
	cout << "Please insert Position (posX):" << endl;
	cin >> posX;
	cout << "Please insert Size (length):" << endl;
	cin >> bLength;
	cout << "Please insert Size (width):" << endl;
	cin >> bWidth;

	for (size_t i = posY; i < posY+bLength; i++)
	{
		for (size_t j = posY; j < posX+bWidth; j++)
		{
			buildingAreaArr[i][j] = BuildingType(0);
		}
	}
	cout << "Area deleted!" << endl;
}

void Sim_BuildingArea::printBuildingPlan()
{
	for (size_t i = 0; i < areaLength; i++)
	{
		for (size_t j = 0; j < areaWidth; j++) 
		{
			cout << buildingAreaArr[i][j] << " ";
		}
		cout << endl;
	}
}