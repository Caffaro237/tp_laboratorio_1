#include <stdio.h>
#include <stdlib.h>
#include "empleados.h"

void inicializar_empleados(e_empleado vec[], int tam)
{
    for(int i = 0; i < tam; i++)
    {
        vec[i].is_empty = 1; //Inicializa todos los empleados
    }
}
