using namespace std;
using namespace Mat;

class Material {
	Material(float _preis) {
		preis = _preis;
	}

	~Material() {
	}

	getPreis() {
		return preis;
	}
};

class Holz : public Material
{
	Holz(float _preis) {
		preis = _preis;
	}

	~Holz() {
	}

};

class Metall : public Material
{
	Metall(float _preis) {
		preis = _preis;
	}

	~Metall() {
	}

};

class Kunststoff : public Material
{
	Kunststoff(float _preis) {
		preis = _preis;
	}

	~Kunststoff() {
	}

};