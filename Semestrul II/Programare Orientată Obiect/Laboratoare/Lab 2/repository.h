#pragma once

#include "entities.h"

#ifndef REPOSITORY_H_
#define REPOSITORY_H_

typedef struct {
	Oferte list[100];
	int nrElem;
} OfferList;

//Functia de creare de oferte.
//Parametrii: ID - int, id-ul ofertei
//			  tip - char, tipul ofertertei
//			  destinatie - char, destinatia ofertei
//			  pret - int, pretul ofertei
//			  zi - int, ziua de plecare
//			  luna - int, luna de plecare
//			  an - int, anul de plecare
//Postconditii: Se va returna o entitate de tip Oferte.
Oferte creeazaOferta_repo(int ID, char tip[], char destinatie[], int pret, int zi, int luna, int an);

//Functia de adaugare a unei oferte in lista de oferte.
//Parametrii: oferta - Oferta, entitate
//			  lst - OfferList, entitatea in care se stocheaza ofertele
//Posconditii: nrElem va creste cu o unitate, iar oferta creata va fi adaugata in OfferList
int adaugaOferta_repo(Oferte oferta, OfferList* lst);

//Functia de actualizare a unei oferte deja existente.
//Parametrii: oferta - Oferta, entitate
//			  lst - OfferList, entitatea in care se stocheaza ofertele
//Posconditii: entitatea cu acelasi ID va fi modificate cu noile date.
int actualizeazaOferta_repo(Oferte oferta, OfferList* lst);

//Functia de stergere a unei oferte existente.
//Parametrii: ID - int, id-ul ofertei
//			  lst - OfferList, entitatea in care se stocheaza ofertele
//Postconditii: entitate cu acelasi ID va fi stearsa din OfferList, iar nrElem va scade cu o unitate.
int stergeOferta_repo(int ID, OfferList* lst);
#endif
