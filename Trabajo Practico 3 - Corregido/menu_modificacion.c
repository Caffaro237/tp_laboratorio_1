#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "Funciones.h"

int menu_modificacion(e_empleado* empleado)
{
    //Menu secundario de opciones para la modificacion

    char opcion;

    system("cls"); //Limpia la consola
    system("color 0F"); //Cambia a color negro de la consola y las letras a blanco brillante

    printf("       *****Menu de modificacion*****\n");
    printf("__________________________________________________\n");
    printf("ID     Nombre      Horas trabajadas  Sueldo\n");
    printf("--------------------------------------------------\n");
    mostrar_empleado_p(empleado); //Llama la funcion para mostrar el empleado seleccionado

    printf("\n");
    printf("a - Modificar nombre\n");
    printf("b - Modificar Horas trabajadas\n");
    printf("c - Modificar sueldo\n");
    printf("d - Salir\n");

    printf("Indique su opcion: ");
    fflush(stdin);
    scanf("%c", &opcion); //Ingresa la opcion

    return opcion;
}
