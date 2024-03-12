#pragma once

#ifndef ENTITIES_H_
#define ENTITIES_H_

typedef struct {
	char* tip;
	char* destinatie;
	int ID, zi, luna, an, pret;
} Oferte;

//Functia de afisare a unei oferte.
//Parametrii: oferta - Oferte, entitate
//Postconditii: Se va afisa in consola o entitate de tip Oferte.
void afis(Oferte oferta);
#endif
