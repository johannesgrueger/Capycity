#pragma once
#include "Material.h"
#include "MatCompare.cpp"
#include <map>
using namespace Mat;

namespace Build {
	class Building {
	public:
		Building();
		~Building();
		map<Material, int, MatCompare> bestandteile;
		float grundpreis;
		int power;
		char label;
		float getPreis();
		float calculatePreis();
		int getPower();
	};

	class Leerstehend : public Building {
	public:
		Leerstehend();
		~Leerstehend();
	};

	class Windkraft : public Building {
	public:
		Windkraft();
		~Windkraft();
	};

	class Wasserkraft : public Building {
	public:
		Wasserkraft();
		~Wasserkraft();
	};

	class Solar : public Building {
	public:
		Solar();
		~Solar();
	};
}