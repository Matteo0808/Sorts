#include <stdio.h>
#include <string.h>
#include <assert.h>



void printfArrInt(int* arr, size_t size);
void printfArrStr(const char** arr, size_t size);

void BubbleSortInt(int* arr, size_t size);
void BubbleSortStr(const char** str1, size_t size);

void ChangeValuesInt(int* val1, int* val2);
void ChangeValuesStr(const char** str1, const char** str2);

int main(){
    
    
    int N_int = 0;
    scanf("%d", &N_int);
    int ArrToSort[N_int] = {};
    for(int i = 0; i < N_int; i++){
        scanf("%d", &ArrToSort[i]);
    }
    printfArrInt(ArrToSort, N_int);
    
    BubbleSortInt(ArrToSort, N_int);

    printfArrInt(ArrToSort, N_int);

    
    printf("\n\n\n");

    const char *StrArr[] = {"strstrstr1", "2", "strstr3", "strstrstr4", "Strstr5", "atrstr5"};
    int N_str = sizeof(StrArr)/sizeof(StrArr[0]);
    printf("%d\n", N_str);
    
    printfArrStr(StrArr, N_str);

    printf("1\n");

    BubbleSortStr(StrArr, N_str);

    printf("2\n");

    printfArrStr(StrArr, N_str);

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

void printfArrStr(const char** arr, size_t size){
    assert(arr != 0);
    for(int i = 0; i < size; i++){
        assert(i >= 0 && i < size);
        printf("arr[%d] = %s\t", i, arr[i]);
    }
    printf("\n");
}

void BubbleSortInt(int* arr, size_t size){
    assert(arr != 0);

    for(int nPass = 0; nPass < size; nPass++){
        assert(nPass >= 0 && nPass < size);
        for(int i = 0; i < size - nPass - 1; i++){
            assert(i >= 0 && i < (size - nPass - 1));
            
            if(arr[i] > arr[i + 1]){
                ChangeValuesInt(&arr[i], &arr[i + 1]);
            }
        }
    }
}

void BubbleSortStr(const char** arr, size_t size){
    assert(arr != 0);

    for(int nPass = 0; nPass < size; nPass++){
        assert(nPass >= 0 && nPass < size);
        for(int i = 0; i < size - nPass - 1; i++){
            assert(i >= 0 && i < (size - nPass - 1));

            if(strcmp(arr[i], arr[i+1]) > 0){
                ChangeValuesStr(&arr[i], &arr[i+1]);
            }
        }
    }
}

void ChangeValuesInt(int* val1, int* val2){
    assert(val1 != 0);
    assert(val2 != 0);

    int temp = *val2;
    *val2 = *val1;
    *val1 = temp;
}



void ChangeValuesStr(const char** str1, const char** str2){
    assert(str1 != 0);
    assert(str2 != 0);

    const char* temp = *str2;
    *str2 = *str1;
    *str1 = temp;

}