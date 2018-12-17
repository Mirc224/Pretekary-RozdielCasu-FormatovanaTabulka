#include "Zavody.h"



Zavody::Zavody()
{
}

void Zavody::nacitaj(std::string fileName)
{
	std::ifstream inputFile(fileName);
	while (!inputFile.eof())
	{
		Pretekar* temp = new Pretekar();
		inputFile >> temp;
		m_zoznamVsPretekarov.push_back(temp);
	}
}

void Zavody::zoradenyVypis()
{
	std::set<int> najlepsieCasyZor;
	for (auto &pretekar : m_zoznamVsPretekarov)
	{
		najlepsieCasyZor.insert(pretekar->getCas().getCasVSekundach());
	}
	std::vector<Pretekar*> zoradenyMuzi;
	std::vector<Pretekar*> zoradeneZeny;
	for (auto &cas : najlepsieCasyZor)
	{
		for (auto &pretekar : m_zoznamVsPretekarov)
		{
			if (pretekar->getCas().getCasVSekundach() == cas)
			{
				if (pretekar->getPohlavie() == 'M')
					zoradenyMuzi.push_back(pretekar);
				else
					zoradeneZeny.push_back(pretekar);
			}
			else
				continue;
		}
	}
	std::cout << "Vysledky - MUZI \n ---------------------\n";
	Cas najlepsiCasKategorie;
	if (zoradenyMuzi.size() != 0)
	{
		najlepsiCasKategorie = zoradenyMuzi.front()->getCas();
	}
	int poradoveCislo = 1;
	for (auto &muz : zoradenyMuzi)
	{
		std::cout << muz->tabulkaToString(poradoveCislo, najlepsiCasKategorie) << std::endl;
		++poradoveCislo;
	}
	std::cout << "Vysledky - ZENY \n ---------------------\n";
	if (zoradeneZeny.size() != 0)
	{
		najlepsiCasKategorie = zoradeneZeny.front()->getCas();
	}
	poradoveCislo = 1;
	for (auto &zena : zoradeneZeny)
	{
		std::cout << zena->tabulkaToString(poradoveCislo, najlepsiCasKategorie) << std::endl;
		++poradoveCislo;
	}
}


Zavody::~Zavody()
{
}
