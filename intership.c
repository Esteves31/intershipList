#include "intership.h"

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    char cn[20], oa[30], t;
    int option;
    intershipList *newIntershipList;

    newIntershipList = (intershipList*) malloc(sizeof(intershipList));
    newIntershipList->firstIntership = NULL;
    newIntershipList->lastIntership = NULL;
    newIntershipList->sizeList = 0;
    
    do {
        printf("\n\n----------------- Choose an option -----------------\n");
        printf("1- Add a intership;\n");
        printf("2- Remove a intership;\n");
        printf("3- List all interships;\n");
        printf("4- List current interships;\n");
        printf("5- Search any intership for index;\n");
        printf("6- Exit.\n\n");
        printf("Option: ");
        scanf("%d", &option);
        printf("----------------------------------------------------\n");

        switch (option)
        {
        case 1:
            printf("What's the name of Company: ");
            scanf("%s", cn);
            printf("What's the occupation area: ");
            scanf("%s", oa);
            printf("What's the type of work: ");
            scanf(" %c", &t);
            addIntership(newIntershipList, cn, oa, t);
            break;

        case 2:
            /* code */
            break;

        case 3:
            listInterships(newIntershipList);
            break;

        case 4:
            listCurrentInterships(newIntershipList);
            break;

        case 5:
            /* code */
            break;
        case 6:
            printf("\nGood Bye!\n");
            option = 0;
            break;

        default:
            printf("\nInvalid option! Please, choose a number between 1 and 6!");
            break;
        }


    } while (option > 0);

    deleteList(newIntershipList);
    return EXIT_SUCCESS;
}

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
            index++;
        }
        aux = aux->next;
    } while (index <= list->sizeList);

    if (qtd == 0) 
        printf("\nThere arent actives interships right now!");
}

void deleteList(intershipList *list)
{
    intership *aux = list->firstIntership;

    if (list == NULL) return;

    while (aux->index < list->lastIntership->index) {
        if (aux->next == list->lastIntership) {
            free(aux->next);
            list->lastIntership = aux;
            deleteList(list);
        }
    }
}