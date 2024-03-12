#include "Multime.h"
#include "IteratorMultime.h"

#include <iostream>

int hashCode(TElem e) {
	return abs(e);
}

int Multime::d(TElem e) {
	return hashCode(e) % m;
}

void Multime::actPrimLiber()
{
	primLiber=0;
	while (primLiber < m && e[primLiber] != NULL_TVALOARE)
		primLiber++;
}

Multime::Multime() {
	m = MAX;
	for (int i = 0; i < m; i++) {
		e[i] = NULL_TVALOARE;
		urm[i] = -1;
	}
	primLiber = 0;
	nrElem = 0;
}


bool Multime::adauga(TElem elem) {
	if (cauta(elem) == false)
	{
		int i = d(elem);
		if (e[i] == NULL_TVALOARE)	
		{
			e[i] = elem;	
			nrElem++;
			if (i == primLiber)
				actPrimLiber();	
			return true;
		}

		int j = -1;	

		while (i != -1)
		{
			j = i;
			i = urm[i];
		}

		if (primLiber >= m)
			return false;

		e[primLiber] = elem;
		nrElem++;
		urm[j] = primLiber;
		actPrimLiber();
		return true;
	}
	return false;
}


bool Multime::sterge(TElem elem) {
	if (cauta(elem) == true)
	{
		int i = d(elem), i2 = -1, j2= -1;
		while (i != -1)
		{
			if (e[i] == elem)
			{
				j2 = i;
				int j = urm[i];
				while (j != -1)
				{
					if (d(e[j]) == i)
					{
						e[i] = e[j];
						i2 = j2;
						i = j;
					}
					j2 = j;
					j = urm[j];
				}
				if (i2 != -1)
					urm[i2] = urm[i];
				e[i] = NULL_TVALOARE;
				urm[i] = -1;
				nrElem--;
				return true;
			}
			i2 = i;
			i = urm[i];
		}
	}
	return false;
}


bool Multime::cauta(TElem elem) {
	int i = d(elem);
	while (i != -1)
	{
		if (e[i] == elem)
			return true;
		i = urm[i];
	}
	return false;
}


int Multime::dim() const {
	return nrElem;
}

bool Multime::vida() const {
	if (nrElem != 0)
		return false;
	return true;
}


Multime::~Multime() {
}



IteratorMultime Multime::iterator() const {
	return IteratorMultime(*this);
}