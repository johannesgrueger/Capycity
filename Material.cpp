#include "Material.h"
#include "Building.h"
#include <iostream>
using namespace std;
using namespace Mat;

// class Material
	Material::Material() {
	}

	Material::~Material() {
	}

// class Holz
	Holz::Holz() {
		preis = 5.50f;
	}

	Holz::~Holz() {
	}

	float Holz::getPreis() {
		return preis;
	}

// class Metall
	Metall::Metall() {
		preis = 12.80f;
	}

	Metall::~Metall() {
	}

	float Metall::getPreis() {
		return preis;
	}

//class Kunststoff
	Kunststoff::Kunststoff() {
		preis = 2.30f;
	}

	Kunststoff::~Kunststoff() {
	}

	float Kunststoff::getPreis() {
		return preis;
	}