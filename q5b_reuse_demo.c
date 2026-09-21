/* 
aram@param-QEMU-Virtual-Machine:~/code/dir1/hol1/q5$ vim reuse_demo.c
param@param-QEMU-Virtual-Machine:~/code/dir1/hol1/q5$ gcc -Wall -o reuse_demo reuse_demo.c 
param@param-QEMU-Virtual-Machine:~/code/dir1/hol1/q5$ ./reuse_demo
A: file1 -> fd 3
A: file2 -> fd 3
A: file3 -> fd 3
A: file4 -> fd 3
A: file5 -> fd 3
B: a=3 b=4 c=5
B: after close(4), new fd = 4
param@param-QEMU-Virtual-Machine:~/code/dir1/hol1/q5$ ulimit -n
1024
param@param-QEMU-Virtual-Machine:~/code/dir1/hol1/q5$ ulimit -Hn
524288

*/

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(void) {
    char name[16];

    for (int i = 1; i <= 5; i++) {
        snprintf(name, sizeof(name), "file%d", i);
        int fd = creat(name, 0644);
        printf("A: %s -> fd %d\n", name, fd);
        close(fd);
    }

    int a = creat("file1", 0644);
    int b = creat("file2", 0644);
    int c = creat("file3", 0644);
    printf("B: a=%d b=%d c=%d\n", a, b, c);
    close(b);
    int d = creat("file4", 0644);
    printf("B: after close(%d), new fd = %d\n", b, d);

    close(a);
    close(c);
    close(d);
    return 0;
}