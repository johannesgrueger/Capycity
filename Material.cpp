#include "Material.h"
#include "Building.h"
#include <iostream>
#include <string>
using namespace std;
using namespace Mat;

// class Material
	Material::Material() {
		preis = 0.0f;
		mat_name = "Material";
	}

	Material::~Material() {
	}
	float Material::getPreis() {
		return preis;
	}

// class Holz
	Holz::Holz() {
		preis = 5.50f;
		mat_name = "Wood";
	}

	Holz::~Holz() {
	}

// class Metall
	Metall::Metall() {
		preis = 12.80f;
		mat_name = "Metal";
	}

	Metall::~Metall() {
	}

//class Kunststoff
	Kunststoff::Kunststoff() {
		preis = 2.30f;
		mat_name = "Plastic";
	}

	Kunststoff::~Kunststoff() {
	}
