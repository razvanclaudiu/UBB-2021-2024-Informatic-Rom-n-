#include "listaoferta.h"
#include "Oferta.h"
#include <stdlib.h>
#include <string.h>
//#pragma warning(disable:6386)

Listaoferte* creeaza_lista_oferte(int capacitate_lista, DestroyFct f)
{
	/*creeaza o lista noua de oferte
	capacitate_lista - intreg
	f - functia de destroy folosita
	pre: capacitate_lista >0
	post: lista_oferte - Listaoferte valida
	*/
	Listaoferte* lista_oferte = malloc(sizeof(Listaoferte));
	if (lista_oferte)
	{
		lista_oferte->lista = (ElemType*)malloc(capacitate_lista * sizeof(ElemType));
		lista_oferte->capacitate_lista = capacitate_lista;
		lista_oferte->numar_oferte = 0;
		lista_oferte->dfnc = f;
	}
	return lista_oferte;
}

int size(Listaoferte* l) 
{
	/*returneaza numarul de oferte din lista
	l - Listaoferte
	post: se returneaza un intreg
	*/
	return l->numar_oferte;
}

ElemType removeLast(Listaoferte* l) 
{
	/*se strege ultimul element din lista de undo
    l - Listaoferte
	pre: undoList.numar_oferte = intreg
	post: undoList.numar_oferte = intreg - 1 
	*/
	ElemType rez = l->lista[l->numar_oferte - 1];
	l->numar_oferte -= 1;
	return rez;
}

void distruge_lista_oferte(Listaoferte* lista_oferte)
{

	/*distruge o lista existenta de oferte (elibereaza memoria alocata)
	lista_oferte - Listaoferte
	pre: lista_oferte valida
	post: memoria a fost eliberata
	*/
	int i;
	for (i = 0; i < lista_oferte->numar_oferte; i++)
	{
		lista_oferte->dfnc(lista_oferte->lista[i]);
	}
	free(lista_oferte->lista);
	free(lista_oferte);
}

int cauta_oferta_in_lista(Listaoferte* lista_oferte, ElemType offer)
{
	/*cauta o oferta in lista
	pre: lista_oferte valida; oferta valid
	post: cauta_oferta_in_lista = i, oferta este pe pozitia i in lista
									   -1, oferta nu este in lista
	*/
	int pozitie = -1;
	for (int i = 0; i < lista_oferte->numar_oferte && pozitie == -1; i++)
		if (verifica_egalitate_intre_oferte(lista_oferte->lista[i], offer) == 1)
			pozitie = i;
	return pozitie;
}

void adauga_oferta_in_lista(Listaoferte* lista_oferte, ElemType offer)
{
	/*adauga oferta in lista
	lista_oferta - Listaoferte
	offer - oferta
	pre: lista_oferte valida; offer valida
	post: lista_oferte-Listaoferte; lista_oferte' = lista_oferte+{offer}
	*/
	if (lista_oferte->numar_oferte == lista_oferte->capacitate_lista)
		redimensioneaza_lista_oferte(lista_oferte);
	lista_oferte->lista[lista_oferte->numar_oferte] = offer;
	lista_oferte->numar_oferte++;
}

int redimensioneaza_lista_oferte(Listaoferte* lista_oferte)
{
	/*mareste capacitatea maxima a listei de oferte
	lista_moferte - Listaoferte
	pre: lista_oferte valida
	post: lista_oferte'-Listaoferte; lista_oferte'.capacitate_lista = 2*lista_oferte.capacitate_lista
	*/
	int capacitate_noua = lista_oferte->capacitate_lista * 2;
	if (capacitate_noua != 0)
	{
		ElemType* lista_noua = (ElemType*)malloc((capacitate_noua) * sizeof(ElemType));
		if (lista_noua != NULL)
			for (int i = 0; i <= lista_oferte->numar_oferte - 1; i++)
				lista_noua[i] = lista_oferte->lista[i];
		free(lista_oferte->lista);
		lista_oferte->lista = lista_noua;
		lista_oferte->capacitate_lista = capacitate_noua;
	}
}

ElemType returneaza_oferta_de_pe_pozitie(Listaoferte* lista_oferte, int pozitie)
{
	/*returneaza o oferta de pe o pozitie data
	lista_oferte - Listaoferte
	pozitie - intreg
	pre: lista_oferte valida; pozitie>=0, pozitie<=numar_oferte
	post: -
	*/
	return lista_oferte->lista[pozitie];
}

Listaoferte* copiaza_lista_oferte(Listaoferte* lista_oferte)
{
	/*copiaza continutul unei liste de oferte
	lista_oferte - Listaoferte
	pre: lista_oferte valida
	post: copie_lista_oferte = lista_oferte
	*/
	Listaoferte* copie_lista_oferte = creeaza_lista_oferte(lista_oferte->capacitate_lista, distruge_oferta);
	for (int i = 0; i < lista_oferte->numar_oferte; i++)
	{
		Oferta* offer = returneaza_oferta_de_pe_pozitie(lista_oferte, i);
		offer = copiaza_oferta(offer);
		adauga_oferta_in_lista(copie_lista_oferte, offer);
	}
	//Oferta* offer1 = copie_lista_oferte->lista[0];
	return copie_lista_oferte;
}

void actualizare_oferta(Listaoferte* lista_oferte, int pret_actualizat, int pozitie)
{
	/*actualizeaza pretul unei oferte din lista
	lista_oferte - Listaoferte
	pret_actualizat - intreg
	pozitie - intreg
	pre: lista_oferte valida; pret_actualizat > 0; pozitie>=0, pozitie<=numar_oferte
	*/
	Oferta* offer = returneaza_oferta_de_pe_pozitie(lista_oferte, pozitie);
	offer->pret = pret_actualizat;
	lista_oferte->lista[pozitie] = offer;
}

void sterge_oferta_din_lista(Listaoferte* lista_oferte, int pozitie)
{
	/*sterge o oferta din lista
	lista_oferte - Listaoferte
	pozitie - intreg
	pre: lista_oferte valida; pozite>=0, pozitie<=numar_oferte
	post: lista_oferte'-Listaoferte; lista_oferte' = lista_oferte-{oferta}
	*/
	if (lista_oferte->capacitate_lista != 0)
	{
		ElemType* lista_noua = (ElemType*)malloc(lista_oferte->capacitate_lista * sizeof(ElemType));
		int pozitie_lista_noua = 0;
		if (lista_noua)
		{
			for (int i = 0; i < lista_oferte->numar_oferte; i++)
				if (i != pozitie)
				{
					lista_noua[pozitie_lista_noua] = lista_oferte->lista[i];
					pozitie_lista_noua++;
				}
		}
		distruge_oferta(lista_oferte->lista[pozitie]);
		free(lista_oferte->lista);
		lista_oferte->lista = lista_noua;
		lista_oferte->numar_oferte--;
	}
	/*int sem = 0;
	for (int i = 0; i < lista_oferte->numar_oferte;i++)
	{
		if (pozitie == i)
		{
			sem = 1;
			ElemType el = returneaza_oferta_de_pe_pozitie(lista_oferte, i);
			distruge_oferta(el);
		}
		if (sem == 1)
			lista_oferte->lista[i] = lista_oferte->lista[i + 1];
	}
	if (sem == 1)
		lista_oferte->numar_oferte--;*/
	
}