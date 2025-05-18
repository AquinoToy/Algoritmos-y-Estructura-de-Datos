/*
Implementacion del algoritmo de ordenamiento por insercion
Autor: Omar Ivan Salinas Aquino Marzo 2025
Version: 1.0

Descripcion: Programa que implementa un algortimo de ordanamiento por insercion
para un arreglo de numeros enteros de un tamanio determinado

Compilacion:
Windows: gcc insercion.c -o insercion.exe
Linux/Mac: gcc insercion.c -o insercion

Ejecucion:
    ./insercion {tamanio del arreglo a ordenar} < lista_de_numeros.txt
    ./insercion {tamanio del arreglo a ordenar} < lista_de_numeros.txt > salida.txt

*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void Insercion(int *A, int n); // Prototipo de funcion. Recibe int * direccion del arreglo A, int n tamanio del arreglo.
int main(int argc, char *argv[])
{
    // Variables para la medición de tiempos
    clock_t t_inicio, t_final;
    double t_intervalo;

    // Variables para el algoritmo
    int i, n, *A;

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
    Insercion(A, n);

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
void Insercion(int *A, int n);
Descripcion: Ordena los elementos de un arreglo de tamanio n.
Recibe: int * direccion de un arreglo A, int n tamanio del arreglo.
Devuelve: void (No retorna valor explicito).
Observaciones: Observaciones: Funcion que ordena los valores del arreglo A de tamanio n
en razon de O(n^2)
*/
void Insercion(int *A, int n)
{
    // Declaración de variables
    int i, j, temp;
    // Recorre el arreglo desde el primer hasta el último elemento
    for (i = 0; i <= (n - 1); i++)
    {
        // Se almacena el valor actual en una variable temporal
        j = i;
        temp = A[i];
        // Desplaza los elementos mayores hacia la derecha para insertar el valor actual en la posición correcta
        while (j > 0 && temp < A[j - 1])
        {
            A[j] = A[j - 1];
            j--;
        }
        // Inserta el valor almacenado en la posición correcta
        A[j] = temp;
    }
}
