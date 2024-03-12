#include "service.h"

const vector<Masina>& MasinaStore::getAllMasina_srv() noexcept
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