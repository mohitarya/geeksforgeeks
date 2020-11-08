#include <stdio.h>

int main()
{
    int A[2][3];
    A[0][0] = 2;
    A[0][1] = 3;
    A[0][2] = 6;
    A[1][0] = 7;
    A[1][1] = 9;
    A[1][2] = 1;
    
    int (*p)[3];
    p = A;
    printf("A = %p...*A = %p... **A = %d....(A+1) = %p....*(A+1) = %p\n", A, *A, **A, (A+1), *(A+1));
    printf("p = %p....(p+1)...%p\n", p, p+1);

    return 0;
}
