#include "intership.h"

#include <stdio.h>
#include <stdlib.h>

void addIntership(intershipList *list, char cn[], char oa[], char t)
{
    intership *newIntership = (intership*) malloc(sizeof(intership));

    for (size_t i = 0; i < 20; i++) {
        newIntership->companyName[i] = cn[i];
    }

    for (size_t i = 0; i < 30; i++) {
        newIntership->occupationArea[i] = oa[i];
    }    
    
    newIntership->type = t;
    newIntership->isActive = true;
    newIntership->next = NULL;
    list->sizeList++;
    newIntership->index = list->sizeList;

    if (list->firstIntership == NULL) {
        list->firstIntership = newIntership;
        list->lastIntership = newIntership;
    }
    else {
        list->lastIntership->next = newIntership;
        list->lastIntership = newIntership;
    }
}

void changeStatusOfIntership(intershipList *list, int index)
{
    int i = 1;
    intership *current = list->firstIntership;


    while (i <= list->sizeList) {
        if (i == index) {
            current->isActive = false;
            return;
        }
        current = current->next;
        i++;
    }
}

void deleteList(intershipList *list)
{
    if (list == NULL) return;

    intership *current = list->firstIntership;
    intership *next;

    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }

    list->firstIntership = NULL;
    list->lastIntership = NULL;
    list->sizeList = 0;
}

void listCurrentInterships(intershipList *list)
{
    if (list->firstIntership == NULL) {
        printf("You don't have any interships registered!");
        return;
    }

    intership *aux = list->firstIntership;
    int qtd = 0;
    int index = 1;

    printf("\n------------- List of current interships -------------\n");
    do {
        if (aux->isActive == 1) {
            printf("index: %d", aux->index);
            printf("\n");
            printf("Company name: %s", aux->companyName);
            printf("\n");
            printf("Occupation area: %s", aux->occupationArea);
            printf("\n");
            printf("Type of work: %c", aux->type);
            printf("\n");
            printf("Is active: %d", aux->isActive);
            printf("\n");
            printf("----------------------------------------------------\n");
            qtd++;
        }
        aux = aux->next;
        index++;
    } while (index <= list->sizeList);

    if (qtd == 0) 
        printf("\nThere arent actives interships right now!");
}

void listInterships(intershipList *list)
{
    if (list->sizeList == 0){ 
        printf("Empty list!");
        return;
    }

    intership *aux = list->firstIntership;
    int index = 1;

    printf("\n---------------- List of interships ----------------\n");
    do {
        printf("index: %d", aux->index);
        printf("\n");
        printf("Company name: %s", aux->companyName);
        printf("\n");
        printf("Occupation area: %s", aux->occupationArea);
        printf("\n");
        printf("Type of work: %c", aux->type);
        printf("\n");
        printf("Is active: %d", aux->isActive);
        printf("\n");
        printf("----------------------------------------------------\n");
        aux = aux->next;
        index++;
    } while (index <= list->sizeList); 
}

void rebouceIntershipsIndexes(intershipList *list) 
{
    if (list->sizeList == 0) return;

    int index = 1;
    intership *aux = list->firstIntership;

    while (aux != NULL) {
        aux->index = index;
        aux = aux->next;
        index++;
    }

}

void removeIntership(intershipList *list, int index)
{
    if (index > list->sizeList || index < 1 || list->sizeList == 0) {
        printf("Index not exists! Please look at the list before try remove it");
        return;
    }

    intership *aux = list->firstIntership;
    intership *nodeToRemove = NULL;

    if (index == list->firstIntership->index) {
        nodeToRemove = list->firstIntership;
        list->firstIntership = nodeToRemove->next;
        if (list->firstIntership == NULL)
            list->lastIntership = NULL;
    }
    else {
        while (aux != NULL && aux->next != NULL && aux->next->index != index) {
            aux = aux->next;
        }
        if (aux != NULL && aux->next != NULL) {
            nodeToRemove = aux->next;
            aux->next = nodeToRemove->next;
            if (aux->next == NULL)
                list->lastIntership = aux;
        }
    }
    if (nodeToRemove) {
        free(nodeToRemove);
        list->sizeList--;
    }

    rebouceIntershipsIndexes(list);

    printf("Intership removed!");
}

void searchIntershipByIndex(intershipList *list, int index)
{
    intership *aux = list->firstIntership;
    bool hasIndex = false;
    int i = 1;

    while (i <= list->sizeList) {
        if (i == index) {
            printf("\n----------------- Intership index %d -----------------\n", index);
            printf("Company name: %s", aux->companyName);
            printf("\n");
            printf("Occupation area: %s", aux->occupationArea);
            printf("\n");
            printf("Type of work: %c", aux->type);
            printf("\n");
            printf("Is active: %d", aux->isActive);
            printf("\n");
            printf("----------------------------------------------------\n");
            hasIndex = true;
        }
        aux = aux->next;
        i++;
    }

    if (!hasIndex)
        printf("Sorry, index not found!");
}
