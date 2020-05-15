#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "empleados.h"

int alta_empleado(int idx, e_empleado vec[], int tam, e_sector sectores[], int tam_sec)
{
    //Declaracion de variables
    int prox_id;
    int indice;
    e_empleado aux_empleado;

    //Inicializacion de variables
    prox_id = 0;

    indice = buscar_libre(vec, tam); //Verifica que haya Lugar disponible

    system("cls"); //Limpia la consola

    printf("*** Alta empleado ***\n\n");
    if(indice == -1) //Pregunta si hay lugar o no
    {
        //En caso de estar completo muestra este mensaje

        system("cls"); //Limpia la consola
        system("color 4F"); //Cambia a color rojo la consola cuando se produce un error

        printf("Sistema completo, no hay lugar para dar el alta a un empleado\n\n");
    }
    else
    {
        //En caso de estar no completo se podra ingresar un nuevo empleado
        aux_empleado.id = idx;

        printf("Ingrese nombre: ");
        fflush(stdin);
        fgets(aux_empleado.nombre, 51, stdin); //Se ingresa el nombre
        aux_empleado.nombre[strlen(aux_empleado.nombre) - 1] = '\0'; //Elimina el \n de el fgets
        normalizar_nombres(aux_empleado.nombre); //Llama a la funcion para normalizar el nombre

        printf("Ingrese apellido: ");
        fflush(stdin);
        fgets(aux_empleado.apellido, 51, stdin); //Se ingresa el apellido
        aux_empleado.apellido[strlen(aux_empleado.apellido) - 1] = '\0'; //Elimina el \n de el fgets
        normalizar_nombres(aux_empleado.apellido); //Llama a la funcion para normalizar el apellido

        printf("Ingrese edad: ");
        aux_empleado.edad = validar_numero(); //Se ingresa la edad y se valida que no sea una letra

        printf("Ingrese sueldo: ");
        aux_empleado.sueldo = validar_numero(); //Se ingresa el sueldo y se valida que no sea una letra

        mostrar_sectores(sectores, tam_sec); //Llama a la funcion para mostrar empleados
        printf("Ingrese ID del sector: ");
        aux_empleado.id_sector = validar_numero(); //Se ingresa el sector y se valida que no sea una letra

        aux_empleado.is_empty = 0; //Cambia el valor de is_empty para indicar que esta ocupado

        vec[indice] = aux_empleado; //Copio al vector el empleado nuevo

        prox_id = 1;

        system("cls"); //Limpia la consola
        system("color 60"); //Cambia a color verde la consola cuando se realiza una acion exitosamente

        printf("***Empleado cargado al sistema con exito***\n\n");

    }

    return prox_id;
}
