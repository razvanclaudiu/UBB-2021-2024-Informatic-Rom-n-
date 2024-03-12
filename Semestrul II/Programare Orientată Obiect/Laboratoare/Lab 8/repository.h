#pragma once
#include "entities.h"
#include <vector>
#include <map>
#include <functional>
#include <algorithm>
#include <chrono>
#include <random>

class MasinaRepository
{
private:

	vector<Masina> allMasina;

public:

	//Constructorul pentru MasinaRepository
	MasinaRepository() = default;

	MasinaRepository(const MasinaRepository& ot) = delete;

	//Functie de returnare
	//Post: Se returneaza lista de masini
	vector<Masina>& getAllMasina() noexcept;

	//Functia de adaugare a unei masini in lista
	//Parametrii: m - const Masina&, entitate care urmeaza a fi adaugata
	//Post: Se va adauga pe ultima pozitie a vectorului o noua entitate Masina
	//Throws: Daca exista o entitate Masina cu acelasi numar de inmatriculare deja 
	//	      existent, se va arunca RepositoryException
	void adauga_repo(Masina& m);

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
	vector<Masina> filtrare_repo(function<bool(const Masina&)> fct);

	//Functia de amestecare
	//Post: va amesteca la intamplare elementele din lista de masini
	void shuffle_repo();

	//Functia de raport
	//Post: va creea un dictionar, cheilele fiind modelul masinilor si valoarea fiind numarul de aparitii ale acelui model de masina
	map<string, int> raport_model_repo();

	friend class MasinaListRepository;
};

class MasinaListRepository 
{
private:
	vector<Masina> lstMasina;
public:
	//Constructorul pentru MasinaRepository
	MasinaListRepository() = default;

	MasinaListRepository(const MasinaListRepository& ot) = delete;

	//Functie de returnare
	//Post: Se returneaza lista de masini
	vector<Masina>& getlstMasina() noexcept;

	//Functia de adaugare a unei masini in lista
	//Parametrii: m - const Masina&, entitate care urmeaza a fi adaugata
	//Post: Se va adauga pe ultima pozitie a vectorului o noua entitate Masina
	//Throws: Daca exista o entitate Masina cu acelasi numar de inmatriculare deja 
	//	      existent sau numarul de inmatriculare nu exista in MasinaRepository, se va arunca RepositoryException
	void lst_adauga_repo(Masina& m);

	//Functia de stergere
	//Post: se vor sterge toate elementele din lista de masini
	void lst_empty_repo() noexcept;

	//Functia de generare a unei liste de masini
	//Parametrii allM - vector<Masina>&, lista de masini din MasinaRepository
	//			 i - int, nr de masini care vor fi adaugate in lista
	//Post: se vor adauga la intamplare i masini din lista din MasinaRepository in lista din MasinaListRepository
	//Throws: Daca i este mai mare decat numarul de elemente din lista din MasinaRepository, atunci se va arunca RepositoryException
	void lst_genereaza_repo(const vector<Masina>& allM, int i);
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

