#include "Material.h"
#include "Building.h"
#include <iostream>
#include <string>
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
		mat_name = "Holz";
	}

	Holz::~Holz() {
	}

	float Holz::getPreis() {
		return preis;
	}

// class Metall
	Metall::Metall() {
		preis = 12.80f;
		mat_name = "Metall";
	}

	Metall::~Metall() {
	}

	float Metall::getPreis() {
		return preis;
	}

//class Kunststoff
	Kunststoff::Kunststoff() {
		preis = 2.30f;
		mat_name = "Kunststoff";
	}

	Kunststoff::~Kunststoff() {
	}

	float Kunststoff::getPreis() {
		return preis;
	}