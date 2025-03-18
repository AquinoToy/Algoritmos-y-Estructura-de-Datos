/*
IMPLEMENTACION RECURSIVA DE LA FUNCION FACTORIAL
AUTOR: OMAR IVAN SALINAS AQUINO
VERSION: 1

DESCRIPCION: RECURSIVIDAD
Una funcion que se define en terminos de si misma, y que utiliza una o mas llamadas
recursivas para llegar a una solucion.

OBSERVACIONES:

COMPILACION PARA GENERAR EL CODIGO: gcc factorial.c -o factorial
                                  ./factorial
*/
// LIBRERIAS
#include <stdio.h>
#include <stdlib.h>

int factorial(int n); // Protipo de funcion, recibe un parametro de tipo entero
int main(int num_args, char *cadena_args[])
{
    if (num_args != 2)
        exit(1);
    int n;
    n = atoi(cadena_args[1]);
    if (n >= 0)
        printf("El resultado de %d! es: %d. ", n, factorial(n));
    else
        printf("El factorial de %d (%d!) no esta definido en los numeros naturales. ", n, n);
    return 0;
}
/*
int factorial(int n);
DESCRIPCION: Funcion factorial (Producto de todos los numeros enteros positivos entre n y 1)
RECIBE: Un valor entero n
DEVUELVE: El resultado de la funcion factorial
OBSERVACIONES: No se valida que el numero ingresado n sea un valor entero, si el numero ingresado
no pertenece al conjunto de numeros enteros se producira un error.
*/
int factorial(int n)
{
    if (n == 0)
        return 1;
    else if (n == 1)
        return n;
    else
        return n * factorial(n - 1);
}