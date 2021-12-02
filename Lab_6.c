/* Laboratorio 6
Luis Jimenez Bogantes
Valentina Mendez Solano
Jimena Madriz Abarca
Keyllin Mendez Cordero */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int menu_Queue();
int is_Empty();
int get_Page_Number();
char* get_Name_Document();
char* get_Author();
void enqueue();
void dequeue();
void clear_Buffer();
void dequeue_By_Priority();

int menu_Pile();
int get_Card_Value();
char* get_Card_Symbol();
void push_Card();
void show_Cards();

//-----Reto 1-----

int size = 0;

struct document {
    int pageNumber;
    char *nameDocument;
    char *author;
    struct document *next;
};

typedef struct document Node; 

Node *rear;
Node *front;

int main(void){
    rear = 0;
    front = 0;

	menu_Queue();
	menu_Pile();

    return 0;
}

int menu_Queue(){
    char choose;
    
    do{
        printf("Welcome to print queue\n");
        printf("Choose an option\n");
        printf("1. Send document to print queue\n");
        printf("2. Print document\n");
        printf("3. Print document by priority order\n");
        printf("4. Exit\n");

        choose = getchar();

        switch(choose){
            case '1':
                enqueue();
                break;
            case '2':
                dequeue();
                break;
            case '3':
                dequeue_By_Priority();
                break;

            default:
                break;
        } 
    } while (choose != '4' && choose != EOF);

    return 1;
}

void is_Empty_Wrap(){
    clear_Buffer();

    if (is_Empty()){
        printf("Empty\n");
    }
    else{
        printf("Not Empty\n");
    }
}

void clear_Buffer() {
  while(getchar() != '\n')
    ;
}

int is_Empty(){
    if (!rear){
        return 1;
    }
    else{
        return 0;
    }
}

int get_Page_Number(){
    int pageNumber;

    printf("Enter the number of pages:\n");
    scanf("%d", &pageNumber);

    return pageNumber;
}

char* get_Name_Document(){
    char character, *name;  
    int i = 0;

    name = (char*) malloc(sizeof(char)*100);

    printf("Enter the name document:\n");

    while((character = getchar()) != EOF && character != '\n'){
        name[i++] = character;
    }

    return name;
}

char* get_Author(){
    char character, *author;  
    int i = 0;

    author = (char*) malloc(sizeof(char)*100);

    printf("Enter the author:\n");

    while((character = getchar()) != EOF && character != '\n'){
        author[i++] = character;
    }

    return author;
}

void enqueue(){
    Node *newNode; 
    Node *aux;

    newNode = (Node*) malloc(sizeof(Node));
    clear_Buffer();

    newNode->nameDocument = get_Name_Document();
    newNode->author = get_Author();
    newNode->pageNumber = get_Page_Number();

    if (is_Empty()){
        rear = newNode;
        front = newNode;
        size++;
    }
    else{
        aux = rear;
        rear = newNode;
        rear->next = aux;
        size++;
    }
    printf("The size of queue is: %d documents\n", size);
    clear_Buffer();
}

void dequeue(){
    Node *current;
    Node *aux;

    clear_Buffer();

    if (is_Empty()){
        printf("The queue is empty\n");
    }
    else{
        if (rear == front){
            printf("Name document: %s | Author: %s | Number of pages: %d\n", rear->nameDocument, rear->author, rear->pageNumber);
            rear = 0;
            front = 0;
            size--;
            printf("The size of queue is: %d documents\n", size);
        }
        else{
            current = rear;
            
            while (current != front){
                aux = current;
                current = aux->next;
            }

            size--;

            printf("Name document: %s | Author: %s | Number of pages: %d\n", front->nameDocument, front->author, front->pageNumber);
            printf("The size of queue is: %d documents\n", size);
            free(front);
            front = aux;
        }
    }
}

