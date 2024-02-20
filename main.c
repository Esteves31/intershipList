#include "intership.h"

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    char cn[20];
    char oa[30];
    char t;
    int option;
    int index;
    intershipList *newIntershipList;

    newIntershipList = (intershipList*)malloc(sizeof(intershipList));
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
        printf("6- Change active intership for index;\n");
        printf("7- Exit.\n\n");
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
                printf("Index you want to remove: ");
                scanf("%d", &index);
                removeIntership(newIntershipList, index);
                break;

            case 3:
                listInterships(newIntershipList);
                break;

            case 4:
                listCurrentInterships(newIntershipList);
                break;

            case 5:
                printf("Index: ");
                scanf("%d", &index);
                searchIntershipByIndex(newIntershipList, index);
                break;
                
            case 6:
                printf("Index you want change active: ");
                scanf("%d", &index);
                changeStatusOfIntership(newIntershipList, index);
                break;

            case 7:
                printf("\nGood Bye!\n");
                break;

            default:
                printf("\nInvalid option! Please, choose a number between 1 and 6!");
                break;
        }
    } while (option != 7);

    deleteList(newIntershipList);
    return EXIT_SUCCESS;
}