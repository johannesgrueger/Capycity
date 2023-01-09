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
		grundpreis = 20;
		label = 'X';
		bestandteile = new Material*[3];
		bestandteile[0] = new Holz();
		bestandteile[1] = new Holz();
		bestandteile[2] = new Metall();
	}
	Windkraft::~Windkraft() {
		delete[] bestandteile;
	}

//class Wasserkraft
	Wasserkraft::Wasserkraft() {
		grundpreis = 50;
		label = 'W';
		bestandteile = new Material*[4];
		bestandteile[0] = new Holz();
		bestandteile[1] = new Metall();
		bestandteile[2] = new Metall();
		bestandteile[3] = new Kunststoff();
	}
	Wasserkraft::~Wasserkraft() {
		delete[] bestandteile;
	}

// class Solar
	Solar::Solar() {
		grundpreis = 5;
		label = 'S';
		bestandteile = new Material * [3];
		bestandteile[0] = new Metall();
		bestandteile[1] = new Metall();
		bestandteile[2] = new Kunststoff();
	}
	Solar::~Solar() {
		delete[] bestandteile;
	}