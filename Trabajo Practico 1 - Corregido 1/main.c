/*
Enunciado:
    Hacer una calculadora. Para ello el programa iniciará y contará con un menú de opciones:
    1. Ingresar 1er operando (A=x)
    2. Ingresar 2do operando (B=y)
    3. Calcular todas las operaciones
        a) Calcular la suma (A+B)
        b) Calcular la resta (A-B)
        c) Calcular la division (A/B)
        d) Calcular la multiplicacion (A*B)
        e) Calcular el factorial (A!)
    4. Informar resultados
        a) “El resultado de A+B es: r”
        b) “El resultado de A-B es: r”
        c) “El resultado de A/B es: r” o “No es posible dividir por cero”
        d) “El resultado de A*B es: r”
        e) “El factorial de A es: r1 y El factorial de B es: r2”
    5. Salir

    • Todas las funciones matemáticas del menú se deberán realizar en una biblioteca aparte,
    que contenga las funciones para realizar las cinco operaciones.
    • En el menú deberán aparecer los valores actuales cargados en los operandos A y B
    (donde dice “x” e “y” en el ejemplo, se debe mostrar el número cargado)
    • Deberán contemplarse los casos de error (división por cero, etc)
    • Documentar todas las funciones
*/

#include <stdio.h>
#include <stdlib.h>
#include "Funciones.h"


int main()
{
    int x;
    int y;
    int resultadoSuma;
    int resultadoResta;
    int resultadoMult;
    float resultadoDiv;
    int resultadoFact1;
    int resultadoFact2;

    printf("Ingrese un numero: "); //Imprime el mensaje para el primer numero
    scanf("%d", &x); //Escanea el ingreso del primer numero

    printf("Ingrese otro numero: "); //Imprime el mensaje para el segundo numero
    scanf("%d", &y); //Escanea el ingreso del segundo numero

    resultadoSuma = suma(x, y); //Le indica a la funcion de suma los numeros a usar
    resultadoResta = resta(x, y); //Le indica a la funcion de resta los numeros a usar
    resultadoDiv = division(x, y); //Le indica a la funcion de division los numeros a usar
    resultadoMult = multiplicacion(x, y); //Le indica a la funcion de multiplicacion los numeros a usar
    resultadoFact1 = factorizacion1(x); //Le indica a la primer funcion de factorizacion los numeros a usar
    resultadoFact2 = factorizacion2(y); //Le indica a la segunda funcion de factorizacion los numeros a usar


    printf("\nEl resultado de A+B es: %d \n", resultadoSuma); //Imprime el resultado de la suma
    printf("El resultado de A-B es: %d \n", resultadoResta); //Imprime el resultado de la resta

    if(y != 0) //Verifica que el ingreso de y no sea 0
    {
        printf("El resultado de A/B es: %.2f \n", resultadoDiv); //Imprime el resultado de la division con 2 decimales
    }
    else
    {
        printf("No es posible dividir por cero\n"); //En caso de ser 0 imprime el error
    }

    printf("El resultado de A*B es: %d \n", resultadoMult); //Imprime el resultado de la multiplicacion
    printf("El factorial de A es: %d y El factorial de B es: %d \n", resultadoFact1, resultadoFact2); //Imprime el resultado de las factorizaciones


    return 0;
}
