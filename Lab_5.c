/* Laboratorio 5
Luis Jimenez Bogantes
Valentina Mendez Solano
Jimena Madriz Abarca
Keyllin Mendez Cordero */

#include <stdio.h>
#include <stdlib.h>

//Reto 2

typedef struct ListaD ListaDoble;
typedef struct Nodo Nodo;

struct Nodo{
	int dato;
	Nodo *siguiente;
	Nodo *anterior; 
};

struct ListaD{
	Nodo *inicio;
	Nodo *final;
};

Nodo* crearNodo(int dato){
	Nodo *nuevo;

	nuevo = (Nodo *) malloc(sizeof(Nodo));
	nuevo->anterior = NULL;
	nuevo->siguiente = NULL;
	nuevo->dato = dato;	
	
	return nuevo;
}

void insertarDato(ListaDoble *Lista, int dato){
	if (Lista->inicio == NULL){
		Lista->inicio = crearNodo(dato);
		Lista->final = Lista->inicio;
		return;
	}
	
	Lista->final->siguiente = crearNodo(dato);
	Lista->final->siguiente->anterior = Lista->final;
	Lista->final = Lista->final->siguiente;
}

void mostrarListaIzqDer(ListaDoble *Lista){
	Nodo *i;

	printf("La lista es: \n");
	for(i = Lista->inicio; i!= NULL; i = i->siguiente)
		printf("%d ", i->dato);
	printf("\n");
}

void eliminarElemento(ListaDoble *Lista, int posicion){
    Nodo *aux;
    int contador;

    if (Lista->inicio != NULL){
        aux = Lista->inicio;
        contador = 1;

        while ((contador != posicion) && (aux != NULL)){
            aux = aux->siguiente;
            contador++;
        }
        
        if (contador == posicion){
            if (aux == Lista->inicio){
                Lista->inicio = Lista->inicio->siguiente;
                if (Lista->inicio != NULL){
                    aux->anterior = NULL;
                }
            }
            else{
                aux->anterior->siguiente = aux->siguiente;
                if (aux->siguiente != NULL){
                    aux->siguiente->anterior = aux->anterior;
                }
            }
            free(aux);
        }
        else{
            printf("Posicion invalida\n");
        }
    }
    else{
        printf("Lista vacia\n");
    }
}

//Reto 3

void intercambiarNodos(ListaDoble *Lista, int a, int b){
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

//Reto 4

typedef struct nodoC{
	int dato;
	struct nodoC* siguiente;
	struct nodoC* anterior;
} nodoC;

nodoC* inicio = NULL;
nodoC* final = NULL;

int suma = 0;
int cantidadDatos = 0;

void insertarDatoListaCricular(){
	nodoC* nuevo = (nodoC*) malloc(sizeof(nodoC));
    
	printf(" Ingrese el dato a la lista circular:\n");
	scanf("%d", &nuevo->dato);
    suma = suma + nuevo->dato;
    cantidadDatos++;

	if(inicio==NULL){
		inicio = nuevo;
		inicio->siguiente = inicio;
		final = inicio;
		inicio->anterior = final;
	}else{
		final->siguiente = nuevo;
		nuevo->siguiente = inicio;
		nuevo->anterior = final;
		final = nuevo;
		inicio->anterior = final;
	}
	printf("Dato ingresado\n");
}

void mostrarListaCircular(){
	nodoC* aux = (nodoC*) malloc(sizeof(nodoC));
    aux = inicio;

    printf("La lista circular es:\n");

    do{
        printf("%d ", aux->dato);
        aux = aux->siguiente;
    } while (aux != inicio);

    free(aux);
        
    printf("\n");
}

int calcularPromedioListaCircular(){
    int promedio = 0;

    promedio = suma / cantidadDatos;

    return promedio; 
}

int main(){
    ListaDoble *Lista;

    printf("--------Reto 2--------\n");

    insertarDato(Lista,3);
	insertarDato(Lista,7);
	insertarDato(Lista,1);
	insertarDato(Lista,9);
	insertarDato(Lista,13);
	insertarDato(Lista,4);
    mostrarListaIzqDer(Lista);

    eliminarElemento(Lista, 5);
    mostrarListaIzqDer(Lista);

    printf("--------Reto 3--------\n");

    int a = 9, b = 7;
	intercambiarNodos(Lista, a, b);
    mostrarListaIzqDer(Lista);

    printf("--------Reto 4--------\n");

    insertarDatoListaCricular();
    insertarDatoListaCricular();
    insertarDatoListaCricular();
    insertarDatoListaCricular();
    mostrarListaCircular();
    int promedio = calcularPromedioListaCircular();
    printf("El promedio de los datos en la lista circular es: %d", promedio);

    return 0; 
}