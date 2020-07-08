#include <stdio.h>
#include <stdlib.h>
#include "prototipos.h"

//Funcion para mostrar los resultados
void informar_resultados(int num_1, int num_2, int resultado_suma, int resultado_resta, int resultado_multiplicacion, int resultado_division, int resultado_factorial_1, int resultado_factorial_2)
{
    printf("El resultado de %d + %d es: %d\n\n", num_1, num_2, resultado_suma); //Mensaje que muestra la suma
    printf("El resultado de %d - %d es: %d\n\n", num_1, num_2, resultado_resta); //Mensaje que muestra la resta
    printf("El resultado de %d * %d es: %d\n\n", num_1, num_2, resultado_multiplicacion); //Mensaje que muestra la multiplicacion

    if(num_2 == 0) //Valida que el divisor no sea 0
        {
            //Si el segundo operando es 0 entra al if

            printf("No es posible dividir por cero\n\n"); //Mensaje que muestra el error de division por 0
        }
        else
        {
            //Si el segundo operando no es 0 entra al else

            printf("El resultado de %d / %d es: %d\n\n", num_1, num_2, resultado_division); //Mensaje que muestra la division
        }

     if(num_1 == 0 && num_2 == 0) //Valida que los operandos no sean 0
     {
         //Si los operandos son 0 entra al if

         /*
             Segun mi criterio el factorial de 0 es 1
             Si desea cambiar eso descomente la linea 37
             y comente la linea 36
             de esa forma el factorial de 0 valdra 0
         */

         printf("El factorial de %d es: 1 y el factorial de %d es: 1\n\n", num_1, num_2); //Mensaje que muestra !0 = 1
         //printf("El factorial de %d es: 0 y el factorial de %d es: 0\n\n", num_1, num_2); //Mensaje que muestra !0 = 0
     }
     else
     {
         //Si los operandos no son 0 entra al else

         if(num_1 < 0 && num_2 < 0) //Valida que los operandos no sean negativos
         {
             //Si los operandos son negativos entra al if

             printf("No es posible obtener el factorial de un numero negativo\n\n"); //Mensaje que muestra el error de la factorizacion
         }
         else
         {
             //Si los operandos no son negativos entra al else

             if(num_1 > 0 && num_2 < 0) //Valida que el segundo operando no sea negativo
             {
                 //Si el segundo operando es negativo entra al if

                 printf("El factorial del 1er operando (%d) es: %d\n\n", num_1, resultado_factorial_1); //Mensaje que muestra la factorizacion del primer operando
                 printf("No se puede obtener el factorial del 2do operando (%d) porque es negativo\n\n", num_2); //Mensaje que muestra el error de la factorizacion
             }
             else //Valida que el segundo operando no sea negativo
             {
                 //Si el segundo operando no es negativo entra al else

                 if(num_1 < 0 && num_2 > 0) //Valida que el primer operando no sea negativo
                 {
                     //Si el primer operando es negativo entra al if

                     printf("No se puede obtener el factorial del 1er operando (%d) porque es negativo\n\n", num_1); //Mensaje que muestra el error de la factorizacion
                     printf("El factorial del 2do operando (%d) es: %d\n\n", num_2, resultado_factorial_2); //Mensaje que muestra la factorizacion del segundo operando
                 }
                 else //Valida que el primer operando no sea negativo
                 {
                     //Si el primer operando es negativo entra al else

                     //Significa que los dos son positivos

                     printf("El factorial de %d es: %d y el factorial de %d es: %d\n\n", num_1, resultado_factorial_1, num_2, resultado_factorial_2); //Mensaje que muestra la factorizacion
                 }
             }
         }
     }
}
