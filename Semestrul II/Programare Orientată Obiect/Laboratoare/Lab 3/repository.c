#pragma once
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "repository.h"
#include "entities.h"
#pragma warning(disable:4996)

OfferList createEmpty() 
{
	OfferList lst;
	lst.capacitate = 2;
	lst.nrElem = 0;
	lst.list = malloc(sizeof(Oferte) * lst.capacitate);
	return lst;
}


Oferte creeazaOferta_repo(int ID, char* tip, char* destinatie, int pret, int zi, int luna, int an)
{
	Oferte oferta;
	int nr = (int) strlen(tip) + 1;
	oferta.tip = malloc(nr * sizeof(char));
	strcpy_s(oferta.tip, nr, tip);
	nr = (int) strlen(destinatie) + 1;
	oferta.destinatie = malloc(nr * sizeof(char));
	strcpy_s(oferta.destinatie, nr, destinatie);
	oferta.ID = ID;
	oferta.pret = pret;
	oferta.zi = zi;
	oferta.luna = luna;
	oferta.an = an;
	return oferta;
}

void destroyOferta(Oferte* oferta) 
{
	free(oferta->tip);
	free(oferta->destinatie);
	oferta->ID = -1;
	oferta->pret = -1;
	oferta->zi = -1;
	oferta->luna = -1;
	oferta->an = -1;
}

void destroyList(OfferList* lst) 
{
	for (int i = 0; i < lst->nrElem; i++) 
	{
		ElemType el = get(lst, i);
		destroyOferta(&el);
	}
	lst->nrElem = 0;
	free(lst->list);
}

ElemType get(OfferList* lst, int poz) 
{
	return lst->list[poz];
}

int adaugaOferta_repo(Oferte oferta, OfferList* lst)
{
	int sem = 1;
	for (int i = 0; i < lst->nrElem;i++)
		if (oferta.ID == lst->list[i].ID)
			sem = 0;
	if (sem == 1)
	{
		if (lst->nrElem == lst->capacitate) 
		{
			int newCapacitate = lst->capacitate * 2;
			ElemType* aux_elems = malloc(sizeof(ElemType) * newCapacitate);
			for (int i = 0; i < lst->nrElem; i++) {
				aux_elems[i] = lst->list[i];
			}
			free(lst->list);
			lst->list = aux_elems;
			lst->capacitate = newCapacitate;
		}
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
			ElemType el = get(lst, i);
			destroyOferta(&el);
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
		{
			sem = 1;
			ElemType el = get(lst, i);
			destroyOferta(&el);
		}
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

void ordonareOferta_repo(OfferList* lst, int (*key)(Oferte, Oferte), int reverse)
{
	int i, j;
	for (i = 0; i < lst->nrElem - 1;i++)
		for (j = i + 1; j < lst->nrElem;j++)
		{
			Oferte a = lst->list[i], b = lst->list[j];
			if (cmp(a, b, key, reverse))
			{
				Oferte aux = lst->list[i];
				lst->list[i] = lst->list[j];
				lst->list[j] = aux;
			}
		}
}

int cmp(Oferte A, Oferte B, int (*key) (Oferte, Oferte), int reverse)
{
	if (reverse == 1)
		return opposite(key(A, B));
	return key(A, B);
}

int opposite(int result)
{
	if (result == 1)
		return 0;
	return 1;
}

int sortdestination(Oferte a, Oferte b)
{
	if (strcmp(a.destinatie, b.destinatie) > 0)
		return 1;
	return 0;
}

int sortprice(Oferte a, Oferte b)
{
	if (a.pret > b.pret)
		return 1;
	return 0;
}
