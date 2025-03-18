/*
CALCULAR EL VALOR DE RAIZ DE X EMPLEANDO UNA DEFINICION RECURRENTE
AUTOR: Omar Ivan Salinas Aquino
Version: 1

DESCRIPCION: RECURSIVIDAD
Una funcion que se define en terminos de si misma, y que utiliza una o mas llamadas
recursivas para llegar a una solucion.

OBSERVACIONES:

COMPILACION PARA GENERAR EL CODIGO: gcc raizX.c -o raizX
                                    ./raizX
*/
// LIBRERIAS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float raizX(int x, int n, int i); // Prototipo de funcion. Recibe dos parametros de tipo entero
int main(int num_args, char *cadena_args[])
{
    int x, n, i;
    x = atoi(cadena_args[1]);
    n = atoi(cadena_args[2]);
    i = 0;
    printf("El valor aproximado de la raiz de %d con %d iteraciones es: %.10lf", x, n, raizX(x, n, i));
    printf("\nEl porcentaje de aproximación es: %.2lf. ", (100 * raizX(x, n, i)) / sqrt(x));
    return 0;
}
/*float raizX(int x, int n, int i)
DESCRIPCION: Calcula el valor aproximado de la raiz de un numero x con n iteraciones.
RECIBE: Dos valores enteros x y n.
DEVUELVE: El valor aproximado de la raiz de x.
OBSERVACIONES: No se valida que el numero ingresado n sea un valor entero, si el numero ingresado
no pertenece al conjunto de numeros enteros se producira un error.
*/
float raizX(int x, int n, int i)
{
    if (i == n)
        return 0;
    else
        return 1 + (x - 1) / (1 + raizX(x, n, i + 1));
}