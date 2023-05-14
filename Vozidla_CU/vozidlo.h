#pragma once

typedef struct vozidlo {
	char nazev[20];
	int kapacita;
	struct vozidlo* dalsi;

}tVozidlo;

tVozidlo* vytvorVozidlo(char* nazev, int kapacita);
tVozidlo* nactiVozidla(char* jmSoub);
