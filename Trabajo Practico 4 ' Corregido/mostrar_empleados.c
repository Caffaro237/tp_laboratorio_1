#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "prototipos.h"
#include "LinkedList.h"

int mostrar_empleados(LinkedList* lista)
{
    //Funcion para mostrar los empleados

    //Declaracion de variables
    int ok;
    int tam;
    int bandera;
    e_empleado* aux_empleado;

    //Inicializacion de variables
    ok = 0;
    bandera = 0;


    if(lista != NULL)
    {
        ok = 1;
        tam = ll_len(lista);

        printf("ID     Nombre         Apellido       Sexo   Sueldo\n");
        printf("-------------------------------------------------------\n");

        for(int i = 0; i < tam; i++)
        {
            aux_empleado = (e_empleado*) ll_get(lista, i); //Lee al empleado en la posicion i

            if(aux_empleado != NULL)
            {
                mostrar_empleado_p(aux_empleado); //Llama a la funcion para mostrar un empleado en la posicion que se leyo
                bandera = 1;
            }
        }

        if(!bandera)
        {
            printf("No hay empleados que listar");
        }

        printf("\n\n");
    }

    return ok;
}

