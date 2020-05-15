#include <stdio.h>
#include <stdlib.h>
#include "empleados.h"

int buscar_empleado(int id, e_empleado vec[], int tam)
{
    int indice;

    indice = -1;

    for(int i = 0; i < tam; i++)
    {
        if(vec[i].id == id && vec[i].is_empty == 0) //Busca la id ingresada y si el vector en la posicion i esta en 1 is_empty
        {
            indice = i;
            break;
        }
    }

    return indice;
}
