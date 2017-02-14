#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int horner_rule(int *coef_arr, int size, int x)
{
    int i, y = 0;
    for(i = size-1; i >= 0; i--){
        y = coef_arr[i] + x * y;
    }
    return y;
}

int main()
{
    int coef, *coef_arr, i, x, result;
    printf("Input the Number of coefficient\n");
    scanf("%d", &coef);
    // initilizing the array to store the coefficient
    coef_arr = (int *) malloc(sizeof(int) * coef);
    for(i = 0; i < coef; i++){
        printf("Input the %d coefficient\n", i);
        scanf("%d", (coef_arr + i));
    }
    print(coef_arr, coef);
    printf("Input the value of x for f(x)\n");
    scanf("%d", &x);
    result = horner_rule(coef_arr, coef, x);
    printf("Output is %d\n", result);
    return 0;
}
