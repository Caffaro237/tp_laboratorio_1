#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "prototipos.h"
#include "LinkedList.h"

e_empleado* empleado_nuevo()
{
    e_empleado* nuevo_empleado = (e_empleado*) malloc(sizeof(e_empleado)); //Asigna memoria dinamica

    if(nuevo_empleado != NULL) //Setea todo vacio
    {
        nuevo_empleado->id = 0;
        strcpy(nuevo_empleado->nombre, "");
        strcpy(nuevo_empleado->apellido, "");
        nuevo_empleado->sexo = ' ';
        nuevo_empleado->sueldo = 0;
        nuevo_empleado->is_empty = 0;
    }

    return nuevo_empleado;
}

e_empleado* empleado_nuevo_parametros(char* id_str, char* nombre_str, char* apellido_str, char* sexo_str, char* sueldo_str, char* is_empty_str)
{
    e_empleado* nuevo_empleado = empleado_nuevo(); //Llama a la funcion para escribir un nuevo empleado

    if(nuevo_empleado != NULL)
    {
        //Llama a las funciones SET para colocar los valores

        if(!(empleado_set_id(nuevo_empleado, atoi(id_str))
                && empleado_set_nombre(nuevo_empleado, nombre_str)
                && empleado_set_apellido(nuevo_empleado, apellido_str)
                && empleado_set_sexo(nuevo_empleado, sexo_str[0])
                && empleado_set_sueldo(nuevo_empleado, atof(sueldo_str))
                && empleado_set_is_empty(nuevo_empleado, atoi(is_empty_str))))
        {
            //Si uno de los valores no se carga se limpia el empleado cargado
            free(nuevo_empleado);
            nuevo_empleado = NULL;
        }

    }
    return nuevo_empleado;
}

int empleado_set_id(e_empleado* empleado, int id)
{
    //Funcion para setear el ID
    int ok;

    ok = 0;

    if(empleado != NULL && id >= 0)
    {
        empleado->id = id;
        ok = 1;
    }

    return ok;
}

int empleado_set_nombre(e_empleado* empleado, char* nombre)
{
    //Funcion para setear el nombre
    int ok;

    ok = 0;

    if(empleado != NULL && nombre != NULL && strlen(nombre) >= 3 && strlen(nombre) < 20)
    {
        strcpy(empleado->nombre, nombre);
        ok = 1;
    }

    return ok;
}

int empleado_set_apellido(e_empleado* empleado, char* apellido)
{
    //Funcion para setear el apellido
    int ok;

    ok = 0;

    if(empleado != NULL && apellido != NULL && strlen(apellido) >= 3 && strlen(apellido) < 20)
    {
        strcpy(empleado->apellido, apellido);
        ok = 1;
    }

    return ok;
}

int empleado_set_sexo(e_empleado* empleado, char sexo)
{
    //Funcion para setear los sexo
    int ok;

    ok = 0;

    if(empleado != NULL || (sexo == 'M' && sexo == 'F'))
    {
        empleado->sexo = sexo;
        ok = 1;
    }

    return ok;
}

int empleado_set_sueldo(e_empleado* empleado, float sueldo)
{
    //Funcion para setear el sueldo
    int ok;

    ok = 0;

    if(empleado != NULL && sueldo >= 0)
    {
        empleado->sueldo = sueldo;
        ok = 1;
    }

    return ok;
}

int empleado_set_is_empty(e_empleado* empleado, int is_empty)
{
    //Funcion para setear el sueldo
    int ok;

    ok = 0;

    if(empleado != NULL && is_empty == 1)
    {
        empleado->is_empty = is_empty;
        ok = 1;
    }

    return ok;
}

int comparar_nombre_empleado(void* a, void* b)
{
    //Funcion para comparar el nombre de dos empleados
    int ok;
    e_empleado* empleado_1;
    e_empleado* empleado_2;

    ok = 0;

    if(a != NULL && b != NULL)
    {
        empleado_1 = (e_empleado*) a;
        empleado_2 = (e_empleado*) b;
    }

    ok = strcmp(empleado_1->nombre, empleado_2->nombre);

    return ok;
}

int filtrar_por_sueldo(void* un_empleado)
{
    int ok = 0;
    e_empleado* x;

    if(un_empleado != NULL)
    {
        x = (e_empleado*) un_empleado;

        if(x->sueldo >= 30000 && x->sueldo <= 40000)
        {
            ok = 1;
        }
    }

    return ok;
}
