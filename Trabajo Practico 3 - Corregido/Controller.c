#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "Funciones.h"


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param recibe el nombre del archivo de texto (nombre_archivo char*)
 * \param recibe un puntero a la lista de los empleados (p_array_empleados LinkedList*)
 * \return retorna 1 si se pudo, o 0 si no se pudieron cargar
 *
 */
int controller_loadFromText(char* nombre_archivo , LinkedList* p_array_empleados)
{
    //Funcion para cargar los empleados de un archivo de texto
    FILE* f;
    int ok;

    f = fopen(nombre_archivo, "r"); //Abre el archivo en modo lectura de texto
    ok = 0;

    if(f != NULL)
    {
        if(parser_EmployeeFromText(f, p_array_empleados)) //Llama a la funcion para parsear los datos de los empleados
        {
            ok = 1;
        }
    }
    else
    {
        printf("No se pudo abrir el archivo\n");
    }

    fclose(f); //Cierra el archivo

    return ok;
}


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param recibe el nombre del archivo binario (nombre_archivo char*)
 * \param recibe un puntero a la lista de los empleados (p_array_empleados LinkedList*)
 * \return retorna 1 si se pudo, o 0 si no se pudieron cargar
 *
 */
int controller_loadFromBinary(char* nombre_archivo , LinkedList* p_array_empleados)
{
    //Funcion para cargar los empleados de un archivo binario
    FILE* f;
    int ok;

    f = fopen(nombre_archivo, "rb"); //Abre el archivo en modo lectura binaria
    ok = 0;

    if(f != NULL)
    {
        if(parser_EmployeeFromBinary(f, p_array_empleados)) //Llama a la funcion para parsear los datos de los empleados
        {
            ok = 1;
        }
    }
    else
    {
        printf("No se pudo abrir el archivo\n");
    }

    fclose(f); //Cierra el archivo

    return ok;
}


/** \brief Alta de empleados
 *
 * \param recibe un puntero a la lista de los empleados (p_array_empleados LinkedList*)
 * \return retorna 0 si se pudo, o -1 si no se pudo dar el alta
 *
 */
int controller_addEmployee(LinkedList* p_array_empleados)
{
    //Funcion para dar de alta un empleado
    system("cls");

    printf("Alta de empleado\n");

    e_empleado* nuevo_empleado;

    int ok;
    int id;
    char nombre[20];
    int horas_trabajadas;
    float sueldo;
    char id_str[10];
    char horas_trabajadas_str[10];
    char sueldo_str[10];

    ok = 0;

    printf("Ingrese ID: "); //Ingreso del ID
    fflush(stdin);
    scanf("%d", &id);
    id = validar_negativos(id); //Llama a la funcion para validar que no sea negativo

    system("cls");
    printf("Ingrese nombre: "); //Ingreso del nombre
    fflush(stdin);
    fgets(nombre, 20, stdin); //Se ingresa el nombre
    nombre[strlen(nombre) - 1] = '\0'; //Elimina el \n de el fgets
    normalizar_nombres(nombre); //Llama a la funcion para normalizar el nombre si se ingreso mal

    system("cls");
    printf("Ingrese horas trabajadas: "); //Ingreso de las horas trabajadas
    fflush(stdin);
    scanf("%d", &horas_trabajadas);
    horas_trabajadas = validar_negativos(horas_trabajadas); //Llama a la funcion para validar que no sea negativo

    system("cls");
    printf("Ingrese sueldo: "); //Ingreso del sueldo
    fflush(stdin);
    scanf("%f", &sueldo);

    //Lo valida para que no sea negativo
    while(sueldo < 0)
    {
        printf("Error, numero negativo. Reingrese la opcion: ");
        fflush(stdin);
        scanf("%f", &sueldo);
    }

    itoa(id, id_str, 10); //Lo convierte de int a char
    itoa(horas_trabajadas, horas_trabajadas_str, 10); //Lo convierte de int a char
    snprintf(sueldo_str, sizeof(sueldo_str), "%f", sueldo); //Lo convierte de float a char

    nuevo_empleado = employee_newParametros(id_str, nombre, horas_trabajadas_str, sueldo_str); //Llama a la funcion para asignarle memoria

    ok = ll_add(p_array_empleados, nuevo_empleado); //Llama a la funcion para realizar la carga

    return ok;
}


