#include "entities.h"

string Masina::getNrInmatriculare() const
{
	return this->nrInmatriculare;
}

string Masina::getProducator() const
{
	return this->producator;
}

string Masina::getModel() const
{
	return this->model;
}

string Masina::getTip() const
{
	return this->tip;
}

void Masina::setNrInmatriculare(string nrInm)
{
	this->nrInmatriculare = nrInm;
}

void Masina::setProducator(string prod)
{
	this->producator = prod;
}

void Masina::setModel(string modl)
{
	this->model = modl;
}

void Masina::setTip(string type)
{
	this->tip = type;
}

bool cmpnrInmatriculare(const Masina& m1, const Masina& m2)
{
	return m1.getNrInmatriculare() < m2.getNrInmatriculare();
}
bool cmpTip(const Masina& m1, const Masina& m2)
{
	return m1.getTip() < m2.getTip();
}

bool cmpProducatorModel(const Masina& m1, const Masina& m2) {
	if (m1.getProducator() == m2.getProducator())
		return m1.getModel() < m2.getModel();
	else
		return m1.getProducator() < m2.getProducator();
}