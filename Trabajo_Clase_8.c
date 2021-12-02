/* Trabajo de clase 8: metodos de ordenamiento parte 2
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

void shell_Sort(int array[], int size){
    int distance, i, aux, j;

    for (distance = size/2; distance > 0; distance /= 2){
        for (i = distance; i < size; i++){
            aux = array[i];

            for (j = i; j >= distance && array[j - distance] > aux; j -= distance){
                array[j] = array[j - distance];
            }

            array[j] = aux;
        }
    }
}

void merge(int array[], int left, int size, int right){
    int i, j, k; 
    int sizeLeft = size - left + 1;
    int sizeRight = right - size;

    int leftArray[sizeLeft], rightArray[sizeRight];

    for (i = 0; i < sizeLeft; i++){
        leftArray[i] = array[left + i];
    }
    
    for (j = 0; j < sizeRight; j++){
        rightArray[j] = array[size + 1 + j];
    }

    i = 0; 
    j = 0;
    k = left;

    while ( i < sizeLeft && j < sizeRight){
        if (leftArray[i] <= rightArray[j]){
            array[k] = leftArray[i];
            i++;
        }
        else{
            array[k] = rightArray[j];
            j++;
        }

        k++;
    }

    while (i < sizeLeft){
        array[k] = leftArray[i];
        i++;
        k++;
    }

    while (j < sizeRight){
        array[k] = rightArray[j];
        j++;
        k++;
    }

}

void merge_Sort(int arr[], int l, int r){
	if (l < r) {
        int m = l + (r - l) / 2;

        merge_Sort(arr, l, m);
        merge_Sort(arr, m + 1, r);
  
        merge(arr, l, m, r);
    }
}

int partition(int array[], int lowIndex, int highIndex){
    int pivot = array[highIndex];
    int i = (lowIndex -1);
    int j;

    for (j = lowIndex; j <= highIndex - 1; j++){
        if (array[j] < pivot){
            i++;
            swap(&array[i], &array[j]);
        }
    }

    swap(&array[i + 1], &array[highIndex]);

    return (i + 1);
}

void quickSort(int array[], int lowIndex, int highIndex){
    if (lowIndex < highIndex){
        int partitionIndex = partition(array, lowIndex, highIndex);

        quickSort(array, lowIndex, partitionIndex - 1);
        quickSort(array, partitionIndex + 1, highIndex);
    }
}

int main(void){
    int arrayA[] = {28, 70, 50, 22, 12, 8, 2};
    int sizeA = sizeof(arrayA) / sizeof(arrayA[0]);

    shell_Sort(arrayA, sizeA);
    printf("Sorted array by shell sort: \n");
    print_Array(arrayA, sizeA);

    int arrayB[] = {18, 70, 25, 22, 12, 43, 2};
    int sizeB = sizeof(arrayB) / sizeof(arrayB[0]);

    merge_Sort(arrayB, 0, sizeB - 1);
    printf("Sorted array by merge sort: \n");
    print_Array(arrayB, sizeB);
    
    int arrayC[] = {10, 7, 8, 9, 1, 5};
    int sizeC = sizeof(arrayC) / sizeof(arrayC[0]);

    quickSort(arrayC, 0, sizeC - 1);
    printf("Sorted array by quick sort: \n");
    print_Array(arrayC, sizeC);

    return 0;
}