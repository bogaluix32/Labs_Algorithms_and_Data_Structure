/* Laboratorio 4 
Luis Jimenez Bogantes
Valentina Mendez Solano
Jimena Madriz Abarca
Keyllin Mendez Cordero */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Lista Lista;
typedef struct Nodo Nodo;
typedef struct ListaInvertida ListaInvertida;

struct Nodo{
	int dato;
	Nodo *siguiente;
};

struct Lista{
	Nodo *inicio;
    Nodo *final;
};

struct ListaInvertida{
    Nodo *inicio;
};

//Reto 1: obtener posicion de una elemento en la lista

int obtenerPosicion(Lista *Lista, int datoIngresado){
	Nodo *nodoAuxiliar = Lista->inicio;
	int posicion = 0;
	
	while (nodoAuxiliar != NULL){

		if (nodoAuxiliar->dato == datoIngresado)
			return posicion;

		nodoAuxiliar = nodoAuxiliar->siguiente;	
		posicion++;	
	}

	return -1;
}

//Reto 2: encontrar elemento en una lista

bool existeElemento(Lista *Lista, int datoIngresado){
	Nodo *nodoAuxiliar = Lista->inicio;
	
	while (nodoAuxiliar != NULL){
		if (nodoAuxiliar->dato == datoIngresado)
			return true;

		nodoAuxiliar = nodoAuxiliar->siguiente;		
	}

	return false;
}

//Funcion auxiliar

void insertarDato(Lista *Lista, int datoNuevo){
	Nodo *elemento, *nodoAuxiliar;
	
	if(Lista->inicio == NULL){
		Lista->inicio = (Nodo *) malloc(sizeof(Nodo));
		Lista->inicio->dato = datoNuevo;
		Lista->inicio->siguiente = NULL;
		return;
	}

	elemento = Lista->inicio;

	while(elemento!= NULL){
		nodoAuxiliar = elemento;
		elemento = elemento->siguiente;		
	}

	nodoAuxiliar->siguiente = (Nodo *) malloc(sizeof(Nodo));
	nodoAuxiliar->siguiente->siguiente = NULL;
	nodoAuxiliar->siguiente->dato = datoNuevo;
}
//Funcion auxiliar

void mostrarLista(Lista *Lista){
	Nodo *i;

	printf("La lista es: \n");
	for(i = Lista->inicio; i!= NULL; i = i->siguiente)
		printf("%d ", i->dato);
	printf("\n");
}

//Reto 3: invertir lista

void invertirLista(Lista *Lista){
	Nodo *pTemporal, *qTemporal;

	if (Lista->inicio != NULL && Lista->inicio->siguiente != NULL){
		pTemporal = Lista->inicio;
		qTemporal = NULL;

		while (Lista->inicio != NULL){
			Lista->inicio = Lista->inicio->siguiente;
			pTemporal->siguiente = qTemporal;
			qTemporal = pTemporal;
			pTemporal = Lista->inicio;
		}
		Lista->inicio = qTemporal;
	}
	else{
		printf("No hay suficientes elementos\n");
	}
}
//Reto 4: concatenar dos listas

typedef struct NodoGeneral{
	int dato;
    struct NodoGeneral *inicio;
	struct NodoGeneral *siguiente; 
}nodoL;

typedef nodoL* lista;
typedef nodoL* lista2;

void insert(lista *L, int num){
    lista aux = malloc(sizeof(nodoL));

    aux->dato = num;
    aux->siguiente = *L;
    *L = aux;

    //printf("Se agrego el numero %d a la lista\n", num);
}

int showList(nodoL *L){
    int i = 0;

    if (L != NULL){
        i = 1;
        printf(" %d <- ", L->dato);
        showList(L->siguiente);
    }
    return i;
}

void concatenarListas(nodoL *L, nodoL *lista2){
	nodoL *auxiliar = L, *i;

	while (auxiliar->siguiente != NULL){
		auxiliar = auxiliar->siguiente;
	}
	auxiliar->siguiente = lista2;

    showList(L);
}

