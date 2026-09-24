#include <stdio.h>
#include <string.h>
#include <assert.h>

#include "printfArr.h"

void QuickSortStr(const char **arr, size_t __left, size_t __right);
void SwapStr(const char **elem1, const char **elem2);

int main(){
    const char* arr[] = {"str1", "2", "str3", "strstr4", "Str5"};
    size_t elemSize = sizeof(arr[0]);
    size_t arrSize = sizeof(arr) / elemSize;

    printfArr((void *)arr, arrSize, elemSize, "%s");

    QuickSortStr(arr, 0, arrSize - 1);

    printfArr((void *)arr, arrSize, elemSize, "%s");

    return 0;
}

void QuickSortStr(const char **arr, size_t __left, size_t __right){
    assert(arr != NULL);

    if(__left >= __right){
        return;
    }
    size_t left = __left;
    size_t right = __right;
    const char *pivot = *(arr + left) + (size_t)((__left + __right) / 2);

    while(left <= right){
        assert(left <= right);
        
        while(strcmp(*(arr + left), pivot) < 0){
            assert(strcmp(*(arr + left), pivot) < 0);
            left++;
        }

        while(strcmp(*(arr + right), pivot) > 0){
            assert(strcmp(*(arr + right), pivot) > 0);
            right--;
            assert(right != ((size_t)-1));
        }

        if(right >= left){
            SwapStr((arr + left), (arr + right));

            if (strcmp(pivot, *(arr + left)) == 0){
                pivot = *(arr + right);
            }
            else if (strcmp(pivot, *(arr + right)) == 0){
                pivot = *(arr + left);
            }

            left++;

            if(right <= 0) {
                break;
            }
            right--;
        }
    }

    if(right > __left){
        QuickSortStr(arr, __left, right);
    }
    if (left < __right){
        QuickSortStr(arr, left, __right);
    }
}

void SwapStr(const char **elem1, const char **elem2){
    assert(elem1 != 0);
    assert(elem2 != 0);

    const char* temp = *elem2;
    *elem2 = *elem1;
    *elem1 = temp;
}