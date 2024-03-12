#include "ui.h"
#include "tests.h"
#include <iostream>

int main()
{
    MasinaRepository repo;
    MasinaValidation val;
    MasinaStore srv{ repo,val };
    ConsoleUI ui{ srv };

    Teste test;

    test.run_teste();

    ui.run();
}
