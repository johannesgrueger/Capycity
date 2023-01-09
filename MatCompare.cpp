#include "Material.h"
using namespace Mat;
	struct MatCompare {
		bool operator() (const Material& eins, const Material& zwei) const
		{
			return eins.preis < zwei.preis;
		}
	};
