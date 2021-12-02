/* Laboratorio 12: grafos
    Estudiantes:
Luis Jimenez Bogantes
Valentina Mendez Solano
Jimena Madriz Abarca
Keylin Mendez Cordero */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <limits.h>

#define max 20
#define vertex 9
#define N 7
#define MAXV 6

int matrix[max][max];
int nodes;

void createGraph(){

    int i, maxEdges, origin, destin;

    printf("Ingrese la cantidad de nodos:\n");
    scanf("%d", &nodes);

    maxEdges = nodes * (nodes - 1);

    for (i = 1; i <= maxEdges; i++){

        printf("Ingrese la arista de origen numero %d:\n", i);
        scanf("%d", &origin);

        printf("Ingrese la arista de destino numero %d:\n", i);
        scanf("%d", &destin);

        if ((origin == 0) && (destin == 0)){

            break;
        }
		if (origin > nodes || destin > nodes || origin <= 0 || destin <= 0){

			printf("Arista invalida\n");
			i--;
		}
		else{

            matrix[origin][destin] = 1;
        }
    }
}

void insertEdge(char x, char y){

	if (x > nodes){

		printf("El nodo de origen no exite\n");
		return;
	}

	if (y > nodes){

		printf("El nodo de destino no exite\n");
		return;
	}

	matrix[x][y] = 1;
}

void deleteEdge(char x, char y){

    if (x > nodes || y > nodes || matrix[x][y] == 0){

	    printf("La arista no existe\n");
	    return;
    }

    matrix[x][y] = 0;
}

//Esta funcion busca el vertice con la menor distancia posible
int minimumDistance(int distance[], bool sptSet[]){

    int minimum = INT_MAX, minimumIndex;

    for (int i = 0; i < vertex; i++){

        if (sptSet[i] == false && distance[i] <= minimum){

            minimum = distance[i], minimumIndex = i;
        }
    }
        
    return minimumIndex;
}

void printDistance(int distance[]){

    printf("Vertice \t Distancia desde el origen\n");

    for (int i = 0; i < vertex; i++){

        printf("%d \t\t %d\n", i, distance[i]);
    }
}

void dijkstra(int matrix[vertex][vertex], int source){

    int dist[vertex]; 
 
    bool sptSet[vertex];
 
    for (int i = 0; i < vertex; i++){

        dist[i] = INT_MAX, sptSet[i] = false;
    }
        
    dist[source] = 0;
 
    for (int count = 0; count < vertex - 1; count++){

        int n = minimumDistance(dist, sptSet);
 
        sptSet[n] = true;
 
        for (int v = 0; v < vertex; v++){

            if (!sptSet[v] && matrix[n][v] && dist[n] != INT_MAX && dist[n] + matrix[n][v] < dist[v]){

                dist[v] = dist[n] + matrix[n][v];
            }
        } 

    }

    printDistance(dist); 
}

//---Auxiliar---

void showGraph(){

	int i, j;

	for (i = 1; i <= nodes; i++){

		for (j = 1; j <= nodes; j++){

            printf("%4d",matrix[i][j]);
        }

		printf("\n");
	}
}

//-----Ejercicio 2-----

typedef struct scientifics{
    char name_A[100];
    char name_B[100];
    int score; 
    int num_A;
    int num_B;
    struct scientifics *next;
}scientificsNode;

scientificsNode* createNode(char scientific_A[], char scientific_B[], int score, int num_A, int num_B){

	scientificsNode *newNode = (scientificsNode *) malloc(sizeof(scientificsNode));

	newNode->next = NULL;

	strcpy(newNode->name_A, scientific_A);
    strcpy(newNode->name_B, scientific_B);
    newNode->score = score;
    newNode->num_A = num_A;
    newNode->num_B = num_B;
	
	return newNode;
}

void appendScientifics(scientificsNode **scientifics, char scientific_A[], char scientific_B[], int score, int num_A, int num_B){

    scientificsNode *newNode = createNode(scientific_A, scientific_B, score, num_A, num_B);
    scientificsNode *last = *scientifics;

    if (*scientifics == NULL){
        *scientifics = newNode;
        return;
    }

    while (last->next != NULL){
        last = last->next;
    }

    last->next = newNode;

    return;
}

