#include "Multime.h"
#include "IteratorMultime.h"

#include <iostream>

//O(1)
int hashCode(TElem e) {
	return abs(e);
}

//O(1)
int Multime::d(TElem e) {
	return hashCode(e) % m;
}

//O(n)
void Multime::actPrimLiber()
{
	primLiber=0;
	while (primLiber < m && e[primLiber] != NULL_TVALOARE)
		primLiber++;
}

//O(n)
Multime::Multime() {
	m = 10;
	e = new TElem[m];
	urm = new int[m];
	for (int i = 0; i < m; i++) {
		e[i] = NULL_TVALOARE;
		urm[i] = -1;
	}
	primLiber = 0;
	nrElem = 0;
}

//O(n)
bool Multime::adauga(TElem elem) {
	if (cauta(elem) == false)
	{
		if (nrElem == m)
		{
			m = m * 2;
			TElem* auxtemp = new TElem[m];
			int* urmaux = new int[m];
			for (int x = 0; x < m; x++) {
				auxtemp[x] = NULL_TVALOARE;
				urmaux[x] = -1;
			}
			primLiber = 0;
			for (int a = 0; a < nrElem; a++)
			{
				int i = d(e[a]);
				if (auxtemp[i] == NULL_TVALOARE)
				{
					auxtemp[i] = e[a];
					if (i == primLiber)
					{
						primLiber=0;
						while (primLiber < m && auxtemp[primLiber] != NULL_TVALOARE)
							primLiber++;
					}
				}
				else
				{

					int j = -1;

					while (i != -1)
					{
						j = i;
						i = urmaux[i];
					}

					auxtemp[primLiber] = e[a];
					urmaux[j] = primLiber;
					primLiber=0;
					while (primLiber < m && auxtemp[primLiber] != NULL_TVALOARE)
						primLiber++;
				}
			}
			delete[] e;
			delete[] urm;
			e = auxtemp;
			urm = urmaux;
			primLiber = 0;
			while (primLiber < m && e[primLiber] != NULL_TVALOARE)
				primLiber++;
		}
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

//O(1)
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
				if (i2 == -1)
				{
					int ai = 0;
					while (i2 == -1 && ai < m)
						if (urm[ai] == i)
							i2 = ai;
						else ai++;
							
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

//O(1)
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

//O(1)
int Multime::dim() const {
	return nrElem;
}

//O(1)
bool Multime::vida() const {
	if (nrElem != 0)
		return false;
	return true;
}

//O(n)
int Multime::diferentaMaxMin() const 
{
	if (nrElem == 0)
		return -1;
	int minim, maxim, j=0;
	for (int i = 0; i < m && j < nrElem; i++) {
		if (e[i] != NULL_TVALOARE)
		{
			if (j == 0)
			{
				minim = e[i];
				maxim = e[i];
			}
			else {
				if (e[i] < minim)
					minim = e[i];
				if (e[i] > maxim)
					maxim = e[i];
			}
			j++;
		}
		
	}
	return maxim - minim;
}

//O(1)
Multime::~Multime() {
}


//O(1)
IteratorMultime Multime::iterator() const {
	return IteratorMultime(*this);
}