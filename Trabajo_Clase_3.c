/* Trabajo clase 3 
Luis Jimenez Bogantes
Valentina Mendez Solano
Jimena Madriz Abarca
Keyllin Mendez Cordero */

#include <stdio.h>
#include <stdlib.h>

typedef struct ListaDoble ListaDoble;
typedef struct Nodo Nodo;

struct Nodo
{
	int dato;
	Nodo *siguiente;
	Nodo *anterior; 
};

struct ListaDoble
{
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

int obtenerPosicion(ListaDoble *L, int dato){
	Nodo *aux = L->inicio;
	int posicion = 0;
	
	while(aux != NULL){
		if(aux->dato == dato)
			return posicion;
		aux = aux->siguiente;	
		posicion = posicion + 1;	
	}
	return -1;
}

void eliminarInicio(ListaDoble *L){
	Nodo *aux;
	
	if(L->inicio == NULL){
		printf("La lista esta vacia...\n");		
	}
	else{
		aux = L->inicio;
		printf("El dato eliminado es %d \n", aux->dato);
		
		if(L->inicio == L->final) 
		{
			L->inicio = NULL;
			L->final = NULL;
		}
		else{
			L->inicio = L->inicio->siguiente;
			L->inicio->anterior = NULL;	
		}		
		free(aux);
	}
}

void eliminarFinal(ListaDoble *L){
	Nodo *aux;
	
	if(L->inicio == NULL){
		printf("La lista esta vacia...\n");		
	}
	else{
		if(L->inicio->siguiente == NULL){
			aux = L->inicio;
			L->inicio = NULL;
			L->final = NULL;			
		}
		else{
			aux = L->final;
			L->final = L->final->anterior;
			L->final->siguiente = NULL;
			
		}		
		printf("El dato eliminado es %d \n", aux->dato);
		free(aux);
	}
}

void eliminarDato(ListaDoble *L, int dato)
{
	Nodo *aux = L->inicio;
	
	if(L->inicio == NULL){
		printf("La lista esta vacia...\n");		
	}
	else
	{
		if(L->inicio->dato == dato){
			if(L->inicio == L->final)
				L->final = NULL;
			L->inicio = L->inicio->siguiente;
			L->inicio->anterior = NULL;				
		}
		else {
			while(aux != NULL){
				if(aux->dato == dato){
					aux->anterior->siguiente = aux->siguiente;
					if(aux != L->final)
						aux->siguiente->anterior = aux->anterior;
					else if(aux == L->final) 
						L->final = L->final->anterior;					
					break;
				}
				aux = aux->siguiente;					
			}
		}
		if(aux != NULL){
			printf("El dato eliminado es %d \n", aux->dato);
			free(aux);
		}
	}
}

void insertarDato(ListaDoble *L, int dato){
	if(L->inicio == NULL) {
		L->inicio = crearNodo(dato);
		L->final = L->inicio;
		return;
	}
	
	L->final->siguiente = crearNodo(dato);
	L->final->siguiente->anterior = L->final;
	L->final = L->final->siguiente;
}

void mostrarListaIzqDer(ListaDoble *L){
	Nodo *i;
	printf("La lista es: \n");
	for(i = L->inicio; i!= NULL; i = i->siguiente)
		printf("%d ", i->dato);
	printf("\n");
}

int main(void){
    ListaDoble *L;
    int resultado;

    insertarDato(L,3);
	insertarDato(L,7);
	insertarDato(L,1);
	insertarDato(L,9);
	insertarDato(L,13);
	insertarDato(L,4);

    printf("\n****  MUESTRA INSERCIONES  ****\n");
	mostrarListaIzqDer(L);

    printf("\n****  PRUEBA ELIMINAR DATO   ****\n");
	eliminarDato(L,13);
	mostrarListaIzqDer(L);

    printf("\n****  PRUEBA OBTENER POSICION   ****\n");
	resultado = obtenerPosicion(L, 9);
	if(resultado >= 0)
		printf("El dato esta en la posicion %d\n", resultado);	
	else	
		printf("El dato no esta en lista\n");

    return 0;
}