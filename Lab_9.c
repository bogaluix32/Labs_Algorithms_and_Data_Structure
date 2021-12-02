/*Laboratorio 9
Estudiantes: 
Luis Jiménez Bogantes
Valentina Méndez Solano
Jimena Madriz Abarca
Keylin Méndez Cordero
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//----------Bubble sort with linked simple list----------

typedef struct ListA{
    int data;
    struct ListA* head;
    struct ListA* next;
} nodeA;

nodeA* createNodeA(int num){
    nodeA *newNode = NULL;

    newNode = (nodeA *) malloc(sizeof(nodeA));
    newNode->data = num;
    newNode->next = NULL;

    return newNode;
}

void insertAtBegin(nodeA **ListA, int newData){
    nodeA *newNode = createNodeA(newData);

    newNode->next = *ListA;
    *ListA = newNode;
}

void showListA(nodeA *listA){
    nodeA *i;
    
    for (i = listA; i != NULL; i = i->next){
        printf("%d ", i->data);
    }
    
    printf("\n");
}

void swap(nodeA *numA, nodeA *numB){
    int aux;
    
    aux = numA->data;
    numA->data = numB->data;
    numB->data = aux;
}

void bubbleSort(nodeA *ListA){
    int sort, i;
    nodeA *ptrAux; 
    nodeA *listAux = NULL;

    if (ListA == NULL){
        return;
    }

    do{
        sort = 0;
        ptrAux = ListA;

        while (ptrAux->next != listAux){
            if (ptrAux->data > ptrAux->next->data){
                swap(ptrAux, ptrAux->next);
                sort = 1;
            }

            ptrAux = ptrAux->next;
        }

        listAux = ptrAux;
    } while (sort);
}

//----------Selection sort with linked simple list----------

typedef struct ListB{
    int data;
    struct ListB* head;
    struct ListB* next;
} nodeB;

nodeB* createNodeB(int num){
    nodeB *newNode = NULL;

    newNode = (nodeB *) malloc(sizeof(nodeB));
    newNode->data = num;
    newNode->next = NULL;

    return newNode;
}

void insertAtBeginListB(nodeB **ListB, int newData){
    nodeB *newNode = createNodeB(newData);

    newNode->next = *ListB;
    *ListB = newNode;
}

void showListB(nodeB *ListB){
    nodeB *i;
    
    for (i = ListB; i != NULL; i = i->next){
        printf("%d ", i->data);
    }
    
    printf("\n");
}

void selectionSort(nodeB *ListB){
    int aux;
    nodeB *current = ListB;

    while (current != NULL){
        nodeB *minimum = current;
        nodeB *rightData = current->next;

        while (rightData != NULL){
            if (minimum->data > rightData->data){
                minimum = rightData;
            }

            rightData = rightData->next;
        }

        aux = current->data;
        current->data = minimum->data;
        minimum->data = aux;
        current = current->next;
    }
}

//----------Insertion sort with linked simple list----------

typedef struct ListC{
    int data;
    struct ListC* head;
    struct ListC* next;
} nodeC;

nodeC* createNodeC(int num){
    nodeC *newNode = NULL;

    newNode = (nodeC *) malloc(sizeof(nodeC));
    newNode->data = num;
    newNode->next = NULL;

    return newNode;
}

void insertAtBeginListC(nodeC **ListC, int newData){
    nodeC *newNode = createNodeC(newData);

    newNode->next = *ListC;
    *ListC = newNode;
}

void showListC(nodeC *ListC){
    nodeC *i;
    
    for (i = ListC; i != NULL; i = i->next){
        printf("%d ", i->data);
    }
    
    printf("\n");
}

void sortedInsert(nodeC **sortedList, nodeC *nodeToInsert){
    nodeC *current;

    if (*sortedList == NULL || (*sortedList)->data >= nodeToInsert->data){
        nodeToInsert->next = *sortedList;
        *sortedList = nodeToInsert;
    }
    else{
        current = *sortedList;

        while (current->next != NULL && current->next->data < nodeToInsert->data){
            current = current->next;
        } 

        nodeToInsert->next = current->next;
        current->next = nodeToInsert;
    }
}

void insertionSort(nodeC **ListC){
    nodeC *sortedList = NULL;
    nodeC *current = *ListC;

    while (current != NULL){
        nodeC *aux = current->next;
        sortedInsert(&sortedList, current);
        current = aux;
    }

    *ListC = sortedList;
}

//----------Merge sort with linked doubly list----------

typedef struct ListD{
    int data;
    struct ListD* head;
    struct ListD* previous;
    struct ListD* next;
} nodeD;

nodeD* createNodeD(int num){
	nodeD *newNode;
	newNode = (nodeD *) malloc(sizeof(nodeD));
	newNode->previous = NULL;
	newNode->next = NULL;
	newNode->data = num;	
	
	return newNode;
}

void insertAtBeginDuoblyListD(nodeD **ListD, int newData){
    nodeD *newNode = createNodeD(newData);
    
    if (*ListD == NULL){
        *ListD = newNode;
    }
    else{
        newNode->next = *ListD;
        (*ListD)->previous = newNode;
        *ListD = newNode;
    }
}

void showListD(nodeD *ListD){
    nodeD *i;
    
    for (i = ListD; i != NULL; i = i->next){
        printf("%d ", i->data);
    }
    
    printf("\n");
}

void swapD(nodeD *numA, nodeD *numB){
    int aux;
    
    aux = numA->data;
    numA->data = numB->data;
    numB->data = aux;
}

nodeD *splitList(nodeD *ListD){
    nodeD *fast = ListD;
    nodeD *slow = ListD;

    while (fast->next && fast->next->next){
        fast = fast->next->next;
        slow = slow->next;
    }

    nodeD *current = slow->next;
    slow->next = NULL;
    
    return current;
}

nodeD *merge(nodeD *firstList, nodeD *secondList){
    if (firstList == NULL){
        return secondList;
    }

    if (secondList == NULL){
        return firstList;
    }

    if (firstList->data < secondList->data){
        firstList->next = merge(firstList->next, secondList);
        firstList->next->previous = firstList;
        firstList->previous = NULL;
        return firstList;
    }
    else{
        secondList->next = merge(firstList, secondList->next);
        secondList->next->previous = secondList;
        secondList->previous = NULL;
        return secondList;
    }
}

nodeD *mergeSort(nodeD *ListD){
    if (ListD == NULL || ListD->next == NULL){
        return ListD;
    }

    nodeD *second = splitList(ListD);
    
    ListD = mergeSort(ListD);
    second = mergeSort(second);

    return merge(ListD, second);
}

//----------Quick sort with linked doubly list----------

typedef struct ListF{
    int data;
    struct ListF* head;
    struct ListF* previous;
    struct ListF* next;
} nodeF;

nodeF* createNodeF(int num){
	nodeF *newNode;
	newNode = (nodeF *) malloc(sizeof(nodeF));
	newNode->previous = NULL;
	newNode->next = NULL;
	newNode->data = num;	
	
	return newNode;
}

void insertAtBeginDuoblyListF(nodeF **ListF, int newData){
    nodeF *newNode = createNodeF(newData);
    
    if (*ListF == NULL){
        *ListF = newNode;
    }
    else{
        newNode->next = *ListF;
        (*ListF)->previous = newNode;
        *ListF = newNode;
    }
}

void showListF(nodeF *ListF){
    nodeF *i;
    
    for (i = ListF; i != NULL; i = i->next){
        printf("%d ", i->data);
    }
    
    printf("\n");
}

void swapF(nodeF *numA, nodeF *numB){
    int aux;
    
    aux = numA->data;
    numA->data = numB->data;
    numB->data = aux;
}

nodeF *findLastNode(nodeF *ListF){
    while (ListF && ListF->next){
        ListF = ListF->next;
    }

    return ListF;
}

nodeF *partition(nodeF *ListF, nodeF *lastNode){
    int pivot = lastNode->data;
    nodeF *i = ListF->previous;
    nodeF *j;

    for (j = ListF; j != lastNode; j = j->next){
        if (j->data <= pivot){
            i = (i == NULL) ? ListF : i->next;
            swapF(i, j);
        }
    }

    i = (i == NULL) ? ListF : i->next;
    swapF(i, lastNode);

    return i;
}

void quick(nodeF *ListF, nodeF *lastNode){
    if (lastNode != NULL && ListF != lastNode && ListF != lastNode->next){
        nodeF *partitionIndex = partition(ListF, lastNode);
        quick(ListF, partitionIndex->previous);
        quick(partitionIndex->next, lastNode);
    }
}

void quickSort(nodeF *ListF){
    nodeF *lastNode = findLastNode(ListF);

    quick(ListF, lastNode);
}

//----------Lineal search with linked simple list----------

typedef struct ListG{
    int data;
    struct ListG* head;
    struct ListG* next;
} nodeG;

nodeG* createNodeG(int num){
    nodeG *newNode = NULL;

    newNode = (nodeG *) malloc(sizeof(nodeG));
    newNode->data = num;
    newNode->next = NULL;

    return newNode;
}

void insertAtBeginListG(nodeG **ListG, int newData){
    nodeG *newNode = createNodeG(newData);

    newNode->next = *ListG;
    *ListG = newNode;
}

void showListG(nodeG *ListG){
    nodeG *i;
    
    for (i = ListG; i != NULL; i = i->next){
        printf("%d ", i->data);
    }
    
    printf("\n");
}

int linealSearch(nodeG *ListG, int num){
    int position = 0;
    nodeG * current = ListG;

    while (current != NULL){
        if (current->data == num){
            return position;
        }

        position++;
        current = current->next;
    }

    return -1;
}

//----------Binary search with linked simple list----------

typedef struct ListH{
    int data;
    struct ListH* head;
    struct ListH* next;
} nodeH;

nodeH* createNodeH(int num){
    nodeH *newNode = NULL;

    newNode = (nodeH *) malloc(sizeof(nodeH));
    newNode->data = num;
    newNode->next = NULL;

    return newNode;
}

void insertAtBeginListH(nodeH **ListH, int newData){
    nodeH *newNode = createNodeH(newData);

    newNode->next = *ListH;
    *ListH = newNode;
}

void showListH(nodeH *ListH){
    nodeH *i;
    
    for (i = ListH; i != NULL; i = i->next){
        printf("%d ", i->data);
    }
    
    printf("\n");
}

nodeH *findMiddle(nodeH *start, nodeH *final){
    if (start == NULL){
        return NULL;
    }

    nodeH *slow = start;
    nodeH *fast = start->next;

    while (fast != final){
        fast = fast->next;

        if (fast != final){
            slow = slow->next;
            fast = fast->next;
        }
    }

    return slow;
}

nodeH *binarySearch(nodeH *ListH, int num){
    nodeH *start = ListH;
    nodeH *last = NULL;

    do{
        nodeH *middle = findMiddle(start, last);

        if (middle == NULL){
            return NULL;
        }

        if (middle->data == num){
            return middle;
        }
        else if(middle->data < num){
            start = middle->next;
        }
        else{
            last = middle;
        }
    } while (last == NULL || last != start);

    return NULL;
}

void selectionSortAux(nodeH *ListH){
    int aux;
    nodeH *current = ListH;

    while (current != NULL){
        nodeH *minimum = current;
        nodeH *rightData = current->next;

        while (rightData != NULL){
            if (minimum->data > rightData->data){
                minimum = rightData;
            }

            rightData = rightData->next;
        }

        aux = current->data;
        current->data = minimum->data;
        minimum->data = aux;
        current = current->next;
    }
}

int linealSearchAux(nodeH *ListH, int num){
    int position = 0;
    nodeH * current = ListH;

    while (current != NULL){
        if (current->data == num){
            return position;
        }

        position++;
        current = current->next;
    }

    return -1;
}

//----------Efficiency test with lineal and binary search in linked simple list----------

//----------Lineal search----------

typedef struct ListI{
    int data;
    struct ListI* head;
    struct ListI* next;
} nodeI;

nodeI* createNodeI(int num){
    nodeI *newNode = NULL;

    newNode = (nodeI *) malloc(sizeof(nodeI));
    newNode->data = num;
    newNode->next = NULL;

    return newNode;
}

void insertAtBeginListI(nodeI **ListI, int newData){
    nodeI *newNode = createNodeI(newData);

    newNode->next = *ListI;
    *ListI = newNode;
}

void showListI(nodeI *ListI){
    nodeI *i;
    
    for (i = ListI; i != NULL; i = i->next){
        printf("%d ", i->data);
    }
    
    printf("\n");
}

int linealSearchTest(nodeI *ListI, int num){
    int position = 0;
    nodeI * current = ListI;

    while (current != NULL){
        if (current->data == num){
            return position;
        }

        position++;
        current = current->next;
    }

    return -1;
}

//----------Binary search----------

typedef struct ListJ{
    int data;
    struct ListJ* head;
    struct ListJ* next;
} nodeJ;

nodeJ* createNodeJ(int num){
    nodeJ *newNode = NULL;

    newNode = (nodeJ *) malloc(sizeof(nodeJ));
    newNode->data = num;
    newNode->next = NULL;

    return newNode;
}

void insertAtBeginListJ(nodeJ **ListJ, int newData){
    nodeJ *newNode = createNodeJ(newData);

    newNode->next = *ListJ;
    *ListJ = newNode;
}

void showListJ(nodeJ *ListJ){
    nodeJ *i;
    
    for (i = ListJ; i != NULL; i = i->next){
        printf("%d ", i->data);
    }
    
    printf("\n");
}

nodeJ *findMiddleAux(nodeJ *start, nodeJ *final){
    if (start == NULL){
        return NULL;
    }

    nodeJ *slow = start;
    nodeJ *fast = start->next;

    while (fast != final){
        fast = fast->next;

        if (fast != final){
            slow = slow->next;
            fast = fast->next;
        }
    }

    return slow;
}

nodeJ *binarySearchForTest(nodeJ *ListJ, int num){
    nodeJ *start = ListJ;
    nodeJ *last = NULL;

    do{
        nodeJ *middle = findMiddleAux(start, last);

        if (middle == NULL){
            return NULL;
        }

        if (middle->data == num){
            return middle;
        }
        else if(middle->data < num){
            start = middle->next;
        }
        else{
            last = middle;
        }
    } while (last == NULL || last != start);

    return NULL;
}

void selectionSortForTest(nodeJ *ListJ){
    int aux;
    nodeJ *current = ListJ;

    while (current != NULL){
        nodeJ *minimum = current;
        nodeJ *rightData = current->next;

        while (rightData != NULL){
            if (minimum->data > rightData->data){
                minimum = rightData;
            }

            rightData = rightData->next;
        }

        aux = current->data;
        current->data = minimum->data;
        minimum->data = aux;
        current = current->next;
    }
}

int main(void){
    int i;
    
    printf("----------Bubble sort----------\n");
    
    int array[] = {10, 48, 2, 12, 4, 75};
    int size = sizeof(array) / sizeof(array[0]);
    nodeA *ListA = NULL;

    for (i = 0; i < size; i++){
        insertAtBegin(&ListA, array[i]);
    }

    printf("List before sorting\n");
    showListA(ListA);

    bubbleSort(ListA);

    printf("List after sorting\n");
    showListA(ListA);
    
    printf("----------Selection sort----------\n");
    
    int arrayB[] = {8, 42, 1, 11, 3, 68};
    int sizeB = sizeof(arrayB) / sizeof(arrayB[0]);
    nodeB *ListB = NULL;

    for (i = 0; i < sizeB; i++){
        insertAtBeginListB(&ListB, arrayB[i]);
    }

    printf("List before sorting\n");
    showListB(ListB);

    selectionSort(ListB);

    printf("List after sorting\n");
    showListB(ListB);
    
    printf("----------Insertion sort----------\n");
    
    int arrayC[] = {9, 38, 3, 14, 5, 88};
    int sizec = sizeof(arrayC) / sizeof(arrayC[0]);
    nodeC *ListC = NULL;

    for (i = 0; i < sizec; i++){
        insertAtBeginListC(&ListC, arrayC[i]);
    }

    printf("List before sorting\n");
    showListC(ListC);

    insertionSort(&ListC);

    printf("List after sorting\n");
    showListC(ListC);

    printf("----------Merge sort----------\n");
    
    int arrayD[] = {7, 36, 5, 16, 9, 62};
    int sizeD = sizeof(arrayD) / sizeof(arrayD[0]);
    nodeD *ListD = NULL;

    for (i = 0; i < sizeD; i++){
        insertAtBeginDuoblyListD(&ListD, arrayD[i]);
    }

    printf("List before sorting\n");
    showListD(ListD);

    ListD = mergeSort(ListD);

    printf("List after sorting\n");
    showListD(ListD);
    
    printf("----------Quick sort----------\n");

    int arrayF[] = {9, 28, 78, 14, 5, 50};
    int sizeF = sizeof(arrayF) / sizeof(arrayF[0]);
    nodeF *ListF = NULL;

    for (i = 0; i < sizeF; i++){
        insertAtBeginDuoblyListF(&ListF, arrayF[i]);
    }

    printf("List before sorting\n");
    showListF(ListF);

    quickSort(ListF);

    printf("List after sorting\n");
    showListF(ListF);
    
    printf("----------Lineal search----------\n");

    int arrayG[] = {10, 48, 2, 12, 4, 75};
    int sizeG = sizeof(arrayG) / sizeof(arrayG[0]);
    nodeG *ListG = NULL;

    for (i = 0; i < sizeG; i++){
        insertAtBeginListG(&ListG, arrayG[i]);
    }

    printf("The list is\n");
    showListG(ListG);

    int dataA = 48;
    int position = linealSearch(ListG, dataA);

    if (position == -1){
        printf("Data %d not found\n-1\n", dataA);
    }
    else{
        printf("The position of the data %d in the list is: position -> %d\n", dataA, position);
    }
    
    printf("----------Binary search----------\n");

    int arrayH[] = {1, 6, 10, 24, 53, 72};
    int sizeH = sizeof(arrayH) / sizeof(arrayH[0]);
    nodeH *ListH = NULL;

    for (i = 0; i < sizeH; i++){
        insertAtBeginListH(&ListH, arrayH[i]);
    }

    printf("The list is\n");
    selectionSortAux(ListH);
    showListH(ListH);

    int dataB = 53;

    if (binarySearch(ListH, dataB) == NULL){
        printf("Data %d not found\n-1\n", dataB);
    }
    else{
        int pos = linealSearchAux(ListH, dataB);
        printf("Data found in position %d\n", pos);
    }
    
    printf("----------Efficiency test with lineal and binary search----------\n");

    nodeI *ListI = NULL;
    nodeJ *ListJ = NULL; 
    int num, numB, random, randomB;

    srand(time(0));
    
    for (i = 0; i < 500; i++){
        num = (rand() % (500 - 1 + 1)) + 1;
        insertAtBeginListI(&ListI, num);
    }

    srand(time(0));

    for (i = 0; i < 500; i++){
        numB = (rand() % (500 - 1 + 1)) + 1;
        insertAtBeginListJ(&ListJ, numB);
    }

    printf("The first list is\n");
    showListI(ListI);

    printf("The second list is\n");
    showListJ(ListJ);

    random = (rand() % (500 - 1 + 1)) + 1;
    printf("The fisrt random number is: %d\n", random);

    randomB = (rand() % (500 - 1 + 1)) + 1;
    printf("The second random number is: %d\n", randomB);

    clock_t time;
    time = clock();

    int positionResult = linealSearchTest(ListI, random);

    if (positionResult == -1){
        printf("Data %d not found\n-1\n", random);
    }
    else{
        printf("The position of the data %d in the list is: position -> %d\n", random, positionResult);
    }

    time = clock() - time;
    double timeTaken = ((double)time) / CLOCKS_PER_SEC; 

    printf("The lineal search took %f seconds to execute\n", timeTaken);

    clock_t timeBinarySearch;
    timeBinarySearch = clock();

    selectionSortForTest(ListJ);
    printf("Sorted list for binary search\n");
    showListJ(ListJ);

    if (binarySearchForTest(ListJ, randomB) == NULL){
        printf("Data %d not found\n-1\n", randomB);
    }
    else{
        printf("Data %d found in the list\n", randomB);
    }

    timeBinarySearch = clock() - timeBinarySearch;
    double timeTakenBinarySearch = ((double)timeBinarySearch) / CLOCKS_PER_SEC; 

    printf("The binary search took %f seconds to execute\n", timeTakenBinarySearch);

    return 0;
}

/*
---------------Tiempos de ejecucion---------------
-----Ejecucion 1-----
Busqueda lineal: 0.001000
Busqueda binary: 0.031000
Diferencia: 0.03 milisegundos
-----Ejecucion 2-----
Busqueda lineal: 0.000000
Busqueda binary: 0.034000
Diferencia: 0.034 milisegundos
-----Ejecucion 3-----
Busqueda lineal: 0.000000
Busqueda binary: 0.026000
Diferencia: 0.026 milisegundos
-----Ejecucion 4-----
Busqueda lineal: 0.001000
Busqueda binary: 0.038000
Diferencia: 0.037 milisegundos
-----Ejecucion 5-----
Busqueda lineal: 0.001000
Busqueda binary: 0.077000
Diferencia: 0.076 milisegundos
-----Ejecucion 6-----
Busqueda lineal: 0.000000
Busqueda binary: 0.055000
Diferencia: 0.055 milisegundos
-----Ejecucion 7-----
Busqueda lineal: 0.000000
Busqueda binary: 0.034000
Diferencia: 0.034 milisegundos
-----Ejecucion 8-----
Busqueda lineal: 0.001000
Busqueda binary: 0.038000
Diferencia: 0.037 milisegundos
-----Ejecucion 9-----
Busqueda lineal: 0.000000
Busqueda binary: 0.048000
Diferencia: 0.048 milisegundos
-----Ejecucion 10-----
Busqueda lineal: 0.000000
Busqueda binary: 0.050000
Diferencia: 0.05 milisegundos
*/