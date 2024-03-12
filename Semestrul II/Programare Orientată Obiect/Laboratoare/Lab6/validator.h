#pragma once
#pragma warning(disable:26823)
#include "entities.h"
#include <vector>
using std::vector;

class MasinaValidation
{
public:
	//Functia de validare a unei entitati masina
	//Parametrii: m - const Masina&, entitate care urmeaza sa fie validata
	//Post: Se va verifica daca datele introduse sunt corecte
	//Throws: In functie de datele introduse, se va arunca ValidationException cu diferite mesaje
	void validate_masina(const Masina& m);

	//Functia de validare a unui numar de inmatriculare
	//Parametrii: nrInmatriculare - string 
	//Post: Se va verifica daca datele introduse sunt corecte
	//Throws: In functie de datele introduse, se va arunca ValidationException
	void validate_nrInmatriculare(string nrInmatriculare);
};

class ValidationException
{
	vector<string> err;
public:
	//Constructorul pentru eroarea ValidationError
	ValidationException(vector<string> err) :err{ err } {};

	//Functia de returnare a unei erori
	//Post: Se va returna o eroare de tip ValidationError
	string getErrorMsg()
	{
		string fullMsg = "";
		for (const string e : err) {
			fullMsg += e;
		}
		fullMsg += "\n";
		return fullMsg;
	}
};
