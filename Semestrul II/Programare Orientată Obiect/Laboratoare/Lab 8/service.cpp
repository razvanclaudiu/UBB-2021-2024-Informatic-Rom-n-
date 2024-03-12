#include "service.h"

vector<Masina>& MasinaStore::getAllMasina_srv() noexcept
{
	return this->repo.getAllMasina();
}

void MasinaStore::adauga_srv(string nrInmatriculare, string producator, string model, string tip)
{
	Masina m1(nrInmatriculare, producator, model, tip);
	val.validate_masina(m1);
	repo.adauga_repo(m1);
}

void MasinaStore::actualizeaza_srv(string nrInmatriculare, string producator, string model, string tip)
{
	Masina m1(nrInmatriculare, producator, model, tip);
	val.validate_masina(m1);
	repo.actualizeaza_repo(m1);
}

void MasinaStore::sterge_srv(string nrInmatriculare)
{
	val.validate_nrInmatriculare(nrInmatriculare);
	repo.sterge_repo(nrInmatriculare);
}

const Masina& MasinaStore::cauta_srv(string nrInmatriculare)
{
	string nrInm = nrInmatriculare;
	val.validate_nrInmatriculare(nrInmatriculare);
	return repo.cauta_repo(nrInm);
}

void MasinaStore::ordonare_srv(bool (*key)(const Masina&, const Masina&))
{
	repo.ordonare_repo(key);
}

void MasinaStore::sortnrInmatriculare() {
	ordonare_srv(cmpnrInmatriculare);	
}

void MasinaStore::sortTip() {
	ordonare_srv(cmpTip);
}

void MasinaStore::sortProducatorModel() {
	ordonare_srv(cmpProducatorModel);
}

vector<Masina> MasinaStore::filtrare_srv(function<bool(const Masina&)> fct)
{
	return repo.filtrare_repo(fct);
}

vector<Masina> MasinaStore::filtrareProducator(string producator)
{
	return filtrare_srv([producator](const Masina& m) {return m.getProducator() == producator;});
}

vector<Masina> MasinaStore::filtrareTip(string tip)
{
	val.validate_tip(tip);
	return filtrare_srv([tip](const Masina& m) {return m.getTip() == tip;});
}

map<string, int> MasinaStore::raport_model_srv()
{
	return repo.raport_model_repo();
}

vector<Masina>& MasinaStore::getlstMasina_srv() noexcept
{
	return this->repolist.getlstMasina();
}

void MasinaStore::lst_adauga_srv(string nrInmatriculare)
{
	Masina m1 = repo.cauta_repo(nrInmatriculare);
	val.validate_masina(m1);
	repolist.lst_adauga_repo(m1);
}

void MasinaStore::lst_empty_srv() noexcept
{
	repolist.lst_empty_repo();
}

void MasinaStore::lst_generate_srv(int i)
{
	repo.shuffle_repo();
	repolist.lst_genereaza_repo(repo.getAllMasina(), i);
}