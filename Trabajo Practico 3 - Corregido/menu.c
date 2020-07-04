#include <stdio.h>
#include <stdlib.h>
#include "Funciones.h"

int menu()
{
    //Menu principal de opciones

    int opcion;

    system("cls"); //Limpia la consola
    system("color 0F"); //Cambia a color negro de la consola y las letras a blanco brillante

    printf("*****Menu de opciones*****\n");
    printf("1 - Cargar los datos de los empleados desde el archivo data.csv (modo texto)\n");
    printf("2 - Cargar los datos de los empleados desde el archivo data.bin (modo binario)\n");
    printf("3 - Alta de empleado\n");
    printf("4 - Modificar datos de empleado\n");
    printf("5 - Baja de empleado\n");
    printf("6 - Listar empleados\n");
    printf("7 - Ordenar empleados\n");
    printf("8 - Guardar los datos de los empleados en el archivo data.csv (modo texto)\n");
    printf("9 - Guardar los datos de los empleados en el archivo data.bin (modo binario)\n");
    printf("10 - Salir\n");

    printf("Indique su opcion: ");
    fflush(stdin);
    scanf("%d", &opcion); //Ingresa la opcion

    return opcion;
}
