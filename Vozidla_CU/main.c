#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "vozidlo.h"
#include "produkt.h"

void naplanujRozvoz(tVozidlo* v, tProdukt* p) {
	while (v != NULL) {
		int kap = v->kapacita;
		printf("%s %d\n", v->nazev, v->kapacita);
		while (p != NULL && kap>=p->pocet) {
			printf("%s %d\n", p->nazev, p->pocet);
			kap -= p->pocet;
			p = p->dalsi;
		}
		printf("-------------\n");
		v = v->dalsi;
	}
} 


int main(void) {
	tProdukt* pos = nactiProdukty("produkty.csv");
	tVozidlo* voz = nactiProdukty("vozidla.csv");
	
	naplanujRozvoz(voz, pos);


	return 0;
}
