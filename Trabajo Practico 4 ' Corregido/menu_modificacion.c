#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "LinkedList.h"
#include "prototipos.h"

int menu_modificacion(e_empleado* empleado)
{
    //Menu secundario de opciones para la modificacion

    char opcion;

    system("cls"); //Limpia la consola
    system("color 0F"); //Cambia a color negro de la consola y las letras a blanco brillante

    printf("    *****Menu de modificacion para el empleado*****\n");
    printf("_______________________________________________________\n");
    printf("ID     Nombre         Apellido       Sexo   Sueldo\n");
    printf("-------------------------------------------------------\n");
    mostrar_empleado_p(empleado); //Llama la funcion para mostrar el empleado seleccionado

    printf("\n");
    printf("a - Modificar nombre\n");
    printf("b - Modificar apellido\n");
    printf("c - Modificar sexo\n");
    printf("d - Modificar sueldo\n");
    printf("e - Salir\n");

    printf("Indique su opcion: ");
    fflush(stdin);
    scanf("%c", &opcion); //Ingresa la opcion

    return opcion;
}
