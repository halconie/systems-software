/* 
param@param-QEMU-Virtual-Machine:~/code/dir1/hol1/q11c$ vim indep_dup_demo.c
param@param-QEMU-Virtual-Machine:~/code/dir1/hol1/q11c$ gcc -Wall -o indep_dup_demo indep_dup_demo.c 
param@param-QEMU-Virtual-Machine:~/code/dir1/hol1/q11c$ ./indep_dup_demo 
fd1=3 fd2=4 (two independent opens)
param@param-QEMU-Virtual-Machine:~/code/dir1/hol1/q11c$ cat separate.txt 
BBBBBDDDDDparam@param-QEMU-Virtual-Machine:~/code/dir1/hol1/q11c$


*/

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(void) {
    int fd1 = open("separate.txt", O_RDWR | O_CREAT | O_TRUNC, 0644);
    int fd2 = open("separate.txt", O_RDWR);
    if (fd1 == -1 || fd2 == -1) { perror("open"); return 1; }
    printf("fd1=%d fd2=%d (two independent opens)\n", fd1, fd2);

    write(fd1, "AAAAA", 5);
    write(fd2, "BBBBB", 5);
    write(fd1, "CCCCC", 5);
    write(fd2, "DDDDD", 5);

    close(fd1);
    close(fd2);
    return 0;
}