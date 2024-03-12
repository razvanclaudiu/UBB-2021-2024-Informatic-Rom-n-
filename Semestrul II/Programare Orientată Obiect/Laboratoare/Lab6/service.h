#pragma once
#include "repository.h"
#include "validator.h"

class MasinaStore
{
private:
	MasinaRepository& repo;
	MasinaValidation& val;
public:
	//Constructorul pentru MasinaStore
	MasinaStore(MasinaRepository& repo, MasinaValidation& val) noexcept :repo{ repo }, val{ val }{};

	//MasinaStore(const MasinaStore& m) = delete;

	//Functie de returnare
	//Post: Se returneaza lista de masini
	const vector<Masina>& getAllMasina_srv() noexcept;

	//Functia de adaugare a unei masini in lista
	//Parametrii: nrInmatriculare - string
	//	          producator - string
	//            model - string
	//            tip - string
	//Post: Se vor valida datele si se va adauga pe ultima pozitie a vectorului o noua entitate Masina
	//Throws: Daca exista o entitate Masina cu acelasi numar de inmatriculare deja 
	//	      existent, se va arunca RepositoryException
	//		  Daca datele introduse nu sunt valide, se va arunca ValidationException cu un mesaj corespunzator
	void adauga_srv(string nrInmatriculare, string producator, string model, string tip);

	//Functia de actualizare a unei masini in lista
	//Parametrii: nrInmatriculare - string
	//	          producator - string
	//            model - string
	//            tip - string
	//Post: Se vor valida datele si se va actualiza entitatea Masina cu acelasi numar de inmatriculare
	//Throws: Daca nu exista o entitate Masina cu numarul de inmatriculare din parametru, se
	//		  va arunca RepositoryException
	//		  Daca datele introduse nu sunt valide, se va arunca ValidationException cu un mesaj corespunzator
	void actualizeaza_srv(string nrInmatriculare, string producator, string model, string tip);


	//Functia de stergere a unei masini in lista
	//Parametrii: nrInmatriculare - string
	//	          producator - string
	//            model - string
	//            tip - string
	//Post: Se vor valida datele si Se va sterge entitatea Masina care are acelasi numar de inmatriculare cu string-ul din parametru
	//Throws: Daca nu exista o entitate Masina cu numarul de inmatriculare din parametru, se
	//		  va arunca RepositoryException
	//		  Daca datele introduse nu sunt valide, se va arunca ValidationException cu un mesaj corespunzator
	void sterge_srv(string nrInmatriculare);
};