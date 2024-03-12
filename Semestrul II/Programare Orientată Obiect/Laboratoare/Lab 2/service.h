#pragma once

#include "entities.h"
#include "repository.h"
#include "validation.h"

#ifndef SERVICE_H_
#define SERVICE_H_

//Functia de adaugare a unei oferte in lista de oferte.
//Parametrii: lst - OfferList, entitatea in care se adauga ofertele
//		      ID - int, id-ul ofertei
//			  tip - char, tipul ofertertei
//			  destinatie - char, destinatia ofertei
//			  pret - int, pretul ofertei
//			  zi - int, ziua de plecare
//			  luna - int, luna de plecare
//			  an - int, anul de plecare
//Posconditii: nrElem va creste cu o unitate, iar oferta creata va fi adaugata in OfferList
int adaugaOferta_srv(OfferList* lst, int ID, char tip[], char destinatie[], int pret, int zi, int luna, int an);

//Functia de actualizare a unei oferte deja existente.
//Parametrii: lst - OfferList, entitatea in care se adauga ofertele
//		      ID - int, id-ul ofertei
//			  tip - char, tipul ofertertei
//			  destinatie - char, destinatia ofertei
//			  pret - int, pretul ofertei
//			  zi - int, ziua de plecare
//			  luna - int, luna de plecare
//			  an - int, anul de plecare
//Posconditii: entitatea cu acelasi ID va fi modificate cu noile date.
int actualizeazaOferta_srv(OfferList* lst, int ID, char tip[], char destinatie[], int pret, int zi, int luna, int an);

//Functia de stergere a unei oferte existente.
//Parametrii: lst - OfferList, entitatea in care se adauga ofertele
//		      ID - int, id-ul ofertei
//			  tip - char, tipul ofertertei
//			  destinatie - char, destinatia ofertei
//			  pret - int, pretul ofertei
//			  zi - int, ziua de plecare
//			  luna - int, luna de plecare
//			  an - int, anul de plecare
//Postconditii: entitate cu acelasi ID va fi stearsa din OfferList, iar nrElem va scade cu o unitate.
int stergeOferta_srv(OfferList* lst, int ID);
#endif