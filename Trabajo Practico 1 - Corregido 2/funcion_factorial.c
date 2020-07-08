#include <stdio.h>
#include <stdlib.h>
#include "prototipos.h"

int factorial_1(int a) //Funcion de Factorizacion
{
    int rta = 1;

    for(int i = 1; i <= a; i++) //Cuenta las veces que tiene que repetir segun el valor de a
    {
        rta = rta * i; //Factoriza a con los valores de i segun el valor de a

        /*
            Ejemplo: a = 4

            i = 1
            rta = 1

            1 = 1 * 1

            i = 2
            1 = 1 * 2

            i = 3
            2 = 2 * 3

            i = 4
            6 = 6 * 4

            rta = 24
        */
    }

    return rta;
}

int factorial_2(int b) //Funcion de Factorizacion
{
    int rta = 1;

    for(int i = 1; i <= b; i++) //Cuenta las veces que tiene que repetir segun el valor de a
    {
        rta = rta * i; //Factoriza a con los valores de i segun el valor de a

        /*
            Ejemplo: b = 4

            i = 1
            rta = 1

            1 = 1 * 1

            i = 2
            1 = 1 * 2

            i = 3
            2 = 2 * 3

            i = 4
            6 = 6 * 4

            rta = 24
        */
    }

    return rta;
}
