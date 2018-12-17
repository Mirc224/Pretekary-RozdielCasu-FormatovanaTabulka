#pragma once
#include <iostream>
#include <string>
#include "Cas.h"
class Pretekar
{
public:
	Pretekar();
	void nacitaj(std::istream& is);
	void vypis(std::ostream& os);
	Cas getCas() { return m_dosiahnutyCas; }
	friend std::istream& operator >>(std::istream& is, Pretekar* b)
	{
		b->nacitaj(is); return is;
	}
	friend std::ostream& operator <<(std::ostream& os, Pretekar* b) //takyto zapis aby sa to dalo retazit
	{
		b->vypis(os); return os;
	}
	std::string tabulkaToString(int poradie, Cas& casPrveho);
	char getPohlavie() { return m_pohlavie; }
	virtual ~Pretekar();
private:
	char m_pohlavie;
	std::string m_meno;
	std::string m_priezvisko;
	int m_startovacieCislo;
	Cas m_dosiahnutyCas;
};

