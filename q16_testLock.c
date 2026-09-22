/* 
param@param-QEMU-Virtual-Machine:~/code/dir1/hol1/q16$ touch target.txt
param@param-QEMU-Virtual-Machine:~/code/dir1/hol1/q16$ vim locktest.c
param@param-QEMU-Virtual-Machine:~/code/dir1/hol1/q16$ gcc -Wall -o locktest locktest.c 

param@param-QEMU-Virtual-Machine:~/code/dir1/hol1/q16$ ./locktest target.txt r 8 &
[1] 6988
[6988] requesting F_RDLCK (read) lock...
[6988] lock acquired, holding for 8 seconds
param@param-QEMU-Virtual-Machine:~/code/dir1/hol1/q16$ sleep 1
^[[Aparam@param-QEMU-Virtual-Machine:~/code/dir1/hol1/q16$ ./locktest target.txt r 5
[6998] requesting F_RDLCK (read) lock...
[6998] lock acquired, holding for 5 seconds
[6988] releasing lock
[6998] releasing lock
[1]+  Done                       ./locktest target.txt r 8

param@param-QEMU-Virtual-Machine:~/code/dir1/hol1/q16$ ./locktest target.txt w 8
[7214] requesting F_WRLCK (write) lock...
[7214] lock acquired, holding for 8 seconds
[7214] releasing lock

//Terminal 2
param@param-QEMU-Virtual-Machine:~/code/dir1/hol1/q16$ time ./locktest target.txt w 5
[7217] requesting F_WRLCK (write) lock...
[7217] lock acquired, holding for 5 seconds
[7217] releasing lock

real	0m9.042s
user	0m0.000s
sys	0m0.001s


param@param-QEMU-Virtual-Machine:~/code/dir1/hol1/q16$ ./locktest target.txt r 8
[7222] requesting F_RDLCK (read) lock...
[7222] lock acquired, holding for 8 seconds
[7222] releasing lock

// Terminal 2
param@param-QEMU-Virtual-Machine:~/code/dir1/hol1/q16$ time ./locktest target.txt w 5
[7228] requesting F_WRLCK (write) lock...
[7228] lock acquired, holding for 5 seconds
[7228] releasing lock

real	0m8.678s
user	0m0.000s
sys	0m0.003s


*/

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "usage: %s <file> <r|w> <hold_seconds>\n", argv[0]);
        return 1;
    }

    char *path = argv[1];
    char type = argv[2][0];
    int hold = atoi(argv[3]);

    int fd = open(path, O_RDWR);
    if (fd == -1) {
        perror("open");
        return 1;
    }

    struct flock fl;
    fl.l_type = (type == 'w') ? F_WRLCK : F_RDLCK;
    fl.l_whence = SEEK_SET;
    fl.l_start = 0;
    fl.l_len = 0;
    fl.l_pid = 0;

    printf("[%d] requesting %s lock...\n", getpid(),
           type == 'w' ? "F_WRLCK (write)" : "F_RDLCK (read)");

    if (fcntl(fd, F_SETLKW, &fl) == -1) {
        perror("fcntl F_SETLKW");
        close(fd);
        return 1;
    }

    printf("[%d] lock acquired, holding for %d seconds\n", getpid(), hold);
    sleep(hold);
    printf("[%d] releasing lock\n", getpid());

    fl.l_type = F_UNLCK;
    fcntl(fd, F_SETLK, &fl);

    close(fd);
    return 0;
}