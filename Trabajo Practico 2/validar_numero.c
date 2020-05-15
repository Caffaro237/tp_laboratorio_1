#include <stdio.h>
#include <stdlib.h>
#include "empleados.h"

int validar_numero()
{
    //Declaracion de variables
    int numero;

    while(scanf("%i", &numero) != 1)
    {
        system("color 4F"); //Cambia el color a la consola a rojo cuando se produce un error
        printf("Error, solo numeros. Reingresar la opcion: ");
        fflush(stdin);
    }

    system("color 0F");

    return numero;
}

