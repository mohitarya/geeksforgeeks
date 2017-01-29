#include <stdio.h>

int main()
{
    int arr[] = {1,2,3,4,5,6,7};
    int num, size, i;
    printf("Input an number to search\n");
    scanf("%d", &num);
    size = sizeof(arr)/sizeof(int);
    for(i = 0; i < size; i++){
        if(*(arr + i) == num){
            printf("Num %d found in array\n", num);
            return 0;
        }
    }
    printf("Num %d Not found in array\n", num);
    return 0;
}
