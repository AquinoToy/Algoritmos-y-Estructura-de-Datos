/*
Implementacion del algoritmo de ordenamiento Burbuja
Autor: Omar Ivan Salinas Aquino
Version: 1.0 Marzo 2025

Descripcion: Programa que implementa el algoritmo de ordenamiento Burbuja
para un arreglo de un tamaño determinado.
*/
#include <stdio.h>
#include <stdlib.h>

void BurbujaOptimizada(char A[], int n);
int main(int num_args, char *cadena_args[])
{
    int i, n, M;
    n = atoi(cadena_args[2]);
    M = malloc(sizeof(int) * n);
    for (i = 0; i < n; i++)
    {
    }
    return 0;
}
/*
void BurbujaOptimizada(char A[], int n);
Descripcion: Ordena los elelementos de un arreglo A de tamaño n.
Recibe: Un arreglo A, y el tamaño del arreglo n.
Devuelve: El arreglo A con sus elementos ordenados.
Observaciones:
*/

void BurbujaOptimizada(char A[], int n)
{
    char *cambios[0];
    int i, j, aux;
    cambios[0] = "SI";
    i = 0;
    while (i <= n - 2 && cambios[0] != "NO")
    {
        cambios[0] = "NO";
        for (j = 0; j <= (n - 2) - i; j++)
        {
            if (A[j] < A[j + 1])
            {
                aux = A[j];
                A[j] = A[j + 1];
                A[j] = aux;
                cambios[0] = "SI";
            };
        }
        i++;
    }
}