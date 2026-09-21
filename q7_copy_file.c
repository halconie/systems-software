/* 
param@param-QEMU-Virtual-Machine:~/code/dir1/hol1/q7$ seq 1 5000 > file1
param@param-QEMU-Virtual-Machine:~/code/dir1/hol1/q7$ head -c 100000 /dev/urandom > bin1
param@param-QEMU-Virtual-Machine:~/code/dir1/hol1/q7$ ls -l file1 bin1
-rw-rw-r-- 1 param param 100000 Sep 21 16:53 bin1
-rw-rw-r-- 1 param param  23893 Sep 21 16:52 file1
param@param-QEMU-Virtual-Machine:~/code/dir1/hol1/q7$ vim mycp.c
param@param-QEMU-Virtual-Machine:~/code/dir1/hol1/q7$ gcc -Wall -o mycp mycp.c 
param@param-QEMU-Virtual-Machine:~/code/dir1/hol1/q7$ ./mycp file1 file2
param@param-QEMU-Virtual-Machine:~/code/dir1/hol1/q7$ ./mycp bin1 bin2
param@param-QEMU-Virtual-Machine:~/code/dir1/hol1/q7$ cmp file1 file2 && echo identical
identical
param@param-QEMU-Virtual-Machine:~/code/dir1/hol1/q7$ cmp bin1 bin2 && echo identical
identical
param@param-QEMU-Virtual-Machine:~/code/dir1/hol1/q7$ ls -l file1 file2 bin1 bin2
-rw-rw-r-- 1 param param 100000 Sep 21 16:53 bin1
-rw-r--r-- 1 param param 100000 Sep 21 17:10 bin2
-rw-rw-r-- 1 param param  23893 Sep 21 16:52 file1
-rw-r--r-- 1 param param  23893 Sep 21 17:10 file2
param@param-QEMU-Virtual-Machine:~/code/dir1/hol1/q7$ ./mycp file1
usage: ./mycp source dest
param@param-QEMU-Virtual-Machine:~/code/dir1/hol1/q7$ ./mycp nosuchfile out.txt
nosuchfile: No such file or directory
param@param-QEMU-Virtual-Machine:~/code/dir1/hol1/q7$ cp file1 file3
param@param-QEMU-Virtual-Machine:~/code/dir1/hol1/q7$ cmp file2 file3 && echo same
same
param@param-QEMU-Virtual-Machine:~/code/dir1/hol1/q7$ chmod 600 file1
param@param-QEMU-Virtual-Machine:~/code/dir1/hol1/q7$ ./mycp file1 file4
param@param-QEMU-Virtual-Machine:~/code/dir1/hol1/q7$ ls -l file1 file4
-rw------- 1 param param 23893 Sep 21 16:52 file1
-rw-r--r-- 1 param param 23893 Sep 21 17:15 file4

*/

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "usage: %s source dest\n", argv[0]);
        return 1;
    }

    int src = open(argv[1], O_RDONLY);
    if (src == -1) {
        perror(argv[1]);
        return 1;
    }

    int dst = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (dst == -1) {
        perror(argv[2]);
        close(src);
        return 1;
    }

    char buf[4096];
    ssize_t n;
    int status = 0;

    while ((n = read(src, buf, sizeof buf)) > 0) {
        if (write(dst, buf, n) != n) {
            perror("write");
            status = 1;
            break;
        }
    }
    if (n == -1) {
        perror("read");
        status = 1;
    }

    close(src);
    close(dst);
    return status;
}