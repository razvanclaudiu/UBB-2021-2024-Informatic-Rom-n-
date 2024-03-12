#include "ui.h"
#include <iostream>
#pragma warning(disable:26823)
using namespace std;

void ConsoleUI::afiseaza()
{
	const vector<Masina>& allMasina = srv.getAllMasina_srv();
	if (allMasina.size() == 0)
		cout << "Nu exista masini!" << endl;
	else 
		for (const auto& m : allMasina)
		{
				cout << "NrInmatriculare: " << m.getNrInmatriculare() << " | Producator: " << m.getProducator() << " | Model: " << m.getModel() << " | Tip: " <<m.getTip() << endl;
		}
}

void ConsoleUI::run()
{
	int cmd, running = 1;
	string nrInmatriculare, producator, model, tip;
	while (running)
	{
		cout << "1. Adauga\n" << "2. Actualizeaza\n" << "3. Sterge\n" << "4. Afiseaza\n" << "0. Exit\n";
		cout << ">>> ";
		cin >> cmd;
		switch (cmd)
		{
		case 1:
			cout << "NrInmatriculare: ";
			getline(cin >> ws, nrInmatriculare);
			cout << "Producator: ";
			getline(cin >> ws, producator);
			cout << "Model: ";
			getline(cin >> ws, model);
			cout << "Tip: ";
			getline(cin >> ws, tip);
			try
			{
				srv.adauga_srv(nrInmatriculare, producator, model, tip);
			}
			catch (RepoException& re)
			{
				cout << re.getErrorMsg();
			}
			catch (ValidationException& ve)
			{
				cout << ve.getErrorMsg();
			}
			break;
		case 2:
			cout << "NrInmatriculare: ";
			getline(cin >> ws, nrInmatriculare);
			cout << "Producator: ";
			getline(cin >> ws, producator);
			cout << "Model: ";
			getline(cin >> ws, model);
			cout << "Tip: ";
			getline(cin >> ws, tip);
			try
			{
				srv.actualizeaza_srv(nrInmatriculare, producator, model, tip);
			}
			catch (RepoException& re)
			{
				cout << re.getErrorMsg();
			}
			catch (ValidationException& ve)
			{
				cout << ve.getErrorMsg();
			}
			break;
		case 3:
			cout << "NrInmatriculare: ";
			getline(cin >> ws, nrInmatriculare);
			try
			{
					srv.sterge_srv(nrInmatriculare);
			}
			catch (RepoException& re)
			{
				cout << re.getErrorMsg();
			}
			catch (ValidationException& ve)
			{
				cout << ve.getErrorMsg();
			}
			break;
		case 4:
			afiseaza();
			break;
		case 0:
			running = 0;
			break;
		default:
			break;
		}
	}
}