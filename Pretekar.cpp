#include "Pretekar.h"



Pretekar::Pretekar()
{
}

void Pretekar::nacitaj(std::istream & is)
{
	is >> m_startovacieCislo >> m_pohlavie >> m_meno >> m_priezvisko >> m_dosiahnutyCas;
}


std::string Pretekar::tabulkaToString(int poradie, Cas& casPrveho)
{
	std::string vystupString;
	if (poradie < 10)
		vystupString += " ";
	vystupString += std::to_string(poradie) + ". (";
	if (m_startovacieCislo < 10)
		vystupString += " ";
	vystupString += std::to_string(m_startovacieCislo) + ") " + m_meno;
	if (m_meno.length() < 7)
		vystupString += "\t";
	vystupString += "\t";
	vystupString += "\t";
	vystupString += m_priezvisko;
	if (m_priezvisko.length() < 8)
		vystupString += "\t";
	vystupString += "\t";
	vystupString += m_dosiahnutyCas.casToStr();
	vystupString += "\t";
	vystupString += m_dosiahnutyCas.casovyRozdiel(casPrveho);

	return vystupString;
}

Pretekar::~Pretekar()
{
}
