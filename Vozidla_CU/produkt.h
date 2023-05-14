#pragma once
typedef struct produkt {
	char nazev[20];
	int pocet;
	struct tProduct* dalsi;
}tProdukt;

tProdukt* vytvorProduct(char* nazev, int pocet);
tProdukt* nactiProdukty(char* jmSoub);