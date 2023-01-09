#include "Material.h"
#include "Building.h"
#include <iostream>
using namespace Build;
using namespace Mat;

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
		bestandteile = new Material*[3];
		bestandteile[0] = new Holz();
		bestandteile[1] = new Holz();
		bestandteile[2] = new Metall();
		grundpreis = bestandteile[0]->preis + bestandteile[1]->preis + bestandteile[2]->preis;
	}
	Windkraft::~Windkraft() {
		delete[] bestandteile;
	}

//class Wasserkraft
	Wasserkraft::Wasserkraft() {
		label = 'W';
		bestandteile = new Material*[4];
		bestandteile[0] = new Holz();
		bestandteile[1] = new Metall();
		bestandteile[2] = new Metall();
		bestandteile[3] = new Kunststoff();
		grundpreis = bestandteile[0]->preis + bestandteile[1]->preis + bestandteile[2]->preis + bestandteile[3]->preis;
	}
	Wasserkraft::~Wasserkraft() {
		delete[] bestandteile;
	}

// class Solar
	Solar::Solar() {
		label = 'S';
		bestandteile = new Material * [3];
		bestandteile[0] = new Metall();
		bestandteile[1] = new Metall();
		bestandteile[2] = new Kunststoff();
		grundpreis = bestandteile[0]->preis + bestandteile[1]->preis + bestandteile[2]->preis;
	}
	Solar::~Solar() {
		delete[] bestandteile;
	}