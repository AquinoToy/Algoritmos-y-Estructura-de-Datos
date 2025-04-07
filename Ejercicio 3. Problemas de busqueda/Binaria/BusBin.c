/*
Implementacion del algorimto de Busqueda binario en un conjunto ordenado
Autor: Omar Ivan Salinas Aquino Abril 2025
Version: 1.0

Descripcion: Programa que implementa un algoritmo de busqueda binario de forma iterativa
con un conjunto de numeros ordenados y regresá el número de comparaciones necesarias para
encontrar el numero dado.

Compilacion:
Windows: gcc BusBin.c -o BusBin.exe
Linux/Mac: gcc BusBin.c -o BusBin

Ejecucion:
    ./BusOrd {tamanio del arreglo a ordenar} {valor a buscar} < lista_de_numeros.txt
    ./BusOrd {tamanio del arreglo a ordenar} {valor a buscar} < lista_de_numeros.txt > salida.txt

*/

#include <stdio.h>
#include <stdlib.h>
// int direccion del arreglo a, int valor a buscar, int incio del arreglo, int final del arreglo, int contador
int Busqueda_binaria(int *A, int valor, int inicio, int fin, int *count);

int main(int num_args, char *cadena_args[])
{
    // Declaracion de variables
    int n, *A, i, valor, count, posicion;

    // Recibir por argumento el tamanio de n y el valor a buscar
    if (num_args != 3)
    {
        printf("\nIndique el tamaño de de arreglo n y el valor a buscar - Ejemplo: %s 1000 278 < {lista_de_numeros.txt}\n", cadena_args[0]);
        exit(1);
    }

    // Tomar el tamanio de n por los argumentos del main
    n = atoi(cadena_args[1]);
    // Tomar el valor de numero a buscar por los argumentos del main
    valor = atoi(cadena_args[2]);

    // Apartar espacio de memoria para A
    A = malloc(n * sizeof(int));
    if (A == NULL)
    {
        printf("\nError al intentar reservar memoria para %d elementos\n", n);
        exit(1);
    }

    // Leer la entreda de los n valores y colocarlos en un arreglo de numeros
    for (i = 0; i < n; i++)
        scanf("%d", &A[i]);
    // Inicar el contador de numerod e coparaciones en cero
    count = 0;

    // Llamar al agoritmo de busqueda
    posicion = Busqueda_binaria(A, valor, 0, n, &count);
    if (posicion != -1)
        printf("El valor a buscar (%d) se encuentra en la posicion: %d. \
        \n Numero de comparaciones: %d\n\n",
               valor, posicion, count);
    else
        printf("El valor a buscar (%d) no se encuentra en el arreglo.\
        \n Numero de comparaciones: %d\n\n",
               valor, count);

    // Liberar memoria del arreglo
    free(A);

    return 0;
}
/*
int Busqueda_binaria(int *A, int valor, int inicio, int fin, int *count);
Descripcion: Funcion que retorna busca un valor en un conjunto de numeros ordenados y devuelve
el numero de comparaciones para encontrarlo.
Recibe: int direccion del arreglo a, int valor a buscar, int incio del arreglo,
        int final del arreglo, int contador
Devuelve: int (valor entero)
Observaciones: Busca un valor en un arreglo desordenado en complejidad O(n)
*/
int Busqueda_binaria(int *A, int valor, int inicio, int fin, int *count)
{
    int res, mitad;
    res = -1;
    while (inicio <= fin)
    {
        mitad = (inicio + fin) / 2;
        (*count)++;
        if (valor == A[mitad])
        {
            return mitad;
        }
        else if (valor > A[mitad])
        {
            inicio = mitad + 1;
        }
        else
        {
            fin = mitad - 1;
        }
    }
    return res;
}
