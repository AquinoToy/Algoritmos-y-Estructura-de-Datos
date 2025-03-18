/*
IMPLEMENTACION DEL MODELO RECURSIVO DEL GCD
AUTOR: Omar Ivan Salinas Aquino
Version: 1

DESCRIPCION: RECURSIVIDAD
Una funcion que se define en terminos de si misma, y que utiliza una o mas llamadas
recursivas para llegar a una solucion.

OBSERVACIONES:

COMPILACION PARA GENERAR EL CODIGO: gcc MCD.c -o MCD
                                    /.MCD
*/
// LIBREARIAS
#include <stdio.h>
#include <stdlib.h>

int GCD(int a, int b); // Prototipo de funcion. Recibe dos parametros de tipo entero
int main(int num_args, char *cadena_args[])
{
    if (num_args != 3)
        exit(1);
    int a, b;
    a = atoi(cadena_args[1]);
    b = atoi(cadena_args[2]);
    if (a >= 0 && b >= 0)
        printf("El maximo comun divisor entre %d y %d es: %d. ", a, b, GCD(a, b));
    else
        printf("Deben ingresarse valor mayores o iguales a 0");
    return 0;
}

/*
int GDC(int a, int b);
DESCRIPCION: Calcula el maximo comun dividos entre los numeros enteros a y b.
RECIBE: Dos numeros de tipo entero.
DEVUELVE: El maximo comun divisor entre los enteros a y b.
OBSERVACIONES: No se valida que el numero ingresado n sea un valor entero, si el numero ingresado
no pertenece al conjunto de numeros enteros se producira un error.
*/
int GCD(int a, int b)
{
    if (b == 0)
        return a;
    else
        return GCD(b, a % b);
}
