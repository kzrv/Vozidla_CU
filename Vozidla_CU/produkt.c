#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "produkt.h"

#define N 100


tProdukt* vytvorProduct(char* nazev, int pocet) {
	tProdukt* p = malloc(sizeof(tProdukt));
	if (p == NULL) {
		printf("CHYBA ALLOKOVANI");
		return NULL;
	}
	strcpy(p->nazev, nazev);
	p->pocet = pocet;
	p->dalsi = NULL;
	return p;
}
tProdukt* nactiProdukty(char* jmSoub) {
	FILE* f = fopen(jmSoub, "r");
	if (f == NULL) {
		printf("CHYBA CTENI");
		return NULL;
	}
	char buf[N];
	fgets(buf, N, f);
	tProdukt* pro = NULL;
	tProdukt* pos = NULL;
	while (fgets(buf, N, f)) {
		char nazev[15]; int pocet;
		sscanf(buf, "%[^;];%d", nazev, &pocet);
		if (pro == NULL) {
			pro = vytvorProduct(nazev, pocet);
			pos = pro;
		}
		else {
			pos->dalsi = vytvorProduct(nazev, pocet);
			pos = pos->dalsi;
		}
	}
	return pro;
}
