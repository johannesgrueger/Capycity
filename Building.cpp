#include "Material.h"
#include "Building.h"
#include "MatCompare.cpp"
#include <iostream>
#include <map>
using namespace Build;
using namespace Mat;
using namespace std;

/*	
	Kapitel 3: Karlas Idee -- Begr�ndung
	- neue Klasse h�tte viel Overhead
	- die Materialien und somit auch die Map an Materalien sind Bestandteil der Geb�ude
	  und sollten deshalb auch im Code bei den Geb�uden bleiben
	- Building-Klasse w�rde sonst nur noch das Label enthalten -> damit quasi unn�tig
	- leichterer Zugriff auf Materialien & somit auch Preis (wird verh�ltnism��ig h�ufig ben�tigt)
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