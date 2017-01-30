#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

// Convert Number to Binary and stored in an Array

number_of_binary_digits(int num)
{
    int i=0;
    while(num > pow(2, i++));
    if(num == pow(2, i-1)){
        return i;
    }else
        return i-1;
}

uint8_t *num_to_binary(int num, int *size)
{
    int bin_digits;
    uint8_t *arr;
    bin_digits = number_of_binary_digits(num);
    *size = bin_digits;
    arr = (uint8_t *)malloc(sizeof(uint8_t) * bin_digits);
    memset(arr, 0x0, sizeof(uint8_t) * bin_digits);
    // Filling the array with bits
    while(num){
        arr[--bin_digits] = (uint8_t)num % 2;
        printf("arr[%d]%d\n", bin_digits, (int)arr[bin_digits]);
        num = num / 2;
    }
    return arr;
}

// Printing Binary Array
void print(uint8_t *arr, int size)
{
    int i;
    printf("Array is:::\n");
    for(i = 0; i < size; i++){
        printf("%d\t", (int)arr[i]);
    }
    printf("\n\n");
}

uint8_t *sum(uint8_t *num1_arr, int arr1_size, uint8_t *num2_arr, int arr2_size, int *sum_arr_size)
{
    int size;
    uint8_t bit_sum, carry = 0, *sum_arr;
    size = ((arr1_size > arr2_size)? arr1_size : arr2_size) + 1;
    *sum_arr_size = size;
    sum_arr = (uint8_t *)malloc(sizeof(uint8_t) * size);
    memset(sum_arr, 0x0, sizeof(uint8_t) * size);
    while(arr1_size > 0 && arr1_size > 0){
        bit_sum = num1_arr[--arr1_size] + num2_arr[--arr2_size] + carry;
        if(bit_sum == 3){
            carry = 1;
            sum_arr[--size] = 1;
        }else if(bit_sum == 2){
            carry = 1;
            sum_arr[--size] = 0;
        }else{
            carry = 0;
            sum_arr[--size] = bit_sum;
        }
    }
    if(arr1_size == 0){
        while(arr2_size > 0){
            bit_sum = num2_arr[--arr2_size] + carry;
            if(bit_sum == 2){
                carry = 1;
                sum_arr[--size] = 0;
            }else{
                carry = 0;
                sum_arr[--size] = bit_sum;
            }
        }
    }else if (arr2_size == 0){
        while(arr1_size > 0){
            bit_sum = num1_arr[--arr1_size] + carry;
            if(bit_sum == 2){
                carry = 1;
                sum_arr[--size] = 0;
            }else{
                carry = 0;
                sum_arr[--size] = bit_sum;
            }
        }
    }
    sum_arr[--size] = carry;
    return sum_arr;
}

int main()
{
    int num1, num2, arr1_size, arr2_size, sum_arr_size;
    uint8_t *num1_arr, *num2_arr, *sum_arr;
    printf("Input First Number\n");
    scanf("%d", &num1);
    printf("Input Second Number\n");
    scanf("%d", &num2);
    // Converting Number to binary and storing in an array
    num1_arr = num_to_binary(num1, &arr1_size);
    num2_arr = num_to_binary(num2, &arr2_size);
    print(num1_arr, arr1_size);
    print(num2_arr, arr2_size);
    // Summing the two arrays
    sum_arr = sum(num1_arr, arr1_size, num2_arr, arr2_size, &sum_arr_size);
    printf("Size of Sum array = %d\n", sum_arr_size);
    print(sum_arr, sum_arr_size);
    return 0;
}
