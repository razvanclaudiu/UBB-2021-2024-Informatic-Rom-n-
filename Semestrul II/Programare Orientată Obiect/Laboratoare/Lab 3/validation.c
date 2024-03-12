#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "validation.h"
#include "entities.h"
#pragma warning(disable:4996)

int validare_oferta(Oferte oferta)
{
	int sem[7] = {1,0,1,1,1,1,1};
	char err[100];
	strcpy(err, "");
	if (oferta.ID < 0)
		sem[0] = 0;
	if (strcmp(oferta.tip, "mare") == 0 || strcmp(oferta.tip, "munte") == 0 || strcmp(oferta.tip, "city break") == 0)
		sem[1] = 1;
	if (strcmp(oferta.destinatie, "")==0)
		sem[2] = 0;
	if (oferta.pret < 0)
		sem[3] = 0;
	if (oferta.zi < 1 || oferta.zi >31)
		sem[4] = 0;
	if (oferta.luna < 1 || oferta.luna >12)
		sem[5] = 0;
	if (oferta.an < 0)
		sem[6] = 0;
	for (int i = 0; i <= 6;i++)
	{
		if (sem[i] == 0)
		{
			if (i == 0)
				strcat(err, "Invalid ID!/");
			if (i == 1)
				strcat(err, "Invalid tip!/");
			if (i == 2)
				strcat(err, "Invalid destinatie!/");
			if (i == 3)
				strcat(err, "Invalid pret!/");
			if (i == 4)
				strcat(err, "Invalid zi!/");
			if (i == 5)
				strcat(err, "Invalid luna!/");
			if (i == 6)
				strcat(err, "Invalid an!/");
		}
	}
	if (strlen(err) > 0)
	{
		//printf("%s\n",&err);
		return 0;
	}
	return 1;
}

int validare_id(int ID)
{
	int sem = 1;
	char err[100];
	strcpy(err, "");
	if (ID < 0)
		sem = 0;
	if(sem == 0)
		strcat(err, "Invalid ID!/");
	if (sem == 0)
	{
		//printf("%s\n", &err);
		return 0;
	}
	return 1;
}