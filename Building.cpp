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
		bestandteile = {Holz(), Holz(), Metall()};
	}
	Windkraft::~Windkraft() {
	}

//class Wasserkraft
	Wasserkraft::Wasserkraft() {
		grundpreis = 50;
		label = 'W';
		bestandteile = {Holz(), Metall(), Metall(), Kunststoff()};
	}
	Wasserkraft::~Wasserkraft() {
	}

// class Solar
	Solar::Solar() {
		grundpreis = 5;
		label = 'S';
		bestandteile = {Metall(), Kunststoff(), Kunststoff()};
	}
	Solar::~Solar() {
	}