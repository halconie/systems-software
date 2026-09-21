/* 
param@param-QEMU-Virtual-Machine:~/code/dir1/hol1/q10$ vim holedemo.c
param@param-QEMU-Virtual-Machine:~/code/dir1/hol1/q10$ gcc -Wall -o holedemo holedemo.c 
param@param-QEMU-Virtual-Machine:~/code/dir1/hol1/q10$ ./holedemo 
lseek returned 20
param@param-QEMU-Virtual-Machine:~/code/dir1/hol1/q10$ ls -l hole.txt
-rw-r--r-- 1 param param 30 Sep 21 19:14 hole.txt
param@param-QEMU-Virtual-Machine:~/code/dir1/hol1/q10$ od -c hole.txt
0000000   0   1   2   3   4   5   6   7   8   9  \0  \0  \0  \0  \0  \0
0000020  \0  \0  \0  \0   A   B   C   D   E   F   G   H   I   J
0000036
param@param-QEMU-Virtual-Machine:~/code/dir1/hol1/q10$ du -h hole
holedemo    holedemo.c  hole.txt    
param@param-QEMU-Virtual-Machine:~/code/dir1/hol1/q10$ du -h hole.txt 
4.0K	hole.txt
param@param-QEMU-Virtual-Machine:~/code/dir1/hol1/q10$ du -h --apparent-size hole.txt
30	hole.txt
param@param-QEMU-Virtual-Machine:~/code/dir1/hol1/q10$ stat -c 'size=%s bytes, blocks=%b' hole.txt
size=30 bytes, blocks=8
param@param-QEMU-Virtual-Machine:~/code/dir1/hol1/q10$ ./holedemo 1048576
lseek returned 1048586
param@param-QEMU-Virtual-Machine:~/code/dir1/hol1/q10$ ls -l hole.txt 
-rw-r--r-- 1 param param 1048596 Sep 21 19:20 hole.txt
param@param-QEMU-Virtual-Machine:~/code/dir1/hol1/q10$ du -h hole.txt 
8.0K	hole.txt
param@param-QEMU-Virtual-Machine:~/code/dir1/hol1/q10$ stat -c 'size=%s bytes, blocks=%b' hole.txt
size=1048596 bytes, blocks=16
param@param-QEMU-Virtual-Machine:~/code/dir1/hol1/q10$ od -c hole.txt 
0000000   0   1   2   3   4   5   6   7   8   9  \0  \0  \0  \0  \0  \0
0000020  \0  \0  \0  \0  \0  \0  \0  \0  \0  \0  \0  \0  \0  \0  \0  \0
*
4000000  \0  \0  \0  \0  \0  \0  \0  \0  \0  \0   A   B   C   D   E   F
4000020   G   H   I   J
4000024

*/

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>

int main(int argc, char *argv[]) {
    off_t gap = 10;
    if (argc > 1) {
        gap = atol(argv[1]);
    }

    int fd = open("hole.txt", O_RDWR | O_CREAT | O_TRUNC, 0644);
    if (fd == -1) {
        perror("open");
        return 1;
    }

    if (write(fd, "0123456789", 10) != 10) {
        perror("first write");
        return 1;
    }

    off_t off = lseek(fd, gap, SEEK_CUR);
    if (off == (off_t) -1) {
        perror("lseek");
        return 1;
    }
    printf("lseek returned %lld\n", (long long) off);

    if (write(fd, "ABCDEFGHIJ", 10) != 10) {
        perror("second write");
        return 1;
    }

    close(fd);
    return 0;
}