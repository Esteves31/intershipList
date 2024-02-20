#ifndef INTERSHIP_H
#define INTERSHIP_H

#include <stdbool.h>

typedef struct Intership intership;
typedef struct IntershipList intershipList;

struct Intership 
{
    char companyName[20];
    char occupationArea[30];
    char type;
    int index;
    bool isActive;
    intership *next;
};

struct IntershipList
{
    int sizeList;
    intership *firstIntership, *lastIntership;
};

void addIntership(intershipList *list, char cn[], char oa[], char t);
void removeIntership(intershipList *list, int index);
void listInterships(intershipList *list);
void listCurrentInterships(intershipList *list);
void deleteList(intershipList *list);
void searchIntershipByIndex(intershipList *list, int index);
void rebouceIntershipsIndexes(intershipList *list);

#endif
