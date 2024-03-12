#pragma once

#include <vector>

typedef int TCheie;
typedef int TValoare;

#include <utility>
typedef std::pair<TCheie,std::vector<TValoare>> TElem;
using namespace std;

class IteratorMDO;

typedef bool(*Relatie)(TCheie, TCheie);

class Nod;

typedef Nod* PNod;

class Nod
{

public:

	friend class MDO;

	Nod(TElem e, PNod st, PNod dr, PNod par);

	TElem element();

	PNod stanga();

	PNod dreapta();

	PNod parinte();


private:

	TElem e;

	PNod st, dr, par;

};

class MDO {
	friend class IteratorMDO;
    private:
		
		PNod rad;
		Relatie r;
		int nr;

		PNod adauga_rec(PNod p, PNod par, TElem e);

		PNod sterge_rec(PNod p, TCheie c, TValoare v, bool val);

    public:

	// constructorul implicit al MultiDictionarului Ordonat
	MDO(Relatie r);

	// adauga o pereche (cheie, valoare) in MDO
	void adauga(TCheie c, TValoare v);

	//cauta o cheie si returneaza vectorul de valori asociate
	vector<TValoare> cauta(TCheie c) const;

	//returneaza adevarat daca s-a gasit cheia si valoarea de sters
	bool sterge(TCheie c, TValoare v);

	//returneaza numarul de perechi (cheie, valoare) din MDO 
	int dim() const;

	//verifica daca MultiDictionarul Ordonat e vid 
	bool vid() const;

	// se returneaza iterator pe MDO
	// iteratorul va returna perechile in ordine in raport cu relatia de ordine
	IteratorMDO iterator() const;

	void distruge_rec(PNod p);

	vector<TValoare> colectiaValorilor() const;

	// destructorul 	
	~MDO();

};
