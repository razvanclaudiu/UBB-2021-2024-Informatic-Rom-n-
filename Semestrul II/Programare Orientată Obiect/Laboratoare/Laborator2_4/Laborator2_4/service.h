#pragma once
#include "Listaoferta.h"
#include "Oferta.h"

typedef struct {
	Listaoferte* allOffers;
	Listaoferte* undoList;
} OfferStore;

//typedef int(*Functie_comparare)(Oferta* offer_1, Oferta* offer_2, int ordine);
OfferStore createStore();

void destroyStore(OfferStore* store);

int undo(OfferStore* store);

int service_adauga_oferta(OfferStore* lista_oferte, char* tip, char* adresa, int suprafata,int pret);

int service_actualizare_oferta(OfferStore* lista_oferte, char* tip, char* adresa, int pret_actualizat);

int service_sterge_oferta(OfferStore* lista_oferte, char* tip, char* adresa);

Listaoferte* filteroffers_tip(Listaoferte* lista_oferte, char* tip);

Listaoferte* filteroffers_pret(Listaoferte* lista_oferte, int pret);

//Listaoferte sortare_pret(Listaoferte* lista_oferte, int ordine);

int comparare_tip(Oferta* offer_1, Oferta* offer_2, int ordine);

int comparare_pret(Oferta* offer_1, Oferta* offer_2, int ordine);

Listaoferte* sortare(Listaoferte* lista_oferte, int ordine, int(*comparare_tip)(Oferta*, Oferta*, int));
