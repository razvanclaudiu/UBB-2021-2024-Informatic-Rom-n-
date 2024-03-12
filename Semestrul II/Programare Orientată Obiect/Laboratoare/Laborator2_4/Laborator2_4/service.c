#include <string.h>
#include "service.h"
#include "Oferta.h"
#include "listaoferta.h"

OfferStore createStore()
{
	/*creaza un store pentru ofertele firmei
	post: se va returna o entitate OfferStore
	*/
	OfferStore rez;
	rez.allOffers = creeaza_lista_oferte(1, distruge_oferta);
	rez.undoList = creeaza_lista_oferte(1, distruge_lista_oferte);
	return rez;
}

void destroyStore(OfferStore* store)
{
	/*functia de dealocare a memoriei ocupata de o entitate OfferStore
	store - OfferStore
	post: memoria va fi dealocata
	*/
	distruge_lista_oferte(store->allOffers);
	distruge_lista_oferte(store->undoList);
}

int undo(OfferStore* store) 
{
	/*functia de undo a ultimei operatii
	store - OfferStore
	post: se va scoate ultimul element din lista undoList si va fi pus in allOffers
	*/
	if (size(store->undoList) == 0) {
		return 1;
	}
	Listaoferte* l = removeLast(store->undoList);
	distruge_lista_oferte(store->allOffers);
	store->allOffers = l;
	return 0;
}


int service_adauga_oferta(OfferStore* store, char* tip, char* adresa, int suprafata,int pret)
{
	/*functie de service pentru adaugarea unei oferte in lista
	lista_moferte - Listaoferte
	tip, adresa - string
	suprafata,pret - intreg
	pre: lista_oferte valida; tip-sa fie string-ul casa,apartament sau teren, adresa sa nu fie stringul vid; suprafata,pret > 0
	post: service_adauga_oferte = 1,2,3,4 daca oferta este invalida
									   0 daca oferta a fost adaugata cu succes
	*/
	Oferta* offer = creeaza_oferta(tip, adresa, suprafata,pret);
	Listaoferte* toUndo = copiaza_lista_oferte(store->allOffers);
	int cod_eroare_validare = valideaza_oferta(offer);
	if (cod_eroare_validare != 0)
	{
		distruge_oferta(offer);
		distruge_lista_oferte(toUndo);
		return cod_eroare_validare;
	}
	adauga_oferta_in_lista(store->allOffers, offer);
	adauga_oferta_in_lista(store->undoList, toUndo);
	return 0;
}

int service_actualizare_oferta(OfferStore* store, char*tip, char* adresa, int pret_actualizat, int suprafata)
{
	/*service pentru actualizarea unei oferte
	pret_actualizat - intreg
	pre: lista_oferte valida; tipul sa fie casa teren sau apartament, adresa sa nu fie stringul vid; pret_actualizat > 0
	post: service_actualizare_oferta = -1 daca oferta nu exista in lista
												   0 daca oferta a fost actualizata
	*/
	Oferta* oferta_auxiliara = creeaza_oferta(tip, adresa, suprafata, 0);
	Listaoferte* toUndo = copiaza_lista_oferte(store->allOffers);
	int oferta_inexistenta = -1, pozitie_oferta;
	pozitie_oferta = cauta_oferta_in_lista(store->allOffers, oferta_auxiliara);
	if (pozitie_oferta == oferta_inexistenta)
	{
		distruge_oferta(oferta_auxiliara);
		distruge_lista_oferte(toUndo);
		return oferta_inexistenta;
	}
	actualizare_oferta(store->allOffers, pret_actualizat, pozitie_oferta);
	adauga_oferta_in_lista(store->undoList, toUndo);
	distruge_oferta(oferta_auxiliara);
	return 0;

}

int service_sterge_oferta(OfferStore* store, char* tip, char* adresa,int suprafata)
{
	/*service pentru a stergerea unei oferte din lista
	tip,adresa - string
	pre: lista_oferte valida; tipul sa fie casa teren sau apartament, adresa sa nu fie stringul vid; pret_actualizat > 0
	post: service_actualizare_oferta = -1 daca oferta nu exista in lista
												   0 daca oferta a fost stearsa
	*/
	Oferta* oferta_auxiliara = creeaza_oferta(tip, adresa, suprafata,0);
	Listaoferte* toUndo = copiaza_lista_oferte(store->allOffers);
	int oferta_inexistenta = -1, pozitie_oferta;
	pozitie_oferta = cauta_oferta_in_lista(store->allOffers, oferta_auxiliara);
	if (pozitie_oferta == oferta_inexistenta)
	{
		distruge_oferta(oferta_auxiliara);
		distruge_lista_oferte(toUndo);
		return oferta_inexistenta;
	}
	sterge_oferta_din_lista(store->allOffers, pozitie_oferta);
	adauga_oferta_in_lista(store->undoList, toUndo);
	distruge_oferta(oferta_auxiliara);
	return 0;
}

