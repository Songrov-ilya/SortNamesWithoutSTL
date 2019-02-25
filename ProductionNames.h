#ifndef PRODUCTIONNAMES_H
#define PRODUCTIONNAMES_H


class ProductionNames
{
    char ** arrAllNamesP;
    int numberAllNamesP;
    const char * nameFileInputP;
    const char * nameFileOutputP;
public:
    ProductionNames(char **arrAllNames);

    void readFileNames();
    int sizeArray(const char *arr);
    void writeFileNames();
    void setNameFileInput(const char * nameFileInput);
    void setNameFileOutput(const char * nameFileOutput);
    void printAllNames();
    int getNumberAllNames();

private:
    void generateAdditionalNames(int &countReadNames, char ** arrAllNames);

};

#endif // PRODUCTIONNAMES_H
