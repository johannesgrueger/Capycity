
using namespace Build;
using namespace Mat;

class Building {
	Building() {

	}
	~Building() {

	}
};

class Leerstehend : public Building {
	Leerstehend() {
		grundpreis = 0;
		label = 'O';
		bestandteile = {};
	}
};

class Windkraft : public Building {
	Windkraft() {
		grundpreis = 20;
		label = 'X';
		bestandteile = { Holz, Holz, Metall };
	}
	~Windkraft() {

	}
};

class Wasserkraft : public Building {
	Wasserkraft() {
		grundpreis = 50;
		label = 'W';
		bestandteile = { Holz, Metall, Metall, Kunststoff };
	~Wasserkraft() {

	}
};

class Solar : public Building {
	Solar() {
		grundpreis = 5;
		label = 'S';
		bestandteile = { Metall, Kunststoff, Kunststoff };
	}
	~Solar() {

	}
};