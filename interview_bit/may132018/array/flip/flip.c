#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FALSE 0
#define TRUE 1
#define STRTOINT(x) (((int) (*(x) - '0') == 1) ? -1 : 1)

int* flip(char* A, int *len1);

int main()
{
    char arr[] = "11110000000";
    int len, i;
    int *output;
    output = flip(arr, &len);
    printf("\n\t\t");
    for(i = 0; i < len; i++)
    {
        printf("%d\t\t", output[i]);
    }
    printf("\n");
    return 0;
}

 
int* flip(char* A, int *len1) {
    /* Initialization of Local Variables */
    int *B, i, total_1s = 0, total_0s = 0, curr_max, global_max, curr_index_start, curr_index_end, global_index_start, global_index_end;
    int bad_input = FALSE;
    size_t A_len = 0;
    A_len = strlen(A);
    /* Checking if all are 1s and all are 0s */
    printf("A_len = %lu\n", A_len);
    for(i = 0; i < A_len; i++)
    {
        if(A[i] == '0')
        {
            total_0s++;
        }
        else if( A[i] == '1')
        {
            total_1s++;
        }
        else
        {
            bad_input = TRUE;
        }
    }
    printf("total_0s = %d total_1s = %d\n", total_0s, total_1s);
    if(total_1s == A_len || bad_input == TRUE)
    {
        *len1 = 1;
        B = (int *) malloc(sizeof(int) * (*len1));
        return B;
    }
    else
    {
        *len1 = 2;
        B = (int *) malloc(sizeof(int) * (*len1));
        if (total_0s == A_len)
        {
            B[0] = 1;
            B[1] = A_len;
            return B;
        }
    }
    /* Apply kadane's Algo to get the max sub array */
    curr_max = STRTOINT(A);
    global_max = STRTOINT(A);
    curr_index_start = 0;
    curr_index_end = 0;
    global_index_start = 0;
    global_index_end = 0;
    for (i = 1; i < A_len; i++)
    {
        if (STRTOINT(A + i) > (curr_max + STRTOINT(A + i)))
        {
            curr_max = STRTOINT(A + i);
            curr_index_start = i;
            curr_index_end = i;
        }
        else
        {
            curr_max = (curr_max + STRTOINT(A + i));
            curr_index_end = i;
        }
        printf("curr_max=%d, global_max = %d curr_index_start=%d, curr_index_end = %d\n", curr_max, global_max, curr_index_start, curr_index_end);
        if(global_max < curr_max)
        {
            global_max = curr_max;
            global_index_start = curr_index_start;
            global_index_end = curr_index_end;
        }
        printf("global_max = %d global_index_start=%d, global_index_end= %d\n", global_max, global_index_start, global_index_end);
    }
    printf("max = %d\n", global_max);
    B[0] = global_index_start + 1;
    B[1] = global_index_end + 1;
    printf("Start Index = %d End Index = %d\n", B[0], B[1]);
    return B;
}
