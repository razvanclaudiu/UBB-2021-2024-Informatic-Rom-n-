#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "repository.h"
#include "entities.h"
#pragma warning(disable:4996)

Oferte creeazaOferta_repo(int ID, char tip[], char destinatie[], int pret, int zi, int luna, int an)
{
	Oferte oferta;
	oferta.ID = ID;
	strcpy(oferta.tip, tip);
	strcpy(oferta.destinatie, destinatie);
	oferta.pret = pret;
	oferta.zi = zi;
	oferta.luna = luna;
	oferta.an = an;
	return oferta;
}

int adaugaOferta_repo(Oferte oferta, OfferList* lst)
{
	int sem = 1;
	for (int i = 0; i < lst->nrElem;i++)
		if (oferta.ID == lst->list[i].ID)
			sem = 0;
	if (sem == 1)
	{
		lst->list[lst->nrElem] = oferta;
		lst->nrElem++;
		return 2;
	}
	return 1;
}

int actualizeazaOferta_repo(Oferte oferta, OfferList* lst)
{
	for (int i = 0; i < lst->nrElem;i++)
		if (oferta.ID == lst->list[i].ID)
		{
			lst->list[i] = oferta;
			return 2;
		}
	return 1;
}

int stergeOferta_repo(int ID, OfferList* lst)
{
	int sem = 0;
	for (int i = 0; i < lst->nrElem;i++)
	{
		if (ID == lst->list[i].ID)
			sem = 1;
		if (sem == 1)
			lst->list[i] = lst->list[i + 1];
	}
	if (sem == 1)
	{
		lst->nrElem--;
		return 2;
	}
	return 1;
}