typedef struct Graph{
    struct Node* head[N];
}Graph;
 
typedef struct Node{
    int dest, weight;
    struct Node* next;
}Node;
 
typedef struct Edge {
    int src, dest, weight;
}Edge;
 
Graph* createGraph2(Edge edges[], int n){
    
    Graph* graph = (Graph*) malloc(sizeof(Graph));
 
    //inicializar puntero cabeza para todos los vertices
    for (int i = 0; i < N; i++) {

        graph->head[i] = NULL;
    }
 
    // agregar aristas
    for (int i = 0; i < n; i++){
        
        int src = edges[i].src;
        int dest = edges[i].dest;
        int weight = edges[i].weight;
 
        Node* newNode = (Node*) malloc(sizeof(Node));
        newNode->dest = dest;
        newNode->weight = weight;
 
        newNode->next = graph->head[src];
 
        graph->head[src] = newNode;
    }
 
    return graph;
}

void auxPrintGraph(scientificsNode *scientifics, int source, int destination, int weight){

    scientificsNode *i;

    for (i = scientifics; i != NULL; i = i->next){

        if (i->num_A == source && i->num_B == destination){

            printf("%s -> %s -> %d pts\t", i->name_A, i->name_B, i->score);
            break;
        }
    }
}
 
void printGraph(Graph* graph, scientificsNode *scientifics){

    for (int i = 0; i < N; i++){
        
        Node* ptr = graph->head[i];

        while (ptr != NULL){

            auxPrintGraph(scientifics, i, ptr->dest, ptr->weight);
            ptr = ptr->next;
        }
 
        printf("\n");
    }
}

void getAverage(scientificsNode *scientifics, char scientificName[]){

    scientificsNode *i;

    int count = 0, sum = 0;
    float average;

    for (i = scientifics; i != NULL; i = i->next){

        if (strcmp(i->name_A, scientificName) == 0){

            sum = sum + i->score;
            count++;
        }

        if (strcmp(i->name_B, scientificName) == 0){

            sum = sum + i->score;
            count++;
        }
    }

    average = sum / count;

    printf("El promedio obtenido por %s en sus investigaciones es %f\n", scientificName, average);
}

//-----Ejercicio 3-----

typedef struct node{
	int label; 
	char *name; 
	struct node *next; 
}node;

node vertexGraph3[MAXV];
char *names[MAXV];

void addToList(node *x, int data){

	node *y = (node *)(malloc(sizeof(node)));

	if(y != NULL){

		y->label = data;
		y->name = names[data];

		if(x->next != NULL)
			y->next = x->next;
		else
			y->next = NULL;
		
		x->next = y;
	}
}

void traverseGraph(){

	int array_size = sizeof(vertexGraph3) / sizeof(vertexGraph3[0]);

	printf("Amistades existentes:\n");

	for(int i = 0; i < MAXV; i++){

		node *temp = &vertexGraph3[i];

		printf("%s es amigo de --> ", temp->name);

		if(temp->next != NULL){

			temp = temp->next;

			while(temp != NULL){

				printf("%s", temp->name);

				if(temp->next != NULL)
					printf(", ");

				temp = temp->next;
			}			
		}

		printf("\n");
	}
}

void notFriends(){
	
	int array_size = sizeof(vertexGraph3) / sizeof(vertexGraph3[0]);

    printf("\n---------------------------------------------\n\n");

	printf("Personas sin amigos:\n");

	for(int i=0;i<MAXV;i++){

		node *temp = &vertexGraph3[i];
        
		if(temp->next == NULL){

            printf("%s\n", temp->name);
		}
        else{

            temp = temp->next;		
        }
	}
}

//Funcion para inicializar los nombres
void initNames(){
	names[0] = "Carlos";
	names[1] = "Laura";
	names[2] = "John";
	names[3] = "Ana";
	names[4] = "Lucia";
	names[5] = "Pablo";
}

