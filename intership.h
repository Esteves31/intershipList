#ifndef INTERSHIP_H
#define INTERSHIP_H

#include <stdbool.h>

typedef struct Intership intership;

struct Intership {
    char companyName[20];
    char occupationArea[30];
    char type;
    int index;
    bool isActive;
};

void addIntership();
void removeIntership();
void listInterships();

#endif
