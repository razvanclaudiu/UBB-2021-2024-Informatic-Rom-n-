#include "IteratorColectie.h"
#include "Colectie.h"

//O(1)
IteratorColectie::IteratorColectie(const Colectie& c): col(c) {
	curent = 0;
}

//O(1)
TElem IteratorColectie::element() const{
	return col.e[curent];
}

//O(1)
bool IteratorColectie::valid() const {
	return curent < col.dim();
}

//O(1)
void IteratorColectie::urmator() {
	curent++;
	valid();
}

//O(1)
void IteratorColectie::prim() {
	curent = 0;
}
