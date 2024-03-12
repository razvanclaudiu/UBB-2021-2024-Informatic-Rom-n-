#include "repository.h"
#pragma warning(disable:26823)

vectorClass<Masina>& MasinaRepository::getAllMasina() noexcept
{
	return this->allMasina;
}

void MasinaRepository::adauga_repo(const Masina& m)
{
	for (const Masina& c : this->allMasina)
		if (c.getNrInmatriculare() == m.getNrInmatriculare())
			throw RepoException("NumarInmatriculare existent!/\n");
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
	throw RepoException("NumarInmatriculare inexistent!/\n");
}

void MasinaRepository::sterge_repo(string nrInmatriculare)
{
	int i = 0;
	auto MasinaID = this->allMasina.begin();
	while (MasinaID != this->allMasina.end())
	{
		if ((*MasinaID).getNrInmatriculare() == nrInmatriculare)
		{
			this->allMasina.erase(i);
			return;
		}
		MasinaID.next();
		i++;
	}
	throw RepoException("NumarInmatriculare inexistent!/\n");}

const Masina& MasinaRepository::cauta_repo(string nrInmatriculare)
{
	for (int i = 0;i < this->allMasina.size();i++) {
		if (this->allMasina.at(i).getNrInmatriculare() == nrInmatriculare)
		{
			return this->allMasina.at(i);
		}
	}
	throw RepoException("Nu exista aceasta masina!\n");}

void MasinaRepository::ordonare_repo(bool (*key)(const Masina&, const Masina&))
{
	int i, j;
	for (i = 0; i < allMasina.size()-1;i++)
		for (j = i + 1; j < allMasina.size();j++)
		{
			Masina a = allMasina.at(i), b = allMasina.at(j);
			if(key != nullptr)
				if (key(a,b))
				{
					Masina aux = allMasina.at(i);
					allMasina.set(i, allMasina.at(j));
					allMasina.set(j, aux);
				}
		}
}

vectorClass<Masina> MasinaRepository::filtrare_repo(function<bool(const Masina&)> fct)
{
	vectorClass<Masina> filteredList;
	for (const auto& m : this->allMasina)
	{
		if (fct(m))
		{
			filteredList.push_back(m);
			
		}
	}
	return filteredList;

}
/*int MasinaRepository::opposite(int result)
{
	if (result == 1)
		return 0;
	return 1;
}*/


