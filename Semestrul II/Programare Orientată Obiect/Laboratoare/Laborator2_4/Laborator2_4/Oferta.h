#pragma once

typedef struct {
	char* tip;
	char* adresa;
	int pret;
	int suprafata;
}Oferta;

Oferta* creeaza_oferta(char* tip, char* adresa, int suprafata,int pret);

void distruge_oferta(Oferta* offer);

Oferta* copiaza_oferta(Oferta* offer);

int valideaza_oferta(Oferta* offer);

int verifica_egalitate_intre_oferte(Oferta* oferta_1, Oferta* oferta_2);

