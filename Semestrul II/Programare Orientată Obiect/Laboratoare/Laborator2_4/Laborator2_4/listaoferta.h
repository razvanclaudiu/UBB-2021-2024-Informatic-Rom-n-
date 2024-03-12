#pragma once
#include "Oferta.h"

typedef void* ElemType;

typedef void(*DestroyFct) (ElemType);

typedef struct
{
	ElemType* lista;
	int capacitate_lista;
	int numar_oferte;
	DestroyFct dfnc;
}Listaoferte;

Listaoferte* creeaza_lista_oferte(int capacitate_lista, DestroyFct f);

ElemType removeLast(Listaoferte* l);

void distruge_lista_oferte(Listaoferte* lista_oferte);

ElemType returneaza_oferta_de_pe_pozitie(Listaoferte* lista_oferte, int pozitie);

void adauga_oferta_in_lista(Listaoferte* lista_oferte, ElemType offer);

int cauta_oferta_in_lista(Listaoferte* lista_oferte, ElemType offer);

void actualizare_oferta(Listaoferte* lista_oferte, int pret_actualizat, int pozitie);

void sterge_oferta_din_lista(Listaoferte* lista_oferte, int pozitie);

int redimensioneaza_lista_oferte(Listaoferte* lista_oferte);

Listaoferte* copiaza_lista_oferte(Listaoferte* lista_oferte);
