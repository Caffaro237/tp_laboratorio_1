#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "empleados.h"

int menu_modificacion(int indice, e_empleado vec[], int tam, e_sector sectores[], int tam_sec)
{
    //Menu secundario de opciones para la modificacion

    char opcion;

    system("cls"); //Limpia la consola
    system("color 0F"); //Cambia a color negro de la consola y las letras a blanco brillante

    printf("                *****Menu de modificacion*****\n");
    printf("________________________________________________________________\n");
    printf("ID      Apellido   Nombre        Edad     Sueldo       Sector\n");
    printf("----------------------------------------------------------------\n");
    mostrar_empleado(vec[indice], sectores, tam_sec); //Llama la funcion para mostrar el empleado seleccionado

    printf("\n\na - Modificar nombre\n");
    printf("b - Modificar apellido\n");
    printf("c - Modificar sueldo\n");
    printf("d - Modificar sector\n");
    printf("e - Salir\n");

    printf("Indique su opcion: ");
    fflush(stdin);
    scanf("%c", &opcion);

    return opcion;
}


