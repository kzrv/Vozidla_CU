#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "vozidlo.h"

#define N 100

tVozidlo* vytvorVozidlo(char* nazev, int kapacita) {
	tVozidlo* p = malloc(sizeof(tVozidlo));
	if (p == NULL) {
		printf("CHYBA ALLOKOVANI");
		return NULL;
	}
	strcpy(p->nazev, nazev);
	p->kapacita = kapacita;
	p->dalsi = NULL;
	return p;
}
tVozidlo* nactiVozidla(char* jmSoub) {
	FILE* f = fopen(jmSoub, "r");
	if (f == NULL) {
		printf("CHYBA CTENI");
		return NULL;
	}
	char buf[N];
	fgets(buf, N, f);
	tVozidlo* voz = NULL;
	tVozidlo* pos = NULL;
	while (fgets(buf, N, f)) {
		char s[20]; int kap;
		sscanf(buf, "%[^;];%d", s, &kap);
		tVozidlo* v = vytvorVozidlo(voz, kap);
		if (voz == NULL) {
			voz = v;
			pos = voz;
		}
		else {
			pos->dalsi = v;
			pos = pos->dalsi;
		}
	}
	return voz;
}
