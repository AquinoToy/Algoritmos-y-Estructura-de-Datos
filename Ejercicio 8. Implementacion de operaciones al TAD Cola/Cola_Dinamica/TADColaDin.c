/*
IMPLEMENTACION DE LA LIBRERIA DEL TAD COLA DINÁMICA (TADColaEst.h)
AUTOR: Edgardo Adrián Franco Martínez (C) Noviembre 2022
VERSIÓN: 1.7

DESCRIPCIÓN: TAD cola o Queue.
Estructura de datos en la que se cumple:
Los elementos se insertan en un extremo (el posterior) y
la supresiones tienen lugar en el otro extremo (frente).

OBSERVACIONES: Hablamos de una Estructura de datos dinámica
cuando se le asigna memoria a medida que es necesitada,
durante la ejecución del programa.


COMPILACIÓN PARA GENERAR EL CÓDIGO OBJETO: gcc -c TADColaEst.c
*/

// LIBRERAS
#include "TADColaDin.h"
#include <stdlib.h>
#include <stdio.h>
// DEFINICIÓN DE FUNCIONES

/*
void Initialize(cola *c);
Descripción: Inicializar cola (Iniciar una cola para su uso)
Recibe: cola *c (Referencia a la cola "c" a operar)
Devuelve:
Observaciones: El usuario a creado una cola y c tiene la referencia a ella,
si esto no ha pasado se ocasionara un error.
*/
void Initialize(cola *c)
{
	c->num_elem = 0;
	c->frente = NULL;
	c->final = NULL;

	return;
}

/*
void Queue(cola * c, elemento e);
Descripción: Recibe una cola y agrega un elemento al final de ella.
Recibe: cola *c (Referencia a la cola "c" a operar) elemento e (Elemento a encolar)
Devuelve:
Observaciones: El usuario a creado una cola y ha sido inicializada y c tiene la referencia a ella,
si esto no ha pasado se ocasionara un error.
*/
void Queue(cola *c, elemento e)
{
	nodo *aux;
	aux = malloc(sizeof(nodo));
	if (aux == NULL)
	{
		printf("ERROR: Queue (c,e) desbordamiento de cola");
		exit(1);
	}
	aux->e = e;
	aux->siguiente = NULL;
	if (c->num_elem > 0)
		c->final->siguiente = aux;
	c->final = aux;
	c->num_elem++;
	if (c->num_elem == 1)
		c->frente = c->final;
	return;
}

/*
elemento Dequeue(cola * c);
Descripción: Recibe una cola y devuelve el elemento que se encuentra al
frente de esta, quitándolo de la cola.
Recibe: cola *c (Referencia a la cola "c" a operar)
Devuelve: elemento (Elemento desencolado)
Observaciones: El usuario a creado e inicializado una cola, ademas la cola tiene
elementos, si no es así se genera un error y se termina el programa. (Subdesboramiento de Cola)
*/
elemento Dequeue(cola *c)
{
	nodo *aux;
	elemento e; // Elemento a retornar
	if (c->num_elem == 0)
	{
		printf("ERROR: Dequeue (c) subdesbordamiento de cola");
		exit(1);
	}
	else
	{
		e = c->frente->e;
		aux = c->frente;
		c->frente = c->frente->siguiente;
		free(aux);
		c->num_elem--;
		if (c->num_elem == 0)
			c->final = NULL;
	}

	// Retornar al elemento
	return e;
}

/*
boolean Empty(cola * c);
Descripción: Recibe una cola y TRUE si la cola esta vacia y FALSE en caso contrario
Recibe: cola *c (Referencia a la cola "c" a verificar)
Devuelve: boolean TRUE O FALSE
Observaciones: El usuario a creado una cola y la cola fue correctamente inicializada
*/
boolean Empty(cola *c)
{

	return (c->num_elem == 0) ? TRUE : FALSE;
}

/*
elemento Front(cola * c);
Descripción: Recibe una cola y devuelve el elemento que se encuentra al frente de esta.
Recibe: cola *c (Referencia a la cola "c")
Devuelve: elemento del frente de la cola
Observaciones: El usuario a creado una cola,la cola fue correctamente inicializada, esta
tiene elementos de lo contrario devolvera ERROR. *No se modifica el TAD
*/
elemento Front(cola *c)
{
	elemento e;

	e = c->frente->e;

	return e;
}

