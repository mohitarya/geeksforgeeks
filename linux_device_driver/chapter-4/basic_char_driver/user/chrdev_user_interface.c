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
    int fd, ret_val = 0, buf_size = 100, wbuf_size = 100;
    ssize_t nbytes;
    char *buf, *wbuff;
    buf = malloc(sizeof(char) * buf_size);
    wbuff = malloc(sizeof(char) * buf_size);
    memset(buf, 0x00, buf_size);
    memset(wbuff, 0x00, buf_size);
    strncpy(wbuff, "Hi I am from the user space please respond", wbuf_size);
    printf("Opening the Driver\n");
    fd = open(chrdev_name, O_RDWR);
    if(fd < 0){
        printf("Failed to open the device %s\n", chrdev_name);
        ret_val = 1;
    }
    printf("Device %s Opened Successfully, descriptor = %d\n", chrdev_name, fd);
    // Reading from the char device

    nbytes = read(fd, buf, buf_size);
    printf("Number of bytes read = %zd\n", nbytes);
    printf("Data from kernel = %s\n", buf);

    write_to_device(fd, wbuff, wbuf_size);

    if(close(fd)){
        printf("Error in closing the device\n");
        return 1;
    }
    printf("Device closed successfully\n");

    return ret_val;
}

int write_to_device(int fd, char *buf, int buf_size)
{
    ssize_t nbytes;
    nbytes = write(fd, buf, 10);
    printf("No of bytes write = %zd\n", nbytes);
    nbytes = write(fd, buf+nbytes, 15);
    printf("No of bytes write = %zd\n", nbytes);
    return 0;
}
