/*
Implementacion del algoritmo de ordenamiento rapido
Autor: Omar Ivan Salinas Aquino Marzo 2025
Version: 1.0

Descripcion: Programa que implementa un algortimo de ordanamiento por rapido
para un arreglo de numeros enteros de un tamanio determinado

Compilacion:
Windows: gcc rapido.c -o rapido.exe
Linux/Mac: gcc rapido.c -o rapido

Ejecucion:
    ./rapido {tamanio del arreglo a ordenar} < lista_de_numeros.txt
    ./rapido {tamanio del arreglo a ordenar} < lista_de_numeros.txt > salida.txt

*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void QuickSort(int *A, int p, int r);    // Prototipo de funcion. Recibe int * direccion del arreglo A, int p incio del arreglo, int r final del arreglo.
int Pivot(int *A, int p, int r);         // Prototipo de funcion. Recibe int * direccion del arreglo A, int p incio del arreglo, int r final del arreglo.
void Intercambiar(int *A, int i, int j); // int * direccion del arreglo A, int i indice de un elemento, int j indice de otro elemento.
int main(int argc, char *argv[])
{
    // Variables para la medición de tiempos
    clock_t t_inicio, t_final;
    double t_intervalo;

    // Variables para el algoritmo
    int i, p, n, *A;
    p = 0;

    // Recibir por argumento el tamanio de n
    if (argc != 2)
    {
        printf("\nIndique el tamanio de n. Ejemplo %s 100\n", argv[0]);
        exit(1);
    }
    // Tomar el tamanio de n por los argumentos del main
    n = atoi(argv[1]);

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

    // Inicia medición del tiempo
    t_inicio = clock();

    // Llamar al algoritmo
    QuickSort(A, p, n - 1);

    // Termina medición del tiempo
    t_final = clock();

    // Cálculo del tiempo y enviar mensaje a salida estandar con la medición
    t_intervalo = (double)(t_final - t_inicio) / CLOCKS_PER_SEC;
    printf("\nTiempo medido: %.10f segundos.\n", t_intervalo);

    // Enviar a la salida estandar el arreglo final
    for (i = 0; i < n; i++)
        printf("\nA[%d]=%d", i, A[i]);

    free(A); // Liberar memoria

    return 0;
}

/*
void QuickSort(int *A, int p, int r);
Descripcion: Ordena los elementos de un arreglo de tamanio n.
Recibe: int * direccion de un arreglo A, int p indice incial del arreglo, int r indice final del arreglo
Devuelve: void (No retorna valor explicito).
Observaciones: Funcion que ordena los valores del arreglo A de tamanio n
en razon de O(nlog(n)) o O(n^2)
*/
void QuickSort(int *A, int p, int r)
{
    int j;
    // Verifica que el índice inicial sea menor que el final (caso base de la recursión)
    if (p < r)
    {
        // Encontrar la posición del pivote y dividir el arreglo
        j = Pivot(A, p, r);
        // Ordenar recursivamente la primera mitad
        QuickSort(A, p, j - 1);
        // Ordenar recursivamente la segunda mitad
        QuickSort(A, j + 1, r);
    }
}
/*
int Pivot(int *A, int p, int r);
Descripcion: Encuentra el pivote y reorganiza el arreglo en torno a él.
Recibe: int * direccion de un arreglo A, int p indice incial del arreglo, int r indice final del arreglo
Devuelve: int j pivote;
Observaciones: Complejidad O(n^2)
*/
int Pivot(int *A, int p, int r)
{
    int piv, i, j;
    piv = A[p]; // Se toma el primer elemento como pivote
    i = p + 1;
    j = r;
    while (i < j)
    {
        // Avanza i hasta encontrar un elemento mayor que el pivote
        while (A[i] <= piv && i < r)
            i++;
        // Retrocede j hasta encontrar un elemento menor que el pivote
        while (A[j] > piv)
            j--;
        // Si i es menor que j, intercambia los elementos
        if (i < j)
            Intercambiar(A, j, i);
    }
    // Coloca el pivote en su posición final
    Intercambiar(A, p, j);
    return j;
}
/*
void Intercambiar(int *A, int i, int j);
Descripcion: Intercambia dos elementos en el arreglo.
Recibe: int * direccion del arreglo A, int i indice de un elemento, int j indice de otro elemento.
Devuelve: void (No retorna valor explicito).
Observaciones: Se utiliza en el algoritmo de QuickSort para reordenar elementos. Complejidad O(1);
*/
void Intercambiar(int *A, int i, int j)
{
    int temp;
    temp = A[j];
    A[j] = A[i];
    A[i] = temp;
}