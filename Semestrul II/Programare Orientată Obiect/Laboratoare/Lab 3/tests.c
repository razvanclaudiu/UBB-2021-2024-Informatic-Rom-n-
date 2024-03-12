#include "service.h"
#include "repository.h"
#include "entities.h"
#include "tests.h"
#include <assert.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#pragma warning(disable:4996)

void test_afis()
{
	OfferList lst = createEmpty();
	Oferte oferta;
	char tip[30] = "munte", destinatie[30] = "Brasov";
	int ID = 1, zi = 3, luna = 4, an = 2007, pret = 200;
	oferta = creeazaOferta_repo(ID, tip, destinatie, pret, zi, luna, an);
	afis(oferta);
	destroyOferta(&oferta);
	destroyList(&lst);
}

void test_creeazaOferta_repo()
{
	Oferte oferta1, oferta2;
	char tip[30] = "munte", destinatie[30] = "Brasov";
	int ID = 1, zi = 3, luna = 4, an = 2007, pret = 200;
	int nr = (int)strlen(tip) + 1;
	oferta1 = creeazaOferta_repo(ID, tip, destinatie, pret, zi, luna, an);
	oferta2 = creeazaOferta_repo(ID, tip, destinatie, pret, zi, luna, an);
	assert(strcmp(oferta1.tip,oferta2.tip)==0);
	assert(strcmp(oferta1.destinatie, oferta2.destinatie) == 0);
	assert(oferta1.ID == oferta2.ID);
	assert(oferta1.pret == oferta2.pret);
	assert(oferta1.zi == oferta2.zi);
	assert(oferta1.luna == oferta2.luna);
	assert(oferta1.an == oferta2.an);
	destroyOferta(&oferta1);
	destroyOferta(&oferta2);
}

void test_adaugaOferta_repo()
{
	OfferList lst = createEmpty();
	Oferte oferta;
	char tip[30] = "munte", destinatie[30] = "Brasov";
	int ID = 1, zi = 3, luna = 4, an = 2007, pret = 200;
	oferta = creeazaOferta_repo(ID, tip, destinatie, pret, zi, luna, an);
	assert(lst.nrElem == 0);
	adaugaOferta_repo(oferta, &lst);
	assert(lst.nrElem == 1);
	ID = 2;
	oferta = creeazaOferta_repo(ID, tip, destinatie, pret, zi, luna, an);
	adaugaOferta_repo(oferta, &lst);
	assert(lst.nrElem == 2);
	ID = 3;
	oferta = creeazaOferta_repo(ID, tip, destinatie, pret, zi, luna, an);
	adaugaOferta_repo(oferta, &lst);
	assert(lst.nrElem == 3);
	destroyList(&lst);
}

void test_validare_oferta()
{
	OfferList lst = createEmpty();
	Oferte oferta;
	char tip[30] = "city break", destinatie[30] = "Brasov";
	int ID = 1, zi = 3, luna = 4, an = 2007, pret = 200;
	oferta = creeazaOferta_repo(ID, tip, destinatie, pret, zi, luna, an);
	assert(validare_oferta(oferta) == 1);
	destroyOferta(&oferta);
	strcpy(tip, "vale");
	strcpy(destinatie, "");
	ID = -1;
	zi = -1;
	luna = -1;
	an = -1;
	pret = -1;
	oferta = creeazaOferta_repo(ID, tip, destinatie, pret, zi, luna, an);
	assert(validare_oferta(oferta) == 0);
	destroyOferta(&oferta);
	destroyList(&lst);
}

void test_adaugaOferta_srv()
{
	OfferList lst = createEmpty();
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
	ID = -1;
	int sem = adaugaOferta_srv(&lst, ID, tip, destinatie, pret, zi, luna, an);
	assert(sem == 0);
	destroyList(&lst);
}

void test_actualizeazaOferta_repo()
{
	OfferList lst = createEmpty();
	Oferte oferta;
	char tip[30] = "munte", destinatie[30] = "Brasov";
	int ID = 1, zi = 3, luna = 4, an = 2007, pret = 200;
	oferta = creeazaOferta_repo(ID, tip, destinatie, pret, zi, luna, an);
	assert(lst.nrElem == 0);
	adaugaOferta_repo(oferta, &lst);
	assert(lst.nrElem == 1);
	zi = 4;
	oferta = creeazaOferta_repo(ID, tip, destinatie, pret, zi, luna, an);
	actualizeazaOferta_repo(oferta, &lst);
	assert(lst.nrElem == 1);
	destroyList(&lst);
}

void test_actualizeazaOferta_srv()
{
	OfferList lst = createEmpty();
	char tip[30] = "munte", destinatie[30] = "Brasov";
	int ID = 1, zi = 3, luna = 4, an = 2007, pret = 200;
	assert(lst.nrElem == 0);
	adaugaOferta_srv(&lst, ID, tip, destinatie, pret, zi, luna, an);
	assert(lst.nrElem == 1);
	ID = 2;
	strcpy(destinatie, "Brasov1");
	adaugaOferta_srv(&lst, ID, tip, destinatie, pret, zi, luna, an);
	assert(lst.nrElem == 2);
	zi = 4;
	strcpy(destinatie, "Brasov2");
	actualizeazaOferta_srv(&lst, ID, tip, destinatie, pret, zi, luna, an);
	assert(lst.nrElem == 2);
	ID = 3;
	strcpy(destinatie, "Brasov3");
	actualizeazaOferta_srv(&lst, ID, tip, destinatie, pret, zi, luna, an);
	assert(lst.nrElem == 2);
	ID = -1;
	strcpy(destinatie, "Brasov4");
	int sem = actualizeazaOferta_srv(&lst, ID, tip, destinatie, pret, zi, luna, an);
	assert(sem == 0);
	destroyList(&lst);
}

