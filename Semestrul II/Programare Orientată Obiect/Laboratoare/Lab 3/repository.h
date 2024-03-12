#pragma once

#include <crtdbg.h>
#include "entities.h"

#ifndef REPOSITORY_H_
#define REPOSITORY_H_
#define _CRTDBG_MAP_ALLOC

typedef Oferte ElemType;
typedef struct {
	ElemType* list;
	int nrElem, capacitate;
} OfferList;

//Functia de creare a unei liste de oferte.
//Postconditii: Se va returna o entitate de tip OfferList.
OfferList createEmpty();

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

//Functia de eliberare a memoriei ocupate de o entitate de tip Oferte.
//Parametrii: oferta - Oferte, entitate
//Postconditii: Se va dealoca spatiul ocupat de oferta respectiva.
void destroyOferta(Oferte* oferta);

//Functia de eliberare a memoriei ocupate de o entitate de tip OfferList.
//Parametrii: lst - OfferList, entitatea in care se stocheaza ofertele
//Postconditii: Se va dealoca spatiul ocupat de lista de oferte respectiva.
void destroyList(OfferList* lst);

//Functia de returnare a unei oferte din lista de oferte.
//Parametrii: lst - OfferList, entitatea in care se stocheaza ofertele
//Postconditii: Se va returna oferta de pe pozitia poz din lista de oferte.
ElemType get(OfferList* lst, int poz);

//Functia de adaugare a unei oferte in lista de oferte.
//Parametrii: oferta - Oferte, entitate
//			  lst - OfferList, entitatea in care se stocheaza ofertele
//Posconditii: nrElem va creste cu o unitate, iar oferta creata va fi adaugata in OfferList
int adaugaOferta_repo(Oferte oferta, OfferList* lst);

//Functia de actualizare a unei oferte deja existente.
//Parametrii: oferta - Oferte, entitate
//			  lst - OfferList, entitatea in care se stocheaza ofertele
//Posconditii: entitatea cu acelasi ID va fi modificate cu noile date.
int actualizeazaOferta_repo(Oferte oferta, OfferList* lst);

//Functia de stergere a unei oferte existente.
//Parametrii: ID - int, id-ul ofertei
//			  lst - OfferList, entitatea in care se stocheaza ofertele
//Postconditii: entitate cu acelasi ID va fi stearsa din OfferList, iar nrElem va scade cu o unitate.
int stergeOferta_repo(int ID, OfferList* lst);

//Functia de ordonare
//Parametrii: lst - OfferList, entitatea in care se stocheaza ofertele
//			  key - tipul de sortare
//            reverse - crescator/descrescator
//Postconditii: lista va fi ordonata in unul dintre cele 4 moduri
void ordonareOferta_repo(OfferList* lst, int (*key)(Oferte, Oferte), int reverse);

//Functia de comparare
//Parametrii: Oferte A, B - de comparat
//			  key - ce se compara
//            reverse - crescator/descrescator
//Postconditii: se vor compara cele doua oferte
int cmp(Oferte A, Oferte B, int (*key) (Oferte, Oferte), int reverse);

//Functia pentru sortarea crescatore/descrescatoare
//Parametrii: result - int
//Postconditii: returneaza opusul lui key(a,b)
int opposite(int result);

//Functia de sortare destinatie
//Parametrii: Oferte A, B - de comparat		 
//Postconditii: se vor compara destinatiile celor doua oferte
int sortdestination(Oferte a, Oferte b);

//Functia de sortare price
//Parametrii: Oferte A, B - de comparat	
//Postconditii: se vor compara preturile celor doua oferte
int sortprice(Oferte a, Oferte b);
#endif
