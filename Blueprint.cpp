#include "Blueprint.h"
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

int Blueprint::idCounter = 0;

Blueprint::Blueprint(string bname, int length, int width)
{
	bID = idCounter++;
	name = bname;
	areaLength = length;
	areaWidth = width;
	buildingAreaArr = new Building**[areaLength];
	for (int i = 0; i < areaLength; i++)
	{
		buildingAreaArr[i] = new Building*[areaWidth];
	}
	for (int i = 0; i < areaLength; i++)
	{
		for (int j = 0; j < areaWidth; j++)
		{
			buildingAreaArr[i][j] = new Leerstehend();
		}
	}
	tempW = Wasserkraft();
	tempX = Windkraft();
	tempS = Solar();
}

string Blueprint::getName() {
	return this->name;
}

Blueprint::~Blueprint()
{
	// muss auskommentiert sein sonst löschts mir irgendwann mal mein array und ich krieg ne lesezugriffsverletzung als runtime error, hab leider keine andere lösung gefunden
	/*for (int i = 0; i < areaLength; i++)
		delete[] buildingAreaArr[i];
	delete[] buildingAreaArr;*/
}

bool Blueprint::operator ==(Blueprint b) {
	if (this->areaLength != b.areaLength || this->areaWidth != b.areaWidth)
		return false;
	for (int i = 0; i < this->areaLength; i++)
	{
		for (int j = 0; j < this->areaWidth; j++)
		{
			if (this->buildingAreaArr[i][j]->label != b.buildingAreaArr[i][j]->label) {
				return false;
			}
		}
	}
	return true;
}

void Blueprint::countBuildings() {
	this->w_count = 0;
	this->o_count = 0;
	this->x_count = 0;
	this->s_count = 0;

	for (int i = 0; i < areaLength; i++)
	{
		for (int j = 0; j < areaWidth; j++)
		{
			if (buildingAreaArr[i][j]->label == 'O') {
				this->o_count++;
			}
			if (buildingAreaArr[i][j]->label == 'W') {
				this->w_count++;
			}
			if (buildingAreaArr[i][j]->label == 'X') {
				this->x_count++;
			}
			if (buildingAreaArr[i][j]->label == 'S') {
				this->s_count++;
			}

		}
	}
}

float Blueprint::calculateEfficiency() {
	this->countBuildings();

	/*int w_power = this->w_count * tempW.power;
	int x_power = this->x_count * tempX.power;
	int s_power = this->s_count * tempS.power;
	int ges_power = w_power + x_power + s_power;*/

	//int ges_power = this->w_count * tempW.power + this->x_count * tempX.power + this->s_count * tempS.power;

	/*float w_preis = this->w_count * tempW.grundpreis;
	float x_preis = this->x_count * tempX.grundpreis;
	float s_preis = this->s_count * tempS.grundpreis;
	float ges_preis = w_preis + x_preis + s_preis;*/

	//float ges_preis = this->w_count * tempW.grundpreis + this->x_count * tempX.grundpreis + this->s_count * tempS.grundpreis;

	//int areaSize = areaLength * areaWidth;

	if (w_count == 0 && x_count == 0 && s_count == 0) {
		return 0.0f;
	}
	else {
		//float k = (ges_power / (ges_preis * areaSize))*100.0f;
		//double k = ((this->w_count * tempW.power + this->x_count * tempX.power + this->s_count * tempS.power) / ((this->w_count * tempW.grundpreis + this->x_count * tempX.grundpreis + this->s_count * tempS.grundpreis) * (areaLength * areaWidth))) * 100.0;
		//return k;
		return ((this->w_count * tempW.power + this->x_count * tempX.power + this->s_count * tempS.power) / ((this->w_count * tempW.grundpreis + this->x_count * tempX.grundpreis + this->s_count * tempS.grundpreis) * (areaLength * areaWidth))) * 100.0;
	}
}

void Blueprint::newBuilding()
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
			for (int i = posY; i < posY + bLength; i++)
			{
				for (int j = posX; j < posX + bWidth; j++)
				{
					buildingAreaArr[i][j] = new Wasserkraft();
				}
			}
			break;
		case 2:
			for (int i = posY; i < posY + bLength; i++)
			{
				for (int j = posX; j < posX + bWidth; j++)
				{
					buildingAreaArr[i][j] = new Windkraft();
				}
			}
			break;
		case 3:
			for (int i = posY; i < posY + bLength; i++)
			{
				for (int j = posX; j < posX + bWidth; j++)
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


bool Blueprint::testBuilding()
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
		for (int i = posY; i < posY + bLength; i++)
		{
			for (int j = posX; j < posX + bWidth; j++)
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

void Blueprint::deleteArea()
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
		for (int i = posY; i < posY + bLength; i++)
		{
			for (int j = posY; j < posX + bWidth; j++)
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

void Blueprint::printBuildingPlan()
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
	
	this->countBuildings();

	cout << "Number of Hydropower (" << tempW.label << "):	" << w_count << ", Cost per Unit: " << tempW.getPreis() << "€, Cost in total: " << w_count * tempW.getPreis() << "€" << endl;
	cout << "					-> Materials: ";
	for (map<Material, int, MatCompare>::iterator i = tempW.bestandteile.begin(); i != tempW.bestandteile.end(); ++i)
	{
		cout << w_count * i->second << " * " << i->first.mat_name << "; ";
	}
	cout << endl << "					-> Power (single):    " << tempW.getPower();
	cout << endl << "					-> Power (together):  " << tempW.getPower() * w_count;
	cout << endl << endl;

	cout << "Number of Windmills (" << tempX.label << "):	" << x_count << ", Cost per Unit: " << tempX.getPreis() << "€, Cost in total: " << x_count * tempX.getPreis() << "€" << endl;
	cout << "					-> Materials: ";
	for (map<Material, int, MatCompare>::iterator i = tempX.bestandteile.begin(); i != tempX.bestandteile.end(); ++i)
	{
		cout << x_count * i->second << " * " << i->first.mat_name << "; ";
	}
	cout << endl << "					-> Power (single):    " << tempX.getPower();
	cout << endl << "					-> Power (together):  " << tempX.getPower() * x_count;
	cout << endl << endl;

	cout << "Number of Photovoltaic (" << tempS.label << "):	" << s_count << ", Cost per Unit: " << tempS.getPreis() << "€, Cost in total: " << s_count * tempS.getPreis() << "€" << endl;
	cout << "					-> Materials: ";
	for (map<Material, int, MatCompare>::iterator i = tempS.bestandteile.begin(); i != tempS.bestandteile.end(); ++i)
	{
		cout << s_count * i->second << " * " << i->first.mat_name << "; ";
	}
	cout << endl << "					-> Power (single):    " << tempS.getPower();
	cout << endl << "					-> Power (together):  " << tempS.getPower() * s_count;
	cout << endl << endl;

	cout << "unused Space: (" << Leerstehend().label << "): " << o_count << endl;

	cout << endl << "Efficiency K: " << this->calculateEfficiency() << endl;

	cout << "-------" << endl << endl;
}