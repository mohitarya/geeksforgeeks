#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>


#define MAX(x,y) ((x >= y) ? x : y)
#define MIN(x,y) ((x <= y) ? x : y)

int max_absolute_difference(int *A, int n1)
{
    int i;
    int first_1 = INT_MIN, second_1 = INT_MIN, third_1 = INT_MIN, fourth_1 = INT_MIN;
    int first_2 = INT_MAX, second_2 = INT_MAX, third_2 = INT_MAX, fourth_2 = INT_MAX;
    int sum = INT_MIN;
    for(i = 0; i < n1; i++)
    {
        first_1 = MAX(first_1, (A[i] + i));
        second_1 = MAX(second_1, (A[i] - i));
        third_1 = MAX(third_1, (-A[i] + i));
        fourth_1 = MAX(fourth_1, (-A[i] - i));
        first_2 = MIN(first_2, (A[i] + i));
        second_2 = MIN(second_2, (A[i] - i));
        third_2 = MIN(third_2, (-A[i] + i));
        fourth_2 = MIN(fourth_2, (-A[i] - i));
    }

    sum = MAX(sum, (first_1 - first_2));
    sum = MAX(sum, (second_1 - second_2));
    sum = MAX(sum, (third_1 - third_2));
    sum = MAX(sum, fourth_1 - fourth_2);

    return sum;
}

int main()
{
    int arr[3] = {1, 3, -1};
    printf("Max Absolute difference = %d\n", max_absolute_difference(arr, 3));
    return 0;
}
