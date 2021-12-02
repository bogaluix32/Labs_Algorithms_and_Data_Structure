/* Trabajo Clase 4: Pilas 
Luis Jimenez Bogantes
Valentina Mendez Solano
Jimena Madriz Abarca
Keyllin Mendez Cordero */

#include <stdio.h>
#include <stdlib.h>

typedef struct Pila Pila;
typedef struct Nodo Nodo;

struct Nodo{
    int dato;
    Nodo *siguiente;
};

struct Pila{
    Nodo *tope;
    int tamanoPila;
};

Nodo* crearNodo(int datoIngresado){
	Nodo *nuevoNodo;
	nuevoNodo = (Nodo *) malloc(sizeof(Nodo));
	nuevoNodo->siguiente = NULL;
	nuevoNodo->dato = datoIngresado;	
	
	return nuevoNodo;
}

void push(Pila *Pila, int datoIngresado){
	Nodo *nuevoNodo = crearNodo(datoIngresado);
	
	nuevoNodo->siguiente = Pila->tope;
	Pila->tope = nuevoNodo;
	Pila->tamanoPila += 1; 
}

void pop(Pila *Pila){
	Nodo *eliminado = Pila->tope;
	
	if(Pila->tope == NULL){
		printf("La pila esta vacia\n");
	}
	else{
		Pila->tope = Pila->tope->siguiente;
		Pila->tamanoPila -= 1;	
		printf("El nodo eliminado es %d\n", eliminado->dato);
		free(eliminado);
	}
}

void tope(Pila *Pila){
	if(Pila->tope == NULL)
		printf("La pila esta vacia\n");	
	else
		printf("El nodo en el tope es %d\n", Pila->tope->dato);
}

void mostrarPila(Pila *Pila){
	Nodo *i;

	printf("La pila es: \n");

	for(i = Pila->tope; i!= NULL; i = i->siguiente)
		printf("%d ", i->dato);
	printf("\n");
}

int main(void){
    Pila *Pila;
    int resultado;

    printf("--------Inserciones en la pila--------\n");
    push(Pila, 10);
    push(Pila, 20);
    push(Pila, 30);
    push(Pila, 40);
    push(Pila, 50);
    mostrarPila(Pila);

    printf("--------Eliminaciones en la pila--------\n");
    pop(Pila);
    mostrarPila(Pila);

    printf("--------Tope en la pila--------\n");
    tope(Pila); 
    mostrarPila(Pila);

    return 0;
}