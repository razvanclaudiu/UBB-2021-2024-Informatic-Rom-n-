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
		assert(re.getErrorMsg() == "NumarInmatriculare existent!/\n");
	}
	Masina m3{ "SB67AAN","Toyota Motor Corporation","Toyota Yaris","automobil" };
	repo.adauga_repo(m3);
	Masina m4{ "SB67AQN","Toyota Motor Corporation","Toyota Yaris","automobil" };
	repo.adauga_repo(m4);
	Masina m5{ "SB67AZN","Toyota Motor Corporation","Toyota Yaris","automobil" };
	repo.adauga_repo(m5);
	Masina m6{ "SB67ANN","Toyota Motor Corporation","Toyota Yaris","automobil" };
	repo.adauga_repo(m6);
	Masina m7{ "SB67AMN","Toyota Motor Corporation","Toyota Yaris","automobil" };
	repo.adauga_repo(m7);
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
		assert(re.getErrorMsg() == "NumarInmatriculare inexistent!/\n");
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
		assert(re.getErrorMsg() == "NumarInmatriculare inexistent!/\n");
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

void Teste::test_valideaza_tip()
{
	MasinaValidation val;
	val.validate_tip("automobil");
	val.validate_tip("camion");
	val.validate_tip("tir");
	val.validate_tip("tractor");
	try
	{
		val.validate_tip("marius");
	}
	catch (ValidationException& ve)
	{
		assert(ve.getErrorMsg() == "Tip invalid!/\n");
	}
}

void Teste::test_adauga_srv()
{
	MasinaRepository repo;
	MasinaListRepository repolist;
	MasinaValidation val;
	MasinaStore srv{ repo,repolist,val };
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
		assert(re.getErrorMsg() == "NumarInmatriculare existent!/\n");
	}
}

void Teste::test_actualizeaza_srv()
{
	MasinaRepository repo;
	MasinaListRepository repolist;
	MasinaValidation val;
	MasinaStore srv{ repo,repolist,val };
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
		assert(re.getErrorMsg() == "NumarInmatriculare inexistent!/\n");
	}
}

void Teste::test_sterge_srv()
{
	MasinaRepository repo;
	MasinaListRepository repolist;
	MasinaValidation val;
	MasinaStore srv{ repo,repolist,val };
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
		assert(re.getErrorMsg() == "NumarInmatriculare inexistent!/\n");
	}
}

void Teste::test_cauta_repo()
{
	MasinaRepository repo;
	Masina m1{ "SB67ARN","Toyota Motor Corporation","Toyota Yaris","automobil" };
	repo.adauga_repo(m1);
	assert(repo.getAllMasina().size() == 1);	
	Masina m2 = repo.cauta_repo("SB67ARN");
	assert(m1.getNrInmatriculare() == m2.getNrInmatriculare());
	Masina m3{ "SB67DFV","Toyota Motor Corporation","Toyota Yaris","automobil" };
	repo.adauga_repo(m3);
	assert(repo.getAllMasina().size() == 2);
	Masina m4 = repo.cauta_repo("SB67DFV");
	assert(m3.getNrInmatriculare() == m4.getNrInmatriculare());
	try
	{
		m2 = repo.cauta_repo("SB23AND");}
	catch (RepoException& re)
	{
		assert(re.getErrorMsg() == "NumarInmatriculare inexistent!/\n");
	}
}

void Teste::test_cauta_srv()
{
	MasinaRepository repo;
	MasinaListRepository repolist;
	MasinaValidation val;
	MasinaStore srv{ repo,repolist,val };
	assert(srv.getAllMasina_srv().size() == 0);
	srv.adauga_srv("SB67ARN", "Toyota Motor Corporation", "Toyota Yaris", "automobil");
	assert(srv.getAllMasina_srv().size() == 1);
	Masina m1 = srv.cauta_srv("SB67ARN");
	assert(m1.getNrInmatriculare() == "SB67ARN");
	assert(m1.getProducator() == "Toyota Motor Corporation");
	assert(m1.getModel() == "Toyota Yaris");
	assert(m1.getTip() == "automobil");
	try
	{
		Masina m2 = srv.cauta_srv("AA67ARN");}
	catch (ValidationException& ve)
	{
		assert(ve.getErrorMsg() == "NumarInmatriculare invalid!/\n");
	}
	try
	{
		Masina m = srv.cauta_srv("SB88RNR");}
	catch (RepoException& re)
	{
		assert(re.getErrorMsg() == "NumarInmatriculare inexistent!/\n");
	}
}

