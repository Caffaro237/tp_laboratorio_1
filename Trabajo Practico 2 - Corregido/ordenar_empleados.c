#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "empleados.h"

void ordenar_empleados(e_empleado vec[], int tam, e_sector sectores[], int tam_sec)
{
    //Declaracion de variables
    e_empleado aux_empleado;

    for(int i = 0; i < tam - 1; i++)
    {
        for(int j = i + 1; j < tam; j++)
        {
            //Ordenamiento de los empleados
            if(strcmp(vec[i].apellido, vec[j].apellido) > 0)
            {
                aux_empleado = vec[i];
                vec[i] = vec[j];
                vec[j] = aux_empleado;
            }
            else
            {
                if(strcmp(vec[i].apellido, vec[j].apellido) == 0 && vec[i].id_sector < vec[j].id_sector)
                {
                    aux_empleado = vec[i];
                    vec[i] = vec[j];
                    vec[j] = aux_empleado;
                }
            }
        }
    }
}
