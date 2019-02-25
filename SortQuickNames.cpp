#include "SortQuickNames.h"
#include <iostream>
#include <string.h>

SortQuickNames::SortQuickNames()
{

}

void SortQuickNames::sortNames(char **arrAllNames, const int numberAllNames)
{
    sortQuickNames(arrAllNames, 0, numberAllNames);
}

void SortQuickNames::sortQuickNames(char **arrAllNames, int first, int last)
{
    int pivotElement = 0;
    if(arrAllNames != nullptr){
        if(first < last){/* finish at the end */
            pivotElement = pivot(arrAllNames, first, last);
            sortQuickNames(arrAllNames, first, pivotElement-1);
            sortQuickNames(arrAllNames, pivotElement+1, last);
        }
    }
}

int SortQuickNames::pivot(char **arrAllNames, const int first, const int last)
{
    int  p = first;
    char *pivotElement = arrAllNames[first];


    for(int i = first+1 ; i <= last ; i++)
    {
        if(strcmp(arrAllNames[i], pivotElement) <= 0)
        {
            p++;
//            swapNames(arrAllNames[i], arrAllNames[p]);
            std::swap(arrAllNames[i], arrAllNames[p]);
        }
    }

//    swapNames(arrAllNames[p], arrAllNames[first]);
    std::swap(arrAllNames[p], arrAllNames[first]);

    return p;
}

void SortQuickNames::swapNames(char *char1, char *char2)
{
    char *temp = char1;
    char1 = char2;
    char2 = temp;
}
