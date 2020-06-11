#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "empleados.h"

#define TAM 20
#define TAM_SEC 5


#define CANT_HARCODE 10 //Cabiar segun cuantos empleados se quieran harcodear **MAXIMO POSIBLE 10**


/*
    Este codigo cuenta con protecciones para que el usuario
    no cometa errores de ingreso, por ejemplo, cuando se pide
    un numero no sea ingresada una letra, o al escribir el
    nombre y apellido el programa lo normalizara con la
    primera letra mayuscula y las demas letras en minusculas.

    Hasta no tener al menos un empleado ingresado no podran
    ser realizados los siguienter pasos.
*/


int main()
{
    //Declaracion de variables
    char seguir;
    int proximo_id;
    e_empleado lista[TAM];
    int flag_alta;
    char confirma;

    e_sector sectores[TAM_SEC] =
    {
        {1, "Sistemas"},
        {2, "RRHH"},
        {3, "Ventas"},
        {4, "Compras"},
        {5, "Contable"}
    };

    //Inicializacion de variables
    seguir = 's';
    proximo_id = 1000;
    flag_alta = 0;

    inicializar_empleados(lista, TAM); //Llama a la funcion para inicializar empelados


    //harcodear_empleados(lista, CANT_HARCODE); //Llama a la funcion para harcodear los empleados
    //proximo_id = proximo_id + CANT_HARCODE; //Suma a proximo_id la cantidad de nombres que se quiera harcodear LINEA DE CODIGO 10
    //DESCOMENTAR LAS DOS LINEAS DE ARRIBA PARA PODER HARCODEAR LOS DATOS
    //O COMENTAR SI NO SE QUIERE HARCODEAR


    printf("***Bienvenido al sistema para la carga de empleados***\n");
    printf("        ***Para iniciar presione enter***\n\n");

    system("color 0F"); //Cambia a color negro de la consola y las letras a blanco brillante
    system("pause"); //Pausa la consola


    do //Estructura repetitiva
    {
        switch(menu()) //Llama a la funcion para mostrar el menu de opciones
        {
            case 1:
                if(alta_empleado(proximo_id, lista, TAM, sectores, TAM_SEC)) //Llama a la funcion para dar de alta un empleado y si devuelve un valor se cumple la condicion
                {
                    //Si se cumple la condicion entra al if
                    proximo_id = proximo_id + 1; //Suma un id
                    flag_alta = 1; //Cambia el valor de la badera a 1
                }
                system("pause"); //Pausa la consola
                break;
            case 2:
                if(proximo_id < 1001 && !flag_alta) //Pregunta si proximo_id es mayor a 1001 o flag_alta sea igual a 0
                {
                    //Si se cumple la condicion entra al if y muestra el error
                    system("cls"); //Limpia la consola
                    system("color 4F"); //Cambia a color rojo la consola cuando se produce un error

                    printf("       ***No se cargo ningun empleado***\n");
                    printf("***Primero debe ingresar al menos un empleado***\n\n");
                }
                else
                {
                    //Si no se cumple la condicion entra al else y llama a la funcion
                    modificar_empleado(lista, TAM, sectores, TAM_SEC); //Llama a la funcion para modificar un empleado
                }
                system("pause"); //Pausa la consola
                break;
            case 3:
                if(proximo_id < 1001 && !flag_alta) //Pregunta si proximo_id es mayor a 1001 o flag_alta sea igual a 0
                {
                    //Si se cumple la condicion entra al if y muestra el error
                    system("cls"); //Limpia la consola
                    system("color 4F"); //Cambia a color rojo la consola cuando se produce un error

                    printf("       ***No se cargo ningun empleado***\n");
                    printf("***Primero debe ingresar al menos un empleado***\n\n");
                }
                else
                {
                    //Si no se cumple la condicion entra al else y llama a la funcion
                    baja_empleado(lista, TAM, sectores, TAM_SEC); //Llama a la funcion para dar de baja un empleado
                }

                system("pause"); //Pausa la consola
                break;
            case 4:
                if(proximo_id < 1001 && !flag_alta) //Pregunta si proximo_id es mayor a 1001 o flag_alta sea igual a 0
                {
                    //Si se cumple la condicion entra al if y muestra el error
                    system("cls"); //Limpia la consola
                    system("color 4F"); //Cambia a color rojo la consola cuando se produce un error

                    printf("       ***No se cargo ningun empleado***\n");
                    printf("***Primero debe ingresar al menos un empleado***\n\n");
                }
                else
                {
                    //Si no se cumple la condicion entra al else y llama a la funcion
                    informar(lista, TAM, sectores, TAM_SEC); //Llama a la funcion para entrar en la parte de informes
                }
                system("pause"); //Pausa la consola
                break;
            case 5:
                //Confirma la salida
                printf("Confirma salir? s/n: ");
                fflush(stdin);
                scanf("%c", &confirma);

                if(confirma == 's')
                {
                    seguir = 'n';
                }
                break;

            default:
                system("cls"); //Limpia la consola
                system("color 4F"); //Cambia a color rojo la consola cuando se produce un error

                printf("*****Opcion invalida*****\n\n");
                system("pause"); //Pausa la consola
        }

    }while(seguir == 's'); //Si seguir es igual a 's' sigue repitiendo

    system("cls"); //Limpia la consola

    printf("*****Gracias por operar con nosotros*****\n");
    printf("     ***Para salir presione enter***\n\n");

    return 0;
}
