#pragma once
#include "repository.h"
#include "validator.h"
#include "undo.h"

class MasinaStore
{
private:
	MasinaRepository& repo;
	MasinaListRepository& repolist;
	MasinaValidation& val;

	vector<unique_ptr<ActiuneUndo>> undolist;

public:
	//Constructorul pentru MasinaStore
	MasinaStore(MasinaRepository& repo, MasinaListRepository& repolist, MasinaValidation& val) noexcept :repo{ repo }, repolist{ repolist }, val{ val }{};

	MasinaStore(const MasinaStore& m) = delete;

	//Functie de returnare
	//Post: Se returneaza lista de masini
	vector<Masina>& getAllMasina_srv() noexcept;

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

	//Functia de cautare a unei masini
	//Parametrii: nrInmatriculare - string
	//Post: se va returna masina care are numarul de inmatriculare egal cu cel din parametru
	//Throws: Daca nu exista o entitate Masina cu numarul de inmatriculare din parametru, se
	//		  va arunca RepositoryException
	const Masina& cauta_srv(string nrInmatriculare);


	//Functia de ordonare a listei de masini
	//Parametrii: bool (*key)(const Masina&, const Masina&) - o functie de comparare bool intre doua entitati Masina
	//Post: lista de Masini din repository va fi ordonata in functie de functia din parametru
	void ordonare_srv(bool (*key)(const Masina&, const Masina&));

	//Functia care apeleaza ordonarea pentru numar de inmatriculare
	//Post: lista de Masini din repository va fi ordoanta in funcite de numarul de inmatriculare
	void sortnrInmatriculare();

	//Functia care apeleaza ordonarea pentru tip
	//Post: lista de Masini din repository va fi ordoanta in funcite de tip
	void sortTip();

	//Functia care apeleaza ordonare pentru productor+model
	//Post: lista de Masini din repository va fi ordoanta in funcite de producator+model
	void sortProducatorModel();

	//Functia de filtrare a liste de masini
	//Parametrii: fct - function<bool(const Masina&)>, functia de comparare
	//Post: se va returna o lista filtrata dependenta de functia de comaparare si de datele introduse de la tastatura
	vector<Masina> filtrare_srv(function<bool(const Masina&)> fct);

	//Functia de apelare a filtrarii pentru producator
	//Parametrii: producator - string
	//Post: se va returna o lista filtrata dependenta de functia de comaparare si de datele introduse de la tastatura
	vector<Masina> filtrareProducator(string producator);

	//Functia de apelare a filtrarii pentru tip
	//Functia de 
	//Post: se va returna o lista filtrata dependenta de functia de comaparare si de datele introduse de la tastatura
	vector<Masina> filtrareTip(string tip);

	//Functia de raport
	//Post: va creea un dictionar, cheilele fiind modelul masinilor si valoarea fiind numarul de aparitii ale acelui model de masina
	map<string, int> raport_model_srv();

	void undo();

	//Functie de returnare
	//Post: Se returneaza lista de masini
	vector<Masina>& getlstMasina_srv() noexcept;

	//Functia de adaugare a unei masini in lista
	//Parametrii: nrInmatriculare - string, numarul de inmatriculare
	//Post: Se va adauga pe ultima pozitie a vectorului o noua entitate Masina
	//Throws: Daca exista o entitate Masina cu acelasi numar de inmatriculare deja 
	//	      existent sau numarul de inmatriculare nu exista in MasinaRepository, se va arunca RepositoryException
	void lst_adauga_srv(string nrInmatriculare);

	//Functia de stergere
	//Post: se vor sterge toate elementele din lista de masini
	void lst_empty_srv() noexcept;

	//Functia de generare a unei liste de masini
	//Parametrii: i - int, nr de masini care vor fi adaugate in lista
	//Post: se vor adauga la intamplare i masini din lista din MasinaRepository in lista din MasinaListRepository
	//Throws: Daca i este mai mare decat numarul de elemente din lista din MasinaRepository, atunci se va arunca RepositoryException
	void lst_generate_srv(int i);

	//Functia de exportare a listei de masini intr-un fisier
	//Parametrii: fname - string, numele fisierului
	//Post: lista de masini va fi stocata in format CVS intr-un fisier
	//Throws: Daca fisierul nu s-a putut deschide atunci se va arunca o exceptie
	void lst_export_srv(string fname);
};