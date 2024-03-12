#include "service.h"
#include "repository.h"
#include "entities.h"
#include "tests.h"
#include <assert.h>
#include <string.h>
#pragma warning(disable:4996)

void test_afis()
{
	OfferList lst;
	lst.nrElem = 0;
	Oferte oferta;
	char tip[30] = "munte", destinatie[30] = "Brasov";
	int ID = 1, zi = 3, luna = 4, an = 2007, pret = 200;
	strcpy(oferta.tip, tip);
	strcpy(oferta.destinatie, destinatie);
	oferta.ID = ID;
	oferta.zi = zi;
	oferta.luna = luna;
	oferta.an = an;
	oferta.pret = pret;
	afis(oferta);
}

void test_creeazaOferta_repo()
{
	Oferte oferta1, oferta2;
	char tip[30] = "munte", destinatie[30] = "Brasov";
	int ID = 1, zi = 3, luna = 4, an = 2007, pret = 200;
	strcpy(oferta1.tip, tip);
	strcpy(oferta1.destinatie, destinatie);
	oferta1.ID = ID;
	oferta1.zi = zi;
	oferta1.luna = luna;
	oferta1.an = an;
	oferta1.pret = pret;
	oferta2 = creeazaOferta_repo(ID, tip, destinatie, pret, zi, luna, an);
	assert(strcmp(oferta1.tip,oferta2.tip)==0);
	assert(strcmp(oferta1.destinatie, oferta2.destinatie) == 0);
	assert(oferta1.ID == oferta2.ID);
	assert(oferta1.pret == oferta2.pret);
	assert(oferta1.zi == oferta2.zi);
	assert(oferta1.luna == oferta2.luna);
	assert(oferta1.an == oferta2.an);
}

void test_adaugaOferta_repo()
{
	OfferList lst;
	lst.nrElem = 0;
	Oferte oferta;
	char tip[30] = "munte", destinatie[30] = "Brasov";
	int ID = 1, zi = 3, luna = 4, an = 2007, pret = 200;
	strcpy(oferta.tip, tip);
	strcpy(oferta.destinatie, destinatie);
	oferta.ID = ID;
	oferta.zi = zi;
	oferta.luna = luna;
	oferta.an = an;
	oferta.pret = pret;
	assert(lst.nrElem == 0);
	adaugaOferta_repo(oferta, &lst);
	assert(lst.nrElem == 1);
}

void test_validare_oferta()
{
	OfferList lst;
	lst.nrElem = 0;
	Oferte oferta;
	char tip[30] = "city break", destinatie[30] = "Brasov";
	int ID = 1, zi = 3, luna = 4, an = 2007, pret = 200;
	strcpy(oferta.tip, tip);
	strcpy(oferta.destinatie, destinatie);
	oferta.ID = ID;
	oferta.zi = zi;
	oferta.luna = luna;
	oferta.an = an;
	oferta.pret = pret;
	assert(validare_oferta(oferta) == 1);
	strcpy(tip, "vale");
	strcpy(destinatie, "");
	ID = -1;
	zi = -1;
	luna = -1;
	an = -1;
	pret = -1;
	strcpy(oferta.tip, tip);
	strcpy(oferta.destinatie, destinatie);
	oferta.ID = ID;
	oferta.zi = zi;
	oferta.luna = luna;
	oferta.an = an;
	oferta.pret = pret;
	assert(validare_oferta(oferta) == 0);
}

void test_adaugaOferta_srv()
{
	OfferList lst;
	lst.nrElem = 0;
	char tip[30] = "munte", destinatie[30] = "Brasov";
	int ID = 1, zi = 3, luna = 4, an = 2007, pret = 200;
	assert(lst.nrElem == 0);
	adaugaOferta_srv(&lst, ID, tip, destinatie, pret, zi, luna, an);
	assert(lst.nrElem == 1);
	ID = 2;
	adaugaOferta_srv(&lst, ID, tip, destinatie, pret, zi, luna, an);
	assert(lst.nrElem == 2);
	adaugaOferta_srv(&lst, ID, tip, destinatie, pret, zi, luna, an);
	assert(lst.nrElem == 2);
}

