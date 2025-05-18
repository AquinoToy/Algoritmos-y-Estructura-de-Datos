/*
AUTOR: Omar Ivan Salinas Aquino Mayo 2025
VERSIÓN: 1

DESCRIPCIÓN: Simula de manera sencilla los movimientos de una hormiga a lo largo de un camino sencillo

OBSERVACIONES: Se puede emplear la libreria TADColaEst.h, TADPilaEstCir.h o TADColaDin.h implementadas
en clase. Ambas estructuras elemento, ya sea la de las implementaciónes estáticas o dinámica deberán
tener un campo int n;

COMPILACIÓN: gcc Hormiga.c Cola_(Dinamica|Estatica)/TADCola(Din|Est|EstCirc).c -o Hormiga  (Si se tiene el fuente de la implementación)

EJECUCIÓN: ./Hormiga
*/

#include <stdio.h>
#include <string.h>
// #include "Cola_Estatica/TADColaEst.h" 	//Si se usa la implementación estática
#include "Cola_Dinamica/TADColaDin.h" // Si se usa la implementación dinámica

void mostrarCola(cola *c)
{
    int tam = Size(c);
    printf("Ruta de la hormiga: ");
    for (int i = 1; i <= tam; i++)
    {
        elemento e = Element(c, i);
        printf("[%s] -> ", e.movimiento);
    }
    printf("NULL\n");
}

int main()
{
    cola movimientos;
    Initialize(&movimientos);

    int opcion;
    elemento e;

    do
    {
        printf("\n--- MENU ---\n");
        printf("1. Agregar movimiento\n");
        printf("2. Eliminar movimiento\n");
        printf("3. Mostrar ruta\n");
        printf("4. Consultar movimiento por paso\n");
        printf("5. Invertir ruta (flip)\n");
        printf("6. Salir\n");
        printf("Selecciona una opción: ");
        scanf("%d", &opcion);
        getchar(); // Limpiar buffer

        switch (opcion)
        {
        case 1:
            printf("Movimiento (adelante, izquierda, derecha): ");
            fgets(e.movimiento, MAX_STR, stdin);
            e.movimiento[strcspn(e.movimiento, "\n")] = '\0';
            Queue(&movimientos, e);
            break;
        case 2:
            if (!Empty(&movimientos))
            {
                e = Dequeue(&movimientos);
                printf("Movimiento eliminado: %s\n", e.movimiento);
            }
            else
            {
                printf("La ruta está vacía.\n");
            }
            break;
        case 3:
            mostrarCola(&movimientos);
            break;
        case 4:
        {
            int paso;
            printf("¿Qué paso deseas consultar? (1 a %d): ", Size(&movimientos));
            scanf("%d", &paso);
            getchar(); // Limpiar buffer

            if (paso >= 1 && paso <= Size(&movimientos))
            {
                e = Element(&movimientos, paso);
                printf("En el paso %d, la hormiga hizo: %s\n", paso, e.movimiento);
            }
            else
            {
                printf("Paso inválido. Debe estar entre 1 y %d.\n", Size(&movimientos));
            }
            break;
        }
        case 5:
            Flip(&movimientos);
            printf("Algo te asustó. ¡La ruta fue invertida!\n");
            break;
        case 6:
            printf("Saliendo...\n");
            break;
        default:
            printf("Opción inválida.\n");
        }
    } while (opcion != 6);

    Destroy(&movimientos);
    return 0;
}
