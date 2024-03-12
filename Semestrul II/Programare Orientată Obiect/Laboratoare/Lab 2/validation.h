#pragma once

#include "entities.h"

#ifndef VALIDATION_H_
#define VALIDATION_H_

//Functia de validare a unei oferte.
//Parametrii: oferta - OFerte, entitate
//Postconditii: Se va returna 0 daca datele nu sunt valide, 1 in caz contrar.
int validare_oferta(Oferte oferta);


//Functia de validare a unui ID.
//Parametrii: ID - int, id-ul ofertei
//Postconditii: Se va returna 0 daca datele nu sunt valide, 1 in caz contrar.
int validare_id(int ID);
#endif