Listaoferte* filteroffers_tip(Listaoferte* lista_oferte, char* tip) {
	/* service pentru filtrarea unei oferte din lista
	tip-string
	lista_oferte-Listaoferte
	post: lista oferte filtrata dupa un anumit tip */
	
		Listaoferte* filteroffers = creeaza_lista_oferte(lista_oferte->capacitate_lista, distruge_oferta);
		for (int i = 0; i < lista_oferte->numar_oferte; i++) {
			Oferta* offer = returneaza_oferta_de_pe_pozitie(lista_oferte, i);
			if (strcmp(tip, offer->tip) == 0)
				adauga_oferta_in_lista(filteroffers, creeaza_oferta(offer->tip, offer->adresa, offer->suprafata, offer->pret));
		}
		return filteroffers;
	

}

Listaoferte* filteroffers_pret(Listaoferte* lista_oferte, int pret) {
	/* service pentru filtrarea unei oferte din lista
	pret - intreg
	lista_oferte-Listaoferte
	post: lista oferte filtrata dupa un anumit pret */

	Listaoferte* filteroffers = creeaza_lista_oferte(lista_oferte->capacitate_lista, distruge_oferta);
	for (int i = 0; i < lista_oferte->numar_oferte; i++) {
		Oferta* offer = returneaza_oferta_de_pe_pozitie(lista_oferte, i);
		if (pret == offer->pret)
			adauga_oferta_in_lista(filteroffers, creeaza_oferta(offer->tip, offer->adresa, offer->suprafata, offer->pret));
	}
	return filteroffers;


}



//Listaoferte sortare_pret(Listaoferte* lista_oferte,int ordine)
//{
//	/*
//	service pentru sortarea listei de oferte dupa pret(functie facuta inainte de cerinta de la lab)
//	lista_oferte-Listaoferte
//	ordine-descrescator/crescator
//	post: sortl-lista sortata dupa pret 
//	*/
//
//	Listaoferte sortlist = copiaza_lista_oferte(lista_oferte);
//	//Sortare
//	int lstsortata = 0;
//	Oferta aux;
//	while (!lstsortata) {
//		lstsortata = 1;
//		for (int i = 0; i < lista_oferte->numar_oferte- 1; i++) {
//			if (comparare_pret(&sortlist.lista[i], &sortlist.lista[i + 1], ordine)) {
//				lstsortata = 0;
//				aux= sortlist.lista[i];
//				sortlist.lista[i] = sortlist.lista[i+1];
//				sortlist.lista[i+1] = aux;
//			}
//		}
//	}
//	return sortlist;
//}

int comparare_tip(Oferta* offer_1, Oferta* offer_2, int ordine)
/*
functie de comparare pentru tipul ofertelor
*/
{
	if (ordine == 1) {
		if (strcmp(offer_1->tip, offer_2->tip)>0)
			return 1;
		else return 0;}
	else {
		if (strcmp(offer_1->tip, offer_2->tip)<0)
			return 1;
		else return 0;

	}
}

int comparare_pret(Oferta* offer_1, Oferta* offer_2, int ordine) {
	/*
	functie de comparare pentru pretul ofertelor 
	offer_1-oferta, offer_2-oferta, ordine-1-crescator,0-descrescator */
	if (ordine == 1) {
		if (offer_1->pret > offer_2->pret)
			return 1;
		else return 0;}
	else {
		if (offer_1->pret < offer_2->pret)
			return 1;
		else return 0;

	}
}


Listaoferte* sortare(Listaoferte* lista_oferte, int ordine, int(*fct)(Oferta*,Oferta*,int))
{
	/*
	service pentru sortarea listei de oferte 
	lista_oferte-Listaoferte
	ordine-descrescator/crescator
	post: sortl-lista sortata 
	*/

	Listaoferte* sortlist = copiaza_lista_oferte(lista_oferte);
	//Sortare
	int lstsortata = 0;
	Oferta* aux;
	while (!lstsortata) {
		lstsortata = 1;
		for (int i = 0; i < lista_oferte->numar_oferte - 1; i++) {
			if (fct(sortlist->lista[i], sortlist->lista[i + 1], ordine)) {
				lstsortata = 0;
				aux = sortlist->lista[i];
				sortlist->lista[i] = sortlist->lista[i + 1];
				sortlist->lista[i + 1] = aux;
			}
		}
	}
	return sortlist;
}

