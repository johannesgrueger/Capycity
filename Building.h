#pragma once
#include "Material.h"
using namespace Mat;

namespace Build {
	class Building {
	public:
		Building();
		~Building();
		Material** bestandteile;
		float grundpreis;
		char label;
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