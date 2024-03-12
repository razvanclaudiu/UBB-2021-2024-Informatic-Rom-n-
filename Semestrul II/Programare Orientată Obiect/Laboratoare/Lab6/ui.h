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

	//Functia de afisare a listei de masini
	//Post: Se vor afisa in consola toate masinile in ordinea lor din lista
	void afiseaza();

	//Functia de run a programului
	//Post: De aici se pot accesa toate functionalitatiile programului
	void run();
};