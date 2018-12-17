#pragma once
#include <vector>
#include <map>
#include <set>
#include <fstream>
#include "Cas.h"
#include "Pretekar.h"
class Zavody
{
public:
	Zavody();
	void nacitaj(std::string fileName);
	void zoradenyVypis();
	virtual ~Zavody();
private:
	std::vector<Pretekar*> m_zoznamVsPretekarov;
};

