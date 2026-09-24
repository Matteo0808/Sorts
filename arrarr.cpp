#include <stdio.h>
#include <string.h>

#include "printfArr.h"

int main(){
    int arrInt[] = {2, 1, 6, 8, 2};
    size_t arrElemIntSize = sizeof(arrInt[0]);
    size_t arrIntSize = sizeof(arrInt) / arrElemIntSize;

    const char* arrStr[] = {"str1", "2", "str3", "strstr4", "Str5"};
    size_t arrElemStrSize = sizeof(arrStr[0]);
    size_t arrStrSize = sizeof(arrStr) / arrElemStrSize;

    printfArrDebug(arrInt, arrIntSize, arrElemIntSize, "%d", FormatInt);
    printfArrDebug(arrStr, arrStrSize, arrElemStrSize, "%s", FormatStr);
}