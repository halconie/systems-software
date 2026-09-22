/* 
param@param-QEMU-Virtual-Machine:~/code/dir1/hol1/q13$ vim selectdemo.c
param@param-QEMU-Virtual-Machine:~/code/dir1/hol1/q13$ gcc -Wall -o selectdemo selectdemo.c 

param@param-QEMU-Virtual-Machine:~/code/dir1/hol1/q13$ ./selectdemo 
Waiting up to 10 seconds for input on stdin...
This is a test text
Data is available now
Read: This is a test text
param@param-QEMU-Virtual-Machine:~/code/dir1/hol1/q13$ ./selectdemo 
Waiting up to 10 seconds for input on stdin...
No data within 10 seconds
param@param-QEMU-Virtual-Machine:~/code/dir1/hol1/q13$ time ./selectdemo < /dev/null
Waiting up to 10 seconds for input on stdin...
Data is available now

real	0m0.008s
user	0m0.000s
sys	0m0.008s

*/

#include <stdio.h>
#include <sys/select.h>
#include <unistd.h>

int main(void) {
    fd_set rfds;
    struct timeval tv;

    FD_ZERO(&rfds);
    FD_SET(0, &rfds);

    tv.tv_sec = 10;
    tv.tv_usec = 0;

    printf("Waiting up to 10 seconds for input on stdin...\n");

    int r = select(1, &rfds, NULL, NULL, &tv);

    if (r == -1) {
        perror("select");
        return 1;
    } else if (r == 0) {
        printf("No data within 10 seconds\n");
    } else {
        printf("Data is available now\n");
        if (FD_ISSET(0, &rfds)) {
            char buf[100];
            ssize_t n = read(0, buf, sizeof buf - 1);
            if (n > 0) {
                buf[n] = '\0';
                printf("Read: %s", buf);
            }
        }
    }

    return 0;
}