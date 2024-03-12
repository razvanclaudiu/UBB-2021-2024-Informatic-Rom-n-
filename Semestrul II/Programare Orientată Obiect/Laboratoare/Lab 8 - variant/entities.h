#pragma once
//#pragma warning(disable:26432)
#include <iostream>
#include <string>
using namespace std;
using std::move;
using std::string;

class Masina
{
private:
	string nrInmatriculare;
	string producator;
	string model;
	string tip;
public:

	Masina() = default;
	//Constructorul pentru entitati de tip Masina
	Masina(string nrInmatriculare, string producator, string model, string tip) :nrInmatriculare{ nrInmatriculare }, producator{ producator }, model{ model }, tip{ tip }{};

	//Constructorul pentru copiere
	Masina(const Masina& m) :nrInmatriculare{m.nrInmatriculare}, producator{m.producator}, model{m.model}, tip{m.tip}
	{
		//cout << "Constructor called!" << endl;
	};


	string getNrInmatriculare() const;
	string getProducator() const;
	string getModel() const;
	string getTip() const;

	void setNrInmatriculare(string nrInmatriculare);
	void setProducator(string producator);
	void setModel(string model);
	void setTip(string tip);

	

};

class Pereche
{
private:
	pair<string, int> perc;
public:
	Pereche() = default;

	Pereche(pair<string, int> perc) :perc{ perc }{};

	Pereche(const Pereche& p) :perc{ p.perc }
	{
		//cout << "Constructor called!" << endl;
	};

	string first() const;
	int second() const;

	void set_second(int i);
};

//Comparator pentru nrInmatriculare
//Parametrii: m1 = const Masina&
//			  m2 = cosnt Masina&, entitati care vor fi comparate intre ele
//Post: se va returna true daca m1 > m2, false in caz contrat
bool cmpnrInmatriculare(const Masina& m1, const Masina& m2);


//Comparator pentru Tip
//Parametrii: m1 = const Masina&
//			  m2 = cosnt Masina&, entitati care vor fi comparate intre ele
//Post: se va returna true daca m1 > m2, false in caz contrat
bool cmpTip(const Masina& m1, const Masina& m2);


//Comparator pentru Produs+Model
//Parametrii: m1 = const Masina&
//			  m2 = cosnt Masina&, entitati care vor fi comparate intre ele
//Post: se va returna true daca m1 > m2, false in caz contrat
bool cmpProducatorModel(const Masina& m1, const Masina& m2);