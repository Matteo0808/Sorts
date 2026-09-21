#include <stdio.h>
#include <string.h>
#include <assert.h>

void printfArrInt(int* arr, size_t size);

int main(){
    
    int N = 0;
    scanf("%d", &N);
    int ArrToSort[N] = {};

    for(int i = 0; i < N; i++){
        scanf("%d", &ArrToSort[i]);
    }
    printfArrInt(ArrToSort, N);
    
    QuickSortInt(ArrToSort, N);

    printfArrInt(ArrToSort, N);

    return 0;
}


void printfArrInt(int* arr, size_t size){
    assert(arr != 0);

    for(int i = 0; i < size; i++){
        printf("arr[%d] = %d\t", i, arr[i]);
    }
    printf("\n");
}

void QuickSortInt(int* arr, size_t size){

}