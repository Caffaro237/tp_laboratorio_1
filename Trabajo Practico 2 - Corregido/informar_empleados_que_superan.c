#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "empleados.h"

void informar_empleados_que_superan(e_empleado vec[], int tam)
{
    //Declaracion de variables
    float sueldo_promedio;
    int contador_empleados;

    //Inicializacion de variables
    sueldo_promedio = 20000;
    contador_empleados = 0;

    for(int i = 0; i < tam - 1; i++)
    {
        if(vec[i].sueldo > sueldo_promedio && vec[i].is_empty == 0) //Pregunta si el sueldo del empleado es mayor al sueldo promedio y si is_empty es 0
        {
            contador_empleados = contador_empleados + 1; //Suma 1 cada vez que entra al if
        }
    }

    if(!contador_empleados) //Pregunta si es igual a 0
    {
        //Si el contador es igual a 0 muestra este mensaje
        printf("No hay empleados que superen el sueldo maximo\n\n");
    }
    else
    {
        if(contador_empleados == 1) //Pregunta si es igual a 1
        {
            //Si el contador es igual a 1 muestra este mensaje en singular
            printf("Hay %d empleado que supera el sueldo maximo\n\n", contador_empleados);
        }
        else
        {
            //Si el contador es mayor a 1 muestra este mensaje en plural
            printf("Hay %d empleados que superen el sueldo maximo\n\n", contador_empleados);
        }
    }
}
