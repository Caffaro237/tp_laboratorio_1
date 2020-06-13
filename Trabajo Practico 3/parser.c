#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"

/** \brief Parsea los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param recibe un puntero de archivo abierto (archivo FILE*)
 * \param recibe un puntero a la lista de los empleados (p_array_empleados LinkedList*)
 * \return retorna 1 si se pudo, o 0 si no se pudieron parsear
 *
 */
int parser_EmployeeFromText(FILE* archivo, LinkedList* p_array_empleados)
{
    //Funcion para parsear los datos de los empleados desde un archivo de texto
    int cant;
    int ok;
    char buffer[4][128];
    e_empleado* nuevo_empleado;

    ok = 0;

    fscanf(archivo, "%[^,], %[^,], %[^,], %[^\n]\n", buffer[0], buffer[1], buffer[2], buffer[3]); //Carga el encabezado

    //printf("%s %s %s %s\n\n", buffer[0], buffer[1], buffer[2], buffer[3]);

    while(!feof(archivo))
    {
        ok = 1;
        cant = fscanf(archivo, "%[^,], %[^,], %[^,], %[^\n]\n", buffer[0], buffer[1], buffer[2], buffer[3]); //Lee los empleados y carga la cantidad de elementos leidos

        if(cant == 4)
        {
            nuevo_empleado = employee_newParametros(buffer[0], buffer[1], buffer[2], buffer[3]); //Llama a la funcion para asignar memoria a los empleados
            ll_add(p_array_empleados, nuevo_empleado); //Llama a la funcion para dar de alta a los empleados

            //printf("%d, %-10s, %d, %5.2f\n", atoi(buffer[0]), buffer[1], atoi(buffer[2]), atof(buffer[3]));
        }
        else
        {
            break;
        }
    }

    return ok;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo datos.bin (modo binario).
 *
 * \param recibe un puntero de archivo abierto (archivo FILE*)
 * \param recibe un puntero a la lista de los empleados (p_array_empleados LinkedList*)
 * \return retorna 1 si se pudo, o 0 si no se pudieron parsear
 *
 */
int parser_EmployeeFromBinary(FILE* archivo, LinkedList* p_array_empleados)
{
    //Funcion para parsear los datos de los empleados desde un archivo binario
    int ok;
    int tam;
    e_empleado* empleado;

    ok = 0;
    tam = ll_len(p_array_empleados);


    for(int i = 0; i < tam; i++)
    {
        empleado = (e_empleado*) ll_get(p_array_empleados, i); //Obtiene el valor de ls empleados en la posicion i

        if(empleado != NULL)
        {
            fread(&empleado, sizeof(e_empleado), 1, archivo); //Lee los empleados
            ok = 1;
            ll_add(p_array_empleados, empleado); //Llama a la funcion para dar de alta a los empleados

            //printf("ID: %d  Nombre: %s  Horas: %d  Sueldo: %.2f\n", empleado->id, empleado->nombre, empleado->horas_trabajadas, empleado->sueldo);
        }
    }

    return ok;
}
