#include "IteratorDictionar.h"
#include "Dictionar.h"
#include <iostream>
using namespace std;

using namespace std;

//O(1)
IteratorDictionar::IteratorDictionar(const Dictionar& d) : dict(d){
	curent = d.prim;
}

//O(1)
void IteratorDictionar::prim() {
	curent = dict.prim;
}

//O(1)
void IteratorDictionar::urmator() {
	curent = dict.urm[curent];
}

//O(1)
TElem IteratorDictionar::element() const{
	return dict.elems[curent];
}

//O(1)
bool IteratorDictionar::valid() const {
	return curent != -1;
}

