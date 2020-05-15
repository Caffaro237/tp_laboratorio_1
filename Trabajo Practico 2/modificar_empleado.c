#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "empleados.h"

void modificar_empleado(e_empleado vec[], int tam, e_sector sectores[], int tam_sec)
{
    //Declaracion de variables
    int id;
    int indice;
    char confirma;
    char nuevo_nombre[51];
    char nuevo_apellido[51];
    float nuevo_sueldo;
    int nuevo_sector;
    char seguir;

    //Inicializacion de variables
    seguir = 's';

    system("cls"); //Limpia la consola

    printf("*** Modificar empleado ***\n");
    printf("Ingrese ID: ");
    id = validar_numero(); //Se ingresa el ID del empleado a modificar y se valida para que no sea una letra

    indice = buscar_empleado(id, vec, tam); //Verifica que el ID ingresado corresponda a un empleado

    if(indice == -1) //Pregunta si existe o no un empleado con ese ID
    {
        //En el caso de que el ID ingresado no corresponda a un empleado muestra este mensaje
        system("color 4F"); //Cambia a color rojo la consola cuando se produce un error

        printf("No hay registro de un empleado con el id %d\n\n", id);
    }
    else
    {
        //En el caso de que el ID ingresado si corresponda a un empleado entra al menu de modificacion

        do //Estructura repetitiva
        {
            switch(menu_modificacion(indice, vec, tam, sectores, tam_sec))
            {
                case 'a':
                    printf("Ingrese nuevo nombre: ");
                    fgets(nuevo_nombre, 51, stdin);
                    strcpy(vec[indice].nombre, nuevo_nombre); //Se ingresa el nuevo nombre

                    system("color 60"); //Cambia a color verde la consola cuando se realiza una acion exitosamente

                    printf("Se ha actualizado el nombre con exito\n\n");

                    system("pause"); //Pausa la consola
                    break;

                case 'b':
                    printf("Ingrese nuevo apellido: ");
                    fgets(nuevo_apellido, 51, stdin);
                    strcpy(vec[indice].apellido, nuevo_apellido); //Se ingresa el nuevo apellido

                    system("color 60"); //Cambia a color verde la consola cuando se realiza una acion exitosamente

                    printf("Se ha actualizado el apellido con exito\n\n");

                    system("pause"); //Pausa la consola
                    break;

                case 'c':
                    printf("Ingrese nuevo sueldo: ");
                    scanf("%f", &nuevo_sueldo);
                    vec[indice].sueldo = nuevo_sueldo; //Se ingresa el nuevo sueldo

                    system("color 60"); //Cambia a color verde la consola cuando se realiza una acion exitosamente

                    printf("Se ha actualizado el sueldo con exito\n\n");

                    system("pause"); //Pausa la consola
                    break;

                case 'd':
                    mostrar_sectores(sectores, tam_sec); //Llama a la duncion para mostrar la lista de sectores

                    printf("Ingrese nuevo sector: ");
                    scanf("%d", &nuevo_sector);
                    vec[indice].id_sector = nuevo_sector; //Se ingresa el nuevo sector

                    printf("Se ha actualizado el sector con exito\n\n");

                    system("color 60"); //Cambia a color verde la consola cuando se realiza una acion exitosamente
                    system("pause"); //Pausa la consola
                    break;

                case 'e':
                    //Confirma la salida
                    printf("Confirma salir? s/n: ");
                    fflush(stdin);
                    scanf("%c", &confirma);

                    if(confirma == 's')
                    {
                        seguir = 'n';
                    }
                    printf("Saliendo del menu de modificacion\n\n");
                    break;

                default:
                    system("cls"); //Limpia la consola
                    system("color 4F"); //Cambia a color rojo la consola cuando se produce un error

                    printf("*****Opcion invalida*****\n");

                    system("pause"); //Pausa la consola
            }

        }while(seguir == 's'); //Si seguir es igual a 's' sigue repitiendo
    }
}


