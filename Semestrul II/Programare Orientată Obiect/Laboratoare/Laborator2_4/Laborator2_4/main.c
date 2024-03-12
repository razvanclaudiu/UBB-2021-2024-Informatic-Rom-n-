//#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

#include <stdio.h>
#include <string.h>
#include "teste.h"
#include "listaoferta.h"
#include "Oferta.h"
#include "service.h"
#pragma warning(disable:4996);


void ui_adauga_oferta_in_lista(OfferStore* store)
{
	/*functie de ui pentru adaugarea unei oferte in lista
	lista_oferte - Listaoferte
	pre: lista_oferte valida
	post: -
	*/
	char tip[30], adresa[30], reziduu_citire[20];
	int suprafata, pret,status_adaugare, nr;
	printf("Introduceti tipul ofertei:\n");
	gets_s(tip, 30);
	printf("Introduceti adresa:\n");
	gets_s(adresa, 30);
	printf("Introduceti suprafata:\n");
	nr = scanf("%d", &suprafata);
	printf("Introduceti pretul :\n");
	nr = scanf("%d", &pret);
	gets_s(reziduu_citire, 20);

	status_adaugare = service_adauga_oferta(store, tip, adresa, suprafata,pret);
	if (status_adaugare == 1 || status_adaugare == 2 || status_adaugare == 3 || status_adaugare==4)
	{
		printf("Oferta invalida!\n");
		return;
	}
	printf(" Oferta adaugata cu succes!\n");
}


void ui_afiseaza_oferte(Listaoferte* lista_oferte)
{
	/*functie care afiseaza ofertele din lista
	lista_oferte - Listaoferte
	pre: lista_oferte valida
	post: -
	*/
	for (int i = 0; i < lista_oferte->numar_oferte; i++)
	{
		Oferta* offer = returneaza_oferta_de_pe_pozitie(lista_oferte,i);
		printf("%s %s %d %d\n", offer->tip, offer->adresa, offer->suprafata, offer->pret);
	}
		
}



void ui_actualizare_oferta(OfferStore* store)
{
	/*functie de ui pentru actualizarea  unei oferte
	lista_oferte - Lista_oferte
	pre: lista_oferte valida
	post: -
	*/
	char tip[30], adresa[30], reziduu_citire[20];
	int pret_actualizat, status_actualizare,suprafata, nr ;

	printf("Introduceti tipul ofertei:\n");
	gets_s(tip, 30);
	printf("Introduceti adresa:\n");
	gets_s(adresa, 30);
	printf("Introduceti pretul nou:\n");
	nr = scanf("%d", &pret_actualizat);
	printf("Introduceti suprafata:\n");
	nr = scanf("%d", &suprafata);
	gets_s(reziduu_citire, 20);

	status_actualizare = service_actualizare_oferta(store, tip, adresa, pret_actualizat, suprafata);

	if (status_actualizare == -1)
	{
		printf("Oferta inexistenta!\n");
		return;
	}
	else
		printf("Oferta actualizata cu succes!\n");
}


void ui_sterge_oferta_din_lista(OfferStore* store)
{
	/*functie de ui pentru stergerea unei oferte din lista
	lista_oferte - Lista_oferte
	pre: lista_oferte valida
	post: -
	*/
	char tip[30], adresa[30];
	int status_stergere,suprafata, nr;

	printf("Introduceti tipul ofertei:\n");
	gets_s(tip, 30);
	printf("Introduceti adresa:\n");
	gets_s(adresa, 30);
	printf("Introduceti suprafata:\n");
	nr = scanf("%d", &suprafata);

	status_stergere = service_sterge_oferta(store, tip, adresa,suprafata);

	if (status_stergere == -1)
	{
		printf("Oferta inexistenta!\n");
		return;
	}
	else
		printf("Oferta stearsa cu succes!\n");
}

void ui_filtreaza_oferte_tip(OfferStore* store)
{
	/*functie de ui pentru filtrarea ofertelor dupa un anumit tip
	lista_oferte-Listaoferte
	pre: lista_oferte valida
	post:lista filtrata-Listaoferte daca sunt oferte care sunt de acel tip
	*/
	char tip[30];
	printf("Introduceti tipul ofertei dupa care doriti filtrarea:\n");
	gets_s(tip, 30);
	Listaoferte* filteredList = filteroffers_tip(store->allOffers, tip);
	if (filteredList->numar_oferte==0)
	{
		printf("Nu exista oferte care sa aiba acest tip!");
		return;
	}
	ui_afiseaza_oferte (filteredList);
	distruge_lista_oferte(filteredList);
}

