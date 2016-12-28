#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>
#include <sys/types.h>
#include <dirent.h>

typedef struct node {
    void *dirent;
    struct node *node;
}node;

int main()
{
    DIR *dir_p;
    node *new_node;
    struct dirent *dir_ent;
    // Dir Path
    char arr[256];
    sprintf(arr, "%s", "/home/mohitarya/repo/geeksforgeeks");
    printf("Dir Path is %s\n", arr);
    
    // Open a dir
    dir_p = opendir(arr);
    if(!dir_p){
        printf("Failed to open the dir\n");
        exit(1);
    }
    while(1){
        // read directory
        dir_ent = readdir(dir_p);
        if(!dir_ent){
            printf("Read dir is done");
            goto exit;
        }
        // Allocate a memory to the node
        new_node 
        printf("Name is %s\n", dir_ent->d_name);
    }

exit:
    if(closedir(dir_p)){
        printf("Failed to close dir %s\n", arr);
    }
    return 0;
}
