#include <stdio.h>
#include <stdlib.h>
#include "prototipos.h"

int menu_opciones(int a, int b, int flag_1, int flag_2, int flag_3) //Funcion del menu de opciones
{
    int opcion;

    system("cls"); //Limpia la consola

    system("color 0F");

    if(flag_1) //Validacion de ingreso del primer operando
    {
        //Si ya se ingreso el primer operando entra el if

        if(flag_2) //Validacion de ingreso del segundo operando
        {
            //Si ya se ingreso el segundo operando entra el if

            if(flag_3) //Validacion de realizacion de calculos
            {
                // Si los calculos se realizaron ingresa al if

                printf("    *****Menu de opciones*****\n");
                printf("__________________________________\n");
                printf("1 - El 1er operando es: %d\n", a);
                printf("2 - El 2do operando es: %d\n", b);
                printf("3 - Ya se calcularon todas las operaciones\n");
                printf("4 - Informar resultados\n\n");
                printf("5 - Salir\n\n");

                printf("Indique su opcion: ");
                scanf("%d", &opcion); //Ingreso de la opcion
            }
            else //Validacion de realizacion de calculos
            {
                // Si los calculos todavia no se realizaron ingresa al else

                printf("    *****Menu de opciones*****\n");
                printf("__________________________________\n");
                printf("1 - El 1er operando es: %d\n", a);
                printf("2 - El 2do operando es: %d\n", b);
                printf("3 - Calcular todas las operaciones\n");
                printf("4 - Informar resultados\n\n");
                printf("5 - Salir\n\n");

                printf("Indique su opcion: ");
                scanf("%d", &opcion); //Ingreso de la opcion
            }
        }
        else //Validacion de ingreso del segundo operando
        {
            //Si todavia no se ingreso el segundo operando entra el else

            printf("    *****Menu de opciones*****\n");
            printf("__________________________________\n");
            printf("1 - El 1er operando es: %d\n", a);
            printf("2 - Ingresar 2do operando \n");
            printf("3 - Calcular todas las operaciones\n");
            printf("4 - Informar resultados\n\n");
            printf("5 - Salir\n\n");

            printf("Indique su opcion: ");
            scanf("%d", &opcion); //Ingreso de la opcion
        }

    }
    else //Validacion de ingreso del primer operando
    {
        //Si todavia no se ingreso el primer operando entra el else

        printf("    *****Menu de opciones*****\n");
        printf("__________________________________\n");
        printf("1 - Ingresar 1er operando\n");
        printf("2 - Ingresar 2do operando \n");
        printf("3 - Calcular todas las operaciones\n");
        printf("4 - Informar resultados\n\n");
        printf("5 - Salir\n\n");

        printf("Indique su opcion: ");
        scanf("%d", &opcion); //Ingreso de la opcion
    }

    return opcion;
}
