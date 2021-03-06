#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node {
    int value;
    struct Node *next;
};

//Helper methods
void swap(int *x,int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

int maxOfArray(int arr[], int size){
    int max = arr[0];
    for(int i = 1; i < size; i++){
        if(arr[i] > max){
            max = arr[i];
        }
    }
    return max;
}

 int numOfDigits(int number){
    int count = 1;
    while(number >= 10){
        count++;
        number = number/10;
    }
    return count;
}

bool isSorted(int arr[], int size){
    for(int i = 0; i < size-1; i++){
        if(arr[i] > arr[i+1]){
            return false;
        }
    }
    return true;
}

void displayArray(int arr[], int size){
    printf("Array: \n");
    for(int i = 0; i < size; i++){
        printf("%d\n", arr[i]);
    }
}

// Bubblesort
void bubblesort(int arr[], int size){
    //for passes
    for(int i = 0; i < size; i++){
        //for comparing adjacent elements
        for(int j = 0; j < size-i; j++){
            if(arr[j] > arr[j+1]){
                int temp = arr[j+1];
                arr[j+1] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

// Quicksort methods
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
        //l == h means there is only one element
        if(lo < hi){
            int pivot = partition(arr, lo, hi);
            quickSort(arr, lo, pivot);
            quickSort(arr, pivot+1, hi);
        }
    }
}

void merge(int arr[], int lo, int mid, int hi){
    int i = lo, j = mid+1, k = lo;
    int buffer[99];

    while(i <= mid && j < hi){
        if(arr[i] < arr[j]){
            buffer[k++] = arr[i++];
        }else{
            buffer[k++] = arr[j++];
        }
    }
    for(; i<=mid; i++){
        buffer[k++] = arr[i];
    }
    for(; j<=hi; j++){
        buffer[k++] = arr[j];
    }

    for(int l = lo; l <= hi; l++){
        arr[l] = buffer[l];
    }
}

void IMergeSort(int arr[], int size){
    //This loop runs log n times, list size always increases by 2x
    int p, l, h, mid, i;
    for(p = 1; p <= size; p = p*2){
        // breaks up main array into arrays of p elements each
        for(i = 0; i+p-1 <= size; i = i+p){
            //lower limit
            l = i;
            //upper limit of each array
            h = i+p-1;
            mid = (l + h)/2;
            merge(arr, l, mid, h);
        }
    }
    //In case array is of odd size, one element is remaining and p/2 = size-1
    if(p/2 < size){
        merge(arr, 0, p/2 - 1, size);
    }
}

void RMergeSort(int arr[], int lo, int hi){
    int mid;
    if(lo < hi){
        mid = (lo + hi)/2;
        RMergeSort(arr, lo, mid);
        RMergeSort(arr, mid+1, hi);
        merge(arr, lo, mid, hi);
    }
}

// Count sort
void countSort(int arr[], int size){
    int j = 0, k= 0, arrayMax = maxOfArray(arr, size);
    int *buffer = (int *)malloc(((arrayMax + 1) * sizeof(int)));

    for(int i = 0; i <= arrayMax; i++){
        buffer[i] = 0;
    }
    for(int i = 0; i < size; i++){
        buffer[arr[i]]++;
    }
    while(j <= arrayMax){
        if(buffer[j] > 0){
            arr[k++] = j;
            buffer[j]--;
        }
        if(buffer[j] == 0){
            j++;
        }
    }
    free(buffer);
}

//Radix Sort
void RadixSort(int arr[], int size){
    struct Node bitset[10];
    int max = maxOfArray(arr, size);
    int passes = numOfDigits(max);

    for(int i = 1; i <= passes; i++){
        int x = i;

        for(int j = 0; j < size; j++){

        }



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

    printf("Array 1 iterative mergesort (odd values): \n");
    int array1b[] = {3, 5, 4, 7, 1, 6, 2};
    IMergeSort(array1b, 7);
    displayArray(array1b, 7);

    printf("Array 1 iterative mergesort (even values): \n");
    int array1c[] = {3, 5, 4, 7, 1, 6, 2, 8};
    IMergeSort(array1c, 8);
    displayArray(array1c, 8);

    printf("Array 2 iterative mergesort (even values): \n");
    int array2b[] = {3, 5, -4, 8, 1, 6};
    IMergeSort(array2b, 6);
    displayArray(array2b, 6);

    printf("Array 2 iterative mergesort (odd values): \n");
    int array2c[] = {3, 5, -4, 7, 1, 6, -2, 8, 75};
    IMergeSort(array2c, 9);
    displayArray(array2c, 9);

    printf("Array 2 recursive mergesort (even values): \n");
    int array2d[] = {3, 5, -4, 8, 1, 6};
    RMergeSort(array2d, 0, 5);
    displayArray(array2d, 6);

    printf("Array 2 recursive mergesort (odd values): \n");
    int array2e[] = {3, 5, -4, 7, 1, 6, -2, 8, 75};
    RMergeSort(array2e, 0,8);
    displayArray(array2e, 9);

    printf("Array 5 countsort: \n");
    int arr5[] = {4, 7, 3, 9, 7, 6};
    displayArray(arr5, 6);
    countSort(arr5, 6);
    displayArray(arr5, 6);

    return 0;
}