void test_actualizeazaOferta_repo()
{
	OfferList lst;
	lst.nrElem = 0;
	Oferte oferta;
	char tip[30] = "munte", destinatie[30] = "Brasov";
	int ID = 1, zi = 3, luna = 4, an = 2007, pret = 200;
	strcpy(oferta.tip, tip);
	strcpy(oferta.destinatie, destinatie);
	oferta.ID = ID;
	oferta.zi = zi;
	oferta.luna = luna;
	oferta.an = an;
	oferta.pret = pret;
	assert(lst.nrElem == 0);
	adaugaOferta_repo(oferta, &lst);
	assert(lst.nrElem == 1);
	zi = 4;
	actualizeazaOferta_repo(oferta, &lst);
	assert(lst.nrElem == 1);
}

void test_actualizeazaOferta_srv()
{
	OfferList lst;
	lst.nrElem = 0;
	char tip[30] = "munte", destinatie[30] = "Brasov";
	int ID = 1, zi = 3, luna = 4, an = 2007, pret = 200;
	assert(lst.nrElem == 0);
	adaugaOferta_srv(&lst, ID, tip, destinatie, pret, zi, luna, an);
	assert(lst.nrElem == 1);
	ID = 2;
	adaugaOferta_srv(&lst, ID, tip, destinatie, pret, zi, luna, an);
	assert(lst.nrElem == 2);
	zi = 4;
	actualizeazaOferta_srv(&lst, ID, tip, destinatie, pret, zi, luna, an);
	assert(lst.nrElem == 2);
	ID = 3;
	actualizeazaOferta_srv(&lst, ID, tip, destinatie, pret, zi, luna, an);
	assert(lst.nrElem == 2);
}

void test_validare_id()
{
	OfferList lst;
	lst.nrElem = 0;
	int ID = 1;
	assert(validare_id(ID) == 1);
	ID = -1;
	assert(validare_id(ID) == 0);
}

void test_stergeOferta_repo()
{
	OfferList lst;
	lst.nrElem = 0;
	Oferte oferta;
	char tip[30] = "munte", destinatie[30] = "Brasov";
	int ID = 1, zi = 3, luna = 4, an = 2007, pret = 200;
	strcpy(oferta.tip, tip);
	strcpy(oferta.destinatie, destinatie);
	oferta.ID = ID;
	oferta.zi = zi;
	oferta.luna = luna;
	oferta.an = an;
	oferta.pret = pret;
	assert(lst.nrElem == 0);
	adaugaOferta_repo(oferta, &lst);
	assert(lst.nrElem == 1);
	stergeOferta_repo(ID, &lst);
	assert(lst.nrElem == 0);
	stergeOferta_repo(ID, &lst);
	assert(lst.nrElem == 0);
}

void test_stergeOferta_srv()
{
	OfferList lst;
	lst.nrElem = 0;
	char tip[30] = "munte", destinatie[30] = "Brasov";
	int ID = 1, zi = 3, luna = 4, an = 2007, pret = 200;
	assert(lst.nrElem == 0);
	adaugaOferta_srv(&lst, ID, tip, destinatie, pret, zi, luna, an);
	assert(lst.nrElem == 1);
	ID = 2;
	adaugaOferta_srv(&lst, ID, tip, destinatie, pret, zi, luna, an);
	assert(lst.nrElem == 2);
	adaugaOferta_srv(&lst, ID, tip, destinatie, pret, zi, luna, an);
	assert(lst.nrElem == 2);
	stergeOferta_srv(&lst, ID);
	assert(lst.nrElem == 1);
}

//Functia de rulare a tuturor testelor.
void run_tests()
{
	test_afis();
	test_creeazaOferta_repo();
	test_adaugaOferta_repo();
	test_validare_oferta();
	test_adaugaOferta_srv();
	test_actualizeazaOferta_repo();
	test_actualizeazaOferta_srv();
	test_validare_id();
	test_stergeOferta_repo();
	test_stergeOferta_srv();
	printf("Succes!\n");
}