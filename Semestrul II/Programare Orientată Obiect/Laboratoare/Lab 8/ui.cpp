#include "ui.h"
#include <iostream>
using namespace std;

void ConsoleUI::filtrare_producator(string producator)
{
	int sem = 0;
	vector<Masina>& allMasina = srv.getAllMasina_srv();
	if (allMasina.size() == 0)
		cout << "Nu exista masini!" << endl;
	else
		for (const Masina& m : allMasina)
		{
			if (m.getProducator() == producator)
			{
				sem = 1;
				cout << "NrInmatriculare: " << m.getNrInmatriculare() << " | Producator: " << m.getProducator() << " | Model: " << m.getModel() << " | Tip: " << m.getTip() << endl;
			}
				
		}
	if (sem == 0)
		cout << "Nu exista masini cu acest producator!";
}

void ConsoleUI::filtrare_tip(string tip)
{
	int sem = 0;
	vector<Masina>& allMasina = srv.getAllMasina_srv();
	if (allMasina.size() == 0)
		cout << "Nu exista masini!" << endl;
	else
		for (const Masina& m : allMasina)
		{
			if (m.getTip()==tip)
			{
				sem = 1;
				cout << "NrInmatriculare: " << m.getNrInmatriculare() << " | Producator: " << m.getProducator() << " | Model: " << m.getModel() << " | Tip: " << m.getTip() << endl;
			}

		}
	if (sem == 0)
		cout << "Nu exista masini cu acest producator!";
}

void ConsoleUI::afiseaza()
{
	vector<Masina>& allMasina = srv.getAllMasina_srv();
	if (allMasina.size() == 0)
		cout << "Nu exista masini!" << endl;
	else
		for (const Masina& m : allMasina)
		{
			cout << "NrInmatriculare: " << m.getNrInmatriculare() << " | Producator: " << m.getProducator() << " | Model: " << m.getModel() << " | Tip: " << m.getTip() << endl;
		}
}

void ConsoleUI::afiseaza_lst()
{
	vector<Masina>& allMasina = srv.getlstMasina_srv();
	if (allMasina.size() == 0)
		cout << "Nu exista masini!" << endl;
	else
		for (const Masina& m : allMasina)
		{
			cout << "NrInmatriculare: " << m.getNrInmatriculare() << " | Producator: " << m.getProducator() << " | Model: " << m.getModel() << " | Tip: " << m.getTip() << endl;
		}
}


void ConsoleUI::afiseaza_filtrat(vector<Masina> list)
{
	vector<Masina>& allMasina = list;
	if (allMasina.size() == 0)
		cout << "Nu exista masini!" << endl;
	else
		for (const Masina& m : allMasina)
		{
			cout << "NrInmatriculare: " << m.getNrInmatriculare() << " | Producator: " << m.getProducator() << " | Model: " << m.getModel() << " | Tip: " << m.getTip() << endl;
		}
}

void ConsoleUI::afiseaza_raport(map<string, int> list)
{
	map<string, int>& modelnrlst = list;
	if (modelnrlst.size() == 0)
		cout << "Nu exista masini!" << endl;
	else
	{
		cout << "Raport:" << endl;
			for (auto pair : modelnrlst)
			{
				cout << pair.first << " - " << pair.second << endl;
			}
	}
}

void ConsoleUI::run()
{
	int cmd, running = 1, menu=1, nrmas = 0;;
	string nrInmatriculare, producator, model, tip;
	while (running)
	{
		if (menu == 1)
		{
			cout << "1. Adauga\n" << "2. Actualizeaza\n" << "3. Sterge\n" << "4. Cauta\n" << "5. Ordoneaza\n" << "6. Filtreaza\n" << "7. Afiseaza\n" << "8. Randomize\n" << "9. Switch Menu to MasinaList\n" << "10. Raport\n" << "0. Exit\n";
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
				cout << "NrInmatriculare: ";
				getline(cin >> ws, nrInmatriculare);
				try
				{
					Masina m = srv.cauta_srv(nrInmatriculare);
					cout << "NrInmatriculare: " << m.getNrInmatriculare() << " | Producator: " << m.getProducator() << " | Model: " << m.getModel() << " | Tip: " << m.getTip() << endl;

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
			case 5:
				printf("Selectati tipul ordonarii:\n   1.Dupa numar de inmatriculare\n   2.Dupa tip\n   3.Dupa producator+model\n");
				printf(">>> ");
				cin >> cmd;
				if (cmd == 1)
					srv.sortnrInmatriculare();
				if (cmd == 2)
					srv.sortTip();
				if (cmd == 3)
					srv.sortProducatorModel();
				break;
			case 6:
				printf("Selectati tipul filtrarii:\n   1.Dupa producator\n   2.Dupa tip\n");
				printf(">>> ");
				cin >> cmd;
				if (cmd == 1)
				{
					cout << "Producator: ";
					getline(cin >> ws, producator);
					try
					{
						afiseaza_filtrat(srv.filtrareProducator(producator));
					}
					catch (ValidationException& ve)
					{
						cout << ve.getErrorMsg();
					}
				}
				if (cmd == 2)
				{
					cout << "Tip: ";
					getline(cin >> ws, tip);
					try
					{
						afiseaza_filtrat(srv.filtrareTip(tip));
					}
					catch (ValidationException& ve)
					{
						cout << ve.getErrorMsg();
					}
				}
				break;
			case 7:
				afiseaza();
				break;
			case 8:
				try
				{
					srv.adauga_srv("SB67ARN", "Toyota Motor Corporation", "Toyota Yariss", "automobil");
					srv.adauga_srv("CJ34BGF", "Honda Motor", "HR-V", "tractor");
					srv.adauga_srv("SB12LDS", "BMW Group", "i4 M50", "tir");
					srv.adauga_srv("CJ43FSD", "Toyota Motor Corporation", "Toyota Avalon", "camion");
					srv.adauga_srv("SB67ARA", "Honda Motor", "Civic Sedan", "automobil");
					srv.adauga_srv("CJ10EFD", "BMW Group", "X2", "camion");
					srv.adauga_srv("SB99ZCF", "Daimler", "GLE SUV", "tir");
					srv.adauga_srv("BV33UWU", "Honda Motor", "Civic Sedan", "automobil");
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
			case 9:
				menu = 2;
				break;
			case 10:
				afiseaza_raport(srv.raport_model_srv());
				break;
			case 0:
				running = 0;
				break;
			default:
				break;
			}
		}
		if (menu == 2)
		{
			cout << "1. Adauga\n" << "2. Sterge\n" << "3. Genereaza\n" << "4. Afiseaza\n"<<"5. Switch Menu to Masina\n" << "0. Exit\n";
			cout << ">>> ";
			cin >> cmd;	
			switch (cmd)
			{
			case 1:
				cout << "NrInmatriculare: ";
				getline(cin >> ws, nrInmatriculare);
				try
				{
					srv.lst_adauga_srv(nrInmatriculare);
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
				srv.lst_empty_srv();
				break;
			case 3:
				cin >> nrmas;
				try
				{
					srv.lst_generate_srv(nrmas);
				}
				catch (RepoException& re)
				{
					cout << re.getErrorMsg();
				}
				break;
			case 4:
				afiseaza_lst();
				break;
			case 5:
				menu = 1;
				break;
			case 0:
				running = 0;
				break;
			default:
				break;
			}
			cout << "Numar Masini in Lista : " << srv.getlstMasina_srv().size() << "\n";
		}	
	}
}