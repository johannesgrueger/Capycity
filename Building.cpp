#include "Material.h"
#include "Building.h"
#include "MatCompare.cpp"
#include <iostream>
#include <map>
using namespace Build;
using namespace Mat;
using namespace std;

// class Building
	Building::Building() {
	}
	Building::~Building() {
	}

// class Leerstehend
	Leerstehend::Leerstehend() {
		grundpreis = 0;
		label = 'O';
		bestandteile = {};
	}
	Leerstehend::~Leerstehend() {
	}

// class Windkraft
	Windkraft::Windkraft() {
		label = 'X';
		grundpreis = 0;
		map<Material, int, MatCompare> bestandteile;
		bestandteile[Holz()] = 2;
		bestandteile[Metall()] = 1;
		for (map<Material, int>::iterator i = bestandteile.begin(); i != bestandteile.end(); ++i)
		{
			grundpreis += i->first.preis * i->second;
		}
	}
	Windkraft::~Windkraft() {
		delete[] bestandteile;
	}

//class Wasserkraft
	Wasserkraft::Wasserkraft() {
		label = 'W';
		map<Material, int, MatCompare> bestandteile;
		bestandteile[Holz()] = 1;
		bestandteile[Metall()] = 2;
		bestandteile[Metall()] = 1;
		for (map<Material, int>::iterator i = bestandteile.begin(); i != bestandteile.end(); ++i)
		{
			grundpreis += i->first.preis * i->second;
		}
	}
	Wasserkraft::~Wasserkraft() {
		delete[] bestandteile;
	}

// class Solar
	Solar::Solar() {
		label = 'S';
		map<Material, int, MatCompare> bestandteile;
		bestandteile[Metall()] = 2;
		bestandteile[Metall()] = 1;
		for (map<Material, int>::iterator i = bestandteile.begin(); i != bestandteile.end(); ++i)
		{
			grundpreis += i->first.preis * i->second;
		}
	}
	Solar::~Solar() {
		delete[] bestandteile;
	}