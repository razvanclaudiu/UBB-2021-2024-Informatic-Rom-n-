#pragma once

#include "service.h"
#include "repository.h"
#include "entities.h"
#include "tests.h"

#ifndef UI_H_
#define UI_H_
//Functia de afisare a ofertelor
//Parametrii: lst - OfferList, entitatea in care se stocheaza ofertele
//Postconditii: Se vor afisa in consola toate ofertele.
void afiseaza(OfferList lst);

//Functia de filtrare dupa destinatie
//Parametrii: lst - OfferList, entitatea in care se stocheaza ofertele
//			  destinatie - char, destinatia ofertei
//Postconditii: Se vor afisa pe ecran ofertele cu destinatia data de la tastatura.
void filtrare_destinatie(OfferList lst, char destinatie[]);

//Functia de filtrare dupa tip
//Parametrii: lst - OfferList, entitatea in care se stocheaza ofertele
//			  tip - char, tipul ofertei
//Postconditii: Se vor afisa pe ecran ofertele cu tipul dat de la tastatura.
void filtrare_tip(OfferList lst, char tip[]);

//Functia de filtrare dupa pret
//Parametrii: lst - OfferList, entitatea in care se stocheaza ofertele
//			  pret - int, pretul ofertei
//Postconditii: Se vor afisa pe ecran ofertele cu pretul dat de la tastatura.
void filtrare_pret(OfferList lst, int pret);

//Functia de rulare prin care se acceseaza functionalitatile programului.
int run();

int main();
#endif