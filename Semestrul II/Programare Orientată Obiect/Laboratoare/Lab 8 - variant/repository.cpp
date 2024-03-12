#include "repository.h"
#pragma warning(disable:26823)

vector<Masina>& MasinaRepository::getAllMasina() noexcept
{
	return this->allMasina;
}

void MasinaRepository::adauga_repo(Masina& m)
{
	all_of(allMasina.begin(), allMasina.end(), [&](Masina c) { return c.getNrInmatriculare() != m.getNrInmatriculare();})?
		this->allMasina.push_back(m):
		throw RepoException("NumarInmatriculare existent!/\n");
}

void MasinaRepository::actualizeaza_repo(const Masina& m)
{
	any_of(allMasina.begin(), allMasina.end(), [&](Masina c) { return c.getNrInmatriculare() == m.getNrInmatriculare();}) ?
		replace_if(allMasina.begin(), allMasina.end(), [&](Masina c) { return c.getNrInmatriculare() == m.getNrInmatriculare();}, m):
		throw RepoException("NumarInmatriculare inexistent!/\n");
}

void MasinaRepository::sterge_repo(string nrInmatriculare)
{
	any_of(allMasina.begin(), allMasina.end(), [&](Masina c) { return c.getNrInmatriculare() == nrInmatriculare;}) ?
		allMasina.erase(remove_if(allMasina.begin(), allMasina.end(), [&](Masina c) { return c.getNrInmatriculare() == nrInmatriculare;})) :
		throw RepoException("NumarInmatriculare inexistent!/\n");
}

const Masina& MasinaRepository::cauta_repo(string nrInmatriculare)
{
	vector<Masina>::iterator itr;
	itr = find_if(allMasina.begin(), allMasina.end(), [&](Masina c) { return c.getNrInmatriculare() == nrInmatriculare;});
	if(itr == allMasina.end())
		throw RepoException("Nu exista aceasta masina!\n");
	return *itr;
}

void MasinaRepository::ordonare_repo(bool (*key)(const Masina&, const Masina&))
{
	sort(allMasina.begin(), allMasina.end(), *key);
}

vector<Masina> MasinaRepository::filtrare_repo(function<bool(const Masina&)> fct)
{
	vector<Masina> filteredList;
	copy_if(allMasina.begin(), allMasina.end(), back_inserter(filteredList), fct);
	return filteredList;

}

void MasinaRepository::shuffle_repo()
{
	auto seed = chrono::system_clock::now().time_since_epoch().count();
	shuffle(allMasina.begin(), allMasina.end(), default_random_engine(seed));
}

vector<Pereche> MasinaRepository::raport_model_repo()
{
	vector<Pereche> modelnr;
	for (const Masina& m : allMasina)
	{
		int sem = 0;
		for (Pereche& pair : modelnr)
		{
			if (pair.first() == m.getModel())
			{
				const int i = pair.second()+1;
				pair.set_second(i);
				sem = 1;
				break;
			}
		}
		if (sem == 0)
		{
			Pereche p1 = { { m.getModel(), 1 } };
			modelnr.push_back(p1);
		}
	}
	return modelnr;
}

vector<Masina>& MasinaListRepository::getlstMasina() noexcept
{
	return this->lstMasina;
}

void MasinaListRepository::lst_adauga_repo(Masina& m)
{
	all_of(lstMasina.begin(), lstMasina.end(), [&](Masina c) { return c.getNrInmatriculare() != m.getNrInmatriculare();}) ?
		this->lstMasina.push_back(m) :
		throw RepoException("NumarInmatriculare existent!/\n");
}

void MasinaListRepository::lst_empty_repo()
{
	lstMasina.clear();
}

void MasinaListRepository::lst_genereaza_repo(vector<Masina>& allM, int i)
{
	if (i > allM.size())
		throw RepoException("Nu exista destule elemente!/\n");
	else
	{
		lstMasina.clear();
		lstMasina.resize(i);
		copy_n(allM.cbegin(), i, lstMasina.begin());
	}
		
}

