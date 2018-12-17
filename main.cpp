#include <iostream>
#include "Cas.h"
#include "Zavody.h"

int main()
{
	Zavody tempZavody = Zavody();
	tempZavody.nacitaj("startListina.txt");
	tempZavody.zoradenyVypis();
	return 0;
}