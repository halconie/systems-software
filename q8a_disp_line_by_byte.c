
/* 
param@param-QEMU-Virtual-Machine:~/code/dir1/hol1/q8$ printf 'first line\nsecond line\nthird line without newline' > test.txt
param@param-QEMU-Virtual-Machine:~/code/dir1/hol1/q8$ od -c test.txt
0000000   f   i   r   s   t       l   i   n   e  \n   s   e   c   o   n
0000020   d       l   i   n   e  \n   t   h   i   r   d       l   i   n
0000040   e       w   i   t   h   o   u   t       n   e   w   l   i   n
0000060   e
0000061
param@param-QEMU-Virtual-Machine:~/code/dir1/hol1/q8$ vim readlines.c
param@param-QEMU-Virtual-Machine:~/code/dir1/hol1/q8$ gcc -Wall -o readlines readlines.c 
param@param-QEMU-Virtual-Machine:~/code/dir1/hol1/q8$ ./readlines test.txt 
1: first line
2: second line
3: third line without newline
param@param-QEMU-Virtual-Machine:~/code/dir1/hol1/q8$ ./readlines nosuchfile
nosuchfile: No such file or directory


*/

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "usage: %s file\n", argv[0]);
        return 1;
    }

    int fd = open(argv[1], O_RDONLY);
    if (fd == -1) {
        perror(argv[1]);
        return 1;
    }

    char line[1024];
    size_t len = 0;
    int lineno = 1;
    char c;
    ssize_t n;

    while ((n = read(fd, &c, 1)) > 0) {
        if (c == '\n') {
            line[len] = '\0';
            printf("%d: %s\n", lineno++, line);
            len = 0;
        } else if (len < sizeof line - 1) {
            line[len++] = c;
        }
    }
    if (n == -1) {
        perror("read");
    }

    if (len > 0) {
        line[len] = '\0';
        printf("%d: %s\n", lineno, line);
    }

    close(fd);
    return 0;
}