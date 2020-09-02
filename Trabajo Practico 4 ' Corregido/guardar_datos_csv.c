#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "LinkedList.h"
#include "prototipos.h"

int guardar_empleados_csv(char* nombre_archivo, LinkedList* lista)
{
    int ok;
    FILE* f;
    e_empleado* nuevo_empleado;

    f = fopen(nombre_archivo, "w"); //Abre el archivo en modo escritura de texto
    ok = 0;

    if(f != NULL)
    {
        ok = 1;
        fprintf(f, "ID, Nombre, Apellido, Sexo, Sueldo\n"); //Coloca el encabezado

        for(int i = 0; i < ll_len(lista); i++)
        {
            nuevo_empleado = (e_empleado*) ll_get(lista, i); //Obtiene la informacion del nuevo_empleado en la posicion i

            if(nuevo_empleado != NULL)
            {
                fprintf(f, "%d, %s, %s, %c, %.2f\n", nuevo_empleado->id, nuevo_empleado->nombre, nuevo_empleado->apellido, nuevo_empleado->sexo, nuevo_empleado->sueldo); //Escribe el nuevo empleado en el archivo
            }
        }
    }
    else
    {
        printf("No se pudo abrir el archivo\n");
    }

    fclose(f); //Cierra el archivo

    return ok;
}
