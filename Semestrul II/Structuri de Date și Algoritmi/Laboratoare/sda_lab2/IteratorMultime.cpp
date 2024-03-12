#include "IteratorMultime.h"
#include "Multime.h"

//O(1)
IteratorMultime::IteratorMultime(const Multime& m): mult(m) {
	curent = mult.prim;
}

//O(1)
TElem IteratorMultime::element() const {
	return curent->element();
}

//O(1)
bool IteratorMultime::valid() const {
	return curent != nullptr;
}

//O(1)
void IteratorMultime::urmator() {
	curent = curent->urmator();
}

//O(1)
void IteratorMultime::prim() {
	curent = mult.prim;
}

