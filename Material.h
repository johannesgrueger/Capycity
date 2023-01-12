#pragma once
#include <string>
using namespace std;

namespace Mat {
	class Material {
	public:
		Material();
		~Material();
		float getPreis();
		float preis;
		string mat_name;
	};

	class Holz : public Material
	{
	public:
		Holz();
		~Holz();
	};

	class Metall : public Material
	{
	public:
		Metall();
		~Metall();
	};

	class Kunststoff : public Material
	{
	public:
		Kunststoff();
		~Kunststoff();
	};
}