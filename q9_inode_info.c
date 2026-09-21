/* 
param@param-QEMU-Virtual-Machine:~/code/dir1/hol1/q9$ printf '0123456789' > ten.txt
param@param-QEMU-Virtual-Machine:~/code/dir1/hol1/q9$ : > empty.txt
param@param-QEMU-Virtual-Machine:~/code/dir1/hol1/q9$ seq 1 5000 > big.txt
param@param-QEMU-Virtual-Machine:~/code/dir1/hol1/q9$ ls -li ten.txt empty.txt big.txt 
656987 -rw-rw-r-- 1 param param 23893 Sep 21 18:10 big.txt
656940 -rw-rw-r-- 1 param param     0 Sep 21 18:10 empty.txt
656937 -rw-rw-r-- 1 param param    10 Sep 21 18:10 ten.txt
param@param-QEMU-Virtual-Machine:~/code/dir1/hol1/q9$ vim statdemo.c
param@param-QEMU-Virtual-Machine:~/code/dir1/hol1/q9$ gcc -Wall -o statdemo statdemo.c 
param@param-QEMU-Virtual-Machine:~/code/dir1/hol1/q9$ ./statdemo ten.txt 
inode:       656937
link count:  1
uid:         1000
gid:         1000
size:        10 bytes
block size:  4096 bytes
blocks:      8 (512-byte units)
atime:       Mon Sep 21 18:10:03 2026
mtime:       Mon Sep 21 18:10:03 2026
ctime:       Mon Sep 21 18:10:03 2026
param@param-QEMU-Virtual-Machine:~/code/dir1/hol1/q9$ stat ten.txt
  File: ten.txt
  size: 10        	Blocks: 8          IO Block: 4096   regular file
Device: 253,2	Inode: 656937      Links: 1
Access: (0664/-rw-rw-r--)  Uid: ( 1000/   param)   Gid: ( 1000/   param)
Access: 2026-09-21 18:10:03.588545770 +0530
Modify: 2026-09-21 18:10:03.514879151 +0530
Change: 2026-09-21 18:10:03.514879151 +0530
 Birth: 2026-09-21 18:10:03.514879151 +0530
param@param-QEMU-Virtual-Machine:~/code/dir1/hol1/q9$ ls -li ten.txt 
656937 -rw-rw-r-- 1 param param 10 Sep 21 18:10 ten.txt
param@param-QEMU-Virtual-Machine:~/code/dir1/hol1/q9$ id
uid=1000(param) gid=1000(param) groups=1000(param),4(adm),24(cdrom),27(sudo),30(dip),46(plugdev),100(users),111(lpadmin),114(lxd)
param@param-QEMU-Virtual-Machine:~/code/dir1/hol1/q9$ ./statdemo ten.txt 
inode:       656937
link count:  1
uid:         1000
gid:         1000
size:        10 bytes
block size:  4096 bytes
blocks:      8 (512-byte units)
atime:       Mon Sep 21 18:10:03 2026
mtime:       Mon Sep 21 18:10:03 2026
ctime:       Mon Sep 21 18:10:03 2026
param@param-QEMU-Virtual-Machine:~/code/dir1/hol1/q9$ ./statdemo empty.txt 
inode:       656940
link count:  1
uid:         1000
gid:         1000
size:        0 bytes
block size:  4096 bytes
blocks:      0 (512-byte units)
atime:       Mon Sep 21 18:10:13 2026
mtime:       Mon Sep 21 18:10:13 2026
ctime:       Mon Sep 21 18:10:13 2026
param@param-QEMU-Virtual-Machine:~/code/dir1/hol1/q9$ ./statdemo big.txt 
inode:       656987
link count:  1
uid:         1000
gid:         1000
size:        23893 bytes
block size:  4096 bytes
blocks:      48 (512-byte units)
atime:       Mon Sep 21 18:10:26 2026
mtime:       Mon Sep 21 18:10:26 2026
ctime:       Mon Sep 21 18:10:26 2026
param@param-QEMU-Virtual-Machine:~/code/dir1/hol1/q9$ ln ten.txt ten_link
param@param-QEMU-Virtual-Machine:~/code/dir1/hol1/q9$ ./statdemo ten.txt 
inode:       656937
link count:  2
uid:         1000
gid:         1000
size:        10 bytes
block size:  4096 bytes
blocks:      8 (512-byte units)
atime:       Mon Sep 21 18:10:03 2026
mtime:       Mon Sep 21 18:10:03 2026
ctime:       Mon Sep 21 18:32:19 2026
param@param-QEMU-Virtual-Machine:~/code/dir1/hol1/q9$ sleep 2
param@param-QEMU-Virtual-Machine:~/code/dir1/hol1/q9$ chmod 600 ten.txt 
param@param-QEMU-Virtual-Machine:~/code/dir1/hol1/q9$ ./statdemo ten.txt 
inode:       656937
link count:  2
uid:         1000
gid:         1000
size:        10 bytes
block size:  4096 bytes
blocks:      8 (512-byte units)
atime:       Mon Sep 21 18:10:03 2026
mtime:       Mon Sep 21 18:10:03 2026
ctime:       Mon Sep 21 18:33:08 2026
param@param-QEMU-Virtual-Machine:~/code/dir1/hol1/q9$ echo x >> ten.txt 
param@param-QEMU-Virtual-Machine:~/code/dir1/hol1/q9$ ./statdemo ten.txt 
inode:       656937
link count:  2
uid:         1000
gid:         1000
size:        12 bytes
block size:  4096 bytes
blocks:      8 (512-byte units)
atime:       Mon Sep 21 18:34:37 2026
mtime:       Mon Sep 21 18:34:37 2026
ctime:       Mon Sep 21 18:34:37 2026

*/

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "usage: %s file\n", argv[0]);
        return 1;
    }

    struct stat sb;
    if (stat(argv[1], &sb) == -1) {
        perror(argv[1]);
        return 1;
    }

    printf("inode:       %lu\n", (unsigned long) sb.st_ino);
    printf("link count:  %lu\n", (unsigned long) sb.st_nlink);
    printf("uid:         %u\n", (unsigned) sb.st_uid);
    printf("gid:         %u\n", (unsigned) sb.st_gid);
    printf("size:        %lld bytes\n", (long long) sb.st_size);
    printf("block size:  %ld bytes\n", (long) sb.st_blksize);
    printf("blocks:      %lld (512-byte units)\n", (long long) sb.st_blocks);
    printf("atime:       %s", ctime(&sb.st_atime));
    printf("mtime:       %s", ctime(&sb.st_mtime));
    printf("ctime:       %s", ctime(&sb.st_ctime));

    return 0;
}