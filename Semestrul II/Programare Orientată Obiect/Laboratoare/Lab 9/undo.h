#pragma once
#include "entities.h"
#include "repository.h"

class ActiuneUndo
{
public:
	virtual void doUndo() = 0;

	virtual ~ActiuneUndo(){};
};

class UndoAdauga : public ActiuneUndo
{
	Masina car;
	MasinaRepository& repo;
public:
	UndoAdauga(MasinaRepository& repo, const Masina& m): repo { repo }, car { m } {}

	//Functia de undo pentru adaugare
	//Post: se va da undo la ultima operatie
	void doUndo() override
	{
		repo.sterge_repo(car.getNrInmatriculare());
	}
};

class UndoActualizeaza : public ActiuneUndo
{
	Masina car;
	MasinaRepository& repo;
public:
	UndoActualizeaza(MasinaRepository& repo, const Masina& m) : repo{ repo }, car{ m } {}

	//Functia de undo pentru actualizare
	//Post: se va da undo la ultima operatie
	void doUndo() override
	{
		repo.actualizeaza_repo(car);
	}
};

class UndoSterge : public ActiuneUndo
{
	Masina car;
	MasinaRepository& repo;
public:
	UndoSterge(MasinaRepository& repo, const Masina& m) : repo{ repo }, car{ m } {}

	//Functia de undo pentru stergere
	//Post: se va da undo la ultima operatie
	void doUndo() override
	{
		repo.adauga_repo(car);
	}
};