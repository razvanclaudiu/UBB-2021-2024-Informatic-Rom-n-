#pragma once

#define NULL_TVALOARE -12345678
typedef int TElem;

class IteratorMultime;

class Multime {
	friend class IteratorMultime;

    private:
		int m;
		TElem* e;
		int* urm; 
		int primLiber;
		int nrElem;

		void actPrimLiber();

		int d(TElem e);

    public:
 		//constructorul implicit
		Multime();

		//adauga un element in multime
		//returneaza adevarat daca elementul a fost adaugat (nu exista deja in multime)
		bool adauga(TElem e);

		//sterge un element din multime
		//returneaza adevarat daca elementul a existat si a fost sters
		bool sterge(TElem e);

		//verifica daca un element se afla in multime
		bool cauta(TElem elem);


		//intoarce numarul de elemente din multime;
		int dim() const;

		//verifica daca multimea e vida;
		bool vida() const;

		//returneaza un iterator pe multime
		IteratorMultime iterator() const;

		//returneaza diferenta dintre cel mai MIN si MAX
		int diferentaMaxMin() const ;

		// destructorul multimii
		~Multime();
};




