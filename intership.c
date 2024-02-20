#include "intership.h"

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    int option;
    intership *newIntership = NULL;
    newIntership = (intership*) malloc(sizeof(intership));

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
            /* code */
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