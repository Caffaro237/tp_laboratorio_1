#ifndef EMPLEADOS_H_INCLUDED
#define EMPLEADOS_H_INCLUDED

/******Declaracion de estructuras******/


//Estructura del empleado
struct
{
    int id;
    char nombre[51];
    char apellido[51];
    int edad;
    float sueldo;
    int id_sector;
    int is_empty;

}typedef e_empleado;


//Estructura del sector
struct
{
    int id;
    char descripcion[20];

}typedef e_sector;


/******Declaracion de funciones******/


//Funciones para buscar
int buscar_libre(e_empleado vec[], int tam);
int buscar_empleado(int id, e_empleado vec[], int tam);


//Funciones para informar
void informar(e_empleado vec[], int tam, e_sector sectores[], int tam_sec);
void informar_empleados_que_superan(e_empleado vec[], int tam);
void informar_total_sueldos(e_empleado vec[], int tam);


//Funciones de menus
int menu();
int menu_informes();
int menu_modificacion(int indice, e_empleado vec[], int tam, e_sector sectores[], int tam_sec);


//Funciones de modificaciones
int alta_empleado(int idx, e_empleado vec[], int tam, e_sector sectores[], int tam_sec);
void baja_empleado(e_empleado vec[], int tam, e_sector sectores[], int tam_sec);
int cargar_descripcion_sector(char descripcion[], int id, e_sector sectores[], int tam);
void inicializar_empleados(e_empleado vec[], int tam);
void modificar_empleado(e_empleado vec[], int tam, e_sector sectores[], int tam_sec);
void normalizar_nombres(char name[]);


//Funciones para mostrar
void mostrar_empleado(e_empleado empleado, e_sector sectores[], int tam_sec);
void mostrar_empleados(e_empleado vec[], int tam, e_sector sectores[], int tam_sec);
void mostrar_sectores(e_sector sectores[], int tam);
void ordenar_empleados(e_empleado vec[], int tam, e_sector sectores[], int tam_sec);

//Funcion de validacion de ingresos
int validar_numero();
char validar_cadenas(int tam);

//Funcion de harcodeo
void harcodear_empleados(e_empleado vec[],int cant);


#endif // EMPLEADOS_H_INCLUDED

