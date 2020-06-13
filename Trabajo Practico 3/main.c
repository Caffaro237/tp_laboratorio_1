#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "Funciones.h"


int main()
{
    LinkedList* lista_empleados = ll_newLinkedList(); //Llama a la funcion para comenzar una nueva lista

    char seguir;

    seguir = 's';


    if(lista_empleados == NULL)
    {
        printf("No se pudo asignar memoria\n");
        exit(EXIT_FAILURE);
    }
    else
    {
        printf("***Bienvenido al sistema para la carga de empleados 2.0***\n");
        printf("         ***Para iniciar presione enter***\n\n");
        system("pause");
    }

    do
    {
        switch(menu()) //Llama a la funcion para mostrar la sopciones principales
        {
            case 1:
                if(controller_loadFromText("data.csv", lista_empleados)) //Llama a la funcion para cargar los datos desde un archivo de texto
                {
                    printf("Carga correcta de los empleados\n\n");
                }
                else
                {
                    printf("No se cargaron los empleados\n\n");
                }
                system("pause");
                break;

            case 2:
                if(controller_loadFromBinary("Datos.bin", lista_empleados)) //Llama a la funcion para cargar los datos desde un archivo binario
                {
                    printf("Carga correcta de los empleados\n\n");
                }
                else
                {
                    printf("No se cargaron los empleados\n\n");
                }
                system("pause");
                break;

            case 3:
                if(controller_addEmployee(lista_empleados) == -1) //Llama a la funcion para dar de alta a un nuevo empelado
                {
                    printf("No se pudo hacer el alta del empleado\n\n");
                }
                else
                {
                    printf("Alta del empleado exitosa\n\n");
                }
                system("pause");
                break;

            case 4:
                if(controller_editEmployee(lista_empleados)) //Llama a la funcion para modificar los datos de un empelado
                {
                    printf("Datos modificados\n\n");
                }
                else
                {
                    printf("No se modifico ningun dato\n\n");
                }
                system("pause");
                break;

            case 5:
                if(controller_removeEmployee(lista_empleados)) //Llama a la funcion para dar de baja a un empelado
                {
                    printf("Se ha dado de baja exitosamente\n\n");
                }
                else
                {
                    printf("No se pudo realizar la baja\n\n");
                }
                system("pause");
                break;

            case 6:
                if(!controller_ListEmployee(lista_empleados)) //Llama a la funcion para listar los empleados
                {
                    system("cls");
                    printf("Error al mostrar los empleados\n\n");
                }
                system("pause");
                break;

            case 7:
                if(!controller_sortEmployee(lista_empleados)) //Llama a la funcion para ordenar los empleados segun lo que se elija
                {
                    system("cls");
                    printf("No se ordenaron los empleados\n\n");
                }
                system("pause");
                break;

            case 8:
                printf("Carga empleados .csv\n");
                if(controller_saveAsText("datos.csv", lista_empleados)) //Llama a la funcion para escribir los datos a un archivo de texto
                {
                    printf("Empelados cargados\n");
                }
                else
                {
                    printf("Empelados no cargados\n");
                }
                system("pause");
                break;

            case 9:
                printf("Guardar los datos de los empleados en el archivo data.bin (modo binario)\n");
                if(controller_saveAsBinary("datos.bin", lista_empleados)) //Llama a la funcion para escribir los datos a un archivo binario
                {
                    printf("Empelados cargados\n");
                }
                else
                {
                    printf("Empelados no cargados\n");
                }
                system("pause");
                break;
            case 10:
                system("cls");
                printf("        Saliendo del programa\n");
                printf("   Gracias por operar con nosotros\n");
                printf("Presione enter para cerrar la consola\n\n");

                seguir = 'n';
                break;
            default:
                printf("Opcion invalida\n");
        }

    }while(seguir == 's');

    return 0;
}
