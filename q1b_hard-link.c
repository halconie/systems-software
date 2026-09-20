/* 
param@param-QEMU-Virtual-Machine:~/code/dir1/hol1/q1$ ln original2.txt hardlink
param@param-QEMU-Virtual-Machine:~/code/dir1/hol1/q1$ ls -li
total 28
655888 -rw-rw-r-- 2 param param   112 Sep 20 03:28 hardlink
656861 -rwxrwxr-x 1 param param 70544 Sep 20 03:19 make_softlink
656907 -rw-rw-r-- 1 param param   186 Sep 20 03:19 make_softlink.c
655888 -rw-rw-r-- 2 param param   112 Sep 20 03:28 original2.txt
656895 lrwxrwxrwx 1 param param    12 Sep 20 03:08 softlink -> original.txt
656870 lrwxrwxrwx 1 param param    12 Sep 20 03:19 softlink2 -> original.txt
param@param-QEMU-Virtual-Machine:~/code/dir1/hol1/q1$ 


param@param-QEMU-Virtual-Machine:~/code/dir1/hol1$ cd q1b
param@param-QEMU-Virtual-Machine:~/code/dir1/hol1/q1b$ ls
original2.txt
param@param-QEMU-Virtual-Machine:~/code/dir1/hol1/q1b$ ln original2.txt hardlink
param@param-QEMU-Virtual-Machine:~/code/dir1/hol1/q1b$ ls
hardlink  original2.txt
param@param-QEMU-Virtual-Machine:~/code/dir1/hol1/q1b$ vim make_hardlink.c
param@param-QEMU-Virtual-Machine:~/code/dir1/hol1/q1b$ ls
hardlink  make_hardlink.c  original2.txt
param@param-QEMU-Virtual-Machine:~/code/dir1/hol1/q1b$ gcc make_hardlink.c -o make_hardlink
param@param-QEMU-Virtual-Machine:~/code/dir1/hol1/q1b$ ./make_hardlink
hardlink2 created
param@param-QEMU-Virtual-Machine:~/code/dir1/hol1/q1b$ ls -li
total 32
655825 -rw-rw-r-- 3 param param   112 Sep 20 13:17 hardlink
655825 -rw-rw-r-- 3 param param   112 Sep 20 13:17 hardlink2
655853 -rwxrwxr-x 1 param param 70544 Sep 20 14:05 make_hardlink
656930 -rw-rw-r-- 1 param param   208 Sep 20 14:05 make_hardlink.c
655825 -rw-rw-r-- 3 param param   112 Sep 20 13:17 original2.txt

*/

#include <stdio.h>
#include <unistd.h>

int main(void) {
    if (link("original2.txt", "hardlink2") == -1) {
        perror("link");
        return 1;
    }
    printf("hardlink2 created\n");
    return 0;
}
