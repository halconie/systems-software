/* 
param@param-QEMU-Virtual-Machine:~/code/dir1/hol1/q3$ vim creat_demo.c

param@param-QEMU-Virtual-Machine:~/code/dir1/hol1/q3$ gcc -Wall -o creat_demo creat_demo.c 
param@param-QEMU-Virtual-Machine:~/code/dir1/hol1/q3$ ./creat_demo
fd = 3
read() returned -1, errno = 9 (Bad file descriptor)
errno is EBADF: descriptor not open for reading
param@param-QEMU-Virtual-Machine:~/code/dir1/hol1/q3$ ls -l newfile.txt 
-rw-r--r-- 1 param param 0 Sep 20 22:44 newfile.txt
param@param-QEMU-Virtual-Machine:~/code/dir1/hol1/q3$ strace ./creat_demo 
// execve("./creat_demo", ["./creat_demo"], 0xffffd7380aa0 \* 55 vars */ //) = 0
// brk(NULL)                               = 0xca896a5f5000
// mmap(NULL, 8192, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_ANONYMOUS, -1, 0) = 0xea70227ab000
// faccessat(AT_FDCWD, "/etc/ld.so.preload", R_OK) = -1 ENOENT (No such file or directory)
// openat(AT_FDCWD, "/etc/ld.so.cache", O_RDONLY|O_CLOEXEC) = 3
// fstat(3, {st_mode=S_IFREG|0644, st_size=63223, ...}) = 0
// mmap(NULL, 63223, PROT_READ, MAP_PRIVATE, 3, 0) = 0xea7022765000
// close(3)                                = 0
// openat(AT_FDCWD, "/usr/lib/aarch64-linux-gnu/libc.so.6", O_RDONLY|O_CLOEXEC) = 3
// read(3, "\177ELF\2\1\1\3\0\0\0\0\0\0\0\0\3\0\267\0\1\0\0\0\3101\2\0\0\0\0\0"..., 832) = 832
// fstat(3, {st_mode=S_IFREG|0755, st_size=1788240, ...}) = 0
// mmap(NULL, 1957440, PROT_NONE, MAP_PRIVATE|MAP_ANONYMOUS|MAP_DENYWRITE, -1, 0) = 0xea7022587000
// mmap(0xea7022590000, 1891904, PROT_READ|PROT_EXEC, MAP_PRIVATE|MAP_FIXED|MAP_DENYWRITE, 3, 0) = 0xea7022590000
// munmap(0xea7022587000, 36864)           = 0
// munmap(0xea702275e000, 28224)           = 0
// mprotect(0xea7022739000, 81920, PROT_NONE) = 0
// mmap(0xea702274d000, 20480, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_FIXED|MAP_DENYWRITE, 3, 0x1ad000) = 0xea702274d000
// mmap(0xea7022752000, 48704, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_FIXED|MAP_ANONYMOUS, -1, 0) = 0xea7022752000
// mmap(0xea7022590000, 1740800, PROT_READ|PROT_EXEC|0x10, MAP_PRIVATE|MAP_FIXED|MAP_DENYWRITE, 3, 0) = 0xea7022590000
// close(3)                                = 0
// set_tid_address(0xea70227ac388)         = 7915
// set_robust_list(0xea70227ac040, 24)     = 0
// rseq(0xea70227ac740, 0x21, 0, 0xd428bc00) = 0
// mprotect(0xea702274d000, 12288, PROT_READ) = 0
// mprotect(0xca8934b9f000, 4096, PROT_READ) = 0
// mmap(NULL, 8192, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_ANONYMOUS, -1, 0) = 0xea70227a9000
// mprotect(0xea70227b3000, 8192, PROT_READ) = 0
// prlimit64(0, RLIMIT_STACK, NULL, {rlim_cur=8192*1024, rlim_max=RLIM64_INFINITY}) = 0
// getrandom("\x0b\xbf\xc5\xa2\x4b\xad\xd1\x0a", 8, GRND_NONBLOCK) = 8
// munmap(0xea7022765000, 63223)           = 0
// openat(AT_FDCWD, "newfile.txt", O_WRONLY|O_CREAT|O_TRUNC, 0644) = 3
// fstat(1, {st_mode=S_IFCHR|0600, st_rdev=makedev(0x88, 0), ...}) = 0
// brk(NULL)                               = 0xca896a5f5000
// brk(0xca896a800000)                     = 0xca896a800000
// madvise(0xca896a5f5000, 2142208, MADV_HUGEPAGE) = 0
// write(1, "fd = 3\n", 7fd = 3
// )                 = 7
// read(3, 0xffffe8fa1ae8, 10)             = -1 EBADF (Bad file descriptor)
// write(1, "read() returned -1, errno = 9 (B"..., 52read() returned -1, errno = 9 (Bad file descriptor)
// ) = 52
// write(1, "errno is EBADF: descriptor not o"..., 48errno is EBADF: descriptor not open for reading
// ) = 48
// close(3)                                = 0
// exit_group(0)                           = ?
// +++ exited with 0 +++


#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>

int main(void) {
    int fd = creat("newfile.txt", 0644);
    if (fd == -1) {
        perror("creat");
        return 1;
    }
    printf("fd = %d\n", fd);

    char buf[10];
    ssize_t n = read(fd, buf, sizeof(buf));
    int err = errno;
    if (n == -1) {
        printf("read() returned -1, errno = %d (%s)\n", err, strerror(err));
        if (err == EBADF)
            printf("errno is EBADF: descriptor not open for reading\n");
    }

    close(fd);
    return 0;
}