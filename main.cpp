#include <iostream>
#include "ProductionNames.h"
#include "SortQuickNames.h"
//#include <gtest/gtest.h>




int main(/*int argc, char *argv[]*/)
{

    char ** arrAllNames = new char * [5001];
    arrAllNames [5000] = nullptr;

    ProductionNames productionNames {arrAllNames};
    const char nameFileInput[] { "namesRusInput=UTF-8.txt" };
    productionNames.setNameFileInput(nameFileInput);
    productionNames.setNameFileOutput("namesRusOutput=UTF-8.txt");
    productionNames.readFileNames();
    productionNames.printAllNames();

    SortQuickNames sortClass;
    sortClass.sortNames(arrAllNames, productionNames.getNumberAllNames());

    productionNames.printAllNames();

    productionNames.writeFileNames();


    for (int var = 0; var < productionNames.getNumberAllNames(); ++var){
        delete [] arrAllNames[var];
    }
    delete [] arrAllNames;

    return 0;
}

