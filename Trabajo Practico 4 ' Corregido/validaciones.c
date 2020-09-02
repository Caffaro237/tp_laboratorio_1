#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "LinkedList.h"
#include "prototipos.h"

char validar_genero(char sexo)
{
    while(sexo != 'M' && sexo != 'F')
    {
        printf("Error, sexo invalido. Reingrese el sexo: ");
        fflush(stdin);
        scanf("%c", &sexo);
    }

    return sexo;
}

float validar_sueldo(float numero)
{
    //Funcion para validar que un numero no sea negativo
    while(numero < 0)
    {
        printf("Error, numero negativo. Reingrese el sueldo: ");
        fflush(stdin);
        scanf("%f", &numero);
    }

    return numero;
}

int validar_id(int numero)
{
    //Funcion para validar que un numero no sea negativo
    while(numero < 0)
    {
        printf("Error, numero negativo. Reingrese el id: ");
        fflush(stdin);
        scanf("%d", &numero);
    }

    return numero;
}
