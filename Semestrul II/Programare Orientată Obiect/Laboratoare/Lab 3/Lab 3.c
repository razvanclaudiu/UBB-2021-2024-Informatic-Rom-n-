#define _CRTDBG_MAP_ALLOC
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <crtdbg.h>
#include "ui.h"
#include "service.h"
#include "repository.h"
#include "entities.h"
#include "tests.h"
#pragma warning(disable:4996)

void afiseaza(OfferList lst)
{
	for (int i = 0; i < lst.nrElem; i++)
		afis(lst.list[i]);
}

void filtrare_destinatie(OfferList lst, char destinatie[])
{
	for (int i = 0; i < lst.nrElem; i++)
		if (strcmp(lst.list[i].destinatie,destinatie)==0)
			afis(lst.list[i]);
}

void filtrare_tip(OfferList lst, char tip[])
{
	for (int i = 0; i < lst.nrElem; i++)
		if (strcmp(lst.list[i].tip, tip) == 0)
			afis(lst.list[i]);
}

void filtrare_pret(OfferList lst, int pret)
{
	for (int i = 0; i < lst.nrElem; i++)
		if (lst.list[i].pret == pret)
			afis(lst.list[i]);
}

int run()
{
	int cmd, nr;
	OfferList lst = createEmpty();
	char tip[30], destinatie[30];
	int ID, zi, luna, an, pret, c;
	while (1)
	{
		printf("Selectati o optiune:\n   1.Adaugare\n   2.Actualizare\n   3.Stergere\n   4.Afiseaza\n   5.Randomize\n   6.Ordonare\n   7.Filtrare\n   0.Exit.\n");
		printf(">>> ");
		nr = scanf("%d", &cmd);
		while ((c = getchar()) != '\n' && c != EOF) {}
		if (cmd == 1)
		{
			printf("ID: ");
			nr = scanf("%d", &ID);
			while ((c = getchar()) != '\n' && c != EOF) {}
			printf("Tip: ");
			fgets(tip, 30, stdin);
			tip[strlen(tip) - 1] = '\0';
			printf("Destinatie: ");
			fgets(destinatie, 30, stdin);
			destinatie[strlen(destinatie) - 1] = '\0';
			printf("Pret: ");
			nr = scanf("%d", &pret);
			while ((c = getchar()) != '\n' && c != EOF) {}
			printf("Zi: ");
			nr = scanf("%d", &zi);
			while ((c = getchar()) != '\n' && c != EOF) {}
			printf("Luna: ");
			nr = scanf("%d", &luna);
			while ((c = getchar()) != '\n' && c != EOF) {}
			printf("Anul: ");
			nr = scanf("%d", &an);
			while ((c = getchar()) != '\n' && c != EOF) {}
			int sem = adaugaOferta_srv(&lst, ID, tip, destinatie, pret, zi, luna, an);
			if (sem == 0)
				printf("Datele sunt incorecte!\n");
			else if (sem == 1)
				printf("ID Existent!\n");

		}
		if (cmd == 2)
		{
			printf("ID: ");
			nr = scanf("%d", &ID);
			while ((c = getchar()) != '\n' && c != EOF) {}
			printf("Tip: ");
			fgets(tip, 30, stdin);
			tip[strlen(tip) - 1] = '\0';
			printf("Destinatie: ");
			fgets(destinatie, 30, stdin);
			destinatie[strlen(destinatie) - 1] = '\0';
			printf("Pret: ");
			nr = scanf("%d", &pret);
			while ((c = getchar()) != '\n' && c != EOF) {}
			printf("Zi: ");
			nr = scanf("%d", &zi);
			while ((c = getchar()) != '\n' && c != EOF) {}
			printf("Luna: ");
			nr = scanf("%d", &luna);
			while ((c = getchar()) != '\n' && c != EOF) {}
			printf("Anul: ");
			nr = scanf("%d", &an);
			while ((c = getchar()) != '\n' && c != EOF) {}
			int sem = actualizeazaOferta_srv(&lst, ID, tip, destinatie, pret, zi, luna, an);
			if (sem == 0)
				printf("Datele sunt incorecte!\n");
			else if (sem == 1)
				printf("ID Existent!\n");
		}
		if (cmd == 3)
		{
			printf("ID: ");
			nr = scanf("%d", &ID);
			while ((c = getchar()) != '\n' && c != EOF) {}
			int sem = stergeOferta_srv(&lst, ID);
			if (sem == 0)
			{
				printf("Datele sunt incorecte!\n");
			}
			else if (sem == 1)
			{
				printf("ID Inexistent!\n");
			}
			else if (sem == 2)
			{
				printf("Oferta a fost stearsa!\n");
			}

		}
		if (cmd == 4)
			afiseaza(lst);
		if (cmd == 5)
		{
			ID = 2;
			strcpy(tip, "mare");
			strcpy(destinatie, "Constanta");
			pret = 300;
			zi = 19;
			luna = 8;
			an = 2022;
			adaugaOferta_srv(&lst, ID, tip, destinatie, pret, zi, luna, an);
			ID = 3;
			strcpy(tip, "city break");
			strcpy(destinatie, "Bucuresti");
			pret = 400;
			zi = 23;
			luna = 12;
			an = 2022;
			adaugaOferta_srv(&lst, ID, tip, destinatie, pret, zi, luna, an);
			ID = 1;
			strcpy(tip, "munte");
			strcpy(destinatie, "Brasov");
			pret = 200;
			zi = 5;
			luna = 5;
			an = 2022;
			adaugaOferta_srv(&lst, ID, tip, destinatie, pret, zi, luna, an);
		}
		if (cmd == 6)
		{
			printf("Selectati tipul ordonarii:\n   1.Dupa pret, crescator\n   2.Dupa pret, descrescator\n   3.Dupa destinatie, crescator\n   4.Dupa destinatie, descrescator\n");
			printf(">>> ");
			nr = scanf("%d", &cmd);
			while ((c = getchar()) != '\n' && c != EOF) {}
			if (cmd == 1)
				ordonareOferta_srv(&lst, &sortprice, 0);
			if (cmd == 2)
				ordonareOferta_srv(&lst, &sortprice, 1);
			if (cmd == 3)
				ordonareOferta_srv(&lst, &sortdestination, 0);
			if(cmd == 4)
				ordonareOferta_srv(&lst, &sortdestination, 1);
			cmd = -1;
		}
		if (cmd == 7)
		{
			printf("Selectati tipul ordonarii:\n   1.Dupa destinatie\n   2.Dupa tip\n   3.Dupa pret\n");
			printf(">>> ");
			nr = scanf("%d", &cmd);
			while ((c = getchar()) != '\n' && c != EOF) {}
			if (cmd == 1)
			{
				printf("Destinatie: ");
				fgets(destinatie, 30, stdin);
				destinatie[strlen(destinatie) - 1] = '\0';
				filtrare_destinatie(lst, destinatie);
			}
			if (cmd == 2)
			{
				printf("Tip: ");
				fgets(tip, 30, stdin);
				tip[strlen(tip) - 1] = '\0';
				filtrare_tip(lst, tip);
			}
			if (cmd == 3)
			{
				printf("Pret: ");
				nr = scanf("%d", &pret);
				while ((c = getchar()) != '\n' && c != EOF) {}
				filtrare_pret(lst, pret);
			}
			cmd = -1;
		}
		if (cmd == 0)
		{
			destroyList(&lst);
			return 0;
		}
	}
}

int main()
{
	run_tests();
	system("cls");
	run();
	_CrtDumpMemoryLeaks();
}