#define _CRTDBG_MAP_ALLOC
#pragma comment(lib, "winmm.lib")
#include <iostream>
#include <crtdbg.h>
#include <chrono>
#include <windows.h>
#include "TestExtins.h"
#include "TestScurt.h"


using namespace std;


int main() {

	auto start = chrono::steady_clock::now();
	testAll();
	testAllExtins();
	_CrtDumpMemoryLeaks;
	cout<<"End"<<endl;
	auto end = chrono::steady_clock::now();
	auto diff = (end - start) / 1000;
	cout << chrono::duration <double, milli>(diff).count() << " seconds" << endl;
	PlaySound(TEXT("Microwave.wav"), NULL, SND_FILENAME | SND_ASYNC);
	cin.get();
}
