#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print(int *arr, int size)
{
    int i;
    for(i = 0; i < size; i++){
        printf("%d\t", *(arr + i));
    }
    printf("\n");
}

void merge(int * arr, int p, int q, int r)
{
    //Calculating the size of the array
    int n1, n2, i, j, k;
    int *left, *right;

    n1 = q - p + 1;
    n2 = r - q;
    left = (int *) malloc(sizeof(int) * n1);
    right = (int *) malloc(sizeof(int) * n2);
    memset(left, 0x0, sizeof(int) * n1);
    memset(right, 0x0, sizeof(int) * n2);
    
    //Filling the right and left array
    for(i = p, j = 0; i <= q; i++, j++){
        left[j] = arr[i];
    }
    for(i = q+1, j = 0; i <= r; i++, j++){
        right[j] = arr[i];
    }
    i = j = 0;
    k = p;
    while(i < n1 && j < n2){
        if(left[i] <= right[j]){
            arr[k] = left[i];
            i++;
        }else{
            arr[k] = right[j];
            j++;
        }
        k++;
    }
    if(i >= n1){
        while(j < n2){
            arr[k] = right[j];
            j++;
            k++;
        }
    }else if(j >= n2){
        while(i < n1){
            arr[k] = left[i];
            i++;
            k++;
        }
    }
}

void merge_sort(int *arr, int p, int r)
{
    int q;
    if(p < r){
        q = (p+r)/2;
        merge_sort(arr, p, q);
        merge_sort(arr, q+1, r);
        merge(arr, p, q, r);
    }
}

int main()
{
    int arr[] = {3,2,0,8,4,9,10};
    int size = sizeof(arr)/sizeof(int);
    printf("Array before sorting:::\n\t\t");
    print(arr, size);
    merge_sort(arr, 0, (size-1));
    printf("Array after the merge sort::\n\t\t"); 
    print(arr, size);
    return 0;
}
