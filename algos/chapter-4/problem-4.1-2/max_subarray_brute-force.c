#include <stdio.h>
#include <limits.h>

int main()
{
    int arr[] = {10, -12, 3, 8, -2};
    int result, size;
    size = sizeof(arr)/sizeof(int);
    result = max_array_using_brute_force(arr, size);
    printf("Input array is ::\n\t\t");
    print(arr, size);
    printf("Maximum array is %d\n", result);
    return 0;
}

int max_array_using_brute_force(int *arr, int size)
{
    int i, j, max_array=INT_MIN, prev_sum, sum;
    for (i = 0; i < size; i++){
        prev_sum = 0;
        for(j = i; j < size; j++){
            sum = prev_sum + arr[j];
            if(max_array < sum){
                max_array = sum;
            }
            prev_sum = sum;
        }
    }
    return max_array;
}