void Teste::test_ordonare_nrInmatriculare()
{
	MasinaRepository repo;
	MasinaListRepository repolist;
	MasinaValidation val;
	MasinaStore srv{ repo,repolist,val };
	assert(srv.getAllMasina_srv().size() == 0);
	srv.adauga_srv("SB67ARN", "Toyota Motor Corporation", "Toyota Yariss", "automobil");
	assert(srv.getAllMasina_srv().size() == 1);
	srv.adauga_srv("CJ34BGF", "Honda Motor", "HR-V", "tractor");
	assert(srv.getAllMasina_srv().size() == 2);
	srv.adauga_srv("SB12LDS", "BMW Group", "i4 M50", "tir");
	assert(srv.getAllMasina_srv().size() == 3);
	srv.adauga_srv("CJ43FSD", "Toyota Motor Corporation", "Toyota Avalon", "camion");
	assert(srv.getAllMasina_srv().size() == 4);
	srv.adauga_srv("SB67ARA", "Honda Motor", "Civic Sedan", "automobil");
	assert(srv.getAllMasina_srv().size() == 5);
	srv.adauga_srv("CJ10EFD", "BMW Group", "X2", "camion");
	assert(srv.getAllMasina_srv().size() == 6);
	srv.adauga_srv("SB99ZCF", "Daimler", "GLE SUV", "tir");
	assert(srv.getAllMasina_srv().size() == 7);
	srv.sortnrInmatriculare();
	vector<Masina> testMasina = srv.getAllMasina_srv();
	assert(testMasina.at(0).getNrInmatriculare() == "CJ10EFD");
	assert(testMasina.at(1).getNrInmatriculare() == "CJ34BGF");
	assert(testMasina.at(2).getNrInmatriculare() == "CJ43FSD");
	assert(testMasina.at(3).getNrInmatriculare() == "SB12LDS");
	assert(testMasina.at(4).getNrInmatriculare() == "SB67ARA");
	assert(testMasina.at(5).getNrInmatriculare() == "SB67ARN");
	assert(testMasina.at(6).getNrInmatriculare() == "SB99ZCF");

}

void Teste::test_ordonare_Tip()
{
	MasinaRepository repo;
	MasinaListRepository repolist;
	MasinaValidation val;
	MasinaStore srv{ repo,repolist,val };
	assert(srv.getAllMasina_srv().size() == 0);
	srv.adauga_srv("SB67ARN", "Toyota Motor Corporation", "Toyota Yariss", "automobil");
	assert(srv.getAllMasina_srv().size() == 1);
	srv.adauga_srv("CJ34BGF", "Honda Motor", "HR-V", "tractor");
	assert(srv.getAllMasina_srv().size() == 2);
	srv.adauga_srv("SB12LDS", "BMW Group", "i4 M50", "tir");
	assert(srv.getAllMasina_srv().size() == 3);
	srv.adauga_srv("CJ43FSD", "Toyota Motor Corporation", "Toyota Avalon", "camion");
	assert(srv.getAllMasina_srv().size() == 4);
	srv.adauga_srv("SB67ARA", "Honda Motor", "Civic Sedan", "automobil");
	assert(srv.getAllMasina_srv().size() == 5);
	srv.adauga_srv("CJ10EFD", "BMW Group", "X2", "camion");
	assert(srv.getAllMasina_srv().size() == 6);
	srv.adauga_srv("SB99ZCF", "Daimler", "GLE SUV", "tir");
	assert(srv.getAllMasina_srv().size() == 7);
	srv.sortTip();
	vector<Masina> testMasina = srv.getAllMasina_srv();
	assert(testMasina.at(0).getTip() == "automobil");
	assert(testMasina.at(1).getTip() == "automobil");
	assert(testMasina.at(2).getTip() == "camion");
	assert(testMasina.at(3).getTip() == "camion");
	assert(testMasina.at(4).getTip() == "tir");
	assert(testMasina.at(5).getTip() == "tir");
	assert(testMasina.at(6).getTip() == "tractor");
}

