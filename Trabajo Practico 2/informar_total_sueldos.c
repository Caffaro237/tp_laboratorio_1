#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "empleados.h"

void informar_total_sueldos(e_empleado vec[], int tam)
{
    //Declaracion de variables
    float total;
    float promedio;

    //Inicializacion de variables
    total = 0;

    system("cls"); //Limpia la consola

    printf("*****Informe total sueldos a pagar*****\n");

    for(int i = 0; i < tam; i++)
    {
        if(vec[i].is_empty == 0) //Pregunta si is_empty es igual a 0
        {
            total = total + vec[i].sueldo; //Acumula todos los sueldos de los empleados
        }
    }
    printf("El total de los sueldos a pagar es: $%.2f-.\n\n", total);

    promedio = total / tam; //Calcula el promedio de los empleados

    printf("El promedio de los sueldos es: $%.2f-.\n\n", promedio);
}
