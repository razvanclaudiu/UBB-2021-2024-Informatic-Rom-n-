#include <iostream>
#include <assert.h>
#include "tests.h"
using namespace std;

void Teste::test_getset()
{
	Masina m1{ "SB67ARN","Toyota Motor Corporation","Toyota Yaris","automobil" };
	assert(m1.getNrInmatriculare() == "SB67ARN");
	assert(m1.getProducator() == "Toyota Motor Corporation");
	assert(m1.getModel() == "Toyota Yaris");
	assert(m1.getTip() == "automobil");

	m1.setNrInmatriculare("CJ89BUJ");
	m1.setProducator("Honda Motor");
	m1.setModel("2022 Accord Sedan");
	m1.setTip("tractor");

	assert(m1.getNrInmatriculare() == "CJ89BUJ");
	assert(m1.getProducator() == "Honda Motor");
	assert(m1.getModel() == "2022 Accord Sedan");
	assert(m1.getTip() == "tractor");
}

void Teste::test_adauga_repo()
{
	MasinaRepository repo;
	Masina m1{ "SB67ARN","Toyota Motor Corporation","Toyota Yaris","automobil" };
	repo.adauga_repo(m1);
	assert(repo.getAllMasina().size() == 1);

	Masina m2{ "SB67ARN","Toyota Motor Corporation","Toyota Yaris","automobil" };
	//Masina m2{ "CJ89BUJ","Honda Motor","2022 Accord Sedan","tractor"};
	//Masina m3{"B109SAU","BMW Group","BMW X2","tir"};
	try
	{
		repo.adauga_repo(m2);
	}
	catch (RepoException& re)
	{
		assert(re.getErrorMsg() == "NumarInmatriculare existent!/");
	}
}

void Teste::test_actualizeaza_repo()
{
	MasinaRepository repo;
	Masina m1{ "SB67ARN","Toyota Motor Corporation","Toyota Yaris","automobil" };
	repo.adauga_repo(m1);
	assert(repo.getAllMasina().size() == 1);

	Masina m2{ "SB67ARN","Honda Motor","2022 Accord Sedan","tractor" };
	repo.actualizeaza_repo(m2);
	assert(repo.getAllMasina().size() == 1);
	Masina m3{ "CJ89BUJ","Honda Motor","2022 Accord Sedan","tractor"};
	try
	{
		repo.actualizeaza_repo(m3);
	}
	catch (RepoException& re)
	{
		assert(re.getErrorMsg() == "NumarInmatriculare inexistent!/");
	}
}

void Teste::test_sterge_repo()
{
	MasinaRepository repo;
	Masina m1{ "SB67ARN","Toyota Motor Corporation","Toyota Yaris","automobil" };
	repo.adauga_repo(m1);
	assert(repo.getAllMasina().size() == 1);
	Masina m2{ "CJ89BUJ","Honda Motor","2022 Accord Sedan","tractor"};
	repo.adauga_repo(m2);
	assert(repo.getAllMasina().size() == 2);

	repo.sterge_repo("CJ89BUJ");
	assert(repo.getAllMasina().size() == 1);

	try
	{
		repo.sterge_repo("CJ89BUJ");
	}
	catch (RepoException& re)
	{
		assert(re.getErrorMsg() == "NumarInmatriculare inexistent!/");
	}
}

void Teste::test_valideaza_masina()
{
	MasinaValidation val;
	Masina m1{ "SB67ARN","Toyota Motor Corporation","Toyota Yaris","automobil" };
	val.validate_masina(m1);
	Masina m2{ "","Honda Motor","2022 Accord Sedan","" };
	try
	{
		val.validate_masina(m2);
	}
	catch (ValidationException& ve)
	{
		assert(ve.getErrorMsg() == "NumarInmatriculare invalid!/Tip invalid!/\n");
	}
	Masina m3{ "C109ARN","Honda Motor","2022 Accord Sedan","" };
	try
	{
		val.validate_masina(m3);
	}
	catch (ValidationException& ve)
	{
		assert(ve.getErrorMsg() == "NumarInmatriculare invalid!/Tip invalid!/\n");
	}
	Masina m4{ "B109893","Honda Motor","2022 Accord Sedan","" };
	try
	{
		val.validate_masina(m4);
	}
	catch (ValidationException& ve)
	{
		assert(ve.getErrorMsg() == "NumarInmatriculare invalid!/Tip invalid!/\n");
	}
	Masina m5{ "XZ43RGF","Honda Motor","2022 Accord Sedan","" };
	try
	{
		val.validate_masina(m5);
	}
	catch (ValidationException& ve)
	{
		assert(ve.getErrorMsg() == "NumarInmatriculare invalid!/Tip invalid!/\n");
	}
	Masina m6{ "SB45678","Honda Motor","2022 Accord Sedan","" };
	try
	{
		val.validate_masina(m6);
	}
	catch (ValidationException& ve)
	{
		assert(ve.getErrorMsg() == "NumarInmatriculare invalid!/Tip invalid!/\n");
	}
	Masina m7{ "SBASFGH","Honda Motor","2022 Accord Sedan","" };
	try
	{
		val.validate_masina(m7);
	}
	catch (ValidationException& ve)
	{
		assert(ve.getErrorMsg() == "NumarInmatriculare invalid!/Tip invalid!/\n");
	}



}

