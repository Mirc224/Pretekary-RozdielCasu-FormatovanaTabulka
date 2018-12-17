#include "Cas.h"



Cas::Cas()
{
}

void Cas::nacitaj(std::istream & is)
{
	std::string newLine;
	std::string cislo;
	is >> newLine;
	std::istringstream ss(newLine);
	std::getline(ss, cislo, ':');
	m_hodiny = std::stoi(cislo);
	std::getline(ss, cislo, ':');
	m_minuty = std::stoi(cislo);
	std::getline(ss, cislo, ':');
	m_sekundy = std::stoi(cislo);
}


std::string Cas::casovyRozdiel(Cas & rozdielovy)
{
	int tempSekundy = 0;
	int tempMinuty = 0;
	int tempHodiny = 0;
	int casVsekundach = std::abs(this->getCasVSekundach() - rozdielovy.getCasVSekundach());
	tempSekundy = casVsekundach % 60;
	casVsekundach -= tempSekundy;
	tempMinuty = (casVsekundach / 60) % 60;
	casVsekundach -= tempMinuty * 60;
	tempHodiny = (casVsekundach / 3600) % 24;


	std::string vystupnyRozdiel = " ";
	char vystupnyZnak;
	if (this->getCasVSekundach() > rozdielovy.getCasVSekundach())
	{
		vystupnyZnak = '+';
	}
	else if (this->getCasVSekundach() < rozdielovy.getCasVSekundach())
	{
		vystupnyZnak = '-';
	}
	else
	{
		return "        0";
	}
	if (tempHodiny != 0)
	{
		if(tempHodiny < 10)
			vystupnyRozdiel += "0";
		vystupnyRozdiel += std::to_string(tempHodiny) +":";
	}
	else
	{
		vystupnyRozdiel += "   ";
	}
	if (tempMinuty != 0)
	{
		if (tempMinuty < 10)
			vystupnyRozdiel += "0";
		vystupnyRozdiel += std::to_string(tempMinuty) + ":";
	}
	else
	{
		if(tempHodiny != 0)
			vystupnyRozdiel += "00:";
		else
			vystupnyRozdiel += "   ";
		
	}
	if (tempSekundy != 0)
	{
		if (tempSekundy < 10)
			vystupnyRozdiel += "0";
		vystupnyRozdiel += std::to_string(tempSekundy);
	}
	else
	{
		vystupnyRozdiel += "00";
	}


	/*int rozdielCasu = std::abs(rozdielovy.getHodiny() - m_hodiny);
	if (!(rozdielCasu == 0))
	{
		if (rozdielCasu < 10)
			vystupnyRozdiel += "0";
		vystupnyRozdiel += std::to_string(rozdielCasu) + ":";
	}
	else
	{
		vystupnyRozdiel += "   ";
	}
	rozdielCasu = std::abs(m_minuty - rozdielovy.getMinuty());
	if (!(rozdielCasu == 0))
	{
		if (rozdielCasu < 10)
			vystupnyRozdiel += "0";
		vystupnyRozdiel += std::to_string(rozdielCasu) + ":";
	}
	else
		vystupnyRozdiel += "   ";
	rozdielCasu = std::abs(m_sekundy - rozdielovy.getSekundy());
	if (!(rozdielCasu == 0))
	{
		if (rozdielCasu < 10)
			vystupnyRozdiel += "0";
		vystupnyRozdiel += std::to_string(rozdielCasu);
	}
	else
		vystupnyRozdiel += "00";*/
	size_t indexNeprazadneho = vystupnyRozdiel.find_first_not_of(' ', (size_t)0);
	vystupnyRozdiel.at(indexNeprazadneho - 1) = vystupnyZnak;
	return vystupnyRozdiel;
}

std::string Cas::casToStr()
{
	std::string casVoFormate = std::to_string(m_hodiny) + ":";
	if (m_minuty < 10)
		casVoFormate += "0";
	casVoFormate += std::to_string(m_minuty) + ":";
	if (m_sekundy < 10)
		casVoFormate += "0";
	casVoFormate += std::to_string(m_sekundy);
	return casVoFormate;
}

Cas::~Cas()
{
}
