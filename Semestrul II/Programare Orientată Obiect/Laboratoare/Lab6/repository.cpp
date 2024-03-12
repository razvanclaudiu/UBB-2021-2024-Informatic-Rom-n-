#include "repository.h"
#pragma warning(disable:26823)

const vector<Masina>& MasinaRepository::getAllMasina() noexcept
{
	return this->allMasina;
}

void MasinaRepository::adauga_repo(const Masina& m)
{
	for (const Masina& c : this->allMasina)
			if (c.getNrInmatriculare() == m.getNrInmatriculare())
				throw RepoException("NumarInmatriculare existent!/");
	this->allMasina.push_back(m);
}

void MasinaRepository::actualizeaza_repo(const Masina& m)
{
	for (Masina& c : this->allMasina)
		if (c.getNrInmatriculare() == m.getNrInmatriculare())
		{
			c.setProducator(m.getProducator());
			c.setModel(m.getModel());
			c.setTip(m.getTip());
			return;
		}
	throw RepoException("NumarInmatriculare inexistent!/");
}

void MasinaRepository::sterge_repo(string nrInmatriculare)
{
	auto MasinaID = this->allMasina.begin();
	while (MasinaID != this->allMasina.end())
	{
		if ((*MasinaID).getNrInmatriculare() == nrInmatriculare)
		{
			this->allMasina.erase(MasinaID);
			return;
		}
		MasinaID++;
	}
	throw RepoException("NumarInmatriculare inexistent!/");
}