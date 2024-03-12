#include "repository.h"
#pragma warning(disable:26823)

vector<Masina>& MasinaRepository::getAllMasina() noexcept
{
	return this->allMasina;
}

void MasinaRepository::adauga_repo(Masina& m)
{
	all_of(allMasina.begin(), allMasina.end(), [&](Masina c) { return c.getNrInmatriculare() != m.getNrInmatriculare();})?
		this->allMasina.push_back(m) :
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
		throw RepoException("NumarInmatriculare inexistent!/\n");
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

map<string, int> MasinaRepository::raport_model_repo()
{
	map<string, int> modelnr;
	for (const Masina& m : allMasina)
	{
		int sem = 0;
		for (auto pair : modelnr)
		{
			if (pair.first == m.getModel())
			{
				modelnr[pair.first]++;
				sem = 1;
				break;
			}
		}
		if (sem == 0)
			modelnr.insert({ m.getModel(), 1 });
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

void MasinaListRepository::lst_empty_repo() noexcept
{
	lstMasina.clear();
}

void MasinaListRepository::lst_genereaza_repo(const vector<Masina>& allM, int i)
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

void MasinaListRepository::lst_export_repo(string fname)
{
	ofstream out(fname, std::ofstream::out | std::ofstream::trunc);
	if (!out.is_open())
		throw RepoException("Cannot write to file " + fname);
	for (const Masina& m : lstMasina) {
		out << m.getNrInmatriculare() << "," << m.getProducator() << "," << m.getModel() << "," << m.getTip() << endl;
	}
	out.close();
}

void FileMasinaRepository::loadFromFile()
{
	ifstream in(this->filename);
	if (!in.is_open()) {
		throw RepoException("Cannot read from file " + filename);
	}
	string line;
	while (getline(in, line))
	{
		string nrInm, producator, model, tip;

		stringstream linestream(line);
		string current_item;
		int item_no = 0;
		while (getline(linestream, current_item, ','))
		{
			//we should do some checks here, make sure
			//that what we read is correct, throw exception otherwise
			//or 'clean' data we read
			//e.g. remove trailing spaces
			//as of now, if in file we have Venom, Eminem,... and we search
			//find("Venom","Eminem") - no space before artist, it won't work
			if (item_no == 0) nrInm = current_item;
			if (item_no == 1) producator = current_item;
			if (item_no == 2) model = current_item;
			if (item_no == 3) tip = current_item;
			item_no++;
		}
		Masina m{ nrInm, producator, model, tip };

		MasinaRepository::adauga_repo(m);
	}
	in.close();
}

void FileMasinaRepository::saveToFile()
{
	ofstream out(this->filename);
	//if (!out.is_open())
		//throw RepoException("Cannot write to file " + filename);
	for (const Masina& m : getAllMasina()) {
		out << m.getNrInmatriculare() << "," << m.getProducator() << "," << m.getModel() << "," << m.getTip() << endl;
	}
	out.close();
}

void FileMasinaRepository::adauga_repo(Masina& m)
{
	MasinaRepository::adauga_repo(m);
	saveToFile();
}
