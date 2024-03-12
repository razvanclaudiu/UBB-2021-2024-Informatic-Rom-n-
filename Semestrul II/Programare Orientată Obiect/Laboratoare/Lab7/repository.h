#pragma once
#include "entities.h"
#include "vectorClass.h"
#include <functional>

class MasinaRepository
{
private:
	vectorClass<Masina> allMasina;
public:

	//Constructorul pentru MasinaRepository
	MasinaRepository() = default;

	MasinaRepository(const MasinaRepository& ot) = delete;

	//Functie de returnare
	//Post: Se returneaza lista de masini
	vectorClass<Masina>& getAllMasina() noexcept;

	//Functia de adaugare a unei masini in lista
	//Parametrii: m - const Masina&, entitate care urmeaza a fi adaugata
	//Post: Se va adauga pe ultima pozitie a vectorului o noua entitate Masina
	//Throws: Daca exista o entitate Masina cu acelasi numar de inmatriculare deja 
	//	      existent, se va arunca RepositoryException
	void adauga_repo(const Masina& m);

	//Functia de actualizare a unei masini in lista
	//Parametrii: m - const Masina&, entitate care urmeaza sa actualizeze una deja existenta
	//Post: Se va actualiza entitatea Masina cu acelasi numar de inmatriculare
	//Throws: Daca nu exista o entitate Masina cu numarul de inmatriculare din parametru, se
	//		  va arunca RepositoryException
	void actualizeaza_repo(const Masina& m);

	//Functia de stergere a unei masini din lista
	//Parametrii: nrInmatriculare - string
	//Post: Se va sterge entitatea Masina care are acelasi numar de inmatriculare cu string-ul din parametru
	//Throws: Daca nu exista o entitate Masina cu numarul de inmatriculare din parametru, se
	//		  va arunca RepositoryException
	void sterge_repo(string nrInmatriculare);
	

	//Functia de cautare a unei masini
	//Parametrii: nrInmatriculare - string
	//Post: se va returna masina care are numarul de inmatriculare egal cu cel din parametru
	//Throws: Daca nu exista o entitate Masina cu numarul de inmatriculare din parametru, se
	//		  va arunca RepositoryException
	const Masina& cauta_repo(string nrInmatriculare);

	//Functia de ordonare a listei de masini
	//Parametrii: bool (*key)(const Masina&, const Masina&) - o functie de comparare bool intre doua entitati Masina
	//Post: lista de Masini din repository va fi ordonata in functie de functia din parametru
	void ordonare_repo(bool (*key)(const Masina&, const Masina&));

	//Functia de filtrare a liste de masini
	//Parametrii: fct - function<bool(const Masina&)>, functia de comparare
	//Post: se va returna o lista filtrata dependenta de functia de comaparare si de datele introduse de la tastatura
	vectorClass<Masina> filtrare_repo(function<bool(const Masina&)> fct);

	//int opposite(int result);



};

class RepoException
{
private:
    string err;
public:
    //Constructorul pentru eroarea RepoException
    RepoException(string err) :err{ err } {};

    //Functia de returnare a unei erori
    //Post: Se va returna o eroare de tip RepoException
    string getErrorMsg()
    {
        return this->err;
    }
};

