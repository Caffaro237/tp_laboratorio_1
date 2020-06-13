#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "Funciones.h"

e_empleado* employee_new()
{
    e_empleado* nuevo_empleado = (e_empleado*) malloc(sizeof(e_empleado)); //Asigna memoria dinamica

    if(nuevo_empleado != NULL) //Setea todo vacio
    {
        nuevo_empleado->id = 0;
        nuevo_empleado->horas_trabajadas = 0;
        nuevo_empleado->sueldo = 0;
        strcpy(nuevo_empleado->nombre, "");
    }

    return nuevo_empleado;
}

e_empleado* employee_newParametros(char* id_str, char* nombre_str, char* horas_trabajadas_str, char* sueldo_str)
{
    e_empleado* nuevo_empleado = employee_new(); //Llama a la funcion para escribir un nuevo empleado

    if(nuevo_empleado != NULL)
    {
        //Llama a las funciones SET para colocar los valores

        if(!(employee_setId(nuevo_empleado, atoi(id_str))
                && employee_setNombre(nuevo_empleado, nombre_str)
                && employee_setHorasTrabajadas(nuevo_empleado, atoi(horas_trabajadas_str))
                && employee_setSueldo(nuevo_empleado, atof(sueldo_str))))
        {
            //Si uno de los valores no se carga se limpia el empleado cargado
            free(nuevo_empleado);
            nuevo_empleado = NULL;
        }
    }
    return nuevo_empleado;
}


int employee_setId(e_empleado* empleado, int id)
{
    //Funcion para setear el ID
    int ok;

    ok = 0;

    if(empleado != NULL && id >=0)
    {
        empleado->id = id;
        ok = 1;
    }

    return ok;
}

int employee_setNombre(e_empleado* empleado, char* nombre)
{
    //Funcion para setear el nombre
    int ok;

    ok = 0;

    if(empleado != NULL && nombre != NULL && strlen(nombre) >= 3 && strlen(nombre)< 20)
    {
        strcpy(empleado->nombre, nombre);
        ok = 1;
    }

    return ok;
}

int employee_setHorasTrabajadas(e_empleado* empleado, int horas_trabajadas)
{
    //Funcion para setear las horas trabajadas
    int ok;

    ok = 0;

    if(empleado != NULL && horas_trabajadas >=0)
    {
        empleado->horas_trabajadas = horas_trabajadas;
        ok = 1;
    }

    return ok;
}

int employee_setSueldo(e_empleado* empleado, float sueldo)
{
    //Funcion para setear el sueldo
    int ok;

    ok = 0;

    if(empleado != NULL && sueldo >=0)
    {
        empleado->sueldo = sueldo;
        ok = 1;
    }

    return ok;
}


int employee_getId(e_empleado* empleado, int* id)
{
    //Funcion para tomar el ID que tiene un empleado cargado
    int ok;

    ok = 0;

    if(empleado != NULL && id != NULL && id > 0)
    {
        *id = empleado->id;
        ok = 1;
    }

    return ok;
}

int employee_getNombre(e_empleado* empleado, char* nombre)
{
    //Funcion para tomar el nombre que tiene un empleado cargado
    int ok;

    ok = 0;

    if(empleado != NULL && nombre != NULL && strlen(nombre) >= 3 && strlen(nombre) < 20)
    {
        strcpy(nombre, empleado->nombre);
        ok = 1;
    }

    return ok;
}

int employee_getHorasTrabajadas(e_empleado* empleado, int* horas_trabajadas)
{
    //Funcion para tomar las horas trabajadas que tiene un empleado cargado
    int ok;

    ok = 0;

    if(empleado != NULL && horas_trabajadas != NULL && horas_trabajadas > 0)
    {
        *horas_trabajadas = empleado->horas_trabajadas;
        ok = 1;
    }

    return ok;
}

int employee_getSueldo(e_empleado* empleado, float* sueldo)
{
    //Funcion para tomar el sueldo que tiene un empleado cargado
    int ok;

    ok = 0;

    if(empleado != NULL && sueldo != NULL && sueldo > 0)
    {
        *sueldo = empleado->sueldo;
        ok = 1;
    }

    return ok;
}


int comparar_id_empleado(void* a, void* b)
{
    //Funcion para comparar el ID de dos empleados
    int ok;

    e_empleado* empleado_1;
    e_empleado* empleado_2;

    ok = 0;

    if(a != NULL && b != NULL)
    {
        empleado_1 = (e_empleado*) a;
        empleado_2 = (e_empleado*) b;
    }

    if(empleado_1->id > empleado_2->id)
    {
        ok = 1;
    }
    else
    {
        if(empleado_1->id < empleado_2->id)
        {
            ok = -1;
        }
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

int comparar_horas_empleado(void* a, void* b)
{
    //Funcion para comparar las horas trabajadas de dos empleados
    int ok;
    e_empleado* empleado_1;
    e_empleado* empleado_2;

    ok = 0;

    if(a != NULL && b != NULL)
    {
        empleado_1 = (e_empleado*) a;
        empleado_2 = (e_empleado*) b;
    }

    if(empleado_1->horas_trabajadas > empleado_2->horas_trabajadas)
    {
        ok = 1;
    }
    else
    {
        if(empleado_1->horas_trabajadas < empleado_2->horas_trabajadas)
        {
            ok = -1;
        }
    }

    return ok;
}

int comparar_sueldo_empleado(void* a, void* b)
{
    //Funcion para comparar el sueldo de dos empleados
    int ok;
    e_empleado* empleado_1;
    e_empleado* empleado_2;

    ok = 0;

    if(a != NULL && b != NULL)
    {
        empleado_1 = (e_empleado*) a;
        empleado_2 = (e_empleado*) b;
    }

    if(empleado_1->sueldo > empleado_2->sueldo)
    {
        ok = 1;
    }
    else
    {
        if(empleado_1->sueldo < empleado_2->sueldo)
        {
            ok = -1;
        }
    }

    return ok;
}


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
        printf("ID     Nombre     Horas trabajadas   Sueldo\n");
        printf("----------------------------------------------\n");

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

int mostrar_empleado_p(e_empleado* empleado)
{
    //Funcion para mostrar un solo empleado
    int ok;

    ok = 0;

    if(empleado != NULL)
    {
        ok = 1;
        printf("%04d   %-10s %3d hs             %.2f\n", empleado->id, empleado->nombre, empleado->horas_trabajadas, empleado->sueldo);
    }
    return  ok;
}

int validar_negativos(int numero)
{
    //Funcion para validar que un numero no sea negativo
    while(numero < 0)
    {
        printf("Error, numero negativo. Reingrese la opcion: ");
        fflush(stdin);
        scanf("%d", &numero);
    }

    return numero;
}

void normalizar_nombres(char* nombre)
{
    //Funcion para normalizar el nombre si se ingresa mal
    strlwr(nombre);

    nombre[0] = toupper(nombre[0]);
}