void dequeue_By_Priority(){
    Node *current;
    Node *aux;

    struct documentByPriority{
    char *name;
    char *author;
    int pages;
    }documentsArray[size];

    int count = 0;
    int sizeAux = size;

    clear_Buffer();

    //Se vacea la cola original y sus datos se pasan al vector

    while (sizeAux != 0){
        if (is_Empty()){
            printf("The queue is empty\n");
            sizeAux = 0;
        }
        else{
            if (rear == front){
                documentsArray[count].name = front->nameDocument;
                documentsArray[count].author = front->author;
                documentsArray[count].pages = front->pageNumber;

                rear = 0;
                front = 0;

                count++;
                sizeAux--;
            }
            else{
                current = rear;
                
                while (current != front){
                    aux = current;
                    current = aux->next;
                }

                documentsArray[count].name = front->nameDocument;
                documentsArray[count].author = front->author;
                documentsArray[count].pages = front->pageNumber;

                count++;
                sizeAux--;

                free(front);
                front = aux;
            }
        }
    }

    //Se ordena el vector

    struct aux{
        char *nameAux;
        char *authorAux;
        int pagesAux;
    }auxArray[1];

    int i, j;

    for (i = 1; i < size; i++){
        for (j = 0; j < size - i; j++){
            if (documentsArray[j].pages > documentsArray[j+1].pages){
                auxArray->nameAux = documentsArray[j].name;
                auxArray->authorAux = documentsArray[j].author;
                auxArray->pagesAux = documentsArray[j].pages;

                documentsArray[j].name = documentsArray[j+1].name;
                documentsArray[j].author = documentsArray[j+1].author;
                documentsArray[j].pages = documentsArray[j+1].pages;

                documentsArray[j+1].name = auxArray->nameAux;
                documentsArray[j+1].author = auxArray->authorAux;
                documentsArray[j+1].pages = auxArray->pagesAux;
            }
        }
    }

    int toDelete = 1;

    if (size == 0){
        printf("The queue is empty\n");
    }
    else{
        for (i = 0; i < size; i++){
            printf("Name document: %s | Autor: %s | Number of pages: %d\n", documentsArray[i].name, documentsArray[i].author, documentsArray[i].pages);
        }

        //Se borran todos los elementos del vector

        while (size != 0){
            for (i = toDelete - 1; i < size - 1; i++){
                documentsArray[i] = documentsArray[i + 1];
            }

            size--;
        }

        if (size == 0){
            printf("The documents were printed successfully\nThe queue is empty\n");
        }
    }
}

//-----Reto 2-----

struct Card{
    int cardValue;
    char *cardSymbol;
    struct Card *next;
};

typedef struct Card NodePile;

NodePile *head = NULL;

int get_Card_Value(){
    int value;

    printf("Insert card value\n");
    scanf("%d", &value);

    return value;
}

char* get_Card_Symbol(){
    char character,*symbol;
    int i = 0;

    symbol = (char*) malloc(sizeof(char)*100);

    printf("Insert card symbol\n");
    while( (character = getchar() ) != EOF && character != '\n') {
        symbol[i++] = character;
    }

    return symbol;
}

void push_Card(){
    int resultCardSymbol, resultCardValue;
    NodePile *newCard = (struct Card*) malloc(sizeof(struct Card));

    if (newCard == NULL){
        printf("Error. Memory not available to create the new card node\n");
    }

    newCard->cardValue = get_Card_Value();
    clear_Buffer();
    newCard->cardSymbol = get_Card_Symbol();

    if (head != NULL){
        if (newCard->cardValue < head->cardValue){
            resultCardValue = 0;
        }
        else{
            resultCardValue = 1;
        }

        resultCardSymbol = strcmp(newCard->cardSymbol, head->cardSymbol);
    }

    if (head == NULL){
        newCard->next = head;
        head = newCard;
        printf("Card inserted successfully\n");
    }
    else{
        if (resultCardValue == 0 && resultCardSymbol != 0){
            newCard->next = head;
            head = newCard;
            printf("Card inserted successfully\n");
        }
        else{
            printf("Error\nUnable to stack the card because its value is greater than the previously stacked card and both have the same symbol\n");
        }
    }
}

void show_Cards(){
    if (head == NULL){
        printf("The pile is empty\n");
    }
    else{
        NodePile *aux = head;

        printf("-----Start-----\n");

        while (aux != NULL){
            printf("Card value: %d\n", aux->cardValue);
            printf("Card symbol: %s\n", aux->cardSymbol);

            aux = aux->next;
        }

        printf("-----End-----\n");
    }
}

int menu_Pile(){
    char choose;
    
    do{
        printf("Welcome to cards pile\n");
        printf("Choose an option\n");
        printf("1. Insert card\n");
        printf("2. Show cards pile\n");
        printf("3. Exit\n");

        choose = getchar();

        switch(choose){
            case '1':
                push_Card();
                break;
            case '2':
                show_Cards();
                break;

            default:
                break;
        } 
    } while (choose != '3' && choose != EOF);

    return 1;
}