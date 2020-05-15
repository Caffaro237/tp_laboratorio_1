#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "empleados.h"

void informar(e_empleado vec[], int tam, e_sector sectores[], int tam_sec)
{
    //Declaracion de variables
    char seguir;

    //Inicializacion de variables
    seguir = 's';

    do //Estructura repetitiva
    {
        switch(menu_informes()) //Llama a la funcion del menu de opciones para informes
        {
            case 'a':
                mostrar_empleados(vec, tam, sectores, tam_sec); //Llama a la funcion para mostrar los empleados
                system("pause"); //Pausa la consola
                break;
            case 'b':
                informar_total_sueldos(vec, tam); //Lama a la funcion para informar el total de sueldos y el promedio
                informar_empleados_que_superan(vec, tam); //Llama a la funcion para mostrar cuantos empleados superan el sueldo promedio
                system("pause"); //Pausa la consola
                break;
            case 'c':
                seguir = 'n';
                break;
            default:
                system("cls"); //Limpia la consola
                system("color 4F"); //Cambia a color rojo la consola cuando se produce un error
                printf("*****Opcion invalida*****\n");
        }

    }while(seguir == 's'); //Si seguir es igual a 's' sigue repitiendo
}
