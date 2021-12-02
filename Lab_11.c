/* Laboratorio 11: monticulos binarios
    Estudiantes:
Luis Jimenez Bogantes
Valentina Mendez Solano
Jimena Madriz Abarca
Keylin Mendez Cordero */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct students{
    char name[100];
    char career[100];
    int indentificationCard;
    int average;
    struct students* next;
}studentsNode;

int size = 0;

void clearBuffer() {
  while((getchar()) != '\n');
}

void swap(int *a, int *b){
    int aux;

    aux = *b;
    *b = *a;
    *a = aux;
}

void heapify(int array[], int size, int i){

    if (size == 1){

        printf("Single element in the heap");
    }
    else{

        int root = i;
        int letf = 2 * i + 1;
        int right = 2 * i + 2;

        if (letf < size && array[letf] > array[root]){
            root = letf;
        }
        if (right < size && array[right] > array[root]){
            root = right;
        }
        if (root != i){

        swap(&array[i], &array[root]);
        heapify(array, size, root);
        }
    }
}

void insertHeap(int array[], int data){

    if (size == 0){
        array[0] = data;
        size += 1;
    }
    else{

        array[size] = data;
        size += 1;

        for (int i = size / 2 - 1; i >= 0; i--){
        heapify(array, size, i);
        }
    }
}

studentsNode * createNode(char name[], char career[], int id, int average){

    studentsNode *newNode = NULL;
    newNode = (studentsNode *) malloc(sizeof(studentsNode));

    strcpy(newNode->name, name);
    strcpy(newNode->career, career);
    newNode->indentificationCard = id;
    newNode->average = average;

    newNode->next = NULL;

    return newNode;
}

void append(studentsNode **students, int averageArray[]){

    char name[100];
    printf("Ingrese el nombre del estudiante\n");
    fgets(name, sizeof(name), stdin);

    int id;
    printf("Ingrese el numero de cedula del estudiante\n");
    scanf("%d", &id);

    clearBuffer();

    char career[100];
    printf("Ingrese la carrera que estudia el estudiante\n");
    fgets(career, sizeof(career), stdin);

    int average;
    printf("Ingrese el promedio ponderado del estudiante\n");
    scanf("%d", &average);
    insertHeap(averageArray, average);

    studentsNode *newNode = createNode(name, career, id, average);
    studentsNode *last = *students;

    if (*students == NULL){
        *students = newNode;
        printf("Estudiante registrado exitosamente\n");
        return;
    }

    while (last->next != NULL){
        last = last->next;
    }

    last->next = newNode;
    printf("Estudiante registrado exitosamente\n");

    return;
}

void showHeap(int array[]){

    printf("-----Average Heap-----\n");

    for (int i = 0; i < size; ++i){

        printf("%d ", array[i]);
    }

    printf("\n");
}

void deleteHeap(int array[], int data){

    int i;

    for (i = 0; i < size; i++){

        if (data == array[i]){
            break;
        }
    }

    swap(&array[i], &array[size - 1]);
    size -= 1;

    for (i = size / 2 - 1; i >= 0; i--){

        heapify(array, size, i);
    }
}

void showStudent(studentsNode *students, int data){

    studentsNode *i;

    for (i = students; i != NULL; i = i->next){
        
        if (i->average == data){

            printf("-----Informacion del estudiante-----\n");
            printf("Nombre: %s", i->name);
            printf("Cedula: %d\n", i->indentificationCard);
            printf("Carrera: %s", i->career);
            printf("Ponderado: %d\n", i->average);
        }
    }
}

void bubble_Sort(int array[], int size){
    int i, j; 

    for (i = 0; i < size - 1; i++){
        for (j = 0; j < size - i - 1; j++){
            if (array[j] < array[j+1]){
                swap(&array[j], &array[j+1]);
            }
        }
    }
}

void showAllStudents(studentsNode *students, int averageArray[]){

    int copy[1000];
    int j = 0, i, value;

    for (i = 0; i < size; i++){

        copy[j] = averageArray[i];
        j++;
    }

    bubble_Sort(copy, size);

    for (i = 0; i < size; i++){

        value = copy[i];
        showStudent(students, value);
    }
}

int main(){

    studentsNode *students = NULL;
    int choice = 0, decision, quantityStudents, value;
    int averageArray[1000];
    bool flag = true;

    while (true){

        printf("\t\t\t Bienvenido\n");
        printf("Seleccione una opcion\n");
        printf("1. Registrar estudiante\n");
        printf("2. Mostrar estudiantes a los que se les otorgara beca\n");
        printf("3. Mostrar todos los cantdatos a beca\n" );
        printf("4. Salir\n");
        
        scanf("%d", &choice); 

        if (choice == 1){

            while (flag){

                clearBuffer();

                append(&students, averageArray);

                printf("Desea registrar otro estudiante?\n Digite 1 para continuar registrando o digite 0 para salir\n");
                scanf("%d", &decision);

                if (decision != 1){
                    flag = false;
                }
            }
            
            bubble_Sort(averageArray, size);
            showHeap(averageArray);
        }

        if (choice == 2){

            printf("Ingrese la cantidad de estudiantes a los que se ortogara beca:\n");
            scanf("%d", &quantityStudents);

            for (int i = 0; i < quantityStudents; i++){

                value = averageArray[i];
                showStudent(students, value);
                deleteHeap(averageArray, value);
            }

            showHeap(averageArray);
        }

        if (choice == 3){

            showAllStudents(students, averageArray);
        }

        if (choice == 4){
            break;
        }
    }

    return 0;
}