/*
 Describe a ‚.n lg n/-time algorithm that, given a set S of n integers and another
 integer x, determines whether or not there exist two elements in S whose sum is
 exactly x.
 */
#include <stdio.h>

void find_num_array(int *arr, int size, int num)
{
    int index, found=0, num1, num2, i;
    //Using Merge sort sorting the array
        
    merge_sort(arr, 0, size-1);
    
    for(i = 0; i < size - 1; i++){
        index = -1;
        num1 = arr[i];
        num2 = num - num1;
        index = binary_search_rec(arr, i+1, size-1, num2);
        if(index >= 0){
            printf("Two num are present in array %d and %d, which make the sum = %d\n", num1, num2, num);
            found = 1;
            break;
        }
    }
    if(found == 0){
        printf("There are no two numbers in array which can custruct num %d\n", num);
    }
}

int main()
{
    int arr[] = {3, 4, 1, 0, 6, 8, 4, 9};
    int size = sizeof(arr)/sizeof(int);
    int num;

    printf("Input the element\n");

    scanf("%d", &num);

    find_num_array(arr, size, num);
    return 0;
}
