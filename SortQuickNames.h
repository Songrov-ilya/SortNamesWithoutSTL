#ifndef SORTQUICKNAMES_H
#define SORTQUICKNAMES_H


class SortQuickNames
{
public:
    SortQuickNames();
    void sortNames(char ** arrAllNames, const int numberAllNames);

private:
    void sortQuickNames(char ** arrAllNames, int first, int last);
    int pivot(char ** arrAllNames, const int first, const int last);
    void swapNames(char *char1, char *char2);
};

#endif // SORTQUICKNAMES_H
