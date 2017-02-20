#include <stdio.h>
#include <limits.h>
#include <string.h>
#include <stdlib.h>

#define MAX(x, y) ((x >= y)? x : y)

int max_array_from_mid(int *arr, int start, int mid, int end)
{
    int left, right, i, sum;
    left = right = sum = 0;
    for(i = mid; i >= 0; i--){
        sum = sum + arr[i];
        if(sum > left){
            left = sum;
        }
    }
    sum = 0;
    for(i = (mid+1); i <= mid; i++){
        sum = sum + arr[i];
        if(sum > right){
            right = sum;
        }
    }
    return(MAX(left, right));
}

int max_subarray_using_recurrsion(int *arr, int start, int end)
{
    int mid, left_max, right_max, mid_max, val_max;
    if(start == end){
        return arr[start];
    }
    mid = (start + end)/2;
    left_max = max_subarray_using_recurrsion(arr, start, mid);
    right_max = max_subarray_using_recurrsion(arr, (mid + 1), end);
    mid_max = max_array_from_mid(arr, start, mid, end);
    val_max = MAX(left_max, mid_max);

    return (MAX(val_max, right_max));
}

int *max_array_using_brute_force(int *arr, int size)
{
    int *result;
    int i, j, max_array=INT_MIN, sum;
    result = (int *)malloc(sizeof(int) * 3);
    memset(result, -1, (sizeof(int) * 3));
    for (i = 0; i < size; i++){
        sum = 0;
        for(j = i; j < size; j++){
            sum = sum + arr[j];
            if(max_array < sum){
                max_array = sum;
               result[0] = i;
               result[1] = j;
            }
        }
    }
    result[2] = max_array;
    return result;
}
int main()
{
    int arr[] = {10, -12, 3, 8, -2};
    int *result, size, result_rec;
    size = sizeof(arr)/sizeof(int);
    result = max_array_using_brute_force(arr, size);
    printf("Input array is ::\n\t\t");
    print(arr, size);
    printf("Maximum array sum-%d at start index-%d end index-%d,\n", result[2], result[0], result[1]);
    result_rec = max_subarray_using_recurrsion(arr, 0, (size - 1));
    printf("Max array Sum using recurrsion method= %d\n", result_rec);
    return 0;
}

