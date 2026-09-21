/* 
param@param-QEMU-Virtual-Machine:~/code/dir1/hol1/q8$ vim readlines_blk.c
param@param-QEMU-Virtual-Machine:~/code/dir1/hol1/q8$ gcc -Wall -o readlines_blk readlines_blk.c
param@param-QEMU-Virtual-Machine:~/code/dir1/hol1/q8$ ./readlines_blk test.txt 
1: first line
2: second line
3: third line without newline
param@param-QEMU-Virtual-Machine:~/code/dir1/hol1/q8$ strace -c -e trace=read ./readlines test.txt 
1: first line
2: second line
3: third line without newline
% time     seconds  usecs/call     calls    errors syscall
------ ----------- ----------- --------- --------- ----------------
100.00    0.001924          37        51           read
------ ----------- ----------- --------- --------- ----------------
100.00    0.001924          37        51           total
param@param-QEMU-Virtual-Machine:~/code/dir1/hol1/q8$ strace -c -e trace=read ./readlines_blk test.txt 
1: first line
2: second line
3: third line without newline
% time     seconds  usecs/call     calls    errors syscall
------ ----------- ----------- --------- --------- ----------------
  0.00    0.000000           0         3           read
------ ----------- ----------- --------- --------- ----------------
100.00    0.000000           0         3           total

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

    char buf[4096];
    char line[1024];
    size_t len = 0;
    int lineno = 1;
    ssize_t n;

    while ((n = read(fd, buf, sizeof buf)) > 0) {
        for (ssize_t i = 0; i < n; i++) {
            if (buf[i] == '\n') {
                line[len] = '\0';
                printf("%d: %s\n", lineno++, line);
                len = 0;
            } else if (len < sizeof line - 1) {
                line[len++] = buf[i];
            }
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