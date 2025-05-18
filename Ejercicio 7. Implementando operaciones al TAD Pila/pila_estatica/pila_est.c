#include <stdlib.h>
#include <stdio.h>
#include "pila_est.h"

/*
Inicializar pila (Initialize): recibe<- pila (s);
Initialize(s);
Efecto: Recibe una pila y la inicializa para su trabajo normal.
*/
void Initialize(pila *s)
{
	(*s).tope = -1; // s->tope=-1;
	return;
}

/*
Empilar (Push): recibe<- pila (s); recibe<- elemento (e)
Push(s,e);
Efecto: Recibe la pila y aumenta su tamaño, poniendo el elemento en la cima de la pila.
*/
void Push(pila *s, elemento e)
{
	if (s->tope < TAM - 1)
	{
		s->tope++;
		s->A[s->tope] = e; //(*s).A[(*s).tope]=e;
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
	if (s->tope != -1)
	{
		r = s->A[s->tope];
		s->tope--;
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
	if (s->tope != -1)
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
	if (s->tope != -1)
	{
		r = s->A[s->tope];
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
	int r;
	r = s->tope + 1;
	return r;
}

/*
Eliminar pila (Destroy): recibe<- pila (s)
Destroy(s);
Efecto: Recibe una pila y la libera completamente
*/
void Destroy(pila *s)
{
	Initialize(s);
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
	if (n < 1 || n > Size(s))
	{
		printf("\nERROR e = Element(S,%d):\"Indice fuera de rango\"", n);
		exit(1);
	}
	else
	{
		// Accede a los elemento de la pila,
		return s->A[n - 1];
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
	int i, j; // Indices para intercambiar elementos de la pila
	elemento temp;
	i = 0;
	j = s->tope - 1;

	while (i < j)
	{
		// Intercambia los elementos de la pila
		temp = s->A[i];
		s->A[i] = s->A[j];
		s->A[j] = temp;
		j--;
		i++;
	}
}