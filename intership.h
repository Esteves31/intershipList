#ifndef INTERSHIP_H
#define INTERSHIP_H

#include <stdbool.h>

typedef struct Intership intership;
typedef struct IntershipList intershipList;

struct Intership 
{
    bool isActive;
    char companyName[20];
    char occupationArea[30];
    char type;
    int index;
    intership *next;
};

struct IntershipList
{
    int sizeList;
    intership *firstIntership, *lastIntership;
};

void addIntership(intershipList *list, char cn[], char oa[], char t);
void changeStatusOfIntership(intershipList *list, int index);
void deleteList(intershipList *list);
void listCurrentInterships(intershipList *list);
void listInterships(intershipList *list);
void rebouceIntershipsIndexes(intershipList *list);
void removeIntership(intershipList *list, int index);
void searchIntershipByIndex(intershipList *list, int index);

#endif
