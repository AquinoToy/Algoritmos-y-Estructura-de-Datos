#include <stdlib.h>
#include <stdio.h>
#include "pila_din.h"

/*
Inicializar pila (Initialize): recibe<- pila (s);
Initialize(s);
Efecto: Recibe una pila y la inicializa para su trabajo normal.
*/
void Initialize(pila *s)
{
	s->size = 0;
	(*s).tope = NULL;
	return;
}

/*
Empilar (Push): recibe<- pila (s); recibe<- elemento (e)
Push(s,e);
Efecto: Recibe la pila y aumenta su tamaño, poniendo el elemento en la cima de la pila.
*/
void Push(pila *s, elemento e)
{
	nodo *aux;

	aux = malloc(sizeof(nodo));

	if (aux != NULL)
	{
		s->size++;
		aux->e = e;
		aux->abajo = s->tope;
		s->tope = aux;
	}
	else // Desbordamiento de pila
	{
		printf("\nERROR Push(s,e):\"Desbordamiento de pila\"");
		exit(1);
	}
	return;
}

/*
Desempilar (Pop): recibe<- pila (s); retorna -> elemento
e=Pop(s);
Efecto: Recibe la pila, remueve el elemento tope y lo retorna.
Excepción: si la pila esta vacía, produce error.
*/
elemento Pop(pila *s)
{
	elemento r;
	nodo *aux;
	if (s->tope != NULL)
	{
		r = s->tope->e;
		aux = s->tope;
		s->tope = s->tope->abajo; // s->tope=aux->abajo
		free(aux);
		s->size--;
	}
	else // Subdesbordamiento de la pila
	{
		printf("\nERROR e=Pop(s):\"Subdesbordamiento de pila\"");
		exit(1);
	}

	return r;
}

/*
Es vacía (Empty): recibe<- pila (s); retorna -> boolean
b=Empty(s);
Efecto: Recibe una pila y devuelve true si esta vacía y false en caso contrario.
*/
boolean Empty(pila *s)
{
	boolean r;
	if (s->tope != NULL)
		r = FALSE;
	else
		r = TRUE;

	return r;
}

/*
Tope pila (Top): recibe<- pila (s); retorna -> elemento
e=Top(s);
Efecto: Devuelve el elemento cima de la pila.
Excepción: si la pila esta vacía produce error
*/
elemento Top(pila *s)
{
	elemento r;
	if (s->tope != NULL)
	{
		r = s->tope->e;
	}
	else // Subdesbordamiento de la pila
	{
		printf("\nERROR e=Top(s):\"Subdesbordamiento de pila\"");
		exit(1);
	}

	return r;
}

/*
Tamaño pila (size): recibe<- pila (s); retorna -> tamaño de la pila (entero)
n=size(s);
Efecto: Devuelve el número de elementos que contiene la pila (Altura de la pila).
*/
int Size(pila *s)
{
	int r = s->size;
	/*int r=0;
	nodo *aux;
	aux=s->tope;
	while(aux!=NULL)
	{
		r++;
		aux=aux->abajo;
	}
*/
	return r;
}

/*
Eliminar pila (Destroy): recibe<- pila (s)
Destroy(s);
Efecto: Recibe una pila y la libera completamente
*/
void Destroy(pila *s)
{
	nodo *aux;
	if (s->tope != NULL)
	{
		do
		{
			aux = s->tope->abajo;
			free(s->tope);
			s->tope = aux;
		} while (aux != NULL);
	}
	s->size = 0;
	return;
}
/*
Elemento (Element): recibe <- pila; recibe <- entero (n); retorna -> elemento (e).
e = Element(S,n);
Efecto: Recibe una pila y un numero entero, devuelve elemento n de la pila.
Excepcion: Si n esta fuera de la pila produce error.
*/
elemento Element(pila *s, int n)
{
	int i;
	if (n < 1 || n > Size(s))
	{
		printf("\nERROR e = Element(S,%d):\"Indice fuera de rango\"", n);
		exit(1);
	}
	else
	{
		nodo *aux = s->tope;
		for (i = 1; i < n; i++)
		{
			aux = aux->abajo;
		}

		return aux->e;
	}
}

/*
Voltear (Flip): recibe <- pila (S)
Flip(S);
Efecto: Recibe una pila "s" y la voltea (Sus elementos quedarán invertidos el que
estaba en el tope estará debajo y el que estaba hasta abajo será el nuevo tope).
*/
void Flip(pila *s)
{
	int n = Size(s);
	int i;
	if (n <= 1)
		return; // Nada que invertir

	elemento *temp = malloc(n * sizeof(*temp));
	if (temp == NULL)
	{
		printf("Error: no se pudo reservar memoria\n");
		return;
	}
	for (i = 0; i < n; ++i)
	{
		temp[i] = Pop(s);
	}
	for (i = 0; i < n; ++i)
	{
		Push(s, temp[i]);
	}

	free(temp);
}