void Teste::test_valideaza_nrInmtriculare()
{
	MasinaValidation val;
	val.validate_nrInmatriculare("SB67ARN");
	try
	{
		val.validate_nrInmatriculare("");
	}
	catch (ValidationException& ve)
	{
		assert(ve.getErrorMsg() == "NumarInmatriculare invalid!/\n");
	}
	try
	{
		val.validate_nrInmatriculare("C109ARN");
	}
	catch (ValidationException& ve)
	{
		assert(ve.getErrorMsg() == "NumarInmatriculare invalid!/\n");
	}
	try
	{
		val.validate_nrInmatriculare("B109893");
	}
	catch (ValidationException& ve)
	{
		assert(ve.getErrorMsg() == "NumarInmatriculare invalid!/\n");
	}
	try
	{
		val.validate_nrInmatriculare("XZ34RFG");
	}
	catch (ValidationException& ve)
	{
		assert(ve.getErrorMsg() == "NumarInmatriculare invalid!/\n");
	}
	try
	{
		val.validate_nrInmatriculare("SBFGRFG");
	}
	catch (ValidationException& ve)
	{
		assert(ve.getErrorMsg() == "NumarInmatriculare invalid!/\n");
	}
	try
	{
		val.validate_nrInmatriculare("SB56987");
	}
	catch (ValidationException& ve)
	{
		assert(ve.getErrorMsg() == "NumarInmatriculare invalid!/\n");
	}
}

void Teste::test_adauga_srv()
{
	MasinaRepository repo;
	MasinaValidation val;
	MasinaStore srv{ repo,val };
	assert(srv.getAllMasina_srv().size() == 0);
	srv.adauga_srv("SB67ARN", "Toyota Motor Corporation", "Toyota Yaris", "automobil");
	assert(srv.getAllMasina_srv().size() == 1);
	try
	{
		srv.adauga_srv("", "Toyota Motor Corporation", "Toyota Yaris", "automobil");
	}
	catch (ValidationException& ve)
	{
		assert(ve.getErrorMsg() == "NumarInmatriculare invalid!/\n");
	}
	try
	{
		srv.adauga_srv("SB67ARN", "Toyota Motor Corporation", "Toyota Yaris", "automobil");
	}
	catch (RepoException& re)
	{
		assert(re.getErrorMsg() == "NumarInmatriculare existent!/");
	}
}

void Teste::test_actualizeaza_srv()
{
	MasinaRepository repo;
	MasinaValidation val;
	MasinaStore srv{ repo,val };
	assert(srv.getAllMasina_srv().size() == 0);
	srv.adauga_srv("SB67ARN", "Toyota Motor Corporation", "Toyota Yaris", "automobil");
	assert(srv.getAllMasina_srv().size() == 1);
	srv.actualizeaza_srv("SB67ARN", "Honda Motor", "2022 Accord Sedan", "tractor");
	assert(srv.getAllMasina_srv().size() == 1);
	try
	{
		srv.actualizeaza_srv("", "Honda Motor", "2022 Accord Sedan", "tractor");
	}
	catch (ValidationException& ve)
	{
		assert(ve.getErrorMsg() == "NumarInmatriculare invalid!/\n");
	}
	try
	{
		srv.actualizeaza_srv("CJ89BUJ", "Honda Motor", "2022 Accord Sedan", "tractor");
	}
	catch (RepoException& re)
	{
		assert(re.getErrorMsg() == "NumarInmatriculare inexistent!/");
	}
}

void Teste::test_sterge_srv()
{
	MasinaRepository repo;
	MasinaValidation val;
	MasinaStore srv{ repo,val };
	assert(srv.getAllMasina_srv().size() == 0);
	srv.adauga_srv("SB67ARN", "Toyota Motor Corporation", "Toyota Yaris", "automobil");
	assert(srv.getAllMasina_srv().size() == 1);
	srv.sterge_srv("SB67ARN");
	assert(srv.getAllMasina_srv().size() == 0);
	try
	{
		srv.sterge_srv("");
	}
	catch (ValidationException& ve)
	{
		assert(ve.getErrorMsg() == "NumarInmatriculare invalid!/\n");
	}
	try
	{
		srv.sterge_srv("SB67ARN");
	}
	catch (RepoException& re)
	{
		assert(re.getErrorMsg() == "NumarInmatriculare inexistent!/");
	}
}
void Teste::run_teste()
{
	test_getset();
	test_adauga_repo();
	test_actualizeaza_repo();
	test_sterge_repo();
	test_valideaza_masina();
	test_valideaza_nrInmtriculare();
	test_adauga_srv();
	test_actualizeaza_srv();
	test_sterge_srv();
	cout << "Succes\n";
}