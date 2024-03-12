#include "IteratorMDO.h"
#include "MDO.h"
#include <iostream>

//O(h)
IteratorMDO::IteratorMDO(const MDO& d) : dict(d){
	prim();
}

//O(h)
void IteratorMDO::prim(){
	PNod p = dict.rad;
	if (p == nullptr)
		current = p;
	else
	{
		while (p->stanga() != nullptr)
			p = p->stanga();
		current = p;
	}
}

//O(h)
void IteratorMDO::urmator(){
	if (current->dreapta() != nullptr)
	{
		current = current->dreapta();
		while (current->stanga() != nullptr)
			current = current->stanga();
	}
	else
	{
		if(current->parinte()!=nullptr)
			while (current->parinte()->dreapta() == current)
			{
				current = current->parinte();
				if (current->parinte() == nullptr)
					break;
			}
		current = current->parinte();
	}
}

//O(1)
bool IteratorMDO::valid() const {
	if (current != nullptr)
		return true;
	return false;
}

//O(1)
TElem IteratorMDO::element() const{
	return current->element();
}