/** \brief Modificar datos de empleado
 *
 * \param recibe un puntero a la lista de los empleados (p_array_empleados LinkedList*)
 * \return retorna 1 si se pudo, o 0 si no se pudo modificar
 *
 */
int controller_editEmployee(LinkedList* p_array_empleados)
{
    //Funcion para editar un empleado
    int id;
    int idx;
    int ok;
    char seguir;

    char nombre[20];
    int horas;
    float sueldo;

    seguir = 's';
    ok = 0;

    system("cls");

    printf("Modificador de empleados\n\n");
    printf("Ingrese el ID: "); //Ingreso del ID
    fflush(stdin);
    scanf("%d", &id);
    id = validar_negativos(id); //Llama a la funcion para validar que no sea negativo

    idx = id - 1;

    e_empleado* empleado;

    empleado = (e_empleado*) ll_get(p_array_empleados, idx); //Obtiene la informacion del empleado que se ingreso el ID

    if(empleado != NULL)
    {
        do
        {
            switch(menu_modificacion(empleado))
            {
                case 'a':
                    system("cls"); //Limpia la consola
                    printf("Ingrese el nuevo nombre: "); //Ingreso del nombre
                    fflush(stdin);
                    fgets(nombre, 20, stdin);
                    nombre[strlen(nombre) - 1] = '\0'; //Elimina el \n de el fgets
                    normalizar_nombres(nombre); //Llama a la funcion para normalizar el nombre si se ingreso mal

                    if(employee_setNombre(empleado, nombre)) //Llama a la funcion para setear el nuevo nombre
                    {
                        printf("Nombre modificado con exito\n");
                        ok = 1;
                    }
                    else
                    {
                        printf("No se pudo modificar el nombre\n");
                    }
                    system("pause");
                    break;

                case 'b':
                    system("cls"); //Limpia la consola
                    printf("Ingrese las nuevas horas trabajadas: "); //Ingreso de las horas trabajadas
                    fflush(stdin);
                    scanf("%d", &horas);
                    horas = validar_negativos(horas); //Llama a la funcion para validar que no sea negativo

                    if(employee_setHorasTrabajadas(empleado, horas)) //Llama a la funcion para setear las nuevas horas trabajadas
                    {
                        printf("Horas modificadas con exito\n");
                        ok = 1;
                    }
                    else
                    {
                        printf("No se pudieron modificar las horas\n");
                    }
                    system("pause");
                    break;

                case 'c':
                    system("cls");
                    printf("Ingrese el nuevo sueldo: "); //Ingreso del sueldo
                    fflush(stdin);
                    scanf("%f", &sueldo);

                    //Lo valida para que no sea negativo
                    while(sueldo < 0)
                    {
                        printf("Error, numero negativo. Reingrese la opcion: ");
                        fflush(stdin);
                        scanf("%f", &sueldo);
                    }

                    if(employee_setSueldo(empleado, sueldo)) //Llama a la funcion para setear el nuevo sueldo
                    {
                        printf("Sueldo modificado con exito\n");
                        ok = 1;
                    }
                    else
                    {
                        printf("No se pudo modificar el sueldo\n");
                    }
                    system("pause");
                    break;

                case 'd':
                    seguir = 'n';
                    break;
                default:
                    printf("Opcion Invalida\n");
                    fflush(stdin);
            }

        }while(seguir == 's');
    }
    else
    {
        printf("\nNo se encontro un empleado con el ID: %d", id);
    }
    printf("\n");

    return ok;
}


