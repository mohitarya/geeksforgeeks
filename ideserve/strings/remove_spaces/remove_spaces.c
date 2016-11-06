#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>

int main()
{
    // Input string
    char str[] = "Hi I am using Whatsapp";
    int read, write = 0, str_len;
    str_len = strlen(str);
    for(read = 0; read <str_len; read++){
        if(str[read] != ' '){
            if(read != write){
                str[write] = str[read];
             }
             write++;
            continue;
        }else{
            continue;
        }
    }
    printf("string = %s\n", str);
    return 0;
}
