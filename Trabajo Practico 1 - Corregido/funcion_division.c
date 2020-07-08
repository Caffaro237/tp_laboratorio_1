#include <stdio.h>
#include <stdlib.h>
#include "prototipos.h"

int division(int a, int b) //Funcion de Division
{
    int rta;
    if(b != 0) //Verifica que el divisor no sea 0
    {
        rta = a / b; //Divide a por b
    }
    return rta;
}
