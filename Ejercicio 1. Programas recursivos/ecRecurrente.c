/*
Implementacion de una ecuacion recurrente
Autor: Omar Ivan Salinas Aquino
Version: 1

Forma de ejecuion del codigo: gcc ecRecurrente.c -o ecRecurrente
                              ./ecRecurrente n

*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int ecRecurrente(int n); // Recibe un parametro de tipo entero
int main(int num_args, char *cadena_args[])
{
    if (num_args != 2)
        exit(1);
    int n;
    n = atoi(cadena_args[1]);
    if (n >= 0)
        printf("El termino %d de la funcion recurrente es: %d ", n, ecRecurrente(n));
    else
        printf("El numero ingresado debe ser mayor o igual a 0. ");
    return 0;
}

/*
int ecRecurrente(int n);
DESCRIPCION: Devuelve el valor de a en el n termino.
RECIBE: Un valor de tipo entero.
DEVUELVE: Un valor de tipo entero.
OBSERVACIONES: No valida que el dato ingresado sea de tipo entero, si se
ingresa un numero que no pertenezca al conjunto de los numeros enteros podria generar
un error.
*/
int ecRecurrente(int n)
{
    if (n == 0)
        return 1;
    else
        return ecRecurrente(n - 1) + pow(2, n);
}