void Teste::test_ordonare_ProducatorModel()
{
	MasinaRepository repo;
	MasinaListRepository repolist;
	MasinaValidation val;
	MasinaStore srv{ repo,repolist,val };
	assert(srv.getAllMasina_srv().size() == 0);
	srv.adauga_srv("SB67ARN", "Toyota Motor Corporation", "Toyota Yariss", "automobil");
	assert(srv.getAllMasina_srv().size() == 1);
	srv.adauga_srv("CJ34BGF", "Honda Motor", "HR-V", "tractor");
	assert(srv.getAllMasina_srv().size() == 2);
	srv.adauga_srv("SB12LDS", "BMW Group", "i4 M50", "tir");
	assert(srv.getAllMasina_srv().size() == 3);
	srv.adauga_srv("CJ43FSD", "Toyota Motor Corporation", "Toyota Avalon", "camion");
	assert(srv.getAllMasina_srv().size() == 4);
	srv.adauga_srv("SB67ARA", "Honda Motor", "Civic Sedan", "automobil");
	assert(srv.getAllMasina_srv().size() == 5);
	srv.adauga_srv("CJ10EFD", "BMW Group", "X2", "camion");
	assert(srv.getAllMasina_srv().size() == 6);
	srv.adauga_srv("SB99ZCF", "Daimler", "GLE SUV", "tir");
	assert(srv.getAllMasina_srv().size() == 7);
	srv.sortProducatorModel();
	vector<Masina> testMasina = srv.getAllMasina_srv();
	assert(testMasina.at(0).getProducator() == "BMW Group");
	assert(testMasina.at(1).getProducator() == "BMW Group");
	assert(testMasina.at(2).getProducator() == "Daimler");
	assert(testMasina.at(3).getProducator() == "Honda Motor");
	assert(testMasina.at(4).getProducator() == "Honda Motor");
	assert(testMasina.at(5).getProducator() == "Toyota Motor Corporation");
	assert(testMasina.at(6).getProducator() == "Toyota Motor Corporation");
	assert(testMasina.at(0).getModel() == "X2");
	assert(testMasina.at(1).getModel() == "i4 M50");
	assert(testMasina.at(2).getModel() == "GLE SUV");
	assert(testMasina.at(3).getModel() == "Civic Sedan");
	assert(testMasina.at(4).getModel() == "HR-V");
	assert(testMasina.at(5).getModel() == "Toyota Avalon");
	assert(testMasina.at(6).getModel() == "Toyota Yariss");
}

void Teste::test_filtrare_Producator()
{

	MasinaRepository repo;
	MasinaListRepository repolist;
	MasinaValidation val;
	MasinaStore srv{ repo,repolist,val };
	assert(srv.getAllMasina_srv().size() == 0);
	srv.adauga_srv("SB67ARN", "Toyota Motor Corporation", "Toyota Yariss", "automobil");
	assert(srv.getAllMasina_srv().size() == 1);
	srv.adauga_srv("CJ34BGF", "Honda Motor", "HR-V", "tractor");
	assert(srv.getAllMasina_srv().size() == 2);
	srv.adauga_srv("SB12LDS", "BMW Group", "i4 M50", "tir");
	assert(srv.getAllMasina_srv().size() == 3);
	srv.adauga_srv("CJ43FSD", "Toyota Motor Corporation", "Toyota Avalon", "camion");
	assert(srv.getAllMasina_srv().size() == 4);
	srv.adauga_srv("SB67ARA", "Honda Motor", "Civic Sedan", "automobil");
	assert(srv.getAllMasina_srv().size() == 5);
	srv.adauga_srv("CJ10EFD", "BMW Group", "X2", "camion");
	assert(srv.getAllMasina_srv().size() == 6);
	srv.adauga_srv("SB99ZCF", "Daimler", "GLE SUV", "tir");
	assert(srv.getAllMasina_srv().size() == 7);
	vector<Masina> filt = srv.filtrareProducator("Toyota Motor Corporation");
	assert(filt.size() == 2);
	filt = srv.filtrareProducator("Daimler");
	assert(filt.size() == 1);
	filt = srv.filtrareProducator("");
	assert(filt.size() == 0);
}

