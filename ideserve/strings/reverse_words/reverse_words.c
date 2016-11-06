#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>

int main()
{
    char list[] = "This is the   list";
    char *temp, *str;
    int list_size = 0, word_len = 0, counter_new_list = 0, word_len_temp = 0;
    // Calsulating the size of the list
    list_size = sizeof(list);
    if(list_size == 0){
        printf("List size is Zero Nothing to do\n");
        return 0;
    }
    temp = (char *) malloc(sizeof(char) * list_size);
    str = list;
    printf("List is = %s\n", list);
    counter_new_list = list_size - 1;
    // Reversing the words
    while(*str){
        // Calculate the word len
        word_len = sizeofword(str);
        word_len_temp = word_len;
        printf("word size %d\n", word_len);
        if(word_len == 0){
            temp[--counter_new_list] = *str;
            str++;
        }else{
            while(word_len){
                temp[--counter_new_list] = str[--word_len];
            }
        }
        temp[--counter_new_list] = str[word_len_temp];
        str = str + word_len_temp + 1;
    }
    temp[list_size - 1] = '\0';
    printf("Changed list = ....%s....\n", temp);
    return 0;
}

int sizeofword(char *list)
{
    int i, word_len = 0;
    for (i = 0; (*(list + i) != ' ') && (*(list + i) != '\0'); i++)
    {
        word_len++;
    }
    return word_len;
}
