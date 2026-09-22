/* 
param@param-QEMU-Virtual-Machine:~/code/dir1/hol1/q12$ touch data.txt
param@param-QEMU-Virtual-Machine:~/code/dir1/hol1/q12$ vim modedemo.c
param@param-QEMU-Virtual-Machine:~/code/dir1/hol1/q12$ gcc -Wall -o modedemo modedemo.c 
param@param-QEMU-Virtual-Machine:~/code/dir1/hol1/q12$ ./modedemo 
--- fd1 (O_RDONLY) ---
access mode: read only
O_APPEND:   not set
O_NONBLOCK: not set
--- fd2 (O_WRONLY|O_APPEND) ---
access mode: write only
O_APPEND:   set
O_NONBLOCK: not set
--- fd3 (O_RDWR|O_NONBLOCK) ---
access mode: read write
O_APPEND:   not set
O_NONBLOCK: set
param@param-QEMU-Virtual-Machine:~/code/dir1/hol1/q12$ vim modedemo.c
param@param-QEMU-Virtual-Machine:~/code/dir1/hol1/q12$ gcc -Wall -o modedemo modedemo.c
param@param-QEMU-Virtual-Machine:~/code/dir1/hol1/q12$ ./modedemo 
--- fd1 (O_RDONLY) ---
O_APPEND:   not set
O_NONBLOCK: not set
--- fd2 (O_WRONLY|O_APPEND) ---
looks write only, but this is wrong
O_APPEND:   set
O_NONBLOCK: not set
--- fd3 (O_RDWR|O_NONBLOCK) ---
looks read & write only, but this is wrong
O_APPEND:   not set
O_NONBLOCK: set


param@param-QEMU-Virtual-Machine:~/code/dir1/hol1/q12$ ./modedemo &
[1] 5145
--- fd1 (O_RDONLY) ---
O_APPEND:   not set
O_NONBLOCK: not set
--- fd2 (O_WRONLY|O_APPEND) ---
looks write only, but this is wrong
O_APPEND:   set
O_NONBLOCK: not set
--- fd3 (O_RDWR|O_NONBLOCK) ---
looks read & write only, but this is wrong
O_APPEND:   not set
O_NONBLOCK: set
param@param-QEMU-Virtual-Machine:~/code/dir1/hol1/q12$ lsof -p $!
[1]+  Done                       ./modedemo

*/

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

void print_mode(int fd) {
    int flags = fcntl(fd, F_GETFL);
    if (flags == -1) {
        perror("fcntl F_GETFL");
        return;
    }

    switch (flags & O_ACCMODE) {
        case O_RDONLY: puts("access mode: read only");  break;
        case O_WRONLY: puts("access mode: write only"); break;
        case O_RDWR:   puts("access mode: read write"); break;
    }

    printf("O_APPEND:   %s\n", (flags & O_APPEND)   ? "set" : "not set");
    printf("O_NONBLOCK: %s\n", (flags & O_NONBLOCK) ? "set" : "not set");
}

int main(void) {
    int fd1 = open("data.txt", O_RDONLY);
    int fd2 = open("data.txt", O_WRONLY | O_APPEND);
    int fd3 = open("data.txt", O_RDWR | O_NONBLOCK);

    if (fd1 == -1 || fd2 == -1 || fd3 == -1) {
        perror("open");
        return 1;
    }

    puts("--- fd1 (O_RDONLY) ---");
    print_mode(fd1);
    puts("--- fd2 (O_WRONLY|O_APPEND) ---");
    print_mode(fd2);
    puts("--- fd3 (O_RDWR|O_NONBLOCK) ---");
    print_mode(fd3);

    close(fd1);
    close(fd2);
    close(fd3);
    return 0;
}