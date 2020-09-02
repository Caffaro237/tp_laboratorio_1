#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "LinkedList.h"
#include "prototipos.h"

int alta_empleado(LinkedList* lista, int cant_empleados)
{
    //Funcion para dar de alta un empleado
    system("cls");

    printf("Alta de empleado\n");

    e_empleado* nuevo_empleado;

    int ok;
    int id;
    char nombre[20];
    char apellido[20];
    char sexo;
    float sueldo;
    char id_str[10];
    char sueldo_str[10];
    char is_empty_str[2];

    ok = -1;
    id = cant_empleados + 1;


    system("cls");
    printf("Ingrese nombre: "); //Ingreso del nombre
    fflush(stdin);
    fgets(nombre, 20, stdin); //Se ingresa el nombre
    nombre[strlen(nombre) - 1] = '\0'; //Elimina el \n de el fgets
    normalizar_nombres(nombre); //Llama a la funcion para normalizar el nombre si se ingreso mal


    system("cls");
    printf("Ingrese apellido: "); //Ingreso del apellido
    fflush(stdin);
    fgets(apellido, 20, stdin); //Se ingresa el apellido
    apellido[strlen(apellido) - 1] = '\0'; //Elimina el \n de el fgets
    normalizar_nombres(apellido); //Llama a la funcion para normalizar el apellido si se ingreso mal


    system("cls");
    printf("Ingrese genero del empleado: "); //Ingreso de las horas trabajadas
    fflush(stdin);
    scanf("%c", &sexo);
    sexo = validar_genero(sexo); //Llama a la funcion para validar que solo sea F o M


    system("cls");
    printf("Ingrese sueldo: "); //Ingreso del sueldo
    fflush(stdin);
    scanf("%f", &sueldo);
    sueldo = validar_sueldo(sueldo); //Llama a la funcion para validar que no sea negativo


    itoa(id, id_str, 10); //Lo convierte de int a char
    snprintf(sueldo_str, sizeof(sueldo_str), "%f", sueldo); //Lo convierte de float a char
    strcpy(is_empty_str, "1");


    nuevo_empleado = empleado_nuevo_parametros(id_str, nombre, apellido, &sexo, sueldo_str, is_empty_str); //Llama a la funcion para asignarle memoria
    ok = ll_add(lista, nuevo_empleado); //Llama a la funcion para realizar la carga

    return ok;
}
