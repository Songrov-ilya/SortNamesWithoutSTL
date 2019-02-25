#include <iostream>
#include <fstream>
#include <string.h>
#include <gtest/gtest.h>


using namespace std;

int readFileNames(const char * nameFileInput, char ** arrAllNames);
void generateAdditionalNames(int &countReadNames, char ** arrAllNames);
int sizeArray(const char *arr);

void sortQuickNames(char ** arrAllNames, int first, int last);
int pivot(char ** arrAllNames, const int first, const int last);
void swapNames(char *char1, char *char2);

void writeFileNames(const char *nameFileOutput, int &numberAllNames, char ** arrAllNames);


int main(/*int argc, char *argv[]*/)
{

    char ** arrAllNames = new char * [5001];
    arrAllNames [5000] = nullptr;
    const char nameFileInput[] { "namesRusInput=UTF-8.txt" };
    int numberAllNames = readFileNames(nameFileInput, arrAllNames);

    for (int var = 0; var < numberAllNames; ++var){
        cout << arrAllNames[var] << endl;
    }

    sortQuickNames(arrAllNames, 0, numberAllNames);

    for (int var = 0; var < numberAllNames; ++var){
        cout << arrAllNames[var] << endl;
    }

    const char nameFileOutput[] { "namesRusOutput=UTF-8.txt" };
    writeFileNames(nameFileOutput, numberAllNames, arrAllNames);


    for (int var = 0; var < numberAllNames; ++var){
        delete [] arrAllNames[var];
    }
    delete [] arrAllNames;

    cout << endl << "Hello World! - End! " << endl;
    return 0;
}


int readFileNames(const char *nameFileInput, char **arrAllNames){

    int countNames = 0;

    ifstream readIfSream;
    readIfSream.open(&nameFileInput[0]);
    if(readIfSream.is_open()){
        cout << "is open" << endl;

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
            arrAllNames[countNames] = anyName;

            countNames++;
            countLetters = 0;
        }

//        cout << "countNames = " << countNames << endl;
        generateAdditionalNames(countNames, arrAllNames);

    }
    else{
        cout << "The file did not open" << endl;
        return 0;
    }

    readIfSream.close();
    return countNames;

}

void generateAdditionalNames(int &countReadNames, char ** arrAllNames){

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

int sizeArray(const char* arr){
    int var = 0;
    for (;;)
    {
        if(arr[var] == '\0'){
            return var;
        }
        ++var;
    }
}

void sortQuickNames(char ** arrAllNames, int first, int last){

    int pivotElement = 0;
    if(arrAllNames != nullptr){
        if(first < last){/* finish at the end */
            pivotElement = pivot(arrAllNames, first, last);
            sortQuickNames(arrAllNames, first, pivotElement-1);
            sortQuickNames(arrAllNames, pivotElement+1, last);
        }
    }
}

int pivot(char **arrAllNames, const int first, const int last){

    int  p = first;
    char *pivotElement = arrAllNames[first];


    for(int i = first+1 ; i <= last ; i++)
    {
        if(strcmp(arrAllNames[i], pivotElement) <= 0)
        {
            p++;
//            swapNames(arrAllNames[i], arrAllNames[p]);
            swap(arrAllNames[i], arrAllNames[p]);
        }
    }

//    swapNames(arrAllNames[p], arrAllNames[first]);
    swap(arrAllNames[p], arrAllNames[first]);

    return p;
}

void swapNames(char *char1, char *char2)
{
    char *temp = char1;
    char1 = char2;
    char2 = temp;
}


void writeFileNames(const char *nameFileOutput, int &numberAllNames, char ** arrAllNames)
{
    ofstream ofstreamFile(nameFileOutput);
    for (int var = 0; var < numberAllNames; ++var) {
        ofstreamFile << arrAllNames[var] << endl;
    }
    ofstreamFile.close();
}
