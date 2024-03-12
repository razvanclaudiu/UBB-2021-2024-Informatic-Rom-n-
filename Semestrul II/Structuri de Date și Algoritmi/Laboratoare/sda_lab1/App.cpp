#define _CRTDBG_MAP_ALLOC
#include <iostream>
#include <crtdbg.h>

#include "TestExtins.h"
#include "TestScurt.h"

using namespace std;


int main() {
	testAllExtins();
	testAll();
	_CrtDumpMemoryLeaks();
}
