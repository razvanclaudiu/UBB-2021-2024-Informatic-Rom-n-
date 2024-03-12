#pragma once
#include "entities.h"
#include "repository.h"
#include "validator.h"
#include "service.h"
#include "vectorClass.h"

class Teste
{
public:

	void test_getset();
	void test_adauga_repo();
	void test_actualizeaza_repo();
	void test_sterge_repo();
	void test_valideaza_masina();
	void test_valideaza_nrInmtriculare();
	void test_valideaza_tip();
	void test_adauga_srv();
	void test_actualizeaza_srv();
	void test_sterge_srv();
	void test_cauta_repo();
	void test_cauta_srv();
	void test_ordonare_nrInmatriculare();
	void test_ordonare_Tip();
	void test_ordonare_ProducatorModel();
	void test_filtrare_Producator();
	void test_filtrare_Tip();
	void run_teste();
};