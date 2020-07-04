#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "Funciones.h"

int menu_orden()
{
    //Menu secundario de opciones para ordenar los empleados

    char opcion;

    system("cls"); //Limpia la consola
    system("color 0F"); //Cambia a color negro de la consola y las letras a blanco brillante

    printf("*****Menu de opciones*****\n");
    printf("a - Ordenar por ID\n");
    printf("b - Ordenar por Nombre\n");
    printf("c - Ordenar por Horas trabajadas\n");
    printf("d - Ordenar por Sueldos\n");
    printf("e - Salir\n");

    printf("Indique su opcion: ");
    fflush(stdin);
    scanf("%c", &opcion); //Ingresa la opcion

    return opcion;
}

int mayor_o_menor()
{
    //Funcion para preguntar si se quiere ordenar de mayor a menor, de menor a mayor, de la A-Z o de la Z-A
    int opcion;

    printf("Mayor a menor / A-Z ingrese 0\n");
    printf("Menor a mayor / Z-A ingrese 1\n");

    printf("Opcion: ");
    scanf("%d", &opcion); //Ingresa la opcion

    system("cls");

    return opcion;
}
