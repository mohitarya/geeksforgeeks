#include <stdio.h>

void print(int *arr, int size)
{
    int i;
    for(i = 0; i < size; i++){
        printf("%d\t", arr[i]);
    }
    printf("\n");
}

int binary_search_rec(int *arr, int start, int end, int num)
{
    int mid;
    if(end < start){
        return -1;
    }
    mid = (start + end)/2;
    if(arr[mid] == num){
        return mid;
    }else if(arr[mid] > num){
        return binary_search_rec(arr, start, mid-1, num);
    }else{
        return binary_search_rec(arr, mid+1, end, num);
    }
}

int binary_search_iter(int *arr, int size, int num)
{
    int start, end, mid;
    if(arr == NULL){
        printf("Input array is NULL\n");
        return -1;
    }
    if(size == 1){
        if(arr[0] == num){
            return 0;
        }else{
            return -1;
        }
    }
    start = 0;
    end = size - 1;
    while(start <= end){
        mid = (start + end)/2;
        if(arr[mid] == num){
            return mid;
        }else if(arr[mid] > num){
            end = mid - 1;
        }else{
            start = mid + 1;
        }
    }
    return -1;
}

int main()
{
    int arr[] = {1, 2, 5, 6, 7, 9, 10, 12};
    int size = sizeof(arr)/sizeof(int);
    int num, result;
    printf("Array is\n\t\t");
    print(arr, size);
    printf("Input the element to search:::\t");  
    scanf("%d", &num);
    result = binary_search_iter(arr, size, num);
    if(result == -1){
        printf("Array does not contain element::%d\n", num);
    }else{
        printf("Array contains the number at index %d\n", result);
    }

    result = binary_search_rec(arr, 0, size-1, num);
    if(result == -1){
        printf("Array does not contain element::%d\n", num);
    }else{
        printf("Array contains the number at index %d\n", result);
    }
    return 0;
}
