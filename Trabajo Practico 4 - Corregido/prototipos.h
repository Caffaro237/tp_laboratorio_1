#ifndef PROTOTIPOS_H_INCLUDED
#define PROTOTIPOS_H_INCLUDED

#include "LinkedList.h"

struct
{
    int id;
    char nombre[100];
    char apellido[100];
    char sexo;
    float sueldo;
    int is_empty;

}typedef e_empleado;


//Prototipos de Funciones
int menu();
int menu_modificacion(e_empleado* empleado);
int cargar_empleados_csv(char* nombre_archivo, LinkedList* lista, int cant_empleados);
int guardar_empleados_csv(char* nombre_archivo, LinkedList* lista);
int mostrar_empleados(LinkedList* lista);
int mostrar_empleado_p(e_empleado* empleado);

int filtrar_por_sueldo(void* un_empleado);
int comparar_nombre_empleado(void* a, void* b);
void normalizar_nombres(char* nombre);
char validar_genero(char sexo);
float validar_sueldo(float numero);
int validar_id(int numero);
int alta_empleado(LinkedList* lista, int cant_empleados);
int baja_empleado(LinkedList* lista);
int modificar_empleado(LinkedList* lista);



//Prototipos de Funciones para el LinkedList
e_empleado* empleado_nuevo_parametros(char* id_str, char* nombre_str, char* apellido_str, char* sexo_str, char* sueldo_str, char* is_empty_str);
e_empleado* empleado_nuevo();

int empleado_set_id(e_empleado* empleado, int id);
int empleado_set_nombre(e_empleado* empleado, char* nombre);
int empleado_set_apellido(e_empleado* empleado, char* apellido);
int empleado_set_sexo(e_empleado* empleado, char sexo);
int empleado_set_sueldo(e_empleado* empleado, float sueldo);
int empleado_set_is_empty(e_empleado* empleado, int is_empty);

#endif // PROTOTIPOS_H_INCLUDED
