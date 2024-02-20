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

void addIntership(intership *new, char cn[], char oa[], char t, int i);
void removeIntership();
void listInterships();

#endif
