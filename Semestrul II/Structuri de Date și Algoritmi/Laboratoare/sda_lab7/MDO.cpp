#include "IteratorMDO.h"
#include "MDO.h"
#include <iostream>
#include <vector>

#include <exception>
using namespace std;


//O(1)
Nod::Nod(TElem e, PNod st, PNod dr, PNod par) 
{
	this->e = e;
	this->st = st;
	this->dr = dr;
	this->par = par;
}

//O(1)
TElem Nod::element() {
	return e;
}

//O(1)
PNod Nod::stanga() {
	return st;
}

//O(1)
PNod Nod::dreapta() {
	return dr;
}

//O(1)
PNod Nod::parinte() {
	return par;
}

//O(1)
MDO::MDO(Relatie r) {
	this->nr = 0;
	this->r = r;
	rad = nullptr;
}

//O(h)
void MDO::adauga(TCheie c, TValoare v) {
	rad = adauga_rec(rad,nullptr,TElem(c,v));
	this->nr++;
}

//O(h)
PNod MDO::adauga_rec(PNod p, PNod par, TElem e) {
	if (p == nullptr) {
		int nr = e.second.size();
		e.second.clear();
		e.second.push_back(nr);
		p = new Nod(e, nullptr, nullptr, par);
	}
	else {
		if (e.first == p->e.first)
		{
			if (p->e.second.at(0) == 0)
				p->e.second.clear();
			p->e.second.push_back(e.second.at(0));
		}
		else if (r(e.first,p->e.first)) //se adauga in stanga
			p->st = adauga_rec(p->st, p, e);
		else //se adauga in dreapta
			p->dr = adauga_rec(p->dr, p, e);
	}
	return p;
}

//O(h)
vector<TValoare> MDO::cauta(TCheie c) const {
	vector<TValoare> val;
	PNod p = rad;
	while (p != nullptr)
	{
		if (c == p->e.first)
		{
			return p->e.second;
		}
		if (r(c, p->e.first))
			p = p->st;
		else p = p->dr;
	}
	return val;
}

//O(h)
bool MDO::sterge(TCheie c, TValoare v) {
	int nr1, nr2;
	if (cauta(c).size() != 0)
	{
		nr1 = cauta(c).size();
		rad = sterge_rec(rad, c, v, false);
		nr2 = cauta(c).size();
		if (nr1 - nr2 == 1)
		{
			this->nr--;
			return true;
		}
	}
	return false;
}

//O(h)
PNod MDO::sterge_rec(PNod p, TCheie c, TValoare v, bool val) {
	PNod temp;
	if (p == nullptr)
		return p;
	else if (!r(p->e.first, c))
	{
		p->st = sterge_rec(p->st, c,v, false);
	}
	else if (!r(c,p->e.first))
	{
		p->dr = sterge_rec(p->dr, c, v, false);
	}
	else
	{
		if (val == true)
		{
			if (p->st == nullptr && p->dr == nullptr)
				return nullptr;
			else if (p->dr == nullptr)
			{
				temp = p->st;
				temp->par = p->par;
				delete p;
				return temp;
			}
			temp = p->dr;
			while (temp->st != nullptr)
				temp = temp->st;
			p->e = temp->e;
			//p->dr = sterge_rec(p->dr, temp->e.first, temp->e.second.at(0), true);
		}
		else
		{
			int sem = 0, i;
			if (p->e.second.at(p->e.second.size() - 1) == v)
				p->e.second.pop_back();
			else
			{
				for (i = 0;i < p->e.second.size() - 1;i++)
				{
					if (p->e.second.at(i) == v && sem == 0);
					{
						p->e.second.at(i) = p->e.second.at(i + 1);
						sem = 1;
					}
					if (sem == 1)
						p->e.second.at(i) = p->e.second.at(i + 1);
				}
				if (sem == 1)
				{
					p->e.second.pop_back();
				}
				else
				{
					if (p->st == nullptr && p->dr == nullptr)
						return nullptr;
					else if (p->st == nullptr)
					{
						temp = p->dr;
						temp->par = p->par;
						delete p;
						return temp;
					}
					else if (p->dr == nullptr)
					{
						temp = p->st;
						temp->par = p->par;
						delete p;
						return temp;
					}
					temp = p->dr;
					while (temp->st != nullptr)
						temp = temp->st;
					p->e = temp->e;
					p->dr = sterge_rec(p->dr, temp->e.first, temp->e.second.at(0), true);
				}
			}
		}
	}
	return p;	
}

//O(1)
int MDO::dim() const {
	return this->nr;
}

//O(1)
bool MDO::vid() const {
	if (nr == 0)
		return true;
	return false;
}

//O(1)
IteratorMDO MDO::iterator() const {
	return IteratorMDO(*this);
}

//O(h)
void MDO::distruge_rec(PNod p)
{
	if (p != nullptr)
	{
		distruge_rec(p->stanga());
		distruge_rec(p->dreapta());
		delete p;
	}
}

//O(h)
vector<TValoare> MDO::colectiaValorilor() const {
	vector<TValoare> val;
	PNod p = rad;
	if (p == nullptr)
		return val;
	else
	{
		while (p->stanga() != nullptr)
			p = p->stanga();
	}
	for(int i=0;i<p->e.second.size();i++)
		val.push_back(p->e.second.at(i));
	while (p != nullptr)
	{
		if (p->dreapta() != nullptr)
		{
			p = p->dreapta();
			while (p->stanga() != nullptr)
				p = p->stanga();
		}
		else
		{
			if (p->parinte() != nullptr)
				while (p->parinte()->dreapta() == p)
				{
					p = p->parinte();
					if (p->parinte() == nullptr)
						break;
				}
			p = p->parinte();
		}
		if (p != nullptr)
			for (int i = 0;i < p->e.second.size();i++)
				val.push_back(p->e.second.at(i));
	}
	return val;
}

//O(h)
MDO::~MDO() {
	distruge_rec(rad);
}