void Teste::test_filtrare_Tip()
{
	MasinaRepository repo;
	MasinaListRepository repolist;
	MasinaValidation val;
	MasinaStore srv{ repo,repolist,val };
	assert(srv.getAllMasina_srv().size() == 0);
	srv.adauga_srv("SB67ARN", "Toyota Motor Corporation", "Toyota Yariss", "automobil");
	assert(srv.getAllMasina_srv().size() == 1);
	srv.adauga_srv("CJ34BGF", "Honda Motor", "HR-V", "tractor");
	assert(srv.getAllMasina_srv().size() == 2);
	srv.adauga_srv("SB12LDS", "BMW Group", "i4 M50", "tir");
	assert(srv.getAllMasina_srv().size() == 3);
	srv.adauga_srv("CJ43FSD", "Toyota Motor Corporation", "Toyota Avalon", "camion");
	assert(srv.getAllMasina_srv().size() == 4);
	srv.adauga_srv("SB67ARA", "Honda Motor", "Civic Sedan", "automobil");
	assert(srv.getAllMasina_srv().size() == 5);
	srv.adauga_srv("CJ10EFD", "BMW Group", "X2", "camion");
	assert(srv.getAllMasina_srv().size() == 6);
	srv.adauga_srv("SB99ZCF", "Daimler", "GLE SUV", "tir");
	assert(srv.getAllMasina_srv().size() == 7);
	vector<Masina> filt = srv.filtrareTip("automobil");
	assert(filt.size() == 2);
	filt = srv.filtrareTip("tractor");
	assert(filt.size() == 1);
	try
	{
		filt = srv.filtrareTip("d");
	}
	catch (ValidationException& ve)
	{
		assert(ve.getErrorMsg() == "Tip invalid!/\n");
	}
}

void Teste::test_lst_adauga()
{
	MasinaRepository repo;
	MasinaListRepository repolist;
	MasinaValidation val;
	MasinaStore srv{ repo,repolist,val };
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
		assert(re.getErrorMsg() == "NumarInmatriculare existent!/\n");
	}
	assert(srv.getlstMasina_srv().size() == 0);
	srv.lst_adauga_srv("SB67ARN");
	assert(srv.getlstMasina_srv().size() == 1);
	try
	{
		srv.lst_adauga_srv("SB67ARN");
	}
	catch (RepoException& re)
	{
		assert(re.getErrorMsg() == "NumarInmatriculare existent!/\n");
	}
}

void Teste::test_lst_empty()
{
	MasinaRepository repo;
	MasinaListRepository repolist;
	MasinaValidation val;
	MasinaStore srv{ repo,repolist,val };
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
		assert(re.getErrorMsg() == "NumarInmatriculare existent!/\n");
	}
	assert(srv.getlstMasina_srv().size() == 0);
	srv.lst_adauga_srv("SB67ARN");
	assert(srv.getlstMasina_srv().size() == 1);
	srv.lst_empty_srv();
	assert(srv.getlstMasina_srv().size() == 0);
}

