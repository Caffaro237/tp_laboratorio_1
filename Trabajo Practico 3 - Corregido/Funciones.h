#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

#include "LinkedList.h"
#include "Employee.h"


//Prototipos de las funciones de menus
int menu();
int menu_modificacion(e_empleado* empleado);
int menu_orden();
int mayor_o_menor();


//Prototipos de las funciones mostrar
int mostrar_empleados(LinkedList* lista);
int mostrar_empleado_p(e_empleado* empleado);


//Prototipos de las funciones de validacion
void normalizar_nombres(char* cadena);
int validar_negativos(int numero);


#endif // FUNCIONES_H_INCLUDED
