#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "entities.h"
#pragma warning(disable:4996)

void afis(Oferte oferta)
{
	printf("ID: %d, Tip: %s, Destinatie: %s, Pret: %d, Data: %d.%d.%d\n", oferta.ID, oferta.tip, oferta.destinatie, oferta.pret, oferta.zi, oferta.luna, oferta.an);
}