void Teste::test_lst_generate()
{
	MasinaRepository repo;
	MasinaListRepository repolist;
	MasinaValidation val;
	MasinaStore srv{ repo,repolist,val };
	assert(srv.getAllMasina_srv().size() == 0);
	srv.adauga_srv("SB67ARN", "Toyota Motor Corporation", "Toyota Yariss", "automobil");
	assert(srv.getAllMasina_srv().size() == 1);
	srv.adauga_srv("CJ34BGF", "Honda Motor", "HR-V", "tractor");
	assert(srv.getAllMasina_srv().size() == 2);
	srv.adauga_srv("SB12LDS", "BMW Group", "i4 M50", "tir");
	assert(srv.getAllMasina_srv().size() == 3);
	srv.adauga_srv("CJ43FSD", "Toyota Motor Corporation", "Toyota Avalon", "camion");
	assert(srv.getAllMasina_srv().size() == 4);
	srv.adauga_srv("SB67ARA", "Honda Motor", "Civic Sedan", "automobil");
	assert(srv.getAllMasina_srv().size() == 5);
	srv.adauga_srv("CJ10EFD", "BMW Group", "X2", "camion");
	assert(srv.getAllMasina_srv().size() == 6);
	srv.adauga_srv("SB99ZCF", "Daimler", "GLE SUV", "tir");
	assert(srv.getAllMasina_srv().size() == 7);
	assert(srv.getlstMasina_srv().size() == 0);
	srv.lst_generate_srv(4);
	assert(srv.getlstMasina_srv().size() == 4);
	srv.lst_generate_srv(7);
	assert(srv.getlstMasina_srv().size() == 7);
	try
	{
		srv.lst_generate_srv(10);
	}
	catch (RepoException& re)
	{
		assert(re.getErrorMsg() == "Nu exista destule elemente!/\n");
	}
}

void Teste::test_lst_export()
{
	MasinaRepository repo;
	MasinaListRepository repolist;
	MasinaValidation val;
	MasinaStore srv{ repo,repolist,val };
	assert(srv.getAllMasina_srv().size() == 0);
	srv.adauga_srv("SB67ARN", "Toyota Motor Corporation", "Toyota Yariss", "automobil");
	assert(srv.getAllMasina_srv().size() == 1);
	srv.adauga_srv("CJ34BGF", "Honda Motor", "HR-V", "tractor");
	assert(srv.getAllMasina_srv().size() == 2);
	srv.adauga_srv("SB12LDS", "BMW Group", "i4 M50", "tir");
	assert(srv.getAllMasina_srv().size() == 3);
	srv.adauga_srv("CJ43FSD", "Toyota Motor Corporation", "Toyota Avalon", "camion");
	assert(srv.getAllMasina_srv().size() == 4);
	srv.adauga_srv("SB67ARA", "Honda Motor", "Civic Sedan", "automobil");
	assert(srv.getAllMasina_srv().size() == 5);
	srv.adauga_srv("CJ10EFD", "BMW Group", "X2", "camion");
	assert(srv.getAllMasina_srv().size() == 6);
	srv.adauga_srv("SB99ZCF", "Daimler", "GLE SUV", "tir");
	assert(srv.getAllMasina_srv().size() == 7);
	assert(srv.getlstMasina_srv().size() == 0);
	srv.lst_generate_srv(4);
	assert(srv.getlstMasina_srv().size() == 4);
	try
	{
		srv.lst_export_srv("/tert.txt");
	}
	catch (RepoException& re)
	{
		assert(re.getErrorMsg() == "Cannot write to file /tert.txt");
	}
	srv.lst_export_srv("test_carlist.txt");
}

void Teste::test_raport()
{
	MasinaRepository repo;
	MasinaListRepository repolist;
	MasinaValidation val;
	MasinaStore srv{ repo,repolist,val };
	assert(srv.getAllMasina_srv().size() == 0);
	srv.adauga_srv("SB67ARN", "Toyota Motor Corporation", "Toyota Yariss", "automobil");
	assert(srv.getAllMasina_srv().size() == 1);
	srv.adauga_srv("CJ34BGF", "Honda Motor", "HR-V", "tractor");
	assert(srv.getAllMasina_srv().size() == 2);
	srv.adauga_srv("SB12LDS", "BMW Group", "i4 M50", "tir");
	assert(srv.getAllMasina_srv().size() == 3);
	srv.adauga_srv("CJ43FSD", "Toyota Motor Corporation", "Toyota Avalon", "camion");
	assert(srv.getAllMasina_srv().size() == 4);
	srv.adauga_srv("SB67ARA", "Honda Motor", "Civic Sedan", "automobil");
	assert(srv.getAllMasina_srv().size() == 5);
	srv.adauga_srv("CJ10EFD", "BMW Group", "X2", "camion");
	assert(srv.getAllMasina_srv().size() == 6);
	srv.adauga_srv("SB99ZCF", "Daimler", "GLE SUV", "tir");
	assert(srv.getAllMasina_srv().size() == 7);
	map<string, int> testmap = srv.raport_model_srv();
	assert(testmap.size() == 7);
	assert(testmap.at("HR-V") == 1);
	assert(testmap.at("Toyota Yariss") == 1);
	assert(testmap.at("i4 M50") == 1);
	assert(testmap.at("Toyota Avalon") == 1);
	assert(testmap.at("Civic Sedan") == 1);
	assert(testmap.at("X2") == 1);
	assert(testmap.at("GLE SUV") == 1);
	srv.adauga_srv("SB93ZCF", "Daimler", "GLE SUV", "tir");
	assert(srv.getAllMasina_srv().size() == 8);
	testmap = srv.raport_model_srv();
	assert(testmap.size() == 7);
	assert(testmap.at("GLE SUV") == 2);
}

