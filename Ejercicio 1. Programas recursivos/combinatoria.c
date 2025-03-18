/*
IMPLEMENTACION DEL MODELO RECURSIVO DE LA COMBINATORIA
AUTOR: Omar Ivan Salinas Aquino
VERSION: 1

DESCRIPCION: RECURSIVIDAD
Una funcion que se define en terminos de si misma, y que utiliza una o mas llamadas
recursivas para llegar a una solucion.

OBSERVACIONES:

COMPILACION PARA GENERAR EL CODIGO: gcc combinatoria.c -o combinatoria
                                    ./combinatoria

*/
// LIBRERIAS
#include <stdio.h>
#include <stdlib.h>

int combinatoria(int n, int k); // Protitipo de funcion, recibe dos parametros de tipo entero
int main(int num_args, char *cadena_args[])
{
    if (num_args != 3)
        exit(1);
    int n, k;
    n = atoi(cadena_args[1]);
    k = atoi(cadena_args[2]);
    if (n >= 0 && k >= 0)
        printf("El resultado de %d en combinacion %d es: %d. ", n, k, combinatoria(n, k));
    else
        printf("La combinatoria no esta definida para numeros negativos");
    return 0;
}
/*
int combinatoria(int n, int k);
DESCRIPCION: Devuelve el resultado de n combinacion k
RECIBE: Dos valores de tipo entero n y k
DEVUELVE: El resultado de la n combinado k
OBSERVACIONES: No se valida que el numero ingresado n sea un valor entero, si el numero ingresado
no pertenece al conjunto de numeros enteros se producira un error.
*/
int combinatoria(int n, int k)
{
    if (k == 0 || k == n)
        return 1;
    else if (k > 0 && k < n)
        return combinatoria(n - 1, k - 1) + combinatoria(n - 1, k);
    else
        return 0;
}