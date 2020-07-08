#include <stdio.h>
#include <stdlib.h>
#include "prototipos.h"

/*
    Este codigo cuenta con protecciones para que el usuario
    no cometa errores de ingreso, o cambio de variables en los operandos.
    Al pedir el numero se toma la precaucion de que no se ingrese una letra,
    y una vez ingresado no puede ser modificado.
    Los calculos solo pueden realizarse una sola vez
    siempre y cuando los operandos ya hayan sudo ingresados.
    Hasta no tener todos los pasos hechos no se podran informar los resultados.
*/

int main()
{
    //Declaracion de variables
    int num_1;
    int num_2;
    int resultado_suma;
    int resultado_resta;
    int resultado_multiplicacion;
    int resultado_division;
    int resultado_factorial_1;
    int resultado_factorial_2;
    int flag_primer_operando;
    int flag_segundo_operando;
    int flag_calculos;
    char respuesta;

    //Inicializacion de algunas variables
    respuesta = 's';
    flag_primer_operando = 0;
    flag_segundo_operando = 0;
    flag_calculos = 0;

    system("color 0F"); //Cambia el color a las letras de la consola a blanco brillante
    printf("     *****Bienvenido a la calculadora*****\n");
    printf("*****Para ingresar apriete cualquier tecla*****\n\n");
    system("pause"); //Pausa la coonsola

    do //Estructura repetitiva
    {
        switch(menu_opciones(num_1, num_2, flag_primer_operando, flag_segundo_operando, flag_calculos)) //Llama a la funcion del menu de opciones y le pasa los valores
        {
            case 1:
                system("cls"); //Limpia la consola
                if(!flag_primer_operando) //Validacion de ingreso del primer operando
                {
                    //Si todavia no se ingreso el primer operando ingresa al if

                    printf("Ingrese el primer operando: ");
                    num_1 = validar_numero(); //Ingreso del primer operando y lo valida para que no sea una letra
                    flag_primer_operando = 1; //Pone la bandera en 1
                }
                else //Validacion de ingreso del primer operando
                {
                    //Si ya se ingreso el primer operando ingresa al else

                    printf("***Ya ingreso el primer operando***\n\n");
                    system("color 4F"); //Cambia el color a la consola a rojo cuando se produce un error
                    system("pause"); //Pausa la consola
                }
                break;
            case 2:
                system("cls"); //Limpia la consola
                if(flag_primer_operando) //Validacion de ingreso del primer operando
                {
                    //Si se ingreso el primer operando ingresa al if

                    if(!flag_segundo_operando) //Validacion de ingreso del segundo operando
                    {
                        //Si todavia no se ingreso el segundo operando ingresa al if

                        printf("Ingrese el segundo operando: ");
                        num_2 = validar_numero(); //Ingreso del segundo operando y lo valida para que no sea una letra
                        flag_segundo_operando = 1; //Pone la bandera en 1
                    }
                    else //Validacion de ingreso del segundo operando
                    {
                        //Si ya se ingreso el segundo operando ingresa al else

                        printf("***Ya ingreso el segundo operando***\n\n");
                        system("color 4F"); //Cambia el color a la consola a rojo cuando se produce un error
                        system("pause"); //Pausa la consola
                    }
                }
                else //Validacion de ingreso del primer operando
                {
                    //Si no se ingreso el primer operando ingresa al else

                    printf("***Antes ingrese el primer operando***\n\n");
                    system("color 4F"); //Cambia el color a la consola a rojo cuando se produce un error
                    system("pause"); //Pausa la consola
                }
                break;
            case 3:
                system("cls"); //Limpia la consola
                if(flag_primer_operando && flag_segundo_operando) //Validacion de ingreso de los operandos
                {
                    //Si se ingresaron los operandos ingresa al if

                    if(!flag_calculos)
                    {
                        //Si se realizaron los calculos ingresa al if

                        //Llama a las funciones para realizar los calculos y les pasa los valores
                        resultado_suma = suma(num_1, num_2);
                        resultado_resta = resta(num_1, num_2);
                        resultado_multiplicacion = multiplicacion(num_1, num_2);
                        resultado_division = division(num_1, num_2);
                        resultado_factorial_1 = factorial_1(num_1);
                        resultado_factorial_2 = factorial_2(num_2);
                        flag_calculos = 1; //Pone la bandera en 1
                        calculos_realizados(); //Llama a la funcion para mostrar el mensaje de calculos realizados
                    }
                    else //Validacion de ingreso de los operandos
                    {
                        //Si no se realizaron los calculos ingresa al else

                        printf("***Ya realizo los calculos***\n\n");
                        system("color 4F"); //Cambia el color a la consola a rojo cuando se produce un error
                    }
                }
                else
                {
                    //Si no se ingresaron los operandos ingresa al else

                    printf("***Primero se deben ingresar los operandos***\n\n");
                    system("color 4F"); //Cambia el color a la consola a rojo cuando se produce un error
                }
                system("pause"); //Pausa la consola
                break;
            case 4:
                system("cls"); //Limpia la consola
                if(flag_primer_operando && flag_segundo_operando) //Validacion de ingreso de los operandos
                {
                    if(flag_calculos) //Validacion de realizacion de calculos
                    {
                        //Llama a la funcion y le pasa los valores para mostrar los resultados
                        informar_resultados(num_1, num_2, resultado_suma, resultado_resta, resultado_multiplicacion, resultado_division, resultado_factorial_1, resultado_factorial_2);

                        //Llama a la funcion para resetrar las banderas
                        resetear_flags(&flag_calculos);
                        resetear_flags(&flag_primer_operando);
                        resetear_flags(&flag_segundo_operando);
                    }
                    else //Validacion de realizacion de calculos
                    {
                        printf("***Primero se deben realizar los calculos***\n\n");
                        system("color 4F"); //Cambia el color a la consola a rojo cuando se produce un error
                    }
                }
                else //Validacion de ingreso de los operandos
                {
                    printf("***Primero se deben ingresar los operandos***\n\n");
                    system("color 4F"); //Cambia el color a la consola a rojo cuando se produce un error
                }
                system("pause"); //Pausa la consola
                break;
            case 5:
                respuesta = 'n'; //Pone a respuesta en otro valor que no sea 's' para salir del menu
                break;
            default:
                system("cls"); //Limpia la consola
                printf("***No es una opcion valida***\n\n"); //Muestra cuando no se ingresa alguna opcion valida
                system("color 4F"); //Cambia el color a la consola a rojo cuando se produce un error
                fflush(stdin);
                system("pause"); //Pausa la consola
        }
    }while(respuesta == 's'); //Repite si es 's', sale si es cualquier otro valor

    system("cls"); //Limpia la consola
    printf("*****Gracias por operar, hasta luego*****\n\n");

    return 0;
}
