#pragma once
namespace Mat {
	class Material {
	public:
		Material(float _preis);
		~Material();
		getPreis();
		int preis;
	};

	class Holz : public Material
	{
		Holz(float _preis);
		~Holz();
	};

	class Metall : public Material
	{
		Metall(float _preis);
		~Metall();
	};

	class Kunststoff : public Material
	{
		Kunststoff(float _preis);
		~Kunststoff();
	};
}