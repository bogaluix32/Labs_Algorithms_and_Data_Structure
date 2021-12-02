/* Trabajo de clase 5: Colas
Luis Jimenez Bogantes
Valentina Mendez Solano
Jimena Madriz Abarca
Keyllin Mendez Cordero */

#include <stdio.h>
#include <stdlib.h>

typedef struct Queue Queue;
typedef struct Node Node;

struct Node{
	int info;
	Node *next;
};

struct Queue{
	Node *front;
	Node *rear;
	int size;
};

Queue *newQueue(void){
	Queue *Cola;

	Cola = (Queue *) malloc(sizeof(Queue));
	Cola->front = NULL;
	Cola->rear = NULL;
	return Cola;
}

Node* newNode(int dato){
	Node *nuevo;

	nuevo = (Node *) malloc(sizeof(Node));
	nuevo->next = NULL;
	nuevo->info = dato;	
	
	return nuevo;
}

void enqueue(Queue *Cola, int dato){
	Cola->size = Cola->size + 1;

	if(Cola->front == NULL){
		//Inserta al inicio de la cola
		Cola->front = newNode(dato);
		Cola->rear = Cola->front;
		return;
	}
	
	Cola->rear->next = newNode(dato);
	Cola->rear = Cola->rear->next;
}

void dequeue(Queue *Cola){
	Node *aux = Cola->front;;
	
	if(Cola->front == NULL){
		printf("La cola esta vacia...\n");		
	}
	else{
		printf("El dato eliminado es %d \n", aux->info);
				
		if(Cola->front == Cola->rear) //Verifica si la cola solo tenga un nodo para actualizar el puntero final
			Cola->rear = NULL;

		Cola->front = Cola->front->next;	
		free(aux);
	}
	Cola->size = Cola->size - 1;
}

void mostrarCola(Queue *Cola){
	Node *i;

	printf("La cola es: \n");

	for(i = Cola->front; i!= NULL; i = i->next)
		printf("%d ", i->info);
    
	printf("\n");
}

void liberarCola(Queue *Cola){
	Node *n, *aux;

	if(Cola->front == NULL)
		return;

	if(Cola->front->next == NULL)
		return;

	n = Cola->front;
	
	while(n != NULL){
		aux = n;
		n = n->next;
		free(aux);
	}
}

int main(void){
    Queue *Cola;

	Cola = newQueue();

    enqueue(Cola,3);
	enqueue(Cola,7);
	enqueue(Cola,1);
	enqueue(Cola,9);
	enqueue(Cola,13);
	enqueue(Cola,4);

    printf("\n****  MUESTRA INSERCIONES  ****\n");
	mostrarCola(Cola);

    printf("\n****  PRUEBA DEQUEUE   ****\n");
	dequeue(Cola);
	mostrarCola(Cola);
	
	dequeue(Cola);
	mostrarCola(Cola);
	
	dequeue(Cola);
	mostrarCola(Cola);

    liberarCola(Cola);

    return 0;
}