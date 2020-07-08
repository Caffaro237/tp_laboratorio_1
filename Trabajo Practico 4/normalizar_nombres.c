#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "LinkedList.h"
#include "prototipos.h"

void normalizar_nombres(char* nombre)
{
    //Funcion para normalizar el nombre si se ingresa mal
    strlwr(nombre);

    nombre[0] = toupper(nombre[0]);
}

