#include "Sim_BuildingArea.h"
#include "Building.h"
#include "Material.h"
#include "MatCompare.cpp"
#include <iostream>
#include <string>
#include <map>

using namespace Sim_Capycity;
using namespace std;
using namespace Build;
using namespace Mat;

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
	tempW = Wasserkraft();
	tempX = Windkraft();
	tempS = Solar();
}

Sim_BuildingArea::~Sim_BuildingArea()
{
	for (int i = 0; i < areaLength; i++)
		delete[] buildingAreaArr[i];
	delete[] buildingAreaArr;
}

void Sim_BuildingArea::newBuilding()
{
	cout << "-------" << endl << "New Building:" << endl;
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
			cout << ">> invalid Input! retry" << endl;
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
			break;
		case 2:
			for (size_t i = posY; i < posY + bLength; i++)
			{
				for (size_t j = posX; j < posX + bWidth; j++)
				{
					buildingAreaArr[i][j] = new Windkraft();
				}
			}
			break;
		case 3:
			for (size_t i = posY; i < posY + bLength; i++)
			{
				for (size_t j = posX; j < posX + bWidth; j++)
				{
					buildingAreaArr[i][j] = new Solar();
				}
			}
			break;
		}
		cout << ">> Building created!" << endl;
	}
	else {
		cout << ">> Error: Building doesn't fit in Plan!" << endl;
	}
	cout << "-------" << endl << endl;
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
	cout << "-------" << endl << "Delete area:" << endl;
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
		cout << ">> Area deleted!" << endl;
	}
	else {
		cout << ">> invalid Input" << endl;
	}
	cout << "-------" << endl << endl;
}

void Sim_BuildingArea::printBuildingPlan()
{
	cout << "-------" << endl << "current Plan:" << endl;
	for (size_t i = 0; i < areaLength; i++)
	{
		for (size_t j = 0; j < areaWidth; j++)
		{
			cout << buildingAreaArr[i][j]->label << " ";
		}
		cout << endl;

	}
	cout << "-------" << endl << "Lineup:" << endl;
	int w_count = 0;
	int o_count = 0;
	int x_count = 0;
	int s_count = 0;
	// count all Buildings
	for (size_t i = 0; i < areaLength; i++)
	{
		for (size_t j = 0; j < areaWidth; j++)
		{
			if (buildingAreaArr[i][j]->label == 'W')
				w_count++;
			if (buildingAreaArr[i][j]->label == 'O')
				o_count++;
			if (buildingAreaArr[i][j]->label == 'X')
				x_count++;
			if (buildingAreaArr[i][j]->label == 'S')
				s_count++;
		}
	}
	cout << "Number of Hydropower (" << tempW.label << "):	" << w_count << ", Cost per Unit: " << tempW.getPreis() << "€, Cost in total: " << w_count * tempW.getPreis() << "€" << endl;
	cout << "					-> Materialien: ";
	for (map<Material, int, MatCompare>::iterator i = tempW.bestandteile.begin(); i != tempW.bestandteile.end(); ++i)
	{
		cout << w_count * i->second << " * " << i->first.mat_name << "; ";
	}
	cout << endl << "					-> Leistung einzeln: " << tempW.getPower();
	cout << endl << "					-> Leistung gesamt:  " << tempW.getPower() * w_count;
	cout << endl << endl;

	cout << "Number of Windmills (" << tempX.label << "):	" << x_count << ", Cost per Unit: " << tempX.getPreis() << "€, Cost in total: " << x_count * tempX.getPreis() << "€" << endl;
	cout << "					-> Materialien: ";
	for (map<Material, int, MatCompare>::iterator i = tempX.bestandteile.begin(); i != tempX.bestandteile.end(); ++i)
	{
		cout << x_count * i->second << " * " << i->first.mat_name << "; ";
	}
	cout << endl << "					-> Leistung einzeln: " << tempX.getPower();
	cout << endl << "					-> Leistung gesamt:  " << tempX.getPower() * x_count;
	cout << endl << endl;

	cout << "Number of Photovoltaic (" << tempS.label << "):	" << s_count << ", Cost per Unit: " << tempS.getPreis() << "€, Cost in total: " << s_count * tempS.getPreis() << "€" << endl;
	cout << "					-> Materialien: ";
	for (map<Material, int, MatCompare>::iterator i = tempS.bestandteile.begin(); i != tempS.bestandteile.end(); ++i)
	{
		cout << s_count * i->second << " * " << i->first.mat_name << "; ";
	}
	cout << endl << "					-> Leistung einzeln: " << tempS.getPower();
	cout << endl << "					-> Leistung gesamt:  " << tempS.getPower() * s_count;
	cout << endl << endl;

	cout << "unused Space: (" << Leerstehend().label << "): " << o_count << endl;

	cout << "-------" << endl << endl;
}