/* 
param@param-QEMU-Virtual-Machine:~/code/dir1/hol1/q1$ ln -s original.txt softlink
param@param-QEMU-Virtual-Machine:~/code/dir1/hol1/q1$ ls -li
total 4
655889 -rw-rw-r-- 1 param param 112 Sep 20 02:54 original.txt
656895 lrwxrwxrwx 1 param param  12 Sep 20 03:08 softlink -> original.txt
*/


#include <stdio.h>
#include <unistd.h>

int main(void){
	if(symlink("original.txt", "softlink2") == -1){
		perror("symlink");
		return 1;
	}

	printf("softlink created\n");
	return 0;
}

/* 
param@param-QEMU-Virtual-Machine:~/code/dir1/hol1/q1$ vim make_softlink.c
param@param-QEMU-Virtual-Machine:~/code/dir1/hol1/q1$ gcc make_softlink.c -o make_softlink
param@param-QEMU-Virtual-Machine:~/code/dir1/hol1/q1$ ./make_softlink
softlink created
param@param-QEMU-Virtual-Machine:~/code/dir1/hol1/q1$ ls -li
total 24
656861 -rwxrwxr-x 1 param param 70544 Sep 20 03:19 make_softlink
656907 -rw-rw-r-- 1 param param   186 Sep 20 03:19 make_softlink.c
655889 -rw-rw-r-- 1 param param   112 Sep 20 02:54 original.txt
656895 lrwxrwxrwx 1 param param    12 Sep 20 03:08 softlink -> original.txt
656870 lrwxrwxrwx 1 param param    12 Sep 20 03:19 softlink2 -> original.txt



param@param-QEMU-Virtual-Machine:~/code/dir1/hol1/q1$ cat softlink
This file was created to do the task of creating a softlink using shell for the 1st question of hands-on list 1
param@param-QEMU-Virtual-Machine:~/code/dir1/hol1/q1$ readlink softlink
original.txt
param@param-QEMU-Virtual-Machine:~/code/dir1/hol1/q1$ ls
make_softlink  make_softlink.c  original.txt  softlink  softlink2
param@param-QEMU-Virtual-Machine:~/code/dir1/hol1/q1$ rm original.txt 
param@param-QEMU-Virtual-Machine:~/code/dir1/hol1/q1$ cat softlink
cat: softlink: No such file or directory
param@param-QEMU-Virtual-Machine:~/code/dir1/hol1/q1$ ls -l
total 20
-rwxrwxr-x 1 param param 70544 Sep 20 03:19 make_softlink
-rw-rw-r-- 1 param param   186 Sep 20 03:19 make_softlink.c
lrwxrwxrwx 1 param param    12 Sep 20 03:08 softlink -> original.txt
lrwxrwxrwx 1 param param    12 Sep 20 03:19 softlink2 -> original.txt

*/