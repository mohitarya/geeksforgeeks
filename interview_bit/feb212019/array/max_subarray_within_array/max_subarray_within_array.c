#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define MAX(x, y) ((x >= y) ? x : y)

// Max sub array using Divide and conquer technique

int max_from_mid(int *arr, int start_index, int mid_index, int end_index)
{
    int left_max = INT_MIN, right_max = INT_MIN, i, sum =0;
    // Calculte left max
    for(i = mid_index; i >= start_index; i--)
    {
        sum = sum + arr[i];
        left_max = MAX(left_max, sum);
    }

    // Calculate right max
    sum = 0;
    for(i = mid_index + 1; i <= end_index; i++)
    {
        sum = sum + arr[i];
        right_max = MAX(right_max, sum);
    }
    return (left_max + right_max);
}

int max_subarray_dvd_cnqr(int *arr, int start_index, int end_index)
{
    int mid, left_max, right_max, mid_max;
    if(start_index == end_index)
    {
        return arr[start_index];
    }
    mid = ((end_index - start_index) / 2) + start_index;
    left_max = max_subarray_dvd_cnqr(arr, start_index, mid);
    right_max = max_subarray_dvd_cnqr(arr, (mid + 1), end_index);
    mid_max = max_from_mid(arr, start_index, mid, end_index);
    return MAX(mid_max, (MAX(left_max, right_max)));
}

// Kadanes algorithm

int max_subarray_kadane(int *arr, int size)
{
    int max_ending_here, max_so_far, i;
    max_ending_here = arr[0];
    max_so_far = arr[0];

    for(i = 1; i < size; i++)
    {
        max_ending_here = MAX(arr[i], arr[i] + max_ending_here);
        max_so_far = MAX(max_so_far, max_ending_here);
    }
    return max_so_far;
}

int max_subarray(int *arr, int size)
{
    int i, j, max_sum = INT_MIN, temp_sum;
    for(i = 0; i < (size); i++)
    {
        temp_sum = arr[i];
        if(max_sum < temp_sum)
        {
            max_sum = temp_sum;
        }
        for(j = (i + 1); j < (size); j++)
        {
            temp_sum = temp_sum + arr[j];
            if(max_sum < temp_sum)
            {
                max_sum = temp_sum;
            }
        }
    }
    return max_sum;
}

int main()
{
    int arr[6] = {-2, 1, -3, 4, -1, 2};
    //int arr[5] = {0, 1, 0, 0, 1};
    printf("Max Sub array = %d\n", max_subarray(arr, 6));
    printf("Max Using Kadane Algo = %d\n", max_subarray_kadane(arr, 6));
    printf("Max Sub array using Divide and conquer = %d\n", max_subarray_dvd_cnqr(arr, 0, 5));
    return 0;
}
