#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "prototipos.h"

int cargar_empleados_csv(char* nombre_archivo, LinkedList* lista, int cant_empleados)
{
    system("cls");

    int ok;
    int cant;
    char buffer[6][100];
    FILE* f;

    e_empleado* nuevo_empleado;

    f = fopen(nombre_archivo, "r");
    ok = 0;

    if(f != NULL)
    {
        fscanf(f, "%[^,], %[^,], %[^,], %[^,], %[^\n]\n", buffer[0], buffer[1], buffer[2], buffer[3], buffer[4]);
        //printf("%s %s %s %s %s\n\n", buffer[0], buffer[1], buffer[2], buffer[3], buffer[4]);

        while(!feof(f))
        {
            cant = fscanf(f, "%[^,], %[^,], %[^,], %[^,], %[^\n]\n", buffer[0], buffer[1], buffer[2], buffer[3], buffer[4]);
            cant_empleados = cant_empleados + 1;
            //printf("%d\n", cant);
            //printf("%d\n", cant_empleados);

            if(cant == 5)
            {
                itoa(cant_empleados, buffer[0], 10); //Lo convierte de int a char
                strcpy(buffer[5], "1");

                nuevo_empleado = empleado_nuevo_parametros(buffer[0], buffer[1], buffer[2], buffer[3], buffer[4], buffer[5]); //Llama a la funcion para asignar memoria a los empleados
                ll_add(lista, nuevo_empleado); //Llama a la funcion para dar de alta a los empleados
                //printf("%04d %-12s %-14s %c %.2f\n", atoi(buffer[0]), buffer[1], buffer[2], buffer[3][0], atof(buffer[4]));
            }
            else
            {
                break;
            }
        }

        ok = 1;
    }
    else
    {
        printf("No se pudo abrir el archivo\n");
    }

    fclose(f);

    return ok;
}
