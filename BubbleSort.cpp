#include <stdio.h>
#include <string.h>
#include <assert.h>

void PrintfArr(void* arr, size_t size, size_t size_elem, const char* format);
void Swap(const void* elem1, const void* elem2);
void BubbleSort(void* arr, size_t size, size_t, size_t size_elem,
                int(*CompareFunc)(const void* a, const void* b));

int main(){

    int N_int = 0;
    scanf("%d", &N_int);
    int ArrToSort[N_int] = {};
    for(int i = 0; i < N_int; i++){
        scanf("%d", &ArrToSort[i]);
    }
    PrintfArr((void *)ArrToSort, N_int, sizeof(ArrToSort[0]), "%d");
    return 0;
}
void printfArrInt(int* arr, size_t size){
    assert(arr != 0);

    for(int i = 0; i < size; i++){
        assert(i >= 0 && i < size);
        printf("arr[%d] = %d\t", i, arr[i]);
    }
    printf("\n");
}

void PrintfArr(void* arr, size_t size, size_t size_elem/*, const char* format*/){
    assert(arr != 0);

    for(int i = 0; i < size; i++){
        assert(i >= 0 && i < size);

        printf("arr[%d] = 0", i);
        printf(format, *((char* )arr + i * size_elem));
    }
    printf("\n");

}

void BubbleSort(void* arr, size_t size, size_t size_elem,
                int(*CompareFunc)(const void* a, const void* b)){
    assert(arr != 0);

    for(int nPass = 0; nPass < size; nPass++){
        assert(nPass >= 0 && nPass < size);
        for(int i = 0; i < size - nPass - 1; i++){
            assert(i >= 0 && i < (size - nPass - 1));
            
            if((*CompareFunc)((const void* )((char*)arr + i * size_elem), (const void *)((char*)arr + (i+1) * size_elem)) > 0){
                Swap((const void* )((char*)arr + i * size_elem), (const void *)((cha*)arr + (i+1) * size_elem));
            }
        }
    }

}

void Swap(const void* elem1, const void* elem2){
    const void* temp = elem2;
    elem2 = elem1;
    elem1 = temp;
}

int CompareUp(const void* elem1, const void* elem2){
    const int val1 = *(const int *)elem1;
    const int val2 = *(const int *)elem2;
    if(val1 < val2) return -1;
    if(val1 > val2) return 1;
    return 0;
}

int CompareDown(const void* elem1, const void* elem2){
    const int val1 = *(const int *)elem1;
    const int val2 = *(const int *)elem2;
    if(val1 > val2) return -1;
    if(val1 < val2) return 1;
    return 0;
}

// void BubbleSortInt(int* arr, size_t size){
//     assert(arr != 0);

//     for(int nPass = 0; nPass < size; nPass++){
//         assert(nPass >= 0 && nPass < size);
//         for(int i = 0; i < size - nPass - 1; i++){
//             assert(i >= 0 && i < (size - nPass - 1));
            
//             if(arr[i] > arr[i + 1]){
//                 ChangeValuesInt(&arr[i], &arr[i + 1]);
//             }
//         }
//     }
// }