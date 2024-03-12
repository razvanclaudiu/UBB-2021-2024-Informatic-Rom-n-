#pragma once
#include "entities.h"
#include <vector>
using std::vector;

class MasinaRepository
{
private:
	vector<Masina> allMasina;
public:
	//Constructorul pentru MasinaRepository
	MasinaRepository() = default;

	//MasinaRepository(const MasinaRepository& m) = delete;

	//Functie de returnare
	//Post: Se returneaza lista de masini
	const vector<Masina>& getAllMasina() noexcept;

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