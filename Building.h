#pragma once
#include "Material.h"
namespace Build {
	class Building {
		Building();
		~Building();
		float grundpreis;
		char label;
		Material[]* bestandteile;
	};

	class Leerstehend : public Building {
		Leerstehend();
		~Leerstehend();
	};

	class Windkraft : public Building {
		Windkraft();
		~Windkraft();
	};

	class Wasserkraft : public Building {
		Wasserkraft();
		~Wasserkraft();
	};

	class Solar : public Building {
		Solar();
		~Solar();
	};
}