#include <stdio.h>
#include <stdlib.h>

int menu()
{
    //Menu principal de opciones

    int opcion;

    system("cls"); //Limpia la consola
    system("color 0F"); //Cambia a color negro de la consola y las letras a blanco brillante

    printf("*****Menu de opciones*****\n");
    printf("1 - Cargar los datos de los empleados desde el archivo empleados.csv (modo texto)\n");
    printf("2 - Listar empleados\n");
    printf("3 - Alta de empleado\n");
    printf("4 - Baja de empleado\n");
    printf("5 - Modificar datos de empleado\n");
    printf("6 - Ordenar empleados por nombre A-Z\n");
    printf("7 - Filtrar por sueldo\n");
    printf("8 - Guardar los datos de los empleados en el archivo Lista Empleados Actualizada.csv (modo texto)\n");
    printf("9 - Salir\n");

    printf("Indique su opcion: ");
    fflush(stdin);
    scanf("%d", &opcion); //Ingresa la opcion

    return opcion;
}
