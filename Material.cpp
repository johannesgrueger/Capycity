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

// class Metall
	Metall::Metall() {
		preis = 12.80f;
		mat_name = "Metall";
	}

	Metall::~Metall() {
	}

//class Kunststoff
	Kunststoff::Kunststoff() {
		preis = 2.30f;
		mat_name = "Kunststoff";
	}

	Kunststoff::~Kunststoff() {
	}
