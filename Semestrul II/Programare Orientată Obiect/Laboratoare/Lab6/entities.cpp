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

void Masina::setNrInmatriculare(string nrInmatriculare)
{
	this->nrInmatriculare = nrInmatriculare;
}

void Masina::setProducator(string producator)
{
	this->producator = producator;
}

void Masina::setModel(string model)
{
	this->model = model;
}

void Masina::setTip(string tip)
{
	this->tip = tip;
}