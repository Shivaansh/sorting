#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void swap(int *x,int *y)
{
    int temp=*x;
    *x=*y;
    *y=temp;
}

void bubblesort(int arr[], int size){
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size-i; j++){
            if(arr[j] > arr[j+1]){
                int temp = arr[j+1];
                arr[j+1] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

bool isSorted(int arr[], int size){
    for(int i = 0; i < size-1; i++){
        if(arr[i] > arr[i+1]){
            return false;
        }
    }
    return true;
}

int partition(int arr[], int lo, int hi){
    int pivot = lo;
    int pivotVal = arr[pivot];
    int i = lo, j = hi;

    while(i < j){
        while(arr[i] <= pivotVal){
            i++;
        }
        while(arr[j] > pivotVal){
            j--;
        }
        if(i < j){
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[pivot], &arr[j]);
    return j;
}

void quickSort(int arr[], int lo, int hi){
    if(!isSorted(arr, hi+1)){
        if(lo < hi){
            int pivot = partition(arr, lo, hi);
            quickSort(arr, lo, pivot);
            quickSort(arr, pivot+1, hi);
        }
    }
}

void displayArray(int arr[], int size){
    printf("Array: \n");
    for(int i = 0; i < size; i++){
        printf("%d\n", arr[i]);
    }
}

int main()
{
    printf("Array 1: \n");
    int array1[] = {5, 3, 4, 7, 1, 6, 2};
    displayArray(array1, 7);
    quickSort(array1, 0, 6);
    displayArray(array1, 7);

    printf("Array 2: \n");
    int array2[] = {1, 2, 3, 4, 5, 6, 7};
    displayArray(array2, 7);
    quickSort(array2, 0, 6);
    displayArray(array2, 7);

    printf("Array 3: \n");
    int array3[] = {7, 6, 5, 4, 3, 2, 1};
    displayArray(array3, 7);
    quickSort(array3, 0, 6);
    displayArray(array3, 7);

    printf("Array 4: \n");
    int array4[] = {5, 0, 77, 3, 1, -10, 49};
    displayArray(array4, 7);
    quickSort(array4, 0, 6);
    displayArray(array4, 7);

    printf("Array 1 bubblesort: \n");
    int array1a[] = {5, 3, 4, 7, 1, 6, 2};
    displayArray(array1a, 7);
    bubblesort(array1a, 6);
    displayArray(array1a, 7);

    return 0;
}