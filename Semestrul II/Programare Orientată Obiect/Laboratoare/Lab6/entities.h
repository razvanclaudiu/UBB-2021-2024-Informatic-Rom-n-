#pragma once
#pragma warning(disable:26432)
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
	Masina() = delete;
	//Constructorul pentru entitati de tip Masina
	Masina(string nrInmatriculare, string producator, string model, string tip) :nrInmatriculare{ nrInmatriculare }, producator{ producator }, model{ model }, tip{ tip }{};

	//Constructorul pentru copiere
	Masina(const Masina& m) :nrInmatriculare{ m.nrInmatriculare }, producator{ m.producator }, model{ m.model }, tip{ m.tip }
	{
		cout << "Constructor called!" << endl;
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