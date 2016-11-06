#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>

#define SWAP(x, y, z) ((z = x), (x = y), (y = z))

int main()
{
    int word_len, start, str_len;
    int current_index = 0;
    // Input String
    char str[] = "This is my string";
    // Calculate the word length
    str_len = sizeof(str);
    while(current_index <= str_len){
        word_len = sizeofword(str, current_index);
        reverse_word(str, current_index, word_len);
        current_index = current_index + word_len + 1;
        printf("Index = %d\n", current_index);
    }
    reverse_word(str, 0, str_len - 1);
    printf("After word reversal %s\n", str);
    return 0;
}

// Reverse a word
reverse_word(char *str, int start, int len)
{
    char temp;
    int i;
    for(i = 0; i < (len/2); i++){
        printf("%d...%c,,..%c\n", i, *(str + start + i), *(str + start + len -i - 1));
        SWAP(*(str + start + i), *(str + start + len -i -1), temp);
    }
}

int sizeofword(char *list, int current_index)
{
    int i, word_len = 0;
    list = list + current_index;
        for (i = 0; (*(list + i) != ' ') && (*(list + i) != '\0'); i++)
            {
                    word_len++;
                        }
                            return word_len;
                            }
