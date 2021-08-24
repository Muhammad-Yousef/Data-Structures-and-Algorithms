#include <stdio.h>
#include <stdlib.h>
#define SIZE 5

int findSmallest(int *arr){
    
    int smallest = arr[0];

    int smallest_index = 0;
    
    for (int i = 1; i < SIZE; i++) {
        
        if (arr[i] < smallest) {
            smallest = arr[i];
            smallest_index = i;
        }
    }
    
    return smallest_index;

}

int *selectionSort(int *arr){

    int *newArr = (int *)malloc(SIZE * sizeof(int));
    
    for (int i = 0; i < SIZE; i++) {
        
        int smallest = findSmallest(arr);
        newArr[i] = arr[smallest];

        arr[smallest] = INT_MAX;
    
    }
    
    return newArr;
}

int main(void) {

    int arr[SIZE] = {5, 3, 6, 2, 10};
    int *sortarr = selectionSort(arr);
    
    for (int i = 0; i < SIZE; i++) {
        printf("%d ", sortarr[i]);
    }
    
    return 0;

}