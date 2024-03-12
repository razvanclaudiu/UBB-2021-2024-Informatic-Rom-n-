#include "Dictionar.h"
#include <iostream>
#include "IteratorDictionar.h"
#include <iostream>
#include <vector>
using namespace std;

//O(n)
Dictionar::Dictionar() {
	cap = 5;
	elems = new TElem[cap];
	urm = new int[cap];
	nrElem = 0;
	prim = -1;
	primLiber = 0;
	for (int i = 0;i <= cap - 1;i++)
		urm[i] = -1;
}

//O(1)
Dictionar::~Dictionar() {
	delete[] elems;
	delete[] urm;
}

//O(n)
TValoare Dictionar::adauga(TCheie c, TValoare v){
	
	int ct = cauta(c);
	if (ct == NULL_TVALOARE)
	{
		if (cap == nrElem)
		{
			cap = cap * 2;
			TElem* elemsaux = new TElem[cap];
			int* urmaux = new int[cap];
			for (int i = 0;i < nrElem;i++)
				elemsaux[i] = elems[i];
			for (int i = 0; i < nrElem;i++)
				urmaux[i] = urm[i];
			for (int i = nrElem;i <= cap - 1;i++)
				urmaux[i] = -1;
			delete[] elems;
			delete[] urm;
			elems = elemsaux;
			urm = urmaux;
			primLiber = nrElem;
		}
		int i = primLiber;
		primLiber++;
		elems[i] = { c,v };
		urm[i] = prim;
		prim = i;
		nrElem++;
		return NULL_TVALOARE;
	}
	else
	{
		for(int i=0;i<nrElem;i++)
			if (elems[i].first == c)
			{
				elems[i].second = v;
				break;
			}
		return ct;
	}
}



//O(n)
TValoare Dictionar::cauta(TCheie c) const{
	for (int i = 0;i < nrElem;i++)
		if (elems[i].first == c)
			return elems[i].second;
	return NULL_TVALOARE;
}

//O(n)
TValoare Dictionar::sterge(TCheie c){
	for (int i = 0;i < nrElem;i++)
		if (elems[i].first == c)
		{
			int vaux = elems[i].second;
			if (nrElem == cap)
				urm[nrElem - 1] = -1;
			else urm[nrElem] = nrElem;
			for (int j = i; j < nrElem;j++)
				elems[j] = elems[j + 1];
			nrElem--;
			prim--;
			primLiber--;
			return vaux;

		}
	return NULL_TVALOARE;
}

//O(1)
int Dictionar::dim() const {
	return nrElem;
}

//O(1)
bool Dictionar::vid() const{
	if(nrElem == 0)
		return true;
	return false;
}

//O(n)
vector<TCheie> Dictionar::multimeaCheilor() const {
	vector<TCheie> keylst;
	for (int i = 0;i < nrElem;i++)
		keylst.push_back(elems[i].first);
	return keylst;
}

//O(1)
IteratorDictionar Dictionar::iterator() const {
	return  IteratorDictionar(*this);
}


