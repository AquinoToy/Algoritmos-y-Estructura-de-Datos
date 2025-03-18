/*
IMPLEMENTACION DEL MODELO DEL MINIMO COMUN MULTIPLO
AUTOR: Omar Ivan Salinas Aquino
VERSION: 1

DESCRIPCION: RECURSIVIDAD
Una funcion que se define en terminos de si misma, y que utiliza una o mas llamadas
recursivas para llegar a una solucion.

OBSERVACIONES:

COMPILACION PARA GENERAR EL CODIGO: gcc MCM.c -o MCM
                        ./MCM
*/
// LIBRERIAS
#include <stdio.h>
#include <stdlib.h>

int GCD(int a, int b); // Protito de funcion. Recibe dos parametros de tipo entero
int LCM(int a, int b); // Protito de funcion. Recibe dos parametros de tipo entero
int main(int num_args, char *cadena_args[])
{
    if (num_args != 3)
        exit(1);
    int a, b;
    a = atoi(cadena_args[1]);
    b = atoi(cadena_args[2]);
    if (a >= 0 && b >= 0)
        printf("El minimo comun multiplo entre %d y %d es: %d", a, b, LCM(a, b));
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
/*
DESCRIPCION: Calcula el minimo comun entre los numeros enteros a y b utilizando el modelo
             recursivo del GDC.
RECIBE: Dos numeros enteros a y b.
DEVUELVE: El minimo comun multiplo de los numeros a y b.
OBSERVACIONES: No se valida que el numero ingresado n sea un valor entero, si el numero ingresado
no pertenece al conjunto de numeros enteros se producira un error.
*/
int LCM(int a, int b)
{
    return (a * b) / GCD(a, b);
}