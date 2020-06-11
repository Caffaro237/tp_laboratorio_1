#include <stdio.h>
#include <stdlib.h>
#include "empleados.h"

int menu()
{
    //Menu principal de opciones

    int opcion;

    system("cls"); //Limpia la consola
    system("color 0F"); //Cambia a color negro de la consola y las letras a blanco brillante

    printf("*****Menu de opciones*****\n");
    printf("1 - Alta empleado\n");
    printf("2 - Modificar empleado\n");
    printf("3 - Baja empleado\n");
    printf("4 - Informes\n");
    printf("5 - Salir\n");

    printf("Indique su opcion: ");
    fflush(stdin);
    scanf("%d", &opcion);

    return opcion;
}
