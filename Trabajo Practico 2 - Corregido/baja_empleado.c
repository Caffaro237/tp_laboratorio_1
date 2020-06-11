#include <stdio.h>
#include <stdlib.h>
#include "empleados.h"

void baja_empleado(e_empleado vec[], int tam, e_sector sectores[], int tam_sec)
{
    //Declaracion de variables
    int id;
    int indice;
    char confirma;

    system("cls"); //Limpia la pantalla

    printf("*** Baja empleado ***\n");
    printf("Ingrese ID: ");
    scanf("%d", &id); //Se ingresa el ID del empleado a dar la baja

    indice = buscar_empleado(id, vec, tam); //Verifica que el ID ingresado corresponda a un empleado

    if(indice == -1) //Pregunta si existe o no un empleado con ese ID
    {
        system("cls"); //Limpia la pantalla
        system("color 4F"); //Cambia a color rojo la consola cuando se produce un error

        //En el caso de que el ID ingresado no corresponda a un empleado muestra este mensaje
        printf("***No hay registro de un empleado con el id %d***\n\n", id);
    }
    else
    {
        //En el caso de que el ID ingresado si corresponda a una notebook pregunta si se le quiere dar la baja
        mostrar_empleado(vec[indice], sectores, tam_sec);
        printf("\nConfirma baja? s/n: ");
        fflush(stdin);
        scanf("%c", &confirma); //Ingresa s o n para confirmar

        if(confirma == 's')
        {
            //En el caso de que confirme muestra este mensaje
            system("cls"); //Limpia la pantalla
            system("color 60"); //Cambia a color verde la consola cuando se realiza una accion exitosamente

            vec[indice].is_empty = 1; //Y pone el is_empty en 1 para declarar que esta ocupada esa posicion
            printf("***Se ha realizado la baja con exito***\n\n");
        }
        else
        {
            //En el caso de que no confirme muestra este mensaje
            system("cls"); //Limpia la pantalla

            printf("***Se ha cancelado la baja***\n\n");
        }
    }
}
