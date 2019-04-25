#include <stdio.h>

#define TRUE    1
#define FALSE   0

int is_bit_set(unsigned int num, int position)
{
    if(num & (1 << position))
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

void toggel_bit(unsigned int *num, int position)
{
    *num = ((*num) ^ (1 << position));
}

int main()
{
    unsigned int num = 11;
    int total_bits, total_iteration, i, j, lsb, msb;

    total_bits = (sizeof(num) * 8);

    total_iteration = total_bits / 2;

    printf("%u\n", num);
    for(i = 0, j = (total_bits - 1); i < total_iteration; i++, j--)
    {
         lsb = is_bit_set(num, i);
         msb = is_bit_set(num, j);
         if(lsb != msb)
         {
            toggel_bit(&num, i);
            toggel_bit(&num, j);
         }
    }
    printf("%u\n", num);
}
