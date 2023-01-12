#include "Material.h"
#include "Building.h"
#include "MatCompare.cpp"
#include <iostream>
#include <map>
using namespace Build;
using namespace Mat;
using namespace std;

/*	
	Kapitel 3: Karlas Idee -- Begründung
	- neue Klasse hätte viel Overhead
	- die Materialien und somit auch die Map an Materalien sind Bestandteil der Gebäude
	  und sollten deshalb auch im Code bei den Gebäuden bleiben
	- Building-Klasse würde sonst nur noch das Label enthalten -> damit quasi unnötig
	- leichterer Zugriff auf Materialien & somit auch Preis (wird verhältnismäßig häufig benötigt)
*/

// class Building
	Building::Building() {
		grundpreis = 0;
		label = '_';
		bestandteile = {};
	}
	Building::~Building() {
	}
	float Building::getPreis() {
		return grundpreis;
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
		bestandteile[Kunststoff()] = 1;
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
		bestandteile[Kunststoff()] = 1;
		float f;
		for (map<Material, int, MatCompare>::iterator i = bestandteile.begin(); i != bestandteile.end(); ++i)
		{
			grundpreis += i->first.preis * i->second;
		}
	}
	Solar::~Solar() {
		// todo
	}