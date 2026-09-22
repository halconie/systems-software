/* 
param@param-QEMU-Virtual-Machine:~/code/dir1/hol1/q11a$ vim dupdemo.c
param@param-QEMU-Virtual-Machine:~/code/dir1/hol1/q11a$ gcc -Wall -o dupdemo dupdemo.c 
param@param-QEMU-Virtual-Machine:~/code/dir1/hol1/q11a$ ./dupdemo 
fd1=3 fd2=4 (dup)

param@param-QEMU-Virtual-Machine:~/code/dir1/hol1/q11a$ cat shared_a.txt 
AAAAABBBBBCCCCCDDDDDparam@param-QEMU-Virtual-Machine:~/code/dir1/hol1/q11a$

param@param-QEMU-Virtual-Machine:~/code/dir1/hol1/q11a$ ./dupdemo &
[1] 4814
fd1=3 fd2=4 (dup)
param@param-QEMU-Virtual-Machine:~/code/dir1/hol1/q11a$ lsof -p $!
[1]+  Done                       ./dupdemo
*/

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(void) {
    int fd1 = open("shared_a.txt", O_RDWR | O_CREAT | O_TRUNC, 0644);
    if (fd1 == -1) { perror("open"); return 1; }

    int fd2 = dup(fd1);
    if (fd2 == -1) { perror("dup"); return 1; }
    printf("fd1=%d fd2=%d (dup)\n", fd1, fd2);

    write(fd1, "AAAAA", 5);
    write(fd2, "BBBBB", 5);
    write(fd1, "CCCCC", 5);
    write(fd2, "DDDDD", 5);

    close(fd1);
    close(fd2);
    return 0;
}