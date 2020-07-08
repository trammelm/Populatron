
#include <stdio.h>
#include <iostream>
#include "processPop.h"

using namespace std;

int mymain(int argc, const char* argv[]) 
{
    if (argc < 2)
    {
        cout << "usage: must include file to parse" << endl;
    }
    else
    {
        Populatron poppy = {};
        CSVTron csvtron = {};
        string cityFile = argv[1];
        csvtron.load(cityFile);
        poppy.processPopulationFile(csvtron);
    }
    return 0;
}
