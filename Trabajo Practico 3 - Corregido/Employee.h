#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED


//Declaracion de la estructura de los empleados
struct
{
    int id;
    char nombre[128];
    int horas_trabajadas;
    float sueldo;

}typedef e_empleado;


//Prototipos de las funciones para la carga empleados
e_empleado* employee_new();
e_empleado* employee_newParametros(char* id_str, char* nombre_str, char* horas_trabajadas_str, char* sueldo_str);
void employee_delete();


//Prototipos de las funciones SET
int employee_setId(e_empleado* empleado, int id);
int employee_setNombre(e_empleado* empleado, char* nombre);
int employee_setHorasTrabajadas(e_empleado* empleado, int horas_trabajadas);
int employee_setSueldo(e_empleado* empleado, float sueldo);


//Prototipos de las funciones GET
int employee_getId(e_empleado* empleado, int* id);
int employee_getNombre(e_empleado* empleado, char* nombre);
int employee_getHorasTrabajadas(e_empleado* empleado, int* horas_trabajadas);
int employee_getSueldo(e_empleado* empleado, float* sueldo);


//Prototipos de las funciones de comparacion
int comparar_id_empleado(void* a, void* b);
int comparar_nombre_empleado(void* a, void* b);
int comparar_horas_empleado(void* a, void* b);
int comparar_sueldo_empleado(void* a, void* b);


#endif // employee_H_INCLUDED
