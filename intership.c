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
            scanf("%s", &cn);
            printf("\n");
            printf("What's the occupation area: ");
            scanf("%s", &oa);
            printf("\n");
            printf("What's the type of work: ");
            scanf("%c", &t);
            addIntership(newIntershipList, cn, oa, t);
            break;

        case 2:
            /* code */
            break;

        case 3:
            /* code */
            break;

        case 4:
            /* code */
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