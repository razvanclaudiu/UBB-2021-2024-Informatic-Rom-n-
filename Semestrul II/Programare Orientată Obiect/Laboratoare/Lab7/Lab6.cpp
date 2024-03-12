#include "ui.h"
#include "tests.h"
#include <iostream>
#include <stdlib.h>
#include <crtdbg.h>


int main()
{
    {
        MasinaRepository repo;
        MasinaValidation val;
        MasinaStore srv{ repo,val };
        ConsoleUI ui{ srv };

        Teste test;

        test.run_teste();

        ui.run();
    }
    _CrtDumpMemoryLeaks();
}

