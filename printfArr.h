#ifndef PRINTFARR_H
#define PRINTFARR_H

#include <stdio.h>
#include <assert.h>

#define MAXSIZE 256

void printfArr(void* arr, size_t arrSize, size_t arrElemSize, const char* spezificator);


void printfArr(void* arr, size_t arrSize, size_t arrElemSize, const char* format){
    assert(arr != NULL);
    assert(format != NULL);

    char strRes[MAXSIZE];
    printf("\n=======================================================================================\n");
    printf("Array: \n");
    for(int index = 0; index < arrSize; index++){
        assert(index >= 0 && index < arrSize);

        snprintf(strRes, MAXSIZE, "[Elem %d]: %s\t", index, format);
        assert(strRes != 0);
        printf(strRes, *((char**)((char *)arr + index * arrElemSize)));
    }
    printf("\n=======================================================================================\n");
}

#endif