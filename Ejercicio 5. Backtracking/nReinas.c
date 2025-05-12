/*
Implementacion del algoritmo de n Reinas como ejercicio de backtraking
Autor: Omar Ivan Salinas Aquino Abril 2025
Version: 1.0

Descripcion: Programa que implementa el algoritmo de n-Reinas por backtracking
encuentra las posibles soluciones al problema de las n-Reinas. El cual consiste en colocar
n reinas en un tablero de n*n de forma que no se amenacen según las normas del ajedrez.

Compilacion:
Windows: gcc nReinas.c -o nReinas.exe
Linux/Mac: gcc nReinas.c -o nReinas

Ejecucion:
    ./nReinas {numero de reinas}
    ./nReinas {numero de reinas} > salida.txt
*/

// Librerias
#include <stdio.h>
#include <stdlib.h>
#define FALSE 0
#define TRUE 1

// int n numero de reinas
void NReinas(int n);
// int ** direccion de direcciones de int, int columna, int n numero de reinas
int nReinasBacktraking(int **tablero, int columna, int n);
// int ** direccion de direcciones de int, int filas, int columna, int n numero de reinas
int validarPosicion(int **tablero, int fila, int columna, int n);

int main(int argc, char *argv[])
{

    // Validar que se reciben los datos necesarios
    if (argc != 2)
    {
        printf("Indique el numero de reinas - Ejemplo: %s 4\n", argv[0]);
        exit(1);
    }
    // Declaración de variables
    int n;

    // Recibir valores por argumento del main
    n = atoi(argv[1]);

    printf("\nPara %d reinas\n", n);
    // Llamar a la función
    NReinas(n);

    return 0;
}
/*
void NReinas(int n);
Descripcion: Funcion que inicializa un nuevo tablero con ceros y llama a la funcion auxiliar
int nReinasBacktraking(int **tablero, int columna, int n) con el tablero en cero y columna en cero.
Recibe: int n
Devuelve: void (no retorna valor explicito)
*/
void NReinas(int n)
{
    int **tablero, i, j;
    // Reservar memoria para las filas
    tablero = malloc(n * sizeof(int *));
    if (tablero == NULL)
    {
        printf("\nNo se pudo reservar memoria para %d columnas\n", n);
        exit(1);
    }
    // Reservar memoria para las columnas
    for (i = 0; i < n; i++)
    {
        tablero[i] = malloc(n * sizeof(int));
        if (tablero[i] == NULL)
        {
            printf("No se pudo reservar memoria para la fila %d\n", i);
            exit(1);
        }
    }
    // Inicializar el tablero en cero
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            tablero[i][j] = 0;
    // Llamar a la funcion recursiva y encontrar solucion
    if (nReinasBacktraking(tablero, 0, n) == TRUE)
    {
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n; j++)
            {
                printf(" %d ", tablero[i][j]);
            }
            printf("\n");
        }
    }
    else
        printf("\nNo se encontro solución\n");
    for (i = 0; i < n; i++)
        free(tablero[i]);
    free(tablero);
}
/*
int nReinasBacktraking(int **tablero, int columna, int n);
Descripción: Funcion recursiva que implementa el algoritmo de backtraking para resolver el
problema de las n reinas.
Recibe: int ** direccion de direcciones de int, int columna, int n numero de reinas
Devuelve: int TRUE(1) o FALSE(0)
*/
int nReinasBacktraking(int **tablero, int columna, int n)
{
    int fila;
    // Verifica si ha coloado todas las reinas en el tablero
    if (columna >= n)
        return TRUE;
    // Intenta colocar otra reina
    for (fila = 0; fila < n; fila++)
        // Verifica si es seguro poner una reina
        if (validarPosicion(tablero, fila, columna, n) == TRUE)
        {
            // Pone la reina
            tablero[fila][columna] = 1;
            // Busca si existe solucion
            if (nReinasBacktraking(tablero, columna + 1, n) == TRUE)
                return TRUE;
            // Restaura el tablero si no hay solucion
            tablero[fila][columna] = 0;
        }
    return FALSE;
}

/*
int validarPosicion(int **tablero, int fila, int columna);
Descripcion: verifica si es seguro colocar una reina en la posicion(fila,columna) del
tablero actual.
Recibe: int ** direccion de direcciones de int, int filas, int columna, int n numero de reinas
Devuelve int TRUE (1) o FALSE (0)
*/
int validarPosicion(int **tablero, int fila, int columna, int n)
{
    int i, j;
    // Revisar fila a la izquierda
    for (i = 0; i < columna; i++)
        if (tablero[fila][i] == 1)
            return FALSE;
    // Revisar diagonal superior izquierda
    for (i = fila, j = columna; i >= 0 && j >= 0; i--, j--)
        if (tablero[i][j] == 1)
            return FALSE;
    // Revisar diagonal inferior izquierda
    for (i = fila, j = columna; i < n && j >= 0; i++, j--)
        if (tablero[i][j] == 1)
            return FALSE;
    return TRUE;
}
