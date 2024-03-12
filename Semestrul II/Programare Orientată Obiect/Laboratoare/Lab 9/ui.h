#pragma once
#include "service.h"

class ConsoleUI
{
private:
	MasinaStore& srv;
public:
	//Constructorul pentru ConsoleUI
	ConsoleUI(MasinaStore& srv) noexcept :srv{ srv } {};
	ConsoleUI(const ConsoleUI& m) = delete;

	//Functia de filtrare a listei de masini dupa producator
	//Post: vor fi afisate toate masinile care au producatorul din parametru
	void filtrare_producator(string producator);

	//Functia de filtrare a listei de masini dupa tip
	//Post: vor fi afisate toate masinile care au tipul din parametru
	void filtrare_tip(string tip);

	//Functia de afisare a listei de masini
	//Post: Se vor afisa in consola toate masinile in ordinea lor din lista
	void afiseaza();

	//Functia de afisarea listei de masini ce trebuie spalate
	//Post: Se vor afisa in consola toate masinile in ordinea lor din lista 
	void afiseaza_lst();

	//Functia de afisare filtrata
	//Post: Se vor afisa in consola doar masinile ce indeplinesc conditiile filtrari
	void afiseaza_filtrat(vector<Masina> list);

	//Functia de afisare a raportului
	//Post: Se va afisa in consola raportul de masini, modelul si de cate ori sa gaseste in lista
	void afiseaza_raport(map<string, int> list);

	//Functia de run a programului
	//Post: De aici se pot accesa toate functionalitatiile programului
	void run();
};