#include <stdio.h>
#include <assert.h>

void printfArrInt(int* arr, size_t size);
void BubbleSortInt(int* arr, size_t size);
void ChangeValuesInt(int* elem1, int* elem2);

int main(){
    int arr[] = {2, 1, 6, 8, 2};
    size_t arrSize = sizeof(arr)/sizeof(int);
    
    
    printfArrInt(arr, arrSize);

    BubbleSortInt(arr, arrSize);

    printfArrInt(arr, arrSize);

    return 0;
}


void printfArrInt(int* arr, size_t size){
    assert(arr != 0);

    printf("\n------------\n");
    printf("Array: \n");
    for(int index = 0; index < size; index++){
        printf("[elem %d]: %d\t", index, *(arr + index));
    }
    printf("\n------------\n");
}

void BubbleSortInt(int* arr, size_t size){
    assert(arr != 0);

    for(int nPass = 0; nPass < size; nPass++){
        assert(nPass >= 0 && nPass < size);
        for(int index = 0; index < (size - nPass - 1); index++){
            assert(index >= 0 && index < (size - nPass - 1));
            // printf("nPass = %d; index = %d\n", nPass, index);
            // printfArrInt(arr, size);
            if(arr[index] > arr[index + 1]){
                ChangeValuesInt(&arr[index], &arr[index + 1]);
            }
        }
    }
}

void ChangeValuesInt(int* elem1, int* elem2){
    assert(elem1 != 0);
    assert(elem2 != 0);

    int temp = *elem2;
    *elem2 = *elem1;
    *elem1 = temp;
}