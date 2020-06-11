#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "empleados.h"

int cargar_descripcion_sector(char descripcion[], int id, e_sector sectores[], int tam)
{

    //Declaracion de variables
    int ok;

    //Inicializacion de variables
    ok = 0;

    for(int i = 0; i < tam; i++)
    {
        if(sectores[i].id == id)
        {
            strcpy(descripcion, sectores[i].descripcion); //Carga la descripcion dl sector
            ok = 1;
        }
    }

    return ok;
}
