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
		power = 0;
		label = '_';
		bestandteile = {};
		grundpreis = calculatePreis();
	}
	Building::~Building() {
	}
	float Building::getPreis() {
		return grundpreis;
	}
	float Building::calculatePreis() {
		float preis = 0;
		for (map<Material, int, MatCompare>::iterator i = bestandteile.begin(); i != bestandteile.end(); ++i)
		{
			preis += i->first.preis * i->second;
		}
		return preis;
	}
	int Building::getPower() {
		return power;
	}

// class Leerstehend
	Leerstehend::Leerstehend() {
		power = 0;
		label = 'O';
		bestandteile = {};
		grundpreis = calculatePreis();
	}
	Leerstehend::~Leerstehend() {
	}


// class Windkraft
	Windkraft::Windkraft() {
		label = 'X';
		power = 5;
		bestandteile[Holz()] = 2;
		bestandteile[Metall()] = 1;
		grundpreis = calculatePreis();
	}
	Windkraft::~Windkraft() {
		//todo
	}


//class Wasserkraft
	Wasserkraft::Wasserkraft() {
		power = 8;
		label = 'W';
		bestandteile[Holz()] = 1;
		bestandteile[Metall()] = 2;
		bestandteile[Kunststoff()] = 1;
		grundpreis = calculatePreis();
	}
	Wasserkraft::~Wasserkraft() {
		//todo
	}

// class Solar
	Solar::Solar() {
		label = 'S';
		power = 3;
		bestandteile[Metall()] = 2;
		bestandteile[Kunststoff()] = 1;
		grundpreis = calculatePreis();
	}
	Solar::~Solar() {
		// todo
	}