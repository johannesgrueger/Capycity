#include "Sim_BuildingArea.h"
#include "Building.h"
#include <iostream>

using namespace Sim_Capycity;
using namespace std;
using namespace Build;

Sim_BuildingArea::Sim_BuildingArea(int length, int width)
{
	areaLength = length;
	areaWidth = width;
	buildingAreaArr = new Building**[areaLength];
	for (size_t i = 0; i < areaLength; i++)
	{
		buildingAreaArr[i] = new Building*[areaWidth];
	}
	for (size_t i = 0; i < areaLength; i++)
	{
		for (size_t j = 0; j < areaWidth; j++)
		{
			buildingAreaArr[i][j] = new Leerstehend();
		}
	}
}

Sim_BuildingArea::~Sim_BuildingArea()
{
	for (int i = 0; i < areaLength; i++)
		delete[] buildingAreaArr[i];
	delete[] buildingAreaArr;
}

void Sim_BuildingArea::newBuilding()
{
	cout << "Please insert Position (posY): " << endl;
	cin >> posY;
	cout << "Please insert Position (posX): " << endl;
	cin >> posX;
	cout << "Please insert Building Width: " << endl;
	cin >> bWidth;
	cout << "Please insert Building Length: " << endl;
	cin >> bLength;

	retry = true;
	do {
		cout << "Please insert Building Type (1='Wasserkraft', 2='Windkraft', 3='Solar'):" << endl;
		cin >> temp;
		if (temp != 1 && temp != 2 && temp != 3)
			cout << "invalid Input! retry" << endl;
		else
			retry = false;
	} while (retry);

	if (testBuilding()) {
		switch (temp) {
		case 1:
			for (size_t i = posY; i < posY + bLength; i++)
			{
				for (size_t j = posX; j < posX + bWidth; j++)
				{
					buildingAreaArr[i][j] = new Wasserkraft();
				}
			}
			cout << "Building created!" << endl;
			break;
		case 2:
			for (size_t i = posY; i < posY + bLength; i++)
			{
				for (size_t j = posX; j < posX + bWidth; j++)
				{
					buildingAreaArr[i][j] = new Windkraft();
				}
			}
			cout << "Building created!" << endl;
			break;
		case 3:
			for (size_t i = posY; i < posY + bLength; i++)
			{
				for (size_t j = posX; j < posX + bWidth; j++)
				{
					buildingAreaArr[i][j] = new Solar();
				}
			}
			cout << "Building created!" << endl;
			break;
		}
	}
	else {
		cout << "Error: Building doesn't fit in Plan!" << endl;
	}
}


bool Sim_BuildingArea::testBuilding()
{
	fitting = true;
	if (posX < 0 || posY < 0 || bWidth < 0 || bLength < 0) {
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
				if (buildingAreaArr[i][j]->label != 'O')
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
	
	if (posX >= 0 && posY >= 0 && posX < areaWidth && posY < areaLength &&  bWidth > 0 && posX + bWidth < areaWidth && bLength > 0 && posY + bLength < areaLength) {
		for (size_t i = posY; i < posY + bLength; i++)
		{
			for (size_t j = posY; j < posX + bWidth; j++)
			{
				delete buildingAreaArr[i][j];
				buildingAreaArr[i][j] = new Leerstehend();
			}
		}
		cout << "Area deleted!" << endl;
	}
	else {
		cout << "invalid Input" << endl;
	}
}

void Sim_BuildingArea::printBuildingPlan()
{
	for (size_t i = 0; i < areaLength; i++)
	{
		for (size_t j = 0; j < areaWidth; j++) 
		{
			cout << buildingAreaArr[i][j]->label << " ";
		}
		cout << endl;
	}
}