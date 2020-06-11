#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "empleados.h"

int menu_informes()
{
    //Menu secundario de opciones para los informes

    char opcion;

    system("cls"); //Limpia la consola
    system("color 0F"); //Cambia a color negro de la consola y las letras a blanco brillante

    printf("*** Informe de Empleados ***\n");
    printf(" *****Menu de informes*****\n");
    printf("a - Listar empleados\n");
    printf("b - Listar salarios\n");
    printf("c - Salir\n\n");

    printf("Indique su opcion: ");
    fflush(stdin);
    scanf("%c", &opcion);

    return opcion;
}
