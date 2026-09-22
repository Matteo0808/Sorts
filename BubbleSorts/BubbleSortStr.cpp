#include <stdio.h>
#include <string.h>
#include <assert.h>

void printfArrStr(const char** arr, size_t size);
void BubbleSortStr(const char** arr, size_t size);
void ChangeValuesStr(const char** elem1, const char** elem2);

int main(){

    const char* arr[] = {"str1", "2", "str3", "strstr4", "Str5"};
    size_t arrSize = sizeof(arr)/sizeof(arr[0]);

    printfArrStr(arr, arrSize);

    BubbleSortStr(arr, arrSize);

    printfArrStr(arr, arrSize);
}

void printfArrStr(const char** arr, size_t size){
    assert(arr != 0);

    printf("\n------------\n");
    printf("Array: \n");
    for(int index = 0; index < size; index++){
        printf("[elem %d]: %s\t", index, *(arr + index));
    }
    printf("\n------------\n");
}

void BubbleSortStr(const char** arr, size_t size){
    assert(arr != 0);

    for(int nPass = 0; nPass < size; nPass++){
        assert(nPass >= 0 && nPass < size);
        for(int index = 0; index < (size - nPass - 1); index++){
            assert(index >= 0 && index < (size - nPass - 1));
            // printf("nPass = %d; index = %d\n", nPass, index);
            // printfArrInt(arr, size);
            if(strcmp(arr[index], arr[index + 1]) > 0){
                ChangeValuesStr(&arr[index], &arr[index + 1]);
            }
        }
    }
}

void ChangeValuesStr(const char** elem1, const char** elem2){
    const char* temp = *elem2;
    *elem2 = *elem1;
    *elem1 = temp;
}