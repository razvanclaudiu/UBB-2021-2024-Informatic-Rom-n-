#include "IteratorMultime.h"
#include "Multime.h"

//O(n)
IteratorMultime::IteratorMultime(const Multime& m) : multime(m){
	curent = 0;
	deplasare();
}

//O(n)
void IteratorMultime::deplasare()
{
	while ((curent < multime.m) && multime.e[curent] == NULL_TVALOARE)
		curent++;
}

//O(n)
void IteratorMultime::prim() {
	curent = 0;
	deplasare();
}

//O(n)
void IteratorMultime::urmator() {
	curent++;
	deplasare();
}

//O(1)
TElem IteratorMultime::element() const {
	return multime.e[curent];
}

//O(1)
TElem IteratorMultime::urm() const {
	return multime.urm[curent];
}

//O(1)
bool IteratorMultime::valid() const {
	return (curent < multime.m);
}
