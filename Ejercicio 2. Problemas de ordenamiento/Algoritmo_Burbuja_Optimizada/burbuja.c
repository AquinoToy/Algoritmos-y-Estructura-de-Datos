/*
Implementacion del algoritmo de ordenamiento Burbuja
Autor: Omar Ivan Salinas Aquino
Version: 1.1 Marzo 2025

Descripcion: Programa que implementa el algoritmo de ordenamiento Burbuja
para un arreglo de numeros enteros de un tamaño determinado.

Compilacion:
Windows: gcc burbuja.c -o burbuja.exe
Linux/mac: gcc burbuja.c -o burbuja

Ejecución:
    ./burbuja {tamamio del arreglo a ordenar}  < lista_de_numeros.txt
    ./burbuja {tamamio del arreglo a ordenar} < llista_de_numeros.txt > salida.txt
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TRUE 1
#define FALSE 0

void BurbujaOptimizada(int *A, int n); // Prototipo de funcion. Recibe int * direccion del arreglo A, int n tamaño del arreglo
int main(int num_args, char *cadena_args[])
{
    // Variables para la medición de tiempos
    clock_t t_inicio, t_final;
    double t_intervalo;

    // Variables para el algoritmo
    int i, n, *A;

    // Recibir por argumento el tamaño de n
    if (num_args != 2)
    {
        printf("\nIndique el tamanio de n - Ejemplo: %s 100\n", cadena_args[0]);
        exit(1);
    }
    // Tomar el argumento del main
    n = atoi(cadena_args[1]); // n

    // Apartar memoria para n números  enteros
    A = malloc(n * sizeof(int));
    if (A == NULL)
    {
        printf("\nError al intentar reservar memoria para %d elementos\n", n);
        exit(1);
    }

    // Leer de la entrada estandar los n valores y colocarlos en el arreglo de números
    for (i = 0; i < n; i++)
        scanf("%d", &A[i]);

    // Inicia medición del tiempo
    t_inicio = clock();

    // Llamar al algoritmo
    BurbujaOptimizada(A, n);

    // Termina medición del tiempo
    t_final = clock();

    // Cálculo del tiempo y enviar mensaje a salida estandar con la medición
    t_intervalo = (double)(t_final - t_inicio) / CLOCKS_PER_SEC;
    printf("\nTiempo medido: %.10f segundos.\n", t_intervalo);

    // Enviar a la salida estandar el arreglo final
    for (i = 0; i < n; i++)
        printf("\nA[%d]=%d", i, A[i]);

    free(A);
    return 0;
}
/*
void BurbujaOptimizada(int *A, int n);
Descripcion: Ordena los elelementos de un arreglo A de tamaño n.
Recibe: int * direccion de un arreglo A, int n tamanio del arreglo.
Devuelve: void (No retorna valor explicito).
Observaciones: Funcion que ordena los valores del arreglo A de tamanio n
en razon de O(n^2)
*/

void BurbujaOptimizada(int *A, int n)
{
    int i, j, aux, cambios;
    // Inicializar variables
    cambios = TRUE;
    i = 0;
    // Se inicia el bucle que recorre todos los elementos del arreglo y verifica si hay cambios
    while (i <= (n - 2) && cambios != FALSE)
    {
        cambios = FALSE;
        // Bucle que compara elementos adyacentes del arreglo
        for (j = 0; j <= (n - 2) - i; j++)
        {
            // Condicion que compara si el elemento de la posicion [j] es menor a [j+1]
            if (A[j] > A[j + 1])
            {
                // Si se cumple la condicion intercambia los elementos del arreglo
                aux = A[j];
                A[j] = A[j + 1];
                A[j + 1] = aux;
                // Cambia la variable 'cambios' a 'si' o 'TRUE'
                cambios = TRUE;
            };
        }
        i++;
    }
}