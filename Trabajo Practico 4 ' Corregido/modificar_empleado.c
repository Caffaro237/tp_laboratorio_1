#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "LinkedList.h"
#include "prototipos.h"

int modificar_empleado(LinkedList* lista)
{
    //Funcion para editar un empleado
    int id;
    int idx;
    int ok;
    char seguir;

    char nombre[20];
    char apellido[20];
    char sexo;
    float sueldo;

    seguir = 's';
    ok = 0;

    system("cls");

    printf("Modificador de empleados\n\n");
    printf("Ingrese el ID: "); //Ingreso del ID
    fflush(stdin);
    scanf("%d", &id);
    id = validar_id(id); //Llama a la funcion para validar que no sea negativo

    idx = id - 1;

    e_empleado* empleado;

    empleado = (e_empleado*) ll_get(lista, idx); //Obtiene la informacion del empleado que se ingreso el ID

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

                    if(empleado_set_nombre(empleado, nombre)) //Llama a la funcion para setear el nuevo nombre
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
                    printf("Ingrese el nuevo apellido: "); //Ingreso del apellido
                    fflush(stdin);
                    fgets(apellido, 20, stdin);
                    apellido[strlen(apellido) - 1] = '\0'; //Elimina el \n de el fgets
                    normalizar_nombres(apellido); //Llama a la funcion para normalizar el apellido si se ingreso mal

                    if(empleado_set_apellido(empleado, apellido)) //Llama a la funcion para setear el nuevo apellido
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

                case 'c':
                    system("cls"); //Limpia la consola
                    printf("Ingrese el nuevo genero: "); //Ingreso del sexo
                    fflush(stdin);
                    scanf("%c", &sexo);
                    sexo = validar_genero(sexo); //Llama a la funcion para validar que sea solo F o M

                    if(empleado_set_sexo(empleado, sexo)) //Llama a la funcion para setear el nuevo sexo
                    {
                        printf("Genero modificado con exito\n");
                        ok = 1;
                    }
                    else
                    {
                        printf("No se pudo modificar el genero\n");
                    }
                    system("pause");
                    break;

                case 'd':
                    system("cls");
                    printf("Ingrese el nuevo sueldo: "); //Ingreso del sueldo
                    fflush(stdin);
                    scanf("%f", &sueldo);
                    sueldo = validar_sueldo(sueldo);

                    if(empleado_set_sueldo(empleado, sueldo)) //Llama a la funcion para setear el nuevo sueldo
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

                case 'e':
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
