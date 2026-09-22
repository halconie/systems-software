/* 
param@param-QEMU-Virtual-Machine:~/code/dir1/hol1/q14$ vim filetype.c
param@param-QEMU-Virtual-Machine:~/code/dir1/hol1/q14$ gcc -Wall -o filetype filetype.c 
param@param-QEMU-Virtual-Machine:~/code/dir1/hol1/q14$ echo hello > reg.txt
param@param-QEMU-Virtual-Machine:~/code/dir1/hol1/q14$ ln -s reg.txt symlink_to_reg
param@param-QEMU-Virtual-Machine:~/code/dir1/hol1/q14$ mkfifo myfifo

param@param-QEMU-Virtual-Machine:~/code/dir1/hol1/q14$ ls -l /dev/tty /dev/vda
crw-rw-rw- 1 root tty    5, 0 Sep 22 15:19 /dev/tty
brw-rw---- 1 root disk 253, 0 Sep 22 15:19 /dev/vda
param@param-QEMU-Virtual-Machine:~/code/dir1/hol1/q14$ ls -l /dev/ | grep '^b'
brw-rw----  1 root  disk      7,   0 Sep 22 15:19 loop0
brw-rw----  1 root  disk      7,   1 Sep 22 15:19 loop1
brw-rw----  1 root  disk      7,  10 Sep 22 15:19 loop10
brw-rw----  1 root  disk      7,  11 Sep 22 15:19 loop11
brw-rw----  1 root  disk      7,  12 Sep 22 15:19 loop12
brw-rw----  1 root  disk      7,  13 Sep 22 15:24 loop13
brw-rw----  1 root  disk      7,  14 Sep 22 15:24 loop14
brw-rw----  1 root  disk      7,   2 Sep 22 15:19 loop2
brw-rw----  1 root  disk      7,   3 Sep 22 15:19 loop3
brw-rw----  1 root  disk      7,   4 Sep 22 15:19 loop4
brw-rw----  1 root  disk      7,   5 Sep 22 15:19 loop5
brw-rw----  1 root  disk      7,   6 Sep 22 15:19 loop6
brw-rw----  1 root  disk      7,   7 Sep 22 15:19 loop7
brw-rw----  1 root  disk      7,   8 Sep 22 15:19 loop8
brw-rw----  1 root  disk      7,   9 Sep 22 15:19 loop9
brw-rw----+ 1 root  cdrom    11,   0 Sep 22 15:19 sr0
brw-rw----  1 root  disk    253,   0 Sep 22 15:19 vda
brw-rw----  1 root  disk    253,   1 Sep 22 15:19 vda1
brw-rw----  1 root  disk    253,   2 Sep 22 15:19 vda2
param@param-QEMU-Virtual-Machine:~/code/dir1/hol1/q14$ ls -l /dev/ | grep '^c'
crw-r--r--  1 root  root     10, 235 Sep 22 15:19 autofs
crw-------  1 root  root     10, 234 Sep 22 15:19 btrfs-control
crw-------  1 root  tty       5,   1 Sep 22 15:19 console
crw-------  1 root  root     10, 260 Sep 22 15:19 cpu_dma_latency
crw-------  1 root  root     10, 261 Sep 22 15:19 cpu_wakeup_latency
crw-------  1 root  root     10, 203 Sep 22 15:19 cuse
crw-------  1 root  root     10, 258 Sep 22 15:19 ecryptfs
crw-rw----  1 root  video    29,   0 Sep 22 15:19 fb0
crw-rw-rw-  1 root  root      1,   7 Sep 22 15:19 full
crw-rw-rw-  1 root  root     10, 229 Sep 22 15:19 fuse
crw-------  1 root  root    234,   0 Sep 22 15:19 hidraw0
crw-------  1 root  root    234,   1 Sep 22 15:19 hidraw1
crw-------  1 root  root    234,   2 Sep 22 15:19 hidraw2
crw-------  1 root  root     10, 183 Sep 22 15:19 hwrng
crw-r--r--  1 root  root      1,  11 Sep 22 15:19 kmsg
crw-rw----  1 root  disk     10, 237 Sep 22 15:19 loop-control
crw-r-----  1 root  kmem      1,   1 Sep 22 15:19 mem
crw-rw-rw-  1 root  root      1,   3 Sep 22 15:19 null
crw-r-----  1 root  kmem      1,   4 Sep 22 15:19 port
crw-------  1 root  root    108,   0 Sep 22 15:19 ppp
crw-------  1 root  root     10,   1 Sep 22 15:19 psaux
crw-rw-rw-  1 root  tty       5,   2 Sep 22 17:02 ptmx
crw-rw-rw-  1 root  root      1,   8 Sep 22 15:19 random
crw-rw-r--+ 1 root  root     10, 242 Sep 22 15:19 rfkill
crw-rw----  1 root  clock   246,   0 Sep 22 15:19 rtc0
crw-rw----+ 1 root  cdrom    21,   0 Sep 22 15:19 sg0
crw-rw-rw-  1 root  tty       5,   0 Sep 22 15:19 tty
crw-------  1 root  tty       4,   0 Sep 22 15:19 tty0
crw-------  1 root  tty       4,   1 Sep 22 15:19 tty1
crw-------  1 root  tty       4,  10 Sep 22 15:19 tty10
crw-------  1 root  tty       4,  11 Sep 22 15:19 tty11
crw-------  1 root  tty       4,  12 Sep 22 15:19 tty12
crw-------  1 root  tty       4,  13 Sep 22 15:19 tty13
crw-------  1 root  tty       4,  14 Sep 22 15:19 tty14
crw-------  1 root  tty       4,  15 Sep 22 15:19 tty15
crw-------  1 root  tty       4,  16 Sep 22 15:19 tty16
crw-------  1 root  tty       4,  17 Sep 22 15:19 tty17
crw-------  1 root  tty       4,  18 Sep 22 15:19 tty18
crw-------  1 root  tty       4,  19 Sep 22 15:19 tty19
crw-------  1 param tty       4,   2 Sep 22 15:19 tty2
crw-------  1 root  tty       4,  20 Sep 22 15:19 tty20
crw-------  1 root  tty       4,  21 Sep 22 15:19 tty21
crw-------  1 root  tty       4,  22 Sep 22 15:19 tty22
crw-------  1 root  tty       4,  23 Sep 22 15:19 tty23
crw-------  1 root  tty       4,  24 Sep 22 15:19 tty24
crw-------  1 root  tty       4,  25 Sep 22 15:19 tty25
crw-------  1 root  tty       4,  26 Sep 22 15:19 tty26
crw-------  1 root  tty       4,  27 Sep 22 15:19 tty27
crw-------  1 root  tty       4,  28 Sep 22 15:19 tty28
crw-------  1 root  tty       4,  29 Sep 22 15:19 tty29
crw-------  1 root  tty       4,   3 Sep 22 15:19 tty3
crw-------  1 root  tty       4,  30 Sep 22 15:19 tty30
crw-------  1 root  tty       4,  31 Sep 22 15:19 tty31
crw-------  1 root  tty       4,  32 Sep 22 15:19 tty32
crw-------  1 root  tty       4,  33 Sep 22 15:19 tty33
crw-------  1 root  tty       4,  34 Sep 22 15:19 tty34
crw-------  1 root  tty       4,  35 Sep 22 15:19 tty35
crw-------  1 root  tty       4,  36 Sep 22 15:19 tty36
crw-------  1 root  tty       4,  37 Sep 22 15:19 tty37
crw-------  1 root  tty       4,  38 Sep 22 15:19 tty38
crw-------  1 root  tty       4,  39 Sep 22 15:19 tty39
crw-------  1 root  tty       4,   4 Sep 22 15:19 tty4
crw-------  1 root  tty       4,  40 Sep 22 15:19 tty40
crw-------  1 root  tty       4,  41 Sep 22 15:19 tty41
crw-------  1 root  tty       4,  42 Sep 22 15:19 tty42
crw-------  1 root  tty       4,  43 Sep 22 15:19 tty43
crw-------  1 root  tty       4,  44 Sep 22 15:19 tty44
crw-------  1 root  tty       4,  45 Sep 22 15:19 tty45
crw-------  1 root  tty       4,  46 Sep 22 15:19 tty46
crw-------  1 root  tty       4,  47 Sep 22 15:19 tty47
crw-------  1 root  tty       4,  48 Sep 22 15:19 tty48
crw-------  1 root  tty       4,  49 Sep 22 15:19 tty49
crw-------  1 root  tty       4,   5 Sep 22 15:19 tty5
crw-------  1 root  tty       4,  50 Sep 22 15:19 tty50
crw-------  1 root  tty       4,  51 Sep 22 15:19 tty51
crw-------  1 root  tty       4,  52 Sep 22 15:19 tty52
crw-------  1 root  tty       4,  53 Sep 22 15:19 tty53
crw-------  1 root  tty       4,  54 Sep 22 15:19 tty54
crw-------  1 root  tty       4,  55 Sep 22 15:19 tty55
crw-------  1 root  tty       4,  56 Sep 22 15:19 tty56
crw-------  1 root  tty       4,  57 Sep 22 15:19 tty57
crw-------  1 root  tty       4,  58 Sep 22 15:19 tty58
crw-------  1 root  tty       4,  59 Sep 22 15:19 tty59
crw-------  1 root  tty       4,   6 Sep 22 15:19 tty6
crw-------  1 root  tty       4,  60 Sep 22 15:19 tty60
crw-------  1 root  tty       4,  61 Sep 22 15:19 tty61
crw-------  1 root  tty       4,  62 Sep 22 15:19 tty62
crw-------  1 root  tty       4,  63 Sep 22 15:19 tty63
crw-------  1 root  tty       4,   7 Sep 22 15:19 tty7
crw-------  1 root  tty       4,   8 Sep 22 15:19 tty8
crw-------  1 root  tty       4,   9 Sep 22 15:19 tty9
crw-rw----  1 root  dialout 204,  64 Sep 22 15:19 ttyAMA0
crw-rw----  1 root  dialout   4,  64 Sep 22 15:19 ttyS0
crw-rw----  1 root  dialout   4,  65 Sep 22 15:19 ttyS1
crw-rw----  1 root  dialout   4,  74 Sep 22 15:19 ttyS10
crw-rw----  1 root  dialout   4,  75 Sep 22 15:19 ttyS11
crw-rw----  1 root  dialout   4,  76 Sep 22 15:19 ttyS12
crw-rw----  1 root  dialout   4,  77 Sep 22 15:19 ttyS13
crw-rw----  1 root  dialout   4,  78 Sep 22 15:19 ttyS14
crw-rw----  1 root  dialout   4,  79 Sep 22 15:19 ttyS15
crw-rw----  1 root  dialout   4,  80 Sep 22 15:19 ttyS16
crw-rw----  1 root  dialout   4,  81 Sep 22 15:19 ttyS17
crw-rw----  1 root  dialout   4,  82 Sep 22 15:19 ttyS18
crw-rw----  1 root  dialout   4,  83 Sep 22 15:19 ttyS19
crw-rw----  1 root  dialout   4,  66 Sep 22 15:19 ttyS2
crw-rw----  1 root  dialout   4,  84 Sep 22 15:19 ttyS20
crw-rw----  1 root  dialout   4,  85 Sep 22 15:19 ttyS21
crw-rw----  1 root  dialout   4,  86 Sep 22 15:19 ttyS22
crw-rw----  1 root  dialout   4,  87 Sep 22 15:19 ttyS23
crw-rw----  1 root  dialout   4,  88 Sep 22 15:19 ttyS24
crw-rw----  1 root  dialout   4,  89 Sep 22 15:19 ttyS25
crw-rw----  1 root  dialout   4,  90 Sep 22 15:19 ttyS26
crw-rw----  1 root  dialout   4,  91 Sep 22 15:19 ttyS27
crw-rw----  1 root  dialout   4,  92 Sep 22 15:19 ttyS28
crw-rw----  1 root  dialout   4,  93 Sep 22 15:19 ttyS29
crw-rw----  1 root  dialout   4,  67 Sep 22 15:19 ttyS3
crw-rw----  1 root  dialout   4,  94 Sep 22 15:19 ttyS30
crw-rw----  1 root  dialout   4,  95 Sep 22 15:19 ttyS31
crw-rw----  1 root  dialout   4,  68 Sep 22 15:19 ttyS4
crw-rw----  1 root  dialout   4,  69 Sep 22 15:19 ttyS5
crw-rw----  1 root  dialout   4,  70 Sep 22 15:19 ttyS6
crw-rw----  1 root  dialout   4,  71 Sep 22 15:19 ttyS7
crw-rw----  1 root  dialout   4,  72 Sep 22 15:19 ttyS8
crw-rw----  1 root  dialout   4,  73 Sep 22 15:19 ttyS9
crw-------  1 root  root      5,   3 Sep 22 15:19 ttyprintk
crw-rw----+ 1 root  kvm      10, 259 Sep 22 15:19 udmabuf
crw-------  1 root  root     10, 239 Sep 22 15:19 uhid
crw-------  1 root  root     10, 223 Sep 22 15:19 uinput
crw-rw-rw-  1 root  root      1,   9 Sep 22 15:19 urandom
crw-------  1 root  root     10, 257 Sep 22 15:19 userfaultfd
crw-------  1 root  root     10, 240 Sep 22 15:19 userio
crw-rw----  1 root  tty       7,   0 Sep 22 15:19 vcs
crw-rw----  1 root  tty       7,   1 Sep 22 15:19 vcs1
crw-rw----  1 root  tty       7,   2 Sep 22 15:19 vcs2
crw-rw----  1 root  tty       7,   3 Sep 22 15:19 vcs3
crw-rw----  1 root  tty       7,   4 Sep 22 15:19 vcs4
crw-rw----  1 root  tty       7,   5 Sep 22 15:19 vcs5
crw-rw----  1 root  tty       7,   6 Sep 22 15:19 vcs6
crw-rw----  1 root  tty       7, 128 Sep 22 15:19 vcsa
crw-rw----  1 root  tty       7, 129 Sep 22 15:19 vcsa1
crw-rw----  1 root  tty       7, 130 Sep 22 15:19 vcsa2
crw-rw----  1 root  tty       7, 131 Sep 22 15:19 vcsa3
crw-rw----  1 root  tty       7, 132 Sep 22 15:19 vcsa4
crw-rw----  1 root  tty       7, 133 Sep 22 15:19 vcsa5
crw-rw----  1 root  tty       7, 134 Sep 22 15:19 vcsa6
crw-rw----  1 root  tty       7,  64 Sep 22 15:19 vcsu
crw-rw----  1 root  tty       7,  65 Sep 22 15:19 vcsu1
crw-rw----  1 root  tty       7,  66 Sep 22 15:19 vcsu2
crw-rw----  1 root  tty       7,  67 Sep 22 15:19 vcsu3
crw-rw----  1 root  tty       7,  68 Sep 22 15:19 vcsu4
crw-rw----  1 root  tty       7,  69 Sep 22 15:19 vcsu5
crw-rw----  1 root  tty       7,  70 Sep 22 15:19 vcsu6
crw-------  1 root  root     10, 256 Sep 22 15:19 vga_arbiter
crw-------  1 root  root     10, 137 Sep 22 15:19 vhci
crw-rw----  1 root  kvm      10, 238 Sep 22 15:19 vhost-net
crw-rw----  1 root  kvm      10, 241 Sep 22 15:19 vhost-vsock
crw-------  1 root  root    236,   1 Sep 22 15:19 vport3p1
crw-------  1 root  root    236,   2 Sep 22 15:19 vport3p2
crw-rw-rw-  1 root  root     10, 262 Sep 22 15:19 vsock
crw-rw-rw-  1 root  root      1,   5 Sep 22 15:19 zero
crw-------  1 root  root     10, 249 Sep 22 15:19 zfs
param@param-QEMU-Virtual-Machine:~/code/dir1/hol1/q14$ ls -ld /tmp
drwxrwxrwt 17 root root 380 Sep 22 16:58 /tmp
param@param-QEMU-Virtual-Machine:~/code/dir1/hol1/q14$ ls -l /run/systemd/notify
srwxrwxrwx 1 root root 0 Sep 22 15:19 /run/systemd/notify
param@param-QEMU-Virtual-Machine:~/code/dir1/hol1/q14$ ./filetype reg.txt 
regular file
param@param-QEMU-Virtual-Machine:~/code/dir1/hol1/q14$ ./filetype /tmp
directory
param@param-QEMU-Virtual-Machine:~/code/dir1/hol1/q14$ ./filetype symlink_to_reg 
symbolic link
param@param-QEMU-Virtual-Machine:~/code/dir1/hol1/q14$ ./filetype /dev/tty
character device
param@param-QEMU-Virtual-Machine:~/code/dir1/hol1/q14$ ./filetype /dev/vda
block device
param@param-QEMU-Virtual-Machine:~/code/dir1/hol1/q14$ ./filetype myfifo 
FIFO
param@param-QEMU-Virtual-Machine:~/code/dir1/hol1/q14$ ./filetype /run/systemd/notify
socket
param@param-QEMU-Virtual-Machine:~/code/dir1/hol1/q14$ ls -l reg.txt /tmp symlink_to_reg /dev/tty /dev/vda myfifo /run/systemd/notify 
crw-rw-rw- 1 root  tty     5, 0 Sep 22 15:19 /dev/tty
brw-rw---- 1 root  disk  253, 0 Sep 22 15:19 /dev/vda
srwxrwxrwx 1 root  root       0 Sep 22 15:19 /run/systemd/notify
prw-rw-r-- 1 param param      0 Sep 22 16:59 myfifo
-rw-rw-r-- 1 param param      6 Sep 22 16:59 reg.txt
lrwxrwxrwx 1 param param      7 Sep 22 16:59 symlink_to_reg -> reg.txt

/tmp:
total 0
drwx------ 5 root root 100 Sep 22 15:24 snap-private-tmp
drwx------ 3 root root  60 Sep 22 15:19 systemd-private-64078063967a46b09ad73fa790de5943-ModemManager.service-mFurgV
drwx------ 3 root root  60 Sep 22 15:19 systemd-private-64078063967a46b09ad73fa790de5943-chrony.service-Dz2UED
drwx------ 3 root root  60 Sep 22 15:19 systemd-private-64078063967a46b09ad73fa790de5943-colord.service-T2nKz1
drwx------ 3 root root  60 Sep 22 15:45 systemd-private-64078063967a46b09ad73fa790de5943-fwupd.service-Oqz5OD
drwx------ 3 root root  60 Sep 22 15:19 systemd-private-64078063967a46b09ad73fa790de5943-polkit.service-ACrMA2
drwx------ 3 root root  60 Sep 22 15:19 systemd-private-64078063967a46b09ad73fa790de5943-power-profiles-daemon.service-pHl0OK
drwx------ 3 root root  60 Sep 22 15:19 systemd-private-64078063967a46b09ad73fa790de5943-spice-vdagentd.service-Zzvy8K
drwx------ 3 root root  60 Sep 22 15:19 systemd-private-64078063967a46b09ad73fa790de5943-switcheroo-control.service-J6mo7L
drwx------ 3 root root  60 Sep 22 15:19 systemd-private-64078063967a46b09ad73fa790de5943-systemd-logind.service-XuKB9l
drwx------ 3 root root  60 Sep 22 15:19 systemd-private-64078063967a46b09ad73fa790de5943-upower.service-WnfXwo
param@param-QEMU-Virtual-Machine:~/code/dir1/hol1/q14$ file reg.txt /tmp symlink_to_reg /dev/tty /dev/vda myfifo /run/systemd/notify 
reg.txt:             ASCII text
/tmp:                sticky, directory
symlink_to_reg:      symbolic link to reg.txt
/dev/tty:            character special (5/0)
/dev/vda:            block special (253/0)
myfifo:              fifo (named pipe)
/run/systemd/notify: socket
param@param-QEMU-Virtual-Machine:~/code/dir1/hol1/q14$ vim filetype.c
param@param-QEMU-Virtual-Machine:~/code/dir1/hol1/q14$ gcc -Wall -o filetype filetype.c
param@param-QEMU-Virtual-Machine:~/code/dir1/hol1/q14$ ./filetype symlink_to_reg 
symbolic link
stat says: NOT a symbolic link (it followed the link)

*/

#include <stdio.h>
#include <sys/stat.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "usage: %s <path>\n", argv[0]);
        return 1;
    }

    struct stat sb;
    if (lstat(argv[1], &sb) == -1) {
        perror("lstat");
        return 1;
    }

    if      (S_ISREG (sb.st_mode)) puts("regular file");
    else if (S_ISDIR (sb.st_mode)) puts("directory");
    else if (S_ISLNK (sb.st_mode)) puts("symbolic link");
    else if (S_ISCHR (sb.st_mode)) puts("character device");
    else if (S_ISBLK (sb.st_mode)) puts("block device");
    else if (S_ISFIFO(sb.st_mode)) puts("FIFO");
    else if (S_ISSOCK(sb.st_mode)) puts("socket");
    else                            puts("unknown type");

    return 0;
}