#include "funciones.h"

int suma(int A, int B) //Funcion de Suma
{
    int rta;
    rta = A + B; //Suma a y b
    return rta;
}

int resta(int A, int B) //Funcion de Resta
{
    int rta;
    rta = A - B; //Resta a y b
    return rta;
}

float division(float A, float B) //Funcion de Division
{
    float rta;
    if(B != 0) //Verifica que el divisor no sea 0
    {
        rta = A / B; //Divide a por b
    }
    return rta;
}

int multiplicacion(int A, int B) //Funcion de Multiplicacion
{
    int rta;
    rta = A * B; //Multiplica a por b
    return rta;
}

int factorizacion1(int A) //Primer funcion de factorizacion
{
    int rta = 1;

    for(int i = 1; i <= A; i++) //Cuenta las veces que tiene que repetir segun el valor de a
    {
        rta = rta * i; //Factoriza a con los valores de i segun el valor de a

        /*
            Ejemplo: A = 4

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

int factorizacion2(int B) //Segunda funcion de factorizacion
{
    int rta = 1;
    for(int i = 1; i <= B; i++) //Cuenta las veces que tiene que repetir segun el valor de b
    {
        rta = rta * i; //Factoriza a con los valores de i segun el valor de b

        /*
            Ejemplo: B = 3

            i = 1
            rta = 1

            1 = 1 * 1

            i = 2
            1 = 1 * 2

            i = 3
            2 = 2 * 3

            rta = 6
        */
    }
    return rta;
}
