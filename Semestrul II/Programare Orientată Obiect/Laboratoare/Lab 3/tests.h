#pragma once

#include "entities.h"
#include "repository.h"
#include "validation.h"
#include "service.h"

#ifndef TESTS_H_
#define TESTS_H_

void test_afis();
void test_creeazaOferta_repo();
void test_adaugaOferta_repo();
void test_validare_oferta();
void test_adaugaOferta_srv();
void test_actualizeazaOferta_repo();
void test_actualizeazaOferta_srv();
void test_validare_id();
void test_stergeOferta_repo();
void test_stergeOferta_srv();
void test_ordonareOferta_repo();
void test_ordonareOferta_srv();
void run_tests();
#endif