/*
elemento Final(cola * c);
Descripción: Recibe una cola y devuelve el elemento que se encuentra al final de esta.
Recibe: cola *c (Referencia a la cola "c")
Devuelve: elemento del final de la cola
Observaciones: El usuario a creado una cola,la cola fue correctamente inicializada, esta
tiene elementos de lo contrario devolvera ERROR. *No se modifica el TAD
*/
elemento Final(cola *c)
{
	elemento e;
	e = c->final->e;
	return e;
}

/*
int Size(cola * c);
Descripción: Recibe una cola y devuelve el número de elemento que se encuentran en esta.
Recibe: cola *c (Referencia a la cola "c")
Devuelve: int (Tamaño de la cola)
Observaciones: El usuario a creado una cola,la cola fue correctamente inicializada, esta
*No se modifica el TAD
*/
int Size(cola *c)
{
	int r;
	r = c->num_elem;
	return r;
}

/*
void Element(cola * c, int i);
Descripción: Recibe una cola y un número de elemento de 1 al tamaño de la cola y retorna el elemento de esa posición.
Devuelve: elemento en la posicion i de la cola
Observaciones: El número i debera estar entre 1 y el tamaño de la cola, si esta es vacia o mas pequeña se provoca un error.
*/
elemento Element(cola *c, int i)
{
	elemento r;
	nodo *aux;
	int j;

	if (i > c->num_elem || i <= 0)
	{
		printf("ERROR: Element(c,i) i se encuentra fuera del rango");
		exit(1);
	}
	aux = c->frente;

	for (j = 1; j < i; j++)
	{
		aux = aux->siguiente;
	}
	r = aux->e;

	return r;
}

/*
void Destroy(cola * c);
Descripción: Recibe una cola y la libera completamente.
Recibe: cola *c (Referencia a la cola "c" a operar)
Devuelve:
Observaciones: La cola se destruye y se inicializa.
*/
void Destroy(cola *c)
{
	nodo *aux;

	aux = c->frente;
	while (aux != NULL)
	{
		c->frente = aux->siguiente;
		free(aux);
		aux = c->frente;
	}
	c->num_elem = 0;
	c->frente = NULL;
	c->final = NULL;

	return;
}

/*
int Search(cola *c, elemento e)
Descripción: Busca un elemento en la cola y retorna su posición
Recibe: cola *c (Referencia a la cola "c" a operar), elemento e (Elemento a buscar)
Devuelve: int - Posición del elemento (1 a Size) o 0 si no se encuentra
Observaciones: La cola no se modifica
*/

int Search(cola *c, elemento e)
{
	int posicion = 0;
	int contador = 1;
	nodo *aux;

	// Si la cola está vacía, retornamos 0 (no encontrado)
	if (Empty(c))
		return 0;

	// Recorremos la cola desde el frente
	aux = c->frente;
	while (aux != NULL)
	{
		// Comparamos el elemento actual con el buscado usando memcmp
		// Comparamos byte a byte la estructura completa
		if (memcmp(&(aux->e), &e, sizeof(elemento)) == 0)
		{
			// Encontramos el elemento, guardamos posición
			posicion = contador;
			break;
		}
		// Avanzamos al siguiente nodo
		aux = aux->siguiente;
		// Incrementamos el contador de posición
		contador++;
	}

	return posicion; // Retornamos la posición o 0 si no se encontró
}

/*
void Flip(cola *c)
Descripción: Invierte el orden de los elementos en la cola
Recibe: cola *c (Referencia a la cola "c" a operar)
Devuelve: Nada
Observaciones: La cola se modifica invirtiendo sus elementos
*/
void Flip(cola *c)
{
	cola aux;
	elemento e;

	// Si la cola está vacía o tiene un solo elemento
	if (Size(c) <= 1)
		return;

	// Inicializar cola auxiliar
	Initialize(&aux);

	int tam = Size(c); // Tamaño actual de la cola
	elemento *elementos = (elemento *)malloc(tam * sizeof(elemento));

	if (elementos == NULL)
	{
		perror("No se pudo asignar memoria para invertir la cola");
		exit(1);
	}
	// Sacar todos los elementos de la cola
	for (int i = 0; i < tam; i++)
	{
		elementos[i] = Dequeue(c);
	}

	// Insertarlos en orden inverso
	for (int i = tam - 1; i >= 0; i--)
	{
		Queue(c, elementos[i]);
	}

	// Liberar la memoria dinámica
	free(elementos);
}
