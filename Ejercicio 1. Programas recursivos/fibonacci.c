/*
IMPLEMENTACION RECURSIVA DE LA SERIE DE FIBONNACI
AUTOR: Omar Ivan Salinas Aquino
VERSION: 1

DESCRIPCION: RECURSIVIDAD
Una funcion que se define en terminos de si misma, y que utiliza una o mas llamadas
recursivas para llegar a una solucion.

OBSERVACIONES:

COMPILACION PARA GENERAR EL CODIGO: gcc fibonacci.c -o fibonacci
                                  ./fibonacci
*/
// LIBRERIAS
#include <stdio.h>
#include <stdlib.h>

int fibonacci(int n); // Protitipo de funcion, recibe un solo paremetro de tipo entero
int main(int num_args, char *cadena_args[])
{
    if (num_args != 2)
        exit(1);
    int n;
    n = atoi(cadena_args[1]);
    if (n >= 0)
        printf("%d ", fibonacci(n));
    else
        printf("No se puede determinar el termino %d de la funcion", n);
    return 0;
}
/*
int fibonacci(int n);
DESCRIPCION: Obtiene el termino n de la funcion fibonacci (Serie donde cada numero de la sucecion
             es la suma de los dos anteriores)
RECIBE: Un valor entero n
DEVUELVE: El resultado de la funcion factorial
OBSERVACIONES: No se valida que el numero ingresado n sea un valor entero, si el numero ingresado
no pertenece al conjunto de numeros enteros se producira un error.
*/
int fibonacci(int n)
{
    if (n == 0)
        return n;
    else if (n == 1)
        return n;
    else
        return fibonacci(n - 1) + fibonacci(n - 2);
}