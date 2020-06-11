#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "empleados.h"

void normalizar_nombres(char name[])
{
    strlwr(name);

    name[0] = toupper(name[0]);
}
