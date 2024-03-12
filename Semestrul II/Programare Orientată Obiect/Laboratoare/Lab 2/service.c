#include <string.h>
#include "service.h"
#include "repository.h"
#include "validation.h"
#include "entities.h"
#pragma warning(disable:4996)

int adaugaOferta_srv(OfferList* lst, int ID, char tip[], char destinatie[], int pret, int zi, int luna, int an)
{
	Oferte oferta;
	oferta = creeazaOferta_repo(ID, tip, destinatie, pret, zi, luna, an);
	int sem =validare_oferta(oferta);
	if (sem == 1)
	{
		int sem2 = adaugaOferta_repo(oferta, lst);
		return sem2;
	}
	return sem;
}

int actualizeazaOferta_srv(OfferList* lst, int ID, char tip[], char destinatie[], int pret, int zi, int luna, int an)
{
	Oferte oferta;
	oferta = creeazaOferta_repo(ID, tip, destinatie, pret, zi, luna, an);
	int sem = validare_oferta(oferta);
	if (sem == 1)
	{
		int sem2 = actualizeazaOferta_repo(oferta, lst);
		return sem2;
	}
	return sem;
}

int stergeOferta_srv(OfferList* lst, int ID)
{
	int sem = validare_id(ID);
	if (sem == 1)
	{
		int sem2 = stergeOferta_repo(ID, lst);
		return sem2;
	}
	return sem;
}