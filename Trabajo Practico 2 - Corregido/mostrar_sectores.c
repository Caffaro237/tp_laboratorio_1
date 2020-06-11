#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "empleados.h"

void mostrar_sectores(e_sector sectores[], int tam)
{
    system("cls");

    printf("*****Lista de sectores*****\n");
    printf("___________________________\n");
    printf("ID    Descripcion\n");

    for(int i = 0; i < tam; i++)
    {
        printf("%d  -  %-10s", sectores[i].id, sectores[i].descripcion);
        printf("\n\n");
    }
}
