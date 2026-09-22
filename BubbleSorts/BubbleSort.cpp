#include <stdio.h>
#include <string.h>
#include <math.h>
#include <assert.h>

#include "printfArr.h"
#include "comparators.h"

void BubbleSort(void* arr, size_t arrSize, size_t arrElemSize, int CompareFunc(const void* elem1, const void* elem2));
void Swap(void* elem1, void* elem2, size_t arrElemSize);

int main(){

    int arrInt[] = {2, 1, 6, 8, 2};
    size_t arrElemIntSize = sizeof(arrInt[0]);
    size_t arrIntSize = sizeof(arrInt) / arrElemIntSize;

    const char* arrStr[] = {"str1", "2", "str3", "strstr4", "Str5"};
    size_t arrElemStrSize = sizeof(arrStr[0]);
    size_t arrStrSize = sizeof(arrStr) / arrElemStrSize;

    printfArr((void *)arrInt, arrIntSize, arrElemIntSize, "%d");
    printfArr((void *)arrStr, arrStrSize, arrElemStrSize, "%s");

    printf("><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><");

    BubbleSort(arrInt, arrIntSize, arrElemIntSize, CompareIntAscend);
    printfArr((void *)arrInt, arrIntSize, arrElemIntSize, "%d");

    BubbleSort(arrInt, arrIntSize, arrElemIntSize, CompareIntDescend);
    printfArr((void *)arrInt, arrIntSize, arrElemIntSize, "%d");

    BubbleSort(arrStr, arrStrSize, arrElemStrSize, CompareStrAscend);
    printfArr((void *)arrStr, arrStrSize, arrElemStrSize, "%s");

    BubbleSort(arrStr, arrStrSize, arrElemStrSize, CompareStrDescend);
    printfArr((void *)arrStr, arrStrSize, arrElemStrSize, "%s");

}



void BubbleSort(void* arr, size_t arrSize, size_t arrElemSize,
                int CompareFunc(const void* elem1, const void* elem2)){
    assert(arr != NULL);
    assert(CompareFunc != NULL);

    for(int nPass = 0; nPass < arrSize; nPass++){
        assert(nPass >= 0 && nPass < arrSize);

        for(int index = 0; index < (arrSize - nPass - 1); index++){
            assert(index >= 0 && index < (arrSize - nPass - 1));
    
            if(CompareFunc((const void *)((char *)arr + index * arrElemSize),
                           (const void *)((char *)arr + (index + 1) * arrElemSize)) > 0){

                Swap((void *)((char *)arr + index * arrElemSize),
                     (void *)((char *)arr + (index + 1) * arrElemSize), arrElemSize);
            }
        }
    }
}

void Swap(void* elem1, void* elem2, size_t arrElemSize ){
    assert(elem1 != 0);
    assert(elem2 != 0);

    void* temp = malloc(arrElemSize);
    
    memcpy(temp, elem2, arrElemSize);
    memcpy(elem2, elem1, arrElemSize);
    memcpy(elem1, temp, arrElemSize);

    free(temp);
}