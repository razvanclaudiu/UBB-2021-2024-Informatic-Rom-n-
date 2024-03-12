#include "IteratorMultime.h"
#include "Multime.h"


IteratorMultime::IteratorMultime(const Multime& m) : multime(m){
	curent = 0;
	deplasare();
}

void IteratorMultime::deplasare()
{
	while ((curent < multime.m) && multime.e[curent] == NULL_TVALOARE)
		curent++;
}


void IteratorMultime::prim() {
	curent = 0;
	deplasare();
}


void IteratorMultime::urmator() {
	curent++;
	deplasare();
}


TElem IteratorMultime::element() const {
	return multime.e[curent];
}

/*TElem IteratorMultime::urm() const {
	return multime.urm[curent];
}*/

bool IteratorMultime::valid() const {
	return (curent < multime.m);
}
