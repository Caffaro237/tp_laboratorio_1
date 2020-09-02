#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "LinkedList.h"
#include "prototipos.h"

int baja_empleado(LinkedList* lista)
{
    int id;
    int idx;
    int ok;

    e_empleado* empleado;
    char confirma;

    ok = 0;
    confirma = 'n';

    system("cls");

    printf("Dar de baja a un empleado\n\n");
    printf("Ingrese el ID: "); //Ingreso del ID
    scanf("%d", &id);
    id = validar_id(id); //Llama a la funcion para validar que no sea negativo

    idx = id - 1;

    empleado = (e_empleado*) ll_get(lista, idx); //Obtiene la informacion del empleado que se ingreso el ID

    if(empleado != NULL)
    {
        system("cls");

        printf("    *****Dar de baja al empleado seleccionado*****\n");
        printf("_______________________________________________________\n");
        printf("ID     Nombre         Apellido       Sexo   Sueldo\n");
        printf("-------------------------------------------------------\n");
        mostrar_empleado_p(empleado); //Llama la funcion para mostrar el empleado obtenido
        printf("\n");

        printf("Desea eliminar al empleado? s/n: "); //Pregunta si se desea eliminar o no
        fflush(stdin);
        scanf("%c", &confirma);

        if(confirma == 's' && !ll_remove(lista, idx) && idx > 0) //Llama a la funcion para remover el empleado de la lista
        {
            empleado->is_empty = 0;
            ok = 1;
        }
        else
        {
            printf("Se cancelo la baja del empleado\n");
        }
    }
    else
    {
        printf("\nNo se encontro un empleado con el ID: %d\n", id);
    }

    printf("\n");

    return ok;
}
