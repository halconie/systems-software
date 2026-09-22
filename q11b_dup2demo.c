/* 
param@param-QEMU-Virtual-Machine:~/code/dir1/hol1/q11b$ vim dup2demo.c
param@param-QEMU-Virtual-Machine:~/code/dir1/hol1/q11b$ gcc -Wall -o dup2demo dup2demo.c 
param@param-QEMU-Virtual-Machine:~/code/dir1/hol1/q11b$ ./dup2demo 
fd1=3 fd2=10 (dup2)
param@param-QEMU-Virtual-Machine:~/code/dir1/hol1/q11b$ cat shared_b.txt 
1111122222param@param-QEMU-Virtual-Machine:~/code/dir1/hol1/q11b$
*/

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(void) {
    int fd1 = open("shared_b.txt", O_RDWR | O_CREAT | O_TRUNC, 0644);
    if (fd1 == -1) { perror("open"); return 1; }

    int fd2 = dup2(fd1, 10);
    if (fd2 == -1) { perror("dup2"); return 1; }
    printf("fd1=%d fd2=%d (dup2)\n", fd1, fd2);

    write(fd1, "11111", 5);
    write(fd2, "22222", 5);

    close(fd1);
    close(fd2);
    return 0;
}