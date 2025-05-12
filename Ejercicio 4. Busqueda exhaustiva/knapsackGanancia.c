/*
Implementacion del algorimto de knapsack como ejercicio de busqueda exhaustiva
Autor: Omar Ivan Salinas Aquino Abril 2025
Version: 1.0

Descripcion: Programa que implementa el algoritmo knapsack 0-1 por busqueda exhaustiva
regresá la maxima ganancia posible sin sobrepasar el peso de la mochila y el listado de objetos que se deben
seleccionar para obtener la ganancia maxima.

Compilacion:
Windows: gcc knapsackGanancia.c -o knapsackGanancia.exe
Linux/Mac: gcc knapsackGanancia.c -o knapsackGanancia

Ejecucion:
    ./knapsackGanancia {peso maximo de la mochila} {numero de objetos} < lista_de_objetos.txt
    ./knapsackGanancia {peso maximo de la mochila} {numero de objetos} < lista_de_objetos.txt > salida.txt

*/

#include <stdio.h>
#include <stdlib.h>
// int direccion del arreglo PESOS, int direccion del arreglo VALORES, int valor n numero de valores, int k capacidad de la mochila, int i objeto actual, int valorActual valor actual
int knapsackGanancia(int *PESOS, int *VALORES, int n, int i, int k, int valorActual);
int main(int num_args, char *cadena_args[])
{
    // Declaracion de variables
    int k, n, *PESOS, *VALORES, i, ValorMaximo;

    // Recibir por argumento el tamanio de n y el valor a buscar
    if (num_args != 3)
    {
        printf("\nIndique el peso maximo de la mochila y la cantidad de elementos - Ejemplo: %s K n < datos.txt\n", cadena_args[0]);
        exit(1);
    }

    // Tomar el tamanio k maximo de la mochila por los argumentos del main
    k = atoi(cadena_args[1]);
    // Tomar el numero de elementos por los argumentos del main
    n = atoi(cadena_args[2]);

    // Apartar espacio de memoria para PESOS y VALORES
    PESOS = malloc(n * sizeof(int));
    VALORES = malloc(n * sizeof(int));

    // Verificar si la asignación de memoria fue exitosa
    if (PESOS == NULL || VALORES == NULL)
    {
        printf("Error: No se pudo asignar memoria\n");
        exit(1);
    }
    // Leer la entre de n pesos y valores desde la entrada estándar y colocarlos en un arreglo
    for (i = 0; i < n; i++)
        scanf("%d", &PESOS[i]);
    for (i = 0; i < n; i++)
        scanf("%d", &VALORES[i]);

    // Mostrar datos de entrada
    printf("\nDatos de entrada:\n");
    printf("Capacidad de peso de la mochila (K): %d\n", k);
    printf("Cantidad de elementos (n): %d\n", n);
    printf("Objeto \t (peso,valor) \n");
    for (i = 0; i < n; i++)
        printf("%d \t (%d, %d)\n", i + 1, PESOS[i], VALORES[i]);
    printf("\n");

    // Llamamos a la función para resolver el problema de la mochila
    ValorMaximo = knapsackGanancia(PESOS, VALORES, n, 0, k, 0);
    printf("\nLa maxima ganancia posible es: %d\n", ValorMaximo);

    // Liberar memoria de los arreglos
    free(PESOS);
    free(VALORES);

    return 0;
}
/*
int knapsackGanancia(int *PESOS, int *VALORES, int n, int i, int k, int valorActual);
Descripcion: Funcion que resuelve el problema de la mochila entera
Recibe: // int direccion del arreglo PESOS, int direccion del arreglo VALORES, int valor n numero de valores,
        int i objeto actual, int k capacidad de la mochila, int valorActual valor actual
Devuelve: int (valor entero)
Observaciones: Resuelve el problema de la mochila entera en complejidad O(2^n)
*/
int knapsackGanancia(int *PESOS, int *VALORES, int n, int i, int k, int valorActual)
{
    int valorIncluido, valorExcluido;
    // Caso base: si ya hemos considerado todos los objetos
    if (i == n)
        return valorActual;

    // Si el objeto actual no cabe en la mochila, lo excluimos
    if (PESOS[i] > k)
        return knapsackGanancia(PESOS, VALORES, n, i + 1, k, valorActual);

    // Incluir el objeto actual
    valorIncluido = knapsackGanancia(PESOS, VALORES, n, i + 1, k - PESOS[i], valorActual + VALORES[i]);
    // Excluir el objeto actual
    valorExcluido = knapsackGanancia(PESOS, VALORES, n, i + 1, k, valorActual);

    // Devolvemos el mayor valor entre las dos opciones
    if (valorExcluido > valorIncluido)
        return valorExcluido;
    else
        return valorIncluido;
}