#include <stdio.h>

int binarySearch(int list[], int len, int item){
    
    int low = 0;
    int high = len;
    
    while (low <= high){
        
        int mid = (low + high) / 2;
        int guess = list[mid];
        
        if(guess == item)
            return mid;
        else if (guess > item)
            high = mid - 1;
        else
            low = mid + 1;
        
    }
    
    return -1;
    
}

int main(){
    
    int list[] = {1, 3, 5, 7, 9};
    int len = sizeof(list) / sizeof(list[0]);

    printf("%d\n", binarySearch(list, 3, len));
    
}