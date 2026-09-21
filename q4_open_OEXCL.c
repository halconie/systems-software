/* 
param@param-QEMU-Virtual-Machine:~/code/dir1/hol1/q4$ touch data.txt
param@param-QEMU-Virtual-Machine:~/code/dir1/hol1/q4$ ls -l data.txt 
-rw-rw-r-- 1 param param 0 Sep 21 00:16 data.txt
param@param-QEMU-Virtual-Machine:~/code/dir1/hol1/q4$ vim open_demo.c
param@param-QEMU-Virtual-Machine:~/code/dir1/hol1/q4$ gcc -W -o open_demo open_demo.c 

param@param-QEMU-Virtual-Machine:~/code/dir1/hol1/q4$ ./open_demo
first open succeeded, fd = 3
open O_RDWR|O_CREAT|O_EXCL: File exists
errno is EEXIST
param@param-QEMU-Virtual-Machine:~/code/dir1/hol1/q4$ ls -l data.txt
-rw-rw-r-- 1 param param 0 Sep 21 00:16 data.txt

*/

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

int main(void) {
    int fd1 = open("data.txt", O_RDWR);
    if (fd1 == -1) {
        perror("open O_RDWR");
        return 1;
    }
    printf("first open succeeded, fd = %d\n", fd1);

    int fd2 = open("data.txt", O_RDWR | O_CREAT | O_EXCL, 0744);
    if (fd2 == -1) {
        int err = errno;
        perror("open O_RDWR|O_CREAT|O_EXCL");
        if (err == EEXIST)
            printf("errno is EEXIST\n");
    } else {
        printf("second open succeeded, fd = %d\n", fd2);
        close(fd2);
    }

    close(fd1);
    return 0;
}