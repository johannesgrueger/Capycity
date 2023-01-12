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