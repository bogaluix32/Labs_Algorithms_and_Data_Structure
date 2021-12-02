/* Trabajo de clase 2
    Estudiantes:
    -Luis Jimenez
    -Valentina Mendez
    -Jimena Madriz
    -Keyllin Mendez
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Lista Lista;
typedef struct Nodo Nodo;

struct Nodo{
	int dato;
	Nodo *siguiente;
};

struct Lista{
	Nodo *inicio;
};

int obtenerPosicion(Lista *elemento, int datoBuscar){
	Nodo *elementoAux = elemento->inicio;
	int posicion = 0;
	
	while(elementoAux != NULL){
		if(elementoAux->dato == datoBuscar)
			return posicion;

		elementoAux = elementoAux->siguiente;	
		posicion = posicion + 1;	
	}
	return -1;
}

void eliminarInicio(Lista *elemento){
	Nodo *elementoAux;
	
	if(elemento->inicio == NULL){
		printf("La lista esta vacia...\n");		
	}
	else{
		elementoAux = elemento->inicio;
		printf("El dato eliminado es %d \n", elementoAux->dato);
		elemento->inicio = elemento->inicio->siguiente;
		free(elementoAux);
	}
}

void eliminarFinal(Lista *elemento){
	Nodo *elementoAux, *anterior;
	
	if(elemento->inicio == NULL){
		printf("La lista esta vacia...\n");		
	}
	else{
		//Valida si la lista tiene solo un nodo
		if(elemento->inicio->siguiente == NULL){
			elementoAux = elemento->inicio;
			elemento->inicio = NULL;			
		}
		else{
			anterior = elemento->inicio;
			elementoAux = anterior->siguiente;
						
			while(elementoAux!= NULL){
				if(elementoAux->siguiente == NULL){ //Esta en el ultimo nodo de la lista
					anterior->siguiente = NULL;
					break;					
				}
				else{
					anterior = elementoAux;
					elementoAux = elementoAux->siguiente;
				}
			}
		}		
		printf("El dato eliminado es %d \n", elementoAux->dato);
		free(elementoAux);
	}
}

void eliminarDato(Lista *elemento, int dato){
	Nodo *elementoAux = elemento->inicio, *anterior = NULL;
	
	//Valida si la lista esta vacia
	if(elemento->inicio == NULL){
		printf("La lista esta vacia...\n");		
	}
	else{
		//Si el nodo a eliminar esta al inicio de la lista
		if(elemento->inicio->dato == dato){
			elementoAux = elemento->inicio;
			elemento->inicio = elemento->inicio->siguiente;				
		}
		else{
			while(elementoAux!= NULL)
			{
				if(elementoAux->dato == dato) //Nodo a eliminar es el ultimo nodo de la lista
				{
					anterior->siguiente = elementoAux->siguiente;
					break;					
				}
				else{
					anterior = elementoAux;
					elementoAux = elementoAux->siguiente;				
				}
			}
		}
		if(elementoAux != NULL){
			printf("El dato eliminado es %d \n", elementoAux->dato);
			free(elementoAux);
		}
	}
}

//Funcion auxiliar para insertar datos en la lista
void insertarDato(Lista *elemento, int dato){
	Nodo *n, *elementoAux;
	
	if(elemento->inicio == NULL){ //Valida si la lista esta vacia
		//Inserta al inicio de la lista
		elemento->inicio = (Nodo *) malloc(sizeof(Nodo));
		elemento->inicio->dato = dato;
		elemento->inicio->siguiente = NULL;
		return;
	}
	n = elemento->inicio;
	while(n!= NULL){
		elementoAux = n;
		n = n->siguiente;		
	}
	elementoAux->siguiente = (Nodo *) malloc(sizeof(Nodo));
	elementoAux->siguiente->siguiente = NULL;
	elementoAux->siguiente->dato = dato;
}

//Funcion auxiliar para mostrar la lista
void mostrarLista(const Lista *elemento){
	Nodo *i;
	printf("La lista es: \n");
	for(i = elemento->inicio; i!= NULL; i = i->siguiente)
		printf("%d ", i->dato);
	printf("\n");
}

int main(void){
	Lista *elemento;
	int res;
	
	insertarDato(elemento,3);
	insertarDato(elemento,7);
	insertarDato(elemento,1);
	insertarDato(elemento,9);
	insertarDato(elemento,13);
	insertarDato(elemento,4);

    printf("\n****  MUESTRA INSERCIONES   ****\n");
	mostrarLista(elemento);
		
	printf("\n****  PRUEBA OBTENER POSICION   ****\n");
	res = obtenerPosicion(elemento, 4);

	if(res >= 0)
		printf("El dato esta en la posicion %d\n", res);	
	else	
		printf("El dato no esta en lista\n");
		
	printf("\n****  PRUEBA ELIMINAR INICIO   ****\n");
	eliminarInicio(elemento);
	mostrarLista(elemento);
	
	printf("\n****  PRUEBA ELIMINAR FINAL   ****\n");
	eliminarFinal(elemento);
	mostrarLista(elemento);
	
	printf("\n****  PRUEBA ELIMINAR DATO   ****\n");
	eliminarDato(elemento,9);
	mostrarLista(elemento);
}