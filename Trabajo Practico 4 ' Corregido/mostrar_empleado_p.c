#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "prototipos.h"
#include "LinkedList.h"

int mostrar_empleado_p(e_empleado* empleado)
{
    //Funcion para mostrar un solo empleado
    int ok;

    ok = 0;

    if(empleado != NULL)
    {
        ok = 1;
        printf("%04d   %-14s %-14s %c      %.2f\n", empleado->id, empleado->nombre, empleado->apellido, empleado->sexo, empleado->sueldo);
    }
    return  ok;
}
