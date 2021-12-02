/* Trabajo de clase 7: metodos de ordenamiento parte 1
Luis Jimenez Bogantes
Valentina Mendez Solano
Jimena Madriz Abarca
Keylin Mendez Cordero */

#include <stdio.h>
#include <stdlib.h>

void swap(int *x, int *y){
    int aux;

    aux = *x;
    *x = *y;
    *y = aux;
}

void print_Array(int array[], int size){
    int i;

    for (i = 0; i < size; i++){
        printf("%d ", array[i]);
    }
    printf("\n");
}

void bubble_Sort(int array[], int size){
    int i, j; 

    for (i = 0; i < size - 1; i++){
        for (j = 0; j < size - i - 1; j++){
            if (array[j] > array[j+1]){
                swap(&array[j], &array[j+1]);
            }
        }
    }
}

void selection_Sort(int array[], int size){
    int i, j, min;

    for (i = 0; i < size - 1; i++){
        min = i;

        for (j = i + 1; j < size; j++){
            if (array[j] < array[min]){
                min = j; 
            }
        }

        swap(&array[min], &array[i]);
    }
}

void insertion_Sort(int array[], int size){
    int i, j, key;

    for (i = 1; i < size; i++){
        key = array[i];
        j = i - 1;

        while (j >= 0 && array[j] > key){
            array[j+1] = array[j];
            j = j - 1;
        }

        array[j+1] = key;
    }
}

int main(void){
    int arrayA[] = {64, 34, 50, 22, 12, 27, 4};
    int sizeA = sizeof(arrayA) / sizeof(arrayA[0]);

    bubble_Sort(arrayA, sizeA);
    printf("Sorted array by bubble sort: \n");
    print_Array(arrayA, sizeA);

    int arrayB[] = {91, 30, 56, 32, 16, 25, 1};
    int sizeB = sizeof(arrayB) / sizeof(arrayB[0]);

    selection_Sort(arrayB, sizeB);
    printf("Sorted array by selection sort: \n");
    print_Array(arrayB, sizeB);

    int arrayC[] = {76, 38, 52, 16, 5, 7, 3};
    int sizeC = sizeof(arrayC) / sizeof(arrayC[0]);

    insertion_Sort(arrayC, sizeC);
    printf("Sorted array by insertion sort: \n");
    print_Array(arrayC, sizeC);

    return 0;
}