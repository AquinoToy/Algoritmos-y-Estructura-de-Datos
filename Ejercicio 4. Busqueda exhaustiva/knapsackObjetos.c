/*
Implementacion del algorimto de knapsack como ejercicio de busqueda exhaustiva
Autor: Omar Ivan Salinas Aquino Abril 2025
Version: 1.0

Descripcion: Programa que implementa el algoritmo knapsack 0-1 por busqueda exhaustiva
regresá la maxima ganancia posible y el listado de objetos para obtenerla sin sobrepasar el peso de
la mochila y el listado de objetos que se deben seleccionar para obtener la ganancia maxima.

Compilacion:
Windows: gcc kanpsackObjetos.c -o kanpsackObjetos.exe
Linux/Mac: gcc kanpsackObjetos.c -o kanpsackObjetos

Ejecucion:
    ./kanpsackObjetos {peso maximo de la mochila} {numero de objetos} < lista_de_objetos.txt
    ./kanpsackObjetos {peso maximo de la mochila} {numero de objetos} < lista_de_objetos.txt > salida.txt

*/

#include <stdio.h>
#include <stdlib.h>
// int direccion del arreglo PESOS, int direccion del arreglo VALORES, int valor n numero de valores, int k capacidad de la mochila, int i objeto actual, int valorActual valor actual,
//  int direccion arreglo solucion actual, int direccion arreglo mejor solucion, int direccion ganancia maxima
int knapsackObjetos(int *PESOS, int *VALORES, int n, int i, int k, int valorActual,
                    int *solucionActual, int *mejorSolucion, int *maxGanancia);
int main(int num_args, char *cadena_args[])
{
    // Declaracion de variables
    int k, n, *PESOS, *VALORES, i, ValorMaximo, *solucionActual, *mejorSolucion, maxGanancia;

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
    solucionActual = calloc(n, sizeof(int));
    mejorSolucion = calloc(n, sizeof(int));
    // Verificar si la asignación de memoria fue exitosa
    if (PESOS == NULL || VALORES == NULL || solucionActual == NULL || mejorSolucion == NULL)
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

    maxGanancia = 0;
    // Llamamos a la función para resolver el problema de la mochila
    ValorMaximo = knapsackObjetos(PESOS, VALORES, n, 0, k, 0, solucionActual, mejorSolucion, &maxGanancia);
    printf("\nLa maxima ganancia posible es: %d\n", ValorMaximo);
    printf("Objetos seleccionados: ");
    printf("Objeto \t (peso,valor) \n");
    for (i = 0; i < n; i++)
        if (mejorSolucion[i])
            printf("%d \t (%d, %d)\n", i + 1, PESOS[i], VALORES[i]);

    // Liberar memoria de los arreglos
    free(PESOS);
    free(VALORES);
    free(solucionActual);
    free(mejorSolucion);

    return 0;
}
/*
int knapsackObjetos(int *PESOS, int *VALORES, int n, int i, int k, int valorActual,
                     int *solucionActual, int *mejorSolucion, int *maxGanancia);Descripcion: Funcion que resuelve el problema de la mochila entera
Recibe: int direccion del arreglo PESOS, int direccion del arreglo VALORES, int valor n numero de valores, int k capacidad de la mochila, int i objeto actual,
        int valorActual valor actual, int direccion arreglo solucion actual, int direccion arreglo mejor solucion, int direccion ganancia maxima
Devuelve: int (valor entero)
Observaciones: Resuelve el problema de la mochila entera en complejidad O(2^n)
*/
int knapsackObjetos(int *PESOS, int *VALORES, int n, int i, int k, int valorActual,
                    int *solucionActual, int *mejorSolucion, int *maxGanancia)
{
    int valorIncluido, valorExcluido, j;

    // Caso base: si ya hemos considerado todos los objetos
    if (i == n)
    {
        // Si el valor actual supera la mejor ganancia encontrada, actualizamos
        if (valorActual > *maxGanancia)
        {
            *maxGanancia = valorActual;
            // Copiar la combinación actual como la mejor hasta ahora
            for (j = 0; j < n; j++)
                mejorSolucion[j] = solucionActual[j];
        }
        return valorActual;
    }

    // Si el objeto actual no cabe en la mochila, lo excluimos
    if (PESOS[i] > k)
    {
        solucionActual[i] = 0;
        return knapsackObjetos(PESOS, VALORES, n, i + 1, k, valorActual, solucionActual, mejorSolucion, maxGanancia);
    }

    // Incluir el objeto actual
    solucionActual[i] = 1;
    valorIncluido = knapsackObjetos(PESOS, VALORES, n, i + 1, k - PESOS[i], valorActual + VALORES[i], solucionActual, mejorSolucion, maxGanancia);

    // Excluir el objeto actual
    solucionActual[i] = 0;
    valorExcluido = knapsackObjetos(PESOS, VALORES, n, i + 1, k, valorActual, solucionActual, mejorSolucion, maxGanancia);

    // Devolver el mayor valor entre incluir o excluir el objeto
    if (valorIncluido > valorExcluido)
        return valorIncluido;
    else
        return valorExcluido;
}
