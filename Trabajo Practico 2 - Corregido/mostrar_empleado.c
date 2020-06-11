#include <stdio.h>
#include <stdlib.h>
#include "empleados.h"

void mostrar_empleado(e_empleado empleado, e_sector sectores[], int tam_sec)
{
    //Declaracion de variables
    char nombre_sector[20];

    cargar_descripcion_sector(nombre_sector, empleado.id_sector, sectores, tam_sec); //Llama a la funcion para cargar la descripcion del sector

    printf("%4d    %-10s %-10s    %2d       %-9.2f    %-10s", empleado.id, empleado.apellido, empleado.nombre, empleado.edad, empleado.sueldo, nombre_sector);
}