//Reto 5 intercambiar nodos

void intercambiarNodos(Lista *Lista, int a, int b){
	Nodo *indiceAnterior_a = NULL;
	Nodo *indiceActual_a = Lista->inicio;

	while (indiceActual_a->dato != a){
		indiceAnterior_a = indiceActual_a;
		indiceActual_a = indiceActual_a->siguiente;
	}

	Nodo *indiceAnterior_b = NULL;
	Nodo *indiceActual_b = Lista->inicio;

	while (indiceActual_b->dato != b){
		indiceAnterior_b = indiceActual_b;
		indiceActual_b = indiceActual_b->siguiente;
	}

	if (indiceActual_a == NULL || indiceActual_b == NULL){
		printf("Elementos no encontrados");
	}

	if (indiceAnterior_a != NULL){
		indiceAnterior_a->siguiente = indiceActual_b;
	}
	else{
		Lista->inicio = indiceActual_b; 
	}

	if (indiceAnterior_b != NULL){
		indiceAnterior_b->siguiente = indiceActual_a; 
	}
	else{
		Lista->inicio = indiceActual_a;
	}

	Nodo *temporal = indiceActual_b->siguiente;
	indiceActual_b->siguiente = indiceActual_a->siguiente;
	indiceActual_a->siguiente = temporal;
}
int longitudLista(Lista *Lista){
    Nodo *aux;
    int longitud = 0;

    if (Lista->inicio != NULL){
        aux = Lista->inicio;
        longitud++;
        
        while (aux->siguiente != NULL){
            aux = aux->siguiente;
            longitud++;
            //printf("estoy");
        }
    }
    else{
        printf("Lista vacia\n");
    }
    
    return longitud;
}
int main(void){
    Lista *Lista;
	ListaInvertida *ListaInvertida;
	int longitud;

    insertarDato(Lista,3);
	insertarDato(Lista,7);
	insertarDato(Lista,1);
	insertarDato(Lista,9);
	insertarDato(Lista,13);
	insertarDato(Lista,4);
	
	longitud = longitudLista(Lista);
    printf("La longitud de la lista es de: %d elementos\n", longitud);

    printf("\n****  MUESTRA INSERCIONES   ****\n");
	mostrarLista(Lista);

	printf("\n");

	printf("La posicion del elemento es %d: \n", obtenerPosicion(Lista, 7));

	printf("\n");

	bool resultado = existeElemento(Lista, 9);
	if (resultado == 1)
		printf("True\n");
	else
		printf("False\n");

    invertirLista(Lista);
	printf("\n****  LISTA INVERTIDA   ****\n");
	mostrarLista(Lista);

	lista miLista = NULL;
    lista2 lista2 = NULL;

    insert(&miLista, 10);
    insert(&miLista, 20);
    insert(&miLista, 30);
    insert(&miLista, 40);

    printf("\n****  LISTA 1 ANTES DE CONCATENAR   ****\n");
    int i = showList(miLista);
    if (i == 0)
        printf("La lista esta vacia\n");
    printf("\n");
    
    printf("\n****  LISTA 2 ANTES DE CONCATENAR   ****\n");
    insert(&lista2, 15);
    insert(&lista2, 25);
    insert(&lista2, 35);
    insert(&lista2, 45);

    int j = showList(lista2);
    if (j == 0)
        printf("La lista esta vacia\n");
    printf("\n");

    printf("\n****  LISTA CONCATENADA   ****\n");
    concatenarListas(miLista, lista2);

	printf("\n");

	printf("\n****  LISTA   ****\n");
	mostrarLista(Lista);
	int a = 9, b = 7;
	intercambiarNodos(Lista, a, b);
	printf("\n****  LISTA CON NODOS INTERCAMBIADOS  ****\n");
	mostrarLista(Lista);

    return 0;
}