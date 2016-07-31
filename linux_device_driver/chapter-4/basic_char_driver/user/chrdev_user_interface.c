#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

const char chrdev_name[] = "/dev/mychrdev";

int main()
{
    int fd, ret_val = 0, buf_size = 100;
    ssize_t nbytes;
    char *buf;
    buf = malloc(sizeof(char) * buf_size);
    memset(buf, 0x00, buf_size);
    printf("Opening the Driver\n");
    fd = open(chrdev_name, O_RDONLY);
    if(fd < 0){
        printf("Failed to open the device %s\n", chrdev_name);
        ret_val = 1;
    }
    printf("Device %s Opened Successfully, descriptor = %d\n", chrdev_name, fd);
    // Reading from the char device

    nbytes = read(fd, buf, buf_size);
    printf("Number of bytes read = %zd\n", nbytes);
    printf("Data from kernel = %s\n", buf);
    return ret_val;
}