void displayNames(){

	printf("Amigos:\n");

	for(int i = 0; i < MAXV; i++){

		printf("%s ", names[i]);
	}
	printf("\n\n---------------------------------------------\n\n");
}

int main(){

    int origin, destin;

    createGraph();
    printf("---Muestra grafo creado---\n");
    showGraph();


    printf("-----Insertar Arista-----\n");
    printf("Ingrese la arista de origen:\n");
	fflush(stdin);
	scanf("%d", &origin);

    printf("Ingrese la arista de destino:\n");
	fflush(stdin);
	scanf("%d", &destin);

	insertEdge(origin, destin);

    printf("---Muestra insercion---\n");
    showGraph();

    printf("-----Eliminar Arista-----\n");
    printf("Ingrese la arista de origen:\n");
	fflush(stdin);
	scanf("%d", &origin);

    printf("Ingrese la arista de destino:\n");
	fflush(stdin);
	scanf("%d", &destin);

    
	deleteEdge(origin, destin);

    printf("---Muestra eliminacion---\n");
    showGraph();

    //-----Encontrar la ruta más cercana entre nodos usando el algoritmo de Dijkstra-----

    printf("---Dijkstra---\n");

    int GRAPH[vertex][vertex] = { { 0, 4, 0, 0, 0, 0, 0, 8, 0 },
                                { 4, 0, 8, 0, 0, 0, 0, 11, 0 },
                                { 0, 8, 0, 7, 0, 4, 0, 0, 2 },
                                { 0, 0, 7, 0, 9, 14, 0, 0, 0 },
                                { 0, 0, 0, 9, 0, 10, 0, 0, 0 },
                                { 0, 0, 4, 14, 10, 0, 2, 0, 0 },
                                { 0, 0, 0, 0, 0, 2, 0, 1, 6 },
                                { 8, 11, 0, 0, 0, 0, 1, 0, 7 },
                                { 0, 0, 2, 0, 0, 0, 6, 7, 0 } 
                              };
            
    dijkstra(GRAPH, 0);

    scientificsNode *scientifics = NULL;
    Edge edges[N];

    appendScientifics(&scientifics, "Einstein", "Newtton", 10, 0, 1);
    appendScientifics(&scientifics, "Newtton", "Tesla", 8, 1, 2);
    appendScientifics(&scientifics, "Tesla", "Einstein", 9, 2, 0);
    appendScientifics(&scientifics, "Tesla", "Newtton", 7, 2, 1);
    appendScientifics(&scientifics, "Galilei", "Tesla", 5, 3, 2);
    appendScientifics(&scientifics, "Curie", "Bohr", 9, 4, 5);
    appendScientifics(&scientifics, "Bohr", "Curie", 6, 5, 4);

    scientificsNode *i; 
    int j = 0;

    for (i = scientifics; i != NULL; i = i->next){

        edges[j].src = i->num_A;
        edges[j].dest = i->num_B;
        edges[j].weight = i->score;

        j++;
        
    }
 
    int size = sizeof(edges)/sizeof(edges[0]);
 
    Graph *graph = createGraph2(edges, size);
 
    printGraph(graph, scientifics);

    getAverage(scientifics, "Einstein");
    getAverage(scientifics, "Newtton");
    getAverage(scientifics, "Tesla");
    getAverage(scientifics, "Galilei");
    getAverage(scientifics, "Curie");
    getAverage(scientifics, "Bohr");

    initNames();

	displayNames();
	
	for(int i = 0; i < MAXV; i++){

		vertexGraph3[i].label = i;
		vertexGraph3[i].name = names[i];
		vertexGraph3[i].next = NULL;
	}
	
	addToList(&vertexGraph3[0], 1);
	addToList(&vertexGraph3[0], 3);
	addToList(&vertexGraph3[1], 2);
	addToList(&vertexGraph3[1], 0);
	addToList(&vertexGraph3[1], 4);
	addToList(&vertexGraph3[2], 1);
	addToList(&vertexGraph3[3], 0);
	addToList(&vertexGraph3[3], 2);
	addToList(&vertexGraph3[4], 1);
	
	traverseGraph();

    notFriends();

    return 0;
}