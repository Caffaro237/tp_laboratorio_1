

//Prototipos de las funciones controller
int controller_loadFromText(char* nombre_archivo , LinkedList* p_array_empleados);
int controller_loadFromBinary(char* nombre_archivo , LinkedList* p_array_empleados);
int controller_addEmployee(LinkedList* p_array_empleados);
int controller_editEmployee(LinkedList* p_array_empleados);
int controller_removeEmployee(LinkedList* p_array_empleados);
int controller_ListEmployee(LinkedList* p_array_empleados);
int controller_sortEmployee(LinkedList* p_array_empleados);
int controller_saveAsText(char* nombre_archivo , LinkedList* p_array_empleados);
int controller_saveAsBinary(char* nombre_archivo , LinkedList* p_array_empleados);

