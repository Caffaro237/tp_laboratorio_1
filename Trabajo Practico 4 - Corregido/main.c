#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "LinkedList.h"
#include "prototipos.h"


int main()
{
    LinkedList* lista_empleados = ll_nueva_linkedlist(); //Llama a la funcion para comenzar una nueva lista
    LinkedList* lista_filtrada = NULL;

    char seguir;
    int bandera_carga;
    int cant_empleados;

    seguir = 's';
    bandera_carga = 0;
    cant_empleados = 0;

    if(lista_empleados == NULL)
    {
        printf("No se pudo asignar espacio de memoria\n");
        exit(EXIT_FAILURE);
    }

    do
    {
        switch(menu()) //Llama a la funcion para mostrar la sopciones principales
        {
            case 1:
                system("cls");

                if(!bandera_carga)
                {
                    if(cargar_empleados_csv("empleados.csv", lista_empleados, cant_empleados))
                    {
                        cant_empleados = cant_empleados + ll_len(lista_empleados);
                        bandera_carga = 1;
                        printf("Carga de los empleados exitosa\n\n");
                    }
                    else
                    {
                        printf("Carga de los empleados erronea\n\n");
                    }
                }
                else
                {
                    printf("Solo se pueden cargar una vez los empleados desde el archivo\n\n");
                }

                system("pause");
                break;

            case 2:
                system("cls");

                mostrar_empleados(lista_empleados);

                system("pause");
                break;

            case 3:
                system("cls");

                if(!alta_empleado(lista_empleados, cant_empleados))
                {
                    bandera_carga = 1;
                    printf("Alta exitosa\n");
                    cant_empleados = cant_empleados + 1;
                }
                else
                {
                    printf("Alta erronea\n");
                }
                system("pause");
                break;

            case 4:
                system("cls");

                if(bandera_carga)
                {
                    if(baja_empleado(lista_empleados))
                    {
                        printf("Baja exitosa\n");
                    }
                    else
                    {
                        printf("Baja erronea\n");
                    }
                }
                else
                {
                    printf("Primero se debe realizar la carga o alta de los empleados\n\n");
                }

                system("pause");
                break;

            case 5:
                system("cls");

                if(bandera_carga)
                {
                    if(modificar_empleado(lista_empleados))
                    {
                        printf("Modificacion exitosa\n");
                    }
                    else
                    {
                        printf("Modificacion erronea\n");
                    }
                }
                else
                {
                    printf("Primero se debe realizar la carga o alta de los empleados\n\n");
                }

                system("pause");
                break;

            case 6:
                system("cls");

                if(bandera_carga)
                {
                    ll_sort(lista_empleados, comparar_nombre_empleado, 1);
                    mostrar_empleados(lista_empleados);
                }
                else
                {
                    printf("Primero se debe realizar la carga o alta de los empleados\n\n");
                }

                system("pause");
                break;

            case 7:
                system("cls");

                if(bandera_carga)
                {
                    lista_filtrada = ll_filter(lista_empleados, filtrar_por_sueldo);
                    printf("Lista filtrada con exito\n\n");
                    guardar_empleados_csv("Lista Empleados Filtrada.csv", lista_filtrada);
                }
                else
                {
                    printf("Primero se debe realizar la carga o alta de los empleados\n\n");
                }

                system("pause");
                break;

            case 8:
                system("cls");

                if(bandera_carga)
                {
                    guardar_empleados_csv("Lista Empleados Actualizada.csv", lista_empleados);
                    printf("Lista guardada con exito\n\n");
                }
                else
                {
                    printf("Primero se debe realizar la carga o alta de los empleados\n\n");
                }

                system("pause");
                break;

            case 9:
                system("cls");
                printf("    ****Saliendo del programa****\n\n\n");

                seguir = 'n';
                break;

            default:
                printf("Opcion invalida\n");
                system("pause");
        }

    }while(seguir == 's');


    return 0;
}

