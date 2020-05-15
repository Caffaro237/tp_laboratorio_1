#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "empleados.h"
#include "data_warehouse.h"

void harcodear_empleados(e_empleado vec[], int cant)
{
    for(int i = 0; i < cant; i++)
    {
        vec[i].id = ids[i];
        strcpy(vec[i].nombre, nombres[i]);
        strcpy(vec[i].apellido, apellidos[i]);
        vec[i].edad = edades[i];
        vec[i].sueldo = sueldos[i];
        vec[i].id_sector = ids_sector[i];
        vec[i].is_empty = 0;
    }
}
