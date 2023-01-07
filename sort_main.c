#include <stdio.h>
#include <string.h>
#include "methods.h"

#define SIZE 50

int main(){
    
    int arr[SIZE];
    for (size_t i = 0; i < SIZE; i++)
    {
        scanf("%d", &arr[i]);
    }
    
    insertion_sort(arr, SIZE);
    print_int_arr(arr, SIZE);

    return 0;
}