void Teste::test_file_adauga()
{
	std::ofstream ofs;
	ofs.open("test_masini.txt", std::ofstream::out | std::ofstream::trunc);
	ofs << "SB67ARN,Toyota Motor Corporation,Toyota Yariss,automobil\n";
	ofs << "CJ34BGF,Honda Motor,HR-V,tractor\n";
	ofs << "SB12LDS,BMW Group,i4M50,tir\n";
	ofs << "CJ43FSD,Toyota Motor Corporation,Toyota Avalon,camion\n";
	ofs.close();
	try
	{
		FileMasinaRepository repo{ "test_test.txt" };}
	catch (RepoException& re)
	{
		assert(re.getErrorMsg() == "Cannot read from file test_test.txt");
	}
	FileMasinaRepository repo{ "test_masini.txt" };
	assert(repo.getAllMasina().size() == 4);


	auto m1 = repo.cauta_repo("SB12LDS");
	assert(m1.getNrInmatriculare() == "SB12LDS");
	assert(m1.getProducator() == "BMW Group");
	assert(m1.getModel() == "i4M50");
	assert(m1.getTip() == "tir");

	Masina m2{ "SB89UDH", "Toyota Motor Corporation", "Toyota Yariss", "camion"};

	repo.adauga_repo(m2);
	assert(repo.getAllMasina().size() == 5);
	Masina m3 = repo.cauta_repo("SB89UDH");
	assert(m3.getNrInmatriculare() == "SB89UDH");

}

void Teste::test_undo()
{
	MasinaRepository repo;
	MasinaListRepository repolist;
	MasinaValidation val;
	MasinaStore srv{ repo,repolist,val };
	assert(srv.getAllMasina_srv().size() == 0);
	srv.adauga_srv("SB67ARN", "Toyota Motor Corporation", "Toyota Yariss", "automobil");
	assert(srv.getAllMasina_srv().size() == 1);
	srv.adauga_srv("CJ34BGF", "Honda Motor", "HR-V", "tractor");
	assert(srv.getAllMasina_srv().size() == 2);
	srv.actualizeaza_srv("CJ34BGF", "BMW Group", "i4 M50", "tir");
	assert(srv.getAllMasina_srv().size() == 2);
	srv.sterge_srv("SB67ARN");
	assert(srv.getAllMasina_srv().size() == 1);
	srv.undo();
	assert(srv.getAllMasina_srv().size() == 2);
	srv.undo();
	assert(srv.getAllMasina_srv().size() == 2);
	srv.undo();
	assert(srv.getAllMasina_srv().size() == 1);
	srv.undo();
	assert(srv.getAllMasina_srv().size() == 0);
	try
	{
		srv.undo();
	}
	catch (RepoException& re)
	{
		assert(re.getErrorMsg() == "Nu mai exista operatii!\n");
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
	test_valideaza_tip();
	test_adauga_srv();
	test_actualizeaza_srv();
	test_sterge_srv();
	test_cauta_repo();
	test_cauta_srv();
	test_ordonare_nrInmatriculare();
	test_ordonare_Tip();
	test_ordonare_ProducatorModel();
	test_filtrare_Producator();
	test_filtrare_Tip();
	test_lst_adauga();
	test_lst_empty();
	test_lst_generate();
	test_lst_export();
	test_raport();
	test_file_adauga();
	test_undo();
	cout << "Succes\n";
}