#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define RETURN_ARRAY_SIZE 2

int *flip(int *A, int n1, int *len1)
{
    int i, j, total_zeros = 0, total_ones = 0;
    // First check for the max 1s and 0s
    // If 1s are greater than 0s then
    // return with blanck array
    int *B;
    int temp_zeros, temp_ones, max_ones, max_index_i, max_index_j;
    B = (int *) malloc(sizeof(int) * RETURN_ARRAY_SIZE);
    for(i = 0; i < n1; i++)
    {
        (A[i] == 0) ? total_zeros++ : total_ones++;
    }
    if(total_ones == n1)
    {
        *len1 = 0;
        return B;
    }

    // Flip can make max No of ones
    // Go for the indexes
    max_ones = 0;
    max_index_i = 0;
    max_index_j = 0; 
    for(i = 0; i < n1; i++)
    {
        temp_zeros = 0;
        temp_ones = 0;
        for(j = i; j < n1; j++)
        {
            (A[j] == 0) ? temp_zeros++ : temp_ones++;
            if((total_ones + temp_zeros - temp_ones) > max_ones)
            {
                max_ones = total_ones + temp_zeros - temp_ones;
                max_index_i = i;
                max_index_j = j;
            }
        }
    }
    B[0] = max_index_i;
    B[1] = max_index_j;
    return B;
}


int main()
{
    int A[3] = {0, 0, 1};
    int *B, len1;
    B = flip(A, 3, &len1);
    printf("i = %d, j = %d\n", B[0], B[1]);
    return 0;
}
