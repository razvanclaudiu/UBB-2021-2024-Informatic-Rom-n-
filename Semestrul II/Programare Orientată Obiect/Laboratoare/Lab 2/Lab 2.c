#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ui.h"
#include "service.h"
#include "repository.h"
#include "entities.h"
#include "tests.h"
#pragma warning(disable:4996)

//Functia de afisare a tuturor ofertelor.
void afiseaza(OfferList lst)
{
	for (int i = 0; i < lst.nrElem; i++)
		afis(lst.list[i]);
}

//Functia de run folosita pentru accesarea functionalitatilor programului.
int run()
{
	int cmd;
	OfferList lst;
	lst.nrElem = 0;
	char tip[30], destinatie[30];
	int ID, zi, luna, an, pret, c;
	while (1)
	{
		printf("Selectati o optiune:\n   1.Adaugare\n   2.Actualizare\n   3.Stergere\n   4.Afiseaza\n   0.Exit.\n");
		printf(">>> ");
		scanf("%d", &cmd);
		while ((c = getchar()) != '\n' && c != EOF) {}
		if (cmd == 1)
		{
			printf("ID: ");
			scanf("%d", &ID);
			while ((c = getchar()) != '\n' && c != EOF) {}
			printf("Tip: ");
			fgets(tip, 30, stdin);
			tip[strlen(tip) - 1] = '\0';
			//while ((c = getchar()) != '\n' && c != EOF) {}
			printf("Destinatie: ");
			fgets(destinatie, 30, stdin);
			destinatie[strlen(destinatie) - 1] = '\0';
			//while ((c = getchar()) != '\n' && c != EOF) {}
			printf("Pret: ");
			scanf("%d", &pret);
			while ((c = getchar()) != '\n' && c != EOF) {}
			printf("Zi: ");
			scanf("%d", &zi);
			while ((c = getchar()) != '\n' && c != EOF) {}
			printf("Luna: ");
			scanf("%d", &luna);
			while ((c = getchar()) != '\n' && c != EOF) {}
			printf("Anul: ");
			scanf("%d", &an);
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
			scanf("%d", &ID);
			while ((c = getchar()) != '\n' && c != EOF) {}
			printf("Tip: ");
			fgets(tip, 30, stdin);
			tip[strlen(tip) - 1] = '\0';
			//while ((c = getchar()) != '\n' && c != EOF) {}
			printf("Destinatie: ");
			fgets(destinatie, 30, stdin);
			destinatie[strlen(destinatie) - 1] = '\0';
			//while ((c = getchar()) != '\n' && c != EOF) {}
			printf("Pret: ");
			scanf("%d", &pret);
			while ((c = getchar()) != '\n' && c != EOF) {}
			printf("Zi: ");
			scanf("%d", &zi);
			while ((c = getchar()) != '\n' && c != EOF) {}
			printf("Luna: ");
			scanf("%d", &luna);
			while ((c = getchar()) != '\n' && c != EOF) {}
			printf("Anul: ");
			scanf("%d", &an);
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
			scanf("%d", &ID);
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
		if (cmd == 0)
			return 0;
	}
}

int main()
{
	run_tests();
	system("cls");
	run();
}