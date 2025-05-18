/*
Implementacion de una pila en c
Autor original: Edgardo Adrián Franco Martínez
Modificdo por: Omar Ivan Salinas Aquino 11/Mayo/2025
Version: 1.0

Descripcion: Este programa implementa una estructura de datos tipo pila (LIFO) para
registrar y manipular un historial de especies animales. Permite al usuario agregar nuevas
especies, visualizar el historial completo, consultar una especie específica, ver la última
especie registrada, invertir el orden del historial, y limpiar los datos al finalizar.
Utiliza operaciones básicas del TAD Pila como Push, Pop, Top, Size, Empty, Element y Flip.

Compilacion:
Windows / Linux: gcc main.c pila_dinamica/pila_din.c -o dinamica
				 gcc main.c pila_estatica/pila_est.c -o estatica

  Ejecución: ./dinamica
			 ./estatica


*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pila_estatica/pila_est.h" // Cambiar por "pila_estatica/pila_din.h" si se usa pila dinamica

// Función para registrar una nueva especie
void registrarEspecie(pila *historial)
{
	elemento e;
	printf("\nNueva especie\n");
	printf("Género: ");
	scanf("%s", e.genero);
	printf("Especie: ");
	scanf("%s", e.especie);
	Push(historial, e);
	printf("Especie registrada exitosamente.\n");
}

// Función para mostrar el historial completo de especies
void mostrarHistorial(pila *historial)
{
	if (Empty(historial))
	{
		printf("Historial vacío.\n");
		return;
	}

	printf("\nHistorial (tope a fondo):\n");
	int i, n;
	for (i = historial->tope, n = 1; i >= 0; i--, n++)
	{
		printf("%d. %s %s\n", n, historial->A[i].genero, historial->A[i].especie);
	}
}

// Función para mostrar la última especie registrada (tope)
void verUltimaEspecie(pila *historial)
{
	if (Empty(historial))
	{
		printf("Historial vacío.\n");
		return;
	}
	elemento e = Top(historial);
	printf("Última especie registrada: %s %s\n", e.genero, e.especie);
}

// Función para consultar una especie en una posición específica
void verElemento(pila *historial)
{
	int pos;
	printf("Ingrese la posición desde el tope (1 a %d): ", Size(historial));
	scanf("%d", &pos);

	if (pos < 1 || pos > Size(historial))
	{
		printf("Posición inválida.\n");
		return;
	}

	elemento e = Element(historial, pos);
	printf("Elemento %d: %s %s\n", pos, e.genero, e.especie);
}

// Función para invertir el orden de la pila
void invertirHistorial(pila *historial)
{
	Flip(historial);
	printf("Historial invertido exitosamente.\n");
	mostrarHistorial(historial);
}

// Función principal con menú interactivo
int main()
{
	pila historial;
	Initialize(&historial);

	int opcion = 0;

	while (opcion != 7)
	{
		printf("\nMenú de Registro de Especies\n");
		printf("1. Registrar nueva especie\n");
		printf("2. Mostrar historial\n");
		printf("3. Ver última especie\n");
		printf("4. Ver tamaño del historial\n");
		printf("5. Ver especie en posición específica\n");
		printf("6. Invertir historial y mostrar\n");
		printf("7. Salir\n");
		printf("Opción: ");
		scanf("%d", &opcion);

		switch (opcion)
		{
		case 1:
			registrarEspecie(&historial);
			break;
		case 2:
			mostrarHistorial(&historial);
			break;
		case 3:
			verUltimaEspecie(&historial);
			break;
		case 4:
			printf("Total de especies: %d\n", Size(&historial));
			break;
		case 5:
			verElemento(&historial);
			break;
		case 6:
			invertirHistorial(&historial);
			break;
		case 7:
			printf("Saliendo y limpiando historial...\n");
			break;
		default:
			printf("Opción no válida.\n");
		}
	}

	Destroy(&historial);
	return 0;
}