#include <stdio.h>
#include <stdlib.h>
#include "prototipos.h"

int validar_numero()
{
    int a;

    while(scanf("%i", &a) != 1)
    {
        system("color 4F"); //Cambia el color a la consola a rojo cuando se produce un error
        system("cls");
        printf("Error, solo numeros. Reingresar el operando: ");
        scanf("%i", &a);
        fflush(stdin);
    }

    return a;
}
