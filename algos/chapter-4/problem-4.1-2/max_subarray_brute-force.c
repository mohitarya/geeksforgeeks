#include <stdio.h>
#include <limits.h>
#include <string.h>
#include <stdlib.h>

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
    int *result, size;
    size = sizeof(arr)/sizeof(int);
    result = max_array_using_brute_force(arr, size);
    printf("Input array is ::\n\t\t");
    print(arr, size);
    printf("Maximum array sum-%d at start index-%d end index-%d,\n", result[2], result[0], result[1]);
    return 0;
}

