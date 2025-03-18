/*
IMPLEMENTACION DEL MODELO RECURSIVO PARA LA APROXIMACION DEL NUMERO PI
AUTOR: Omar Ivan Salinas Aquino
Version: 1

DESCRIPCION: RECURSIVIDAD
Una funcion que se define en terminos de si misma, y que utiliza una o mas llamadas
recursivas para llegar a una solucion.

OBSERVACIONES:

COMPILACION PARA GENERAR EL CODIGO: gcc Leibniz.c -o Leibniz
                                    ./Leibniz
*/
// LIBRERIAS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float serieLeibnitz(int n, int i); // Protipo de funcion. Recibe solamente un parametro de tipo entero
int main(int num_args, char *cadena_args[])
{
    if (num_args != 2)
        exit(1);
    int n, i;
    n = atoi(cadena_args[1]);
    i = 0;
    if (n >= 0)
        printf("El valor aproximado de pi de la sumatoria de %d terminos de la serie de Leibnitz es: %.20lf. ", n, 4 * serieLeibnitz(n, i));
    else
        printf("El valor ingresado debe ser un numero positivo.");
    return 0;
}
/*
int serieLeibnitz(int n);
DESCRIPCION: Calcula el valor aproximado de suma de la serie creada por Leibniz.
RECIBE: Un parametro de tipo entero:
DEVUELVE: Un valor aproximado de la suma de la serie de Leibnitz (Aproximacion al valor de Pi sobre cuatro)
OBSERVACIONES: No se valida que el numero ingresado n sea un valor entero, si el numero ingresado
no pertenece al conjunto de numeros enteros se producira un error.
*/
float serieLeibnitz(int n, int i)
{
    if (n == i)
        return 0;
    else
        return pow(-1, i) / (2 * i + 1) + serieLeibnitz(n, i + 1);
}