#include "Multime.h"
#include "IteratorMultime.h"
#include <iostream>

using namespace std;

//O(1)
bool rel(TElem e1, TElem e2) {
	if (e1 <= e2) 
		return true;
	return false;
	
}

//O(1)
Nod::Nod(TElem e, PNod urm) {
	this->e = e;
	this->urm = urm;
}

//O(1)
TElem Nod::element() {
	return e;
}

//O(1)
PNod Nod::urmator() {
	return urm;
}


//O(1)
Multime::Multime() {
	prim = nullptr;
	ultm = nullptr;
	nr = 0;
}

//O(n)
bool Multime::adauga(TElem elem) {
	if (cauta(elem) == true)
		return false;
	if (nr != 0)
	{
		PNod aux1 = prim;
		PNod aux2 = nullptr;
		while (aux1 != nullptr)
		{
			if (rel(aux1->e, elem) == false)
			{
				PNod q = new Nod(elem, nullptr);
				q->urm = aux1;
				if (aux2 != nullptr)
					aux2->urm = q;
				else prim = q;
				nr++;
				return true;
			}
			aux2 = aux1;
			aux1 = aux1->urm;
		}
		PNod q = new Nod(elem, nullptr);
		aux2->urm = q;
		aux1 = q;
		ultm = q;
		nr++;
		return true;
	}
	else
	{
		PNod q = new Nod(elem, nullptr);
		q->urm = prim;
		prim = q;
		ultm = q;
		nr++;
		return true;
	} 
}

//O(n)
bool Multime::sterge(TElem elem) {
	int sem = 0;
	PNod aux1 = prim;
	PNod aux2 = nullptr;
	while(aux1 != nullptr)
	{
		if (aux1->e == elem)
			sem = 1;
		if (sem == 1)
		{
			if (aux2 == nullptr)
			{
				prim = prim->urm;
				delete aux1;
				nr--;
				return true;
			}
			if (aux1->urm == nullptr)
			{
				aux2->urm = nullptr;
				delete aux1;
				ultm = aux2;
				nr--;
				return true;
			}
			aux2->urm = aux1->urm;
			delete aux1;
			nr--;
			return true;	
		}
		aux2 = aux1;
		aux1 = aux1->urm;
			
	}
	return false;
}

//O(n)	
bool Multime::cauta(TElem elem) const {
	PNod aux = prim;
	if (aux != nullptr)
	{
		if (elem < aux->e)
			return false;
		if (elem > ultm->e)
			return false;
	}
	while (aux != nullptr)
	{
		if (aux->e == elem)
			return true;
		aux = aux->urm;
	}
	return false;
}

//O(1)
int Multime::diferetaMaxMin() const
{
	if (prim == nullptr && ultm == nullptr)
		return -1;
	else return ultm->e - prim->e;
}

//O(1)
int Multime::dim() const {
	/*PNod aux = prim;
	int nr = 0;
	while (aux != nullptr) {
		aux = aux->urm;
		nr++;
	}*/
	return nr;
}


//O((1)
bool Multime::vida() const {
	if (prim != nullptr)
		return false;
	return true;
}

//O(1)
IteratorMultime Multime::iterator() const {
	return IteratorMultime(*this);
}

//O(1)
Multime::~Multime() {
	while (prim != nullptr) {
		PNod p = prim;
		prim = prim->urm;
		delete p;
	}
}






