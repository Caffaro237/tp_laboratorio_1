#include <stdio.h>
#include <stdlib.h>
#include "empleados.h"

void mostrar_empleados(e_empleado vec[], int tam, e_sector sectores[], int tam_sec)
{
    //Declaracion de variables
    int flag;

    //Inicializacion de variables
    flag = 0;

    system("cls");

    ordenar_empleados(vec, tam, sectores, tam_sec); //Llama a la funcion para ordenar los empleados

    printf("                *****Lista de empleados*****\n");
    printf("________________________________________________________________\n");
    printf("ID      Apellido   Nombre        Edad     Sueldo       Sector\n");
    printf("----------------------------------------------------------------\n");

    for(int i = 0; i < tam; i++)
    {
        if(vec[i].is_empty == 0) //Pregunta si is_empty esta en 0 o 1
        {
            //Si esta en 0 entra y muestra los empleados
            mostrar_empleado(vec[i], sectores, tam_sec); //Llama a la funcion para mostrar empleados
            printf("\n");
            flag = 1;
        }
    }
    printf("\n");

    if(!flag) //Pregunta si flag esta en 0 o 1
    {
        //Si esta en 0 entra y muestra el mensaje
        printf("***No hay empleados que listar***\n\n");
    }
}
