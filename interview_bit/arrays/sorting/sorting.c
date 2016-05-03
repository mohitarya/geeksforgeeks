#include <stdio.h>
#include <stdlib.h>

void insertion_sort(int *, int);
void merge_sort(int *, int);
void merge(int *, int, int *, int, int *);
void print_arr(int *, int);
void quick_sort(int *, int, int);
int quick_partition(int *, int, int);

#define SWAP(x, y, z) ((z = x), (x = y), (y = z))

int main()
{
    int *arr, n, i;
    printf("Input the number of elements in the array\n"); 
    scanf("%d", &n);
    if(n <= 0){
        printf("Error:: Interger list should be greater then 0\n");
        return -1;
    }
    arr = (int *) malloc(sizeof(int) * n);
    if(arr == NULL){
        printf("Error:: Out of memory\n");
        return -1;
    }
    printf("Info:: Randomly generated array list is\n\t");
    for(i = 0; i < n; i++){
        *(arr + i) = rand()/1000000;
        printf("%d ", *(arr + i));
    }
    printf("\n");
//    insertion_sort(arr, n);
//    merge_sort(arr, n);
    quick_sort(arr, 0, (n - 1));
    printf("Info:: After Sorting array is:\n\t");
    print_arr(arr, n);
    if(arr != NULL){
        free(arr);
        arr = NULL;
    }
    return 0;
}

void print_arr(int *arr, int n)
{
    int i;
    for(i = 0; i < n; i++){
        printf("%d ", *(arr + i));
    }
    printf("\n");
}

void insertion_sort(int *arr, int n)
{
    int i, key, index, j;
    for(i = 1; i < n; i++){
        key = *(arr + i);
        index = i;
        while((index >= 0) && (*(arr + (index - 1)) > key)){
            *(arr + index) = *(arr + (index - 1));
            index--;
        }
        *(arr + index) = key;
    }
    printf("Info:: Sorted via insersion sort, array list is\n\t");
    for(j = 0; j < n; j++){
        printf("%d ", *(arr + j));
    }
    printf("\n");

}
void merge_sort(int *arr, int n)
{
    int *L, *R, Ln, Rn, i, mid;
    if(n < 2){
        return;
    }
    //Calculating the mid of array
    mid = n/2;
    //Assigning the memory to the new arrays Left and Right
    Ln = mid;
    Rn = n - mid; 
    L = (int *) malloc(sizeof(int) * Ln);
    R = (int *) malloc(sizeof(int) * Rn);
    //Fill up the L and R array
    for(i = 0; i < Ln; i++){
        *(L + i) = *(arr + i);
    }
    for(i = 0; i < Rn; i++){
        *(R + i) = *(arr + mid + i);
    }
    merge_sort(L, Ln);
    merge_sort(R, Rn);
    merge(L, Ln, R, Rn, arr);
    if(L != NULL){
        free(L);
        L =NULL;
    }
    if(R != NULL){
        free(L);
        L = NULL;
    }
}
void merge(int *L, int Ln, int *R, int Rn, int *arr)
{
    int i, j, k;
    i = j = k = 0;
    while((i < Ln) && (j < Rn)){
        if(*(L + i) < *(R + j)){
            *(arr + k) = *(L + i);
            i++;
        }else{
            *(arr + k) = *(R + j);
            j++;
        }
        k++;
    }
    while(i < Ln){
        *(arr + k) = *(L + i);
        i++;
        k++;
    }
    while(j < Rn){
        *(arr + k) = *(R + j);
        j++;
        k++;
    }
}
int quick_partition(int *arr, int start, int end)
{
    int pivot, pindex = 0, i, temp;
    pivot = *(arr + end);
    for(i = 0; i < end; i++){
        if(*(arr + i) <= pivot){
            SWAP(*(arr + pindex), *(arr + i), temp);
            pindex++;
        }
    }
    SWAP(*(arr + pindex), *(arr + end), temp);
    return pindex;
}
void quick_sort(int *arr, int start, int end)
{
    int pindex;
    if(start < end){
        pindex = quick_partition(arr, start, end);
        quick_sort(arr, start, (pindex - 1));
        quick_sort(arr, (pindex + 1), end);
    }
}   
