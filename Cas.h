#pragma once
#include <string>
#include <iostream>
#include <sstream>
#include <stdlib.h>  
class Cas
{
public:
	Cas();

	void nacitaj(std::istream& is);
	friend std::istream& operator >>(std::istream& is, Cas& b)
	{
		b.nacitaj(is); return is;
	}
	int getCasVSekundach() { return m_hodiny * 3600 + m_minuty * 60 + m_sekundy; }
	std::string casovyRozdiel(Cas& rozdielovy);
	int getMinuty() { return m_minuty; }
	int getSekundy() { return m_sekundy; }
	int getHodiny() { return m_hodiny; }
	std::string casToStr();
	virtual ~Cas();
private:
	int m_hodiny;
	int m_minuty;
	int m_sekundy;
};

