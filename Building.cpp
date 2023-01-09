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
		bestandteile[Holz()] = 2;
		bestandteile[Metall()] = 1;
		for (map<Material, int, MatCompare>::iterator i = bestandteile.begin(); i != bestandteile.end(); ++i)
		{
			grundpreis += i->first.preis * i->second;
		}
	}
	Windkraft::~Windkraft() {
		//todo
	}


//class Wasserkraft
	Wasserkraft::Wasserkraft() {
		label = 'W';
		bestandteile[Holz()] = 1;
		bestandteile[Metall()] = 2;
		bestandteile[Metall()] = 1;
		for (map<Material, int, MatCompare>::iterator i = bestandteile.begin(); i != bestandteile.end(); ++i)
		{
			grundpreis += i->first.preis * i->second;
		}
	}
	Wasserkraft::~Wasserkraft() {
		//todo
	}

// class Solar
	Solar::Solar() {
		label = 'S';
		bestandteile[Metall()] = 2;
		bestandteile[Metall()] = 1;
		for (map<Material, int, MatCompare>::iterator i = bestandteile.begin(); i != bestandteile.end(); ++i)
		{
			grundpreis += i->first.preis * i->second;
		}
	}
	Solar::~Solar() {
		// todo
	}