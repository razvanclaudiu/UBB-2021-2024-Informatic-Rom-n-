#include "Colectie.h"
#include "IteratorColectie.h"
#include <iostream>

using namespace std;

//O(1)
bool rel(TElem e1, TElem e2) {
	if (e1 <= e2)
		return true;
	return false;
}

//O(1)
Colectie::Colectie() {
	this->cp = 1;
	e = new TElem[cp];
	this->nr = 0;
}

//O(n)
void Colectie::adauga(TElem e) {
	if (nr == cp)
		redim();
	if(nr == 0)
		this->e[nr++] = e;
	else
	{
		nr++;
		for (int i = 0; i < nr - 1; i++)
			if (rel(this->e[i], e) == false)
			{
				for (int j = nr - 1;j > i;j--)
					this->e[j] = this->e[j - 1];
				this->e[i] = e;
				return;
			}
		this->e[nr - 1] = e;
		return;
	}
}

//O(n)
void Colectie::redim() {
	TElem* eNou = new int[2 * cp];

	for (int i = 0; i < nr; i++)
		eNou[i] = e[i];

	cp = 2 * cp;

	delete[] e;

	e = eNou;
}

//O(n)
bool Colectie::sterge(TElem e) {
	int sem = 0;
	for (int i = 0; i < nr; i++)
	{
		if (this->e[i] == e)
		{
			sem = 1;
		}
		if (sem == 1)
			this->e[i] = this->e[i + 1];
	}
	if (sem == 1)
	{
		nr--;
		return true;
	}
	return false;
}

//O(n)
bool Colectie::cauta(TElem elem) const {
	for (int i = 0; i < nr; i++)
		if (this->e[i] == elem)
			return true;
	return false;
}

//O(n)
int Colectie::nrAparitii(TElem elem) const {
	int nrapar = 0;
	for (int i = 0; i < nr; i++)
		if (this->e[i] == elem)
			nrapar++;
	return nrapar;
}


//O(1)
int Colectie::dim() const {
	return nr;
}

//O(1)
bool Colectie::vida() const {
	if (nr != 0)
		return false;
	return true;
}

//O(1)
IteratorColectie Colectie::iterator() const {
	return  IteratorColectie(*this);
}

//O(1)
Colectie::~Colectie() {
	delete[] e;
}
