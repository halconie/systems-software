/* 
param@param-QEMU-Virtual-Machine:~/code/dir1/hol1/q5$ vim five_files.c
param@param-QEMU-Virtual-Machine:~/code/dir1/hol1/q5$ gcc -Wall -o five_files five_files.c 

param@param-QEMU-Virtual-Machine:~/code/dir1/hol1/q5$ ./five_files &
[1] 9077
file1 -> fd 3
file2 -> fd 4
file3 -> fd 5
file4 -> fd 6
file5 -> fd 7
param@param-QEMU-Virtual-Machine:~/code/dir1/hol1/q5$ jobs
[1]+  Running                    ./five_files &
param@param-QEMU-Virtual-Machine:~/code/dir1/hol1/q5$ PID=$!
param@param-QEMU-Virtual-Machine:~/code/dir1/hol1/q5$ echo $PID
9077
param@param-QEMU-Virtual-Machine:~/code/dir1/hol1/q5$ ls -l /proc/$PID/fd
total 0
lrwx------ 1 param param 64 Sep 21 01:32 0 -> /dev/pts/0
lrwx------ 1 param param 64 Sep 21 01:32 1 -> /dev/pts/0
lrwx------ 1 param param 64 Sep 21 01:32 2 -> /dev/pts/0
l-wx------ 1 param param 64 Sep 21 01:32 3 -> /home/param/code/dir1/hol1/q5/file1
l-wx------ 1 param param 64 Sep 21 01:32 4 -> /home/param/code/dir1/hol1/q5/file2
l-wx------ 1 param param 64 Sep 21 01:32 5 -> /home/param/code/dir1/hol1/q5/file3
l-wx------ 1 param param 64 Sep 21 01:32 6 -> /home/param/code/dir1/hol1/q5/file4
l-wx------ 1 param param 64 Sep 21 01:32 7 -> /home/param/code/dir1/hol1/q5/file5
param@param-QEMU-Virtual-Machine:~/code/dir1/hol1/q5$ lsof -p $PID
COMMAND    PID  USER  FD   TYPE DEVICE SIZE/OFF    NODE NAME
five_file 9077 param cwd    DIR  253,2     4096  656945 /home/param/code/dir1/hol1/q5
five_file 9077 param rtd    DIR  253,2     4096       2 /
five_file 9077 param txt    REG  253,2    70712  656935 /home/param/code/dir1/hol1/q5/five_files
five_file 9077 param mem    REG  253,2  1788240 2230048 /usr/lib/aarch64-linux-gnu/libc.so.6
five_file 9077 param mem    REG  253,2   201872 2230045 /usr/lib/aarch64-linux-gnu/ld-linux-aarch64.so.1
five_file 9077 param   0u   CHR  136,0      0t0       3 /dev/pts/0
five_file 9077 param   1u   CHR  136,0      0t0       3 /dev/pts/0
five_file 9077 param   2u   CHR  136,0      0t0       3 /dev/pts/0
five_file 9077 param   3w   REG  253,2        0  656939 /home/param/code/dir1/hol1/q5/file1
five_file 9077 param   4w   REG  253,2        0  656957 /home/param/code/dir1/hol1/q5/file2
five_file 9077 param   5w   REG  253,2        0  656958 /home/param/code/dir1/hol1/q5/file3
five_file 9077 param   6w   REG  253,2        0  656959 /home/param/code/dir1/hol1/q5/file4
five_file 9077 param   7w   REG  253,2        0  656960 /home/param/code/dir1/hol1/q5/file5
param@param-QEMU-Virtual-Machine:~/code/dir1/hol1/q5$ kill $PID
[1]+  Terminated                 ./five_files
param@param-QEMU-Virtual-Machine:~/code/dir1/hol1/q5$ rm file1 file2 file3 file4 file5

*/

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(void) {
    char name[16];

    for (int i = 1; i <= 5; i++) {
        snprintf(name, sizeof(name), "file%d", i);
        int fd = creat(name, 0644);
        if (fd == -1) {
            perror("creat");
            return 1;
        }
        printf("%s -> fd %d\n", name, fd);
    }

    while (1) {
        sleep(1);
    }
    return 0;
}