/** \brief Baja de empleado
 *
 * \param recibe un puntero a la lista de los empleados (p_array_empleados LinkedList*)
 * \return retorna 1 si se pudo, o 0 si no se pudo eliminar
 *
 */
int controller_removeEmployee(LinkedList* p_array_empleados)
{
    int id;
    int idx;
    int ok;
    e_empleado* empleado;
    char confirma;

    ok = 0;
    confirma = 'n';

    system("cls");

    printf("Dar de baja a un empleado\n\n");
    printf("Ingrese el ID: "); //Ingreso del ID
    scanf("%d", &id);
    id = validar_negativos(id); //Llama a la funcion para validar que no sea negativo

    idx = id - 1;

    empleado = (e_empleado*) ll_get(p_array_empleados, idx); //Obtiene la informacion del empleado que se ingreso el ID

    if(empleado != NULL)
    {
        system("cls");

        printf("   *****Eliminar al empleado seleccionado*****\n");
        printf("__________________________________________________\n");
        printf("ID     Nombre      Horas trabajadas  Sueldo\n");
        printf("--------------------------------------------------\n");
        mostrar_empleado_p(empleado); //Llama la funcion para mostrar el empleado obtenido
        printf("\n");

        printf("Desea eliminar al empleado? s/n: "); //Pregunta si se desea eliminar o no
        fflush(stdin);
        scanf("%c", &confirma);

        if(confirma == 's' && !ll_remove(p_array_empleados, idx) && idx > 0) //Llama a la funcion para remover el empleado de la lista
        {
            ok = 1;
        }
        else
        {
            printf("Se cancelo la baja del empleado\n");
        }
    }
    else
    {
        printf("\nNo se encontro un empleado con el ID: %d\n", id);
    }

    printf("\n");

    return ok;
}


/** \brief Listar empleados
 *
 * \param recibe un puntero a la lista de los empleados (p_array_empleados LinkedList*)
 * \return retorna 1 si se pudo, o 0 si no se pudieron listar
 *
 */
int controller_ListEmployee(LinkedList* p_array_empleados)
{
    //Funcion para listar lo empelados
    system("cls");
    int ok;

    ok = 0;

    if(mostrar_empleados(p_array_empleados)) //Llama a la funcion para mostrar los empleados
    {
        ok = 1;
    }

    return ok;
}


/** \brief Ordenar empleados
 *
 * \param recibe un puntero a la lista de los empleados (p_array_empleados LinkedList*)
 * \return retorna 1 si se pudo, o 0 si no se pudieron ordenar
 *
 */
int controller_sortEmployee(LinkedList* p_array_empleados)
{
    //Funcion para ordenar los empleados
    char seguir;
    int mayor_menor;
    int ok;

    seguir = 's';
    ok = 0;

    do
    {
        switch(menu_orden()) //Llama a la funcion menu para mostrar las opciones
        {
            case 'a':
                mayor_menor = mayor_o_menor(); //Llama a la funcion para elegir si se quiere de mayor a menor o menor a mayor

                if(ll_sort(p_array_empleados, comparar_id_empleado, mayor_menor) == -1) //Llama a la funcion para ordenarlos por ID
                {
                    printf("Datos no ordenados\n\n");
                }
                else
                {
                    printf("Datos ordenados\n\n");
                    ok = 1;
                }
                system("pause");
                break;

            case 'b':
                mayor_menor = mayor_o_menor(); //Llama a la funcion para elegir si se quiere de A-Z o Z-A

                if(ll_sort(p_array_empleados, comparar_nombre_empleado, mayor_menor) == -1) //Llama a la funcion para ordenarlos por nombre
                {
                    printf("Datos no ordenados\n\n");
                }
                else
                {
                    printf("Datos ordenados\n\n");
                    ok = 1;
                }
                system("pause");
                break;

            case 'c':
                mayor_menor = mayor_o_menor(); //Llama a la funcion para elegir si se quiere de mayor a menor o menor a mayor

                if(ll_sort(p_array_empleados, comparar_horas_empleado, mayor_menor) == -1) //Llama a la funcion para ordenarlos por horas trabajadas
                {
                    printf("Datos no ordenados\n\n");
                }
                else
                {
                    printf("Datos ordenados\n\n");
                    ok = 1;
                }
                system("pause");
                break;

            case 'd':
                mayor_menor = mayor_o_menor(); //Llama a la funcion para elegir si se quiere de mayor a menor o menor a mayor

                if(ll_sort(p_array_empleados, comparar_sueldo_empleado, mayor_menor) == -1) //Llama a la funcion para ordenarlos por sueldo
                {
                    printf("Datos no ordenados\n\n");
                }
                else
                {
                    printf("Datos ordenados\n\n");
                    ok = 1;
                }
                system("pause");
                break;

            case 'e':
                seguir = 'n';
                break;

            default:
                printf("Opcion Invalida\n");
                fflush(stdin);
        }

    }while(seguir == 's');

    return ok;
}


