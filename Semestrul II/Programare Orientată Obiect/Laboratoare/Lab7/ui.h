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

	void afiseaza_filtrat(vectorClass<Masina> list);

	//Functia de run a programului
	//Post: De aici se pot accesa toate functionalitatiile programului
	void run();
};