void ui_filtreaza_oferte_pret(OfferStore* store)
{
	/*functie de ui pentru filtrarea ofertelor dupa un anumit tip
	lista_oferte-Listaoferte
	pre: lista_oferte valida
	post:lista filtrata-Listaoferte daca sunt oferte care sunt de acel tip
	*/
	int pret, nr;
	printf("Introduceti pretul ofertei dupa care doriti filtrarea:\n");
	nr = scanf("%d", &pret);
	Listaoferte* filteredList = filteroffers_pret(store->allOffers, pret);
	if (filteredList->numar_oferte == 0)
	{
		printf("Nu exista oferte care sa aiba acest pret!");
		return;
	}
	ui_afiseaza_oferte(filteredList);
	distruge_lista_oferte(filteredList);
}


void ui_sortare_pret(OfferStore* store)
{
	/* functie de ui pentru sortarea ofertelor  dupa pret
	pre:lista_oferte-Listaoferte
	post:sortlist-listaoferte sortata  dupa pret
	*/
	int ordine, nr ;
	printf("Introduceti ordinea pe care o doriti.\nTastati 1 pentru ordine crescatoare, 0 pentru descrescatoare:\n");
	nr = scanf("%d", &ordine);
	Listaoferte* sortl = sortare(store->allOffers, ordine, comparare_pret);
	if (sortl->numar_oferte == 0)
	{
		printf("Nu exista inca oferte in lista!");
		return;
	}
	ui_afiseaza_oferte(sortl);
	//distruge_lista_oferte(sortl);
}

void ui_sortare_tip(OfferStore* store)
{
	/* functie de ui pentru sortarea ofertelor  dupa tip
	pre:lista_oferte-Listaoferte
	post:sortlist-listaoferte sortata  dupa tip
	*/
	int ordine, nr;
	printf("Introduceti ordinea pe care o doriti.\nTastati 1 pentru ordine crescatoare, 0 pentru descrescatoare:\n");
	nr = scanf("%d", &ordine);
	Listaoferte* sortl = sortare(store->allOffers, ordine,comparare_tip);
	if (sortl->numar_oferte == 0)
	{
		printf("Nu exista inca oferte in lista!");
		return;
	}
	ui_afiseaza_oferte(sortl);
	distruge_lista_oferte(sortl);
}

void UI()
{
	//meniul aplicatiei
	OfferStore store = createStore();
	int cmd, nr;
	char reziduu_citire[20];
	printf("0.Iesire\n1.Adauga oferta\n2.Sterge o anumita oferta.\n3.Actualizeaza o anumita oferta\n4.Filtreaza ofertele dupa un anumit tip\n5.Filtreaza ofertele dupa un anumit pret\n6.Sortare oferte  dupa pret.\n7.Sortare oferte  dupa tip.\n8.Undo ultima operatie\n9.Afiseaza toate ofertele\n10.Randomize oferte\n");
	while (1)
	{
		printf("Introduceti comanda:\n");
		nr = scanf("%d", &cmd);
		gets_s(reziduu_citire, 20);
		if (cmd == 0)
			break;
		if (cmd == 1)
			ui_adauga_oferta_in_lista(&store);
		if (cmd == 2)
			ui_sterge_oferta_din_lista(&store);
		if (cmd == 3)
			ui_actualizare_oferta(&store);
		if (cmd == 4)
			ui_filtreaza_oferte_tip(&store);
		if (cmd == 5)
			ui_filtreaza_oferte_pret(&store);
		if (cmd == 6)
			ui_sortare_pret(&store);
		if (cmd == 7)
			ui_sortare_tip(&store);
		if (cmd == 8)
			if (undo(&store) != 0)
				printf("No more undos!\n");
		if (cmd == 9)
			ui_afiseaza_oferte(store.allOffers);
		if (cmd == 10)
		{
			char test_tip[30], test_adresa[30];
			int test_suprafata, test_pret;

			strcpy(test_tip, "casa");
			strcpy(test_adresa, "Vidraru");
			test_pret = 50;
			test_suprafata = 80;
			service_adauga_oferta(&store, test_tip, test_adresa, test_suprafata, test_pret);

			strcpy(test_tip, "apartament");
			strcpy(test_adresa, "Dunarii");
			test_pret = 100;
			test_suprafata = 60;
			service_adauga_oferta(&store, test_tip, test_adresa, test_suprafata, test_pret);

			strcpy(test_tip, "teren");
			strcpy(test_adresa, "Turnului");
			test_pret = 200;
			test_suprafata = 150;
			service_adauga_oferta(&store, test_tip, test_adresa, test_suprafata, test_pret);

			strcpy(test_tip, "apartament");
			strcpy(test_adresa, "Ploiesti");
			test_pret = 50;
			test_suprafata = 100;
			service_adauga_oferta(&store, test_tip, test_adresa, test_suprafata, test_pret);
		}
	}
	destroyStore(&store);
}

int main()
{
	ruleaza_toate_testele();
	UI();
	_CrtDumpMemoryLeaks();
	return 0;
}