/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param recibe el nombre del archivo de texto (nombre_archivo char*)
 * \param recibe un puntero a la lista de los empleados (p_array_empleados LinkedList*)
 * \return retorna 1 si se pudo, o 0 si no se pudieron guardar
 *
 */
int controller_saveAsText(char* nombre_archivo , LinkedList* p_array_empleados)
{
    //Funcion para guardar los empleados en un archivo de texto
    FILE* f;
    int ok;
    int tam;
    e_empleado* empleado;

    ok = 0;
    tam = ll_len(p_array_empleados); //Asigna el tamaño de la lista LinkedList

    f = fopen(nombre_archivo, "w"); //Abre el archivo en modo escritura de texto

    if(f != NULL)
    {
        fprintf(f, "ID, Nombre, Horas trabajadas, Sueldo\n"); //Coloca el encabezado

        for(int i = 0; i < tam; i++)
        {
            empleado = (e_empleado*) ll_get(p_array_empleados, i); //Obtiene la informacion del empleado en la posicion i

            if(empleado != NULL)
            {
                fprintf(f, "%d, %s, %d, %.2f\n", empleado->id, empleado->nombre, empleado->horas_trabajadas, empleado->sueldo); //Escribe el empleado en el archivo
                ok = 1;
            }
        }
    }
    else
    {
        printf("No se pudo abrir el archivo\n");
    }

    fclose(f); //Cierra el archivo

    return ok;
}


/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param recibe el nombre del archivo binario (nombre_archivo char*)
 * \param recibe un puntero a la lista de los empleados (p_array_empleados LinkedList*)
 * \return retorna 1 si se pudo, 0 si no se pudieron cargar
 *
 */
int controller_saveAsBinary(char* nombre_archivo , LinkedList* p_array_empleados)
{
    FILE* f;
    int ok;
    int tam;
    e_empleado* empleado;
    //char encabezado[40] = {"ID, Nombre, Horas trabajadas, Sueldo\n"};

    ok = 0;
    tam = ll_len(p_array_empleados); //Asigna el tamaño de la lista LinkedList

    f = fopen(nombre_archivo, "wb"); //Abre el archivo en modo escritura binaria

    if(f != NULL)
    {
        for(int i = 0; i < tam; i++)
        {
            empleado = (e_empleado*) ll_get(p_array_empleados, tam); //Obtiene la informacion del empleado en la posicion i

            if(empleado != NULL)
            {
                fwrite(&empleado, sizeof(e_empleado), tam, f); //Escribe el empleado en el archivo
                ok = 1;
            }
        }
    }
    else
    {
        printf("No se pudo abrir el archivo\n");
    }

    fclose(f); //Cierra el archivo

    return ok;
}

