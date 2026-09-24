#include <stdio.h>
#include <string.h>
#include <assert.h>

#include "printfArr.h"

void QuickSortInt(int *arr, size_t __left, size_t __right);
void SwapInt(int* elem1, int* elem2);

int main(){
    int arr[] = {2, 1, 6, 8, 2, 10, 1, 11};
    size_t elemSize = sizeof(arr[0]);
    size_t arrSize = sizeof(arr) / elemSize;
    
    printfArr((void *)arr, arrSize, elemSize, "%d");

    QuickSortInt(arr, 0, arrSize - 1);

    printfArr((void *)arr, arrSize, elemSize, "%d");

    return 0;
}

void QuickSortInt(int *arr, size_t __left, size_t __right){
    assert(arr != NULL);

    if(__left >= __right){
        return;
    }
    size_t left = __left;
    size_t right = __right;
    int *pivot = arr + (size_t)((__left + __right) / 2);

    while(left <= right){
        assert(left <= right);
        
        while(*(arr + left) < *pivot){
            assert(*(arr + left) < *pivot);
            left++;
        }

        while(*(arr + right) > *pivot){
            assert(*(arr + right) > *pivot);
            right--;
            assert(right != ((size_t)-1));
        }

        if(right >= left){
            SwapInt((arr + left), (arr + right));

            if (pivot == arr + left){
                pivot = arr + right;
            }
            else if (pivot == arr + right){
                pivot = arr + left;
            }

            left++;

            if(right <= 0) {
                break;
            }
            right--;
        }
    }

    if(right > __left){
        QuickSortInt(arr, __left, right);
    }
    if (left < __right){
        QuickSortInt(arr, left, __right);
    }
}

void SwapInt(int* elem1, int* elem2){
    assert(elem1 != 0);
    assert(elem2 != 0);

    int temp = *elem1;
    *elem1 = *elem2;
    *elem2 = temp;
}