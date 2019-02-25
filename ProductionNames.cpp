#include "ProductionNames.h"
#include <iostream>
#include <fstream>
#include <random>

ProductionNames::ProductionNames(char **arrAllNames) :
    arrAllNamesP {arrAllNames},
    numberAllNamesP {0},
    nameFileInputP {nullptr},
    nameFileOutputP {nullptr}
{

}

void ProductionNames::readFileNames()
{

    int countNames = 0;

    std::ifstream readIfSream;
    readIfSream.open(&nameFileInputP[0]);
    if(readIfSream.is_open()){
        std::cout << "is open" << std::endl;

        int countLetters = 0;
        char temporaryName [100] {'\0'};
        while (readIfSream >> temporaryName)
        {
            countLetters = sizeArray(temporaryName);
            char * anyName = new char[countLetters+1];
            anyName[countLetters] = '\0';
            for (int var = 0; var < countLetters; ++var) {
                anyName[var] = temporaryName[var];
            }
            arrAllNamesP[countNames] = anyName;

            countNames++;
            countLetters = 0;
        }

//        cout << "countNames = " << countNames << endl;
        generateAdditionalNames(countNames, arrAllNamesP);

    }
    else{
        std::cout << "The file did not open" << std::endl;
        return;
    }

    readIfSream.close();
    numberAllNamesP = countNames;
}

int ProductionNames::sizeArray(const char *arr)
{
    int var = 0;
    for (;;)
    {
        if(arr[var] == '\0'){
            return var;
        }
        ++var;
    }
}

void ProductionNames::writeFileNames()
{
    std::ofstream ofstreamFile(nameFileOutputP);
    for (int var = 0; var < numberAllNamesP; ++var) {
        ofstreamFile << arrAllNamesP[var] << std::endl;
    }
    ofstreamFile.close();
}

void ProductionNames::setNameFileInput(const char *nameFileInput)
{
    nameFileInputP = nameFileInput;
}

void ProductionNames::setNameFileOutput(const char *nameFileOutput)
{
    nameFileOutputP = nameFileOutput;
}

void ProductionNames::printAllNames()
{
    for (int var = 0; var < numberAllNamesP; ++var){
        std::cout << arrAllNamesP[var] << std::endl;
    }
}

int ProductionNames::getNumberAllNames()
{
    return numberAllNamesP;
}

void ProductionNames::generateAdditionalNames(int &countReadNames, char **arrAllNames)
{
    if(countReadNames <= 0){
        countReadNames = 0;
        return;
    }
    const int countUniqueNames = countReadNames;
    for (int var = countUniqueNames; var < 5001; ++var)
    {
        int firstName = rand() % (countUniqueNames);
        int secondName = rand() % (countUniqueNames);
        int countLettersFirst = sizeArray(arrAllNames[firstName]);
        int countLettersSecond = sizeArray(arrAllNames[secondName]);
        int countLettersSuperName = countLettersFirst + countLettersSecond;
        char *arrSuperName = new char[countLettersSuperName+1];
        arrSuperName[countLettersSuperName] = '\0';
        for (int var = 0; var < countLettersFirst; ++var) {
            arrSuperName[var] = arrAllNames[firstName][var];
        }
        arrAllNames[countReadNames] = arrSuperName;
        for (int var = 0; var < countLettersSecond; ++var) {
            arrAllNames[countReadNames][var + countLettersFirst] = arrAllNames[secondName][var];
        }
//        cout << arrAllNames[countReadNames] << "::" << endl;
        countReadNames++;
    }
    --countReadNames;
}

