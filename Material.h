#pragma once
namespace Mat {
	class Material {
	public:
		Material();
		~Material();
		float getPreis();
		float preis;
	};

	class Holz : public Material
	{
	public:
		Holz();
		~Holz();
		float getPreis();
	};

	class Metall : public Material
	{
	public:
		Metall();
		~Metall();
		float getPreis();
	};

	class Kunststoff : public Material
	{
	public:
		Kunststoff();
		~Kunststoff();
		float getPreis();
	};
}