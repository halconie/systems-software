/* 
param@param-QEMU-Virtual-Machine:~/code/dir1/hol1/q11c$ vim dupfcntlDemo.c
param@param-QEMU-Virtual-Machine:~/code/dir1/hol1/q11c$ gcc -Wall -o dupfcntlDemo dupfcntlDemo.c 
param@param-QEMU-Virtual-Machine:~/code/dir1/hol1/q11c$ ./dupfcntlDemo 
fd1=3 fd2=4 (fcntl F_DUPFD)
param@param-QEMU-Virtual-Machine:~/code/dir1/hol1/q11c$ cat shared_c.txt 
XXXXXYYYYYparam@param-QEMU-Virtual-Machine:~/code/dir1/hol1/q11c$
*/

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(void) {
    int fd1 = open("shared_c.txt", O_RDWR | O_CREAT | O_TRUNC, 0644);
    if (fd1 == -1) { perror("open"); return 1; }

    int fd2 = fcntl(fd1, F_DUPFD, 0);
    if (fd2 == -1) { perror("fcntl"); return 1; }
    printf("fd1=%d fd2=%d (fcntl F_DUPFD)\n", fd1, fd2);

    write(fd1, "XXXXX", 5);
    write(fd2, "YYYYY", 5);

    close(fd1);
    close(fd2);
    return 0;
}