void test_validare_id()
{
	OfferList lst = createEmpty();
	int ID = 1;
	assert(validare_id(ID) == 1);
	ID = -1;
	assert(validare_id(ID) == 0);
	destroyList(&lst);
}

void test_stergeOferta_repo()
{
	OfferList lst = createEmpty();
	Oferte oferta;
	char tip[30] = "munte", destinatie[30] = "Brasov";
	int ID = 1, zi = 3, luna = 4, an = 2007, pret = 200;
	oferta = creeazaOferta_repo(ID, tip, destinatie, pret, zi, luna, an);
	assert(lst.nrElem == 0);
	adaugaOferta_repo(oferta, &lst);
	assert(lst.nrElem == 1);
	stergeOferta_repo(ID, &lst);
	assert(lst.nrElem == 0);
	stergeOferta_repo(ID, &lst);
	assert(lst.nrElem == 0);
	destroyList(&lst);
}

void test_stergeOferta_srv()
{
	OfferList lst = createEmpty();
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
	ID = -1;
	int sem = stergeOferta_srv(&lst, ID);
	assert(sem == 0);
	destroyList(&lst);
}

void test_ordonareOferta_repo()
{
	OfferList lst = createEmpty();
	char tip[30] = "munte", destinatie[30] = "Brasov";
	int ID = 1, zi = 3, luna = 4, an = 2007, pret = 200;
	assert(lst.nrElem == 0);
	adaugaOferta_srv(&lst, ID, tip, destinatie, pret, zi, luna, an);
	assert(lst.nrElem == 1);
	ID = 3;
	strcpy(tip, "city break");
	strcpy(destinatie, "Bucuresti");
	pret = 400;
	zi = 23;
	luna = 12;
	an = 2022;
	adaugaOferta_srv(&lst, ID, tip, destinatie, pret, zi, luna, an);
	assert(lst.nrElem == 2);
	ID = 2;
	strcpy(tip, "mare");
	strcpy(destinatie, "Constanta");
	pret = 300;
	zi = 19;
	luna = 8;
	an = 2022;
	adaugaOferta_srv(&lst, ID, tip, destinatie, pret, zi, luna, an);
	assert(lst.nrElem == 3);
	ordonareOferta_repo(&lst, sortprice, 0);
	assert(lst.list[0].ID == 1);
	assert(lst.list[1].ID == 2);
	assert(lst.list[2].ID == 3);
	ordonareOferta_repo(&lst, sortprice, 1);
	assert(lst.list[0].ID == 3);
	assert(lst.list[1].ID == 2);
	assert(lst.list[2].ID == 1);
	ordonareOferta_repo(&lst, sortdestination, 0);
	assert(lst.list[0].ID == 1);
	assert(lst.list[1].ID == 3);
	assert(lst.list[2].ID == 2);
	ordonareOferta_repo(&lst, sortdestination, 1);
	assert(lst.list[0].ID == 2);
	assert(lst.list[1].ID == 3);
	assert(lst.list[2].ID == 1);
	destroyList(&lst);

}

void test_ordonareOferta_srv()
{
	OfferList lst = createEmpty();
	char tip[30] = "munte", destinatie[30] = "Brasov";
	int ID = 1, zi = 3, luna = 4, an = 2007, pret = 200;
	assert(lst.nrElem == 0);
	adaugaOferta_srv(&lst, ID, tip, destinatie, pret, zi, luna, an);
	assert(lst.nrElem == 1);
	ID = 2;
	strcpy(tip, "mare");
	strcpy(destinatie, "Constanta");
	pret = 300;
	zi = 19;
	luna = 8;
	an = 2022;
	adaugaOferta_srv(&lst, ID, tip, destinatie, pret, zi, luna, an);
	assert(lst.nrElem == 2);
	ID = 3;
	strcpy(tip, "city break");
	strcpy(destinatie, "Bucuresti");
	pret = 400;
	zi = 23;
	luna = 12;
	an = 2022;
	adaugaOferta_srv(&lst, ID, tip, destinatie, pret, zi, luna, an);
	assert(lst.nrElem == 3);
	ordonareOferta_srv(&lst, sortprice, 0);
	assert(lst.list[0].ID == 1);
	assert(lst.list[1].ID == 2);
	assert(lst.list[2].ID == 3);
	ordonareOferta_srv(&lst, sortprice, 1);
	assert(lst.list[0].ID == 3);
	assert(lst.list[1].ID == 2);
	assert(lst.list[2].ID == 1);
	ordonareOferta_srv(&lst, sortdestination, 0);
	assert(lst.list[0].ID == 1);
	assert(lst.list[1].ID == 3);
	assert(lst.list[2].ID == 2);
	ordonareOferta_srv(&lst, sortdestination, 1);
	assert(lst.list[0].ID == 2);
	assert(lst.list[1].ID == 3);
	assert(lst.list[2].ID == 1);
	destroyList(&lst);

}

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
	test_ordonareOferta_repo();
	test_ordonareOferta_srv();
	printf("Succes!\n");
}