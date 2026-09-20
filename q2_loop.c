/* 
param@param-QEMU-Virtual-Machine:~/code/dir1/hol1$ mkdir q2
param@param-QEMU-Virtual-Machine:~/code/dir1/hol1$ ls
q1a  q1b  q2
param@param-QEMU-Virtual-Machine:~/code/dir1/hol1$ cd q2
param@param-QEMU-Virtual-Machine:~/code/dir1/hol1/q2$ vim loop.c
param@param-QEMU-Virtual-Machine:~/code/dir1/hol1/q2$ gcc -Wall -o loop loop.c

param@param-QEMU-Virtual-Machine:~/code/dir1/hol1/q2$ jobs
param@param-QEMU-Virtual-Machine:~/code/dir1/hol1/q2$ ./loop &
[1] 6209
param@param-QEMU-Virtual-Machine:~/code/dir1/hol1/q2$ PID=$!
param@param-QEMU-Virtual-Machine:~/code/dir1/hol1/q2$ echo $PID
6209
param@param-QEMU-Virtual-Machine:~/code/dir1/hol1/q2$ jobs
[1]+  Running                    ./loop &


param@param-QEMU-Virtual-Machine:~/code/dir1/hol1/q2$ ls /proc/$PID/
attr        cmdline          exe      ksm_merging_pages  map_files  mountstats  oom_score      projid_map  setgroups     statm           timers
autogroup   comm             fd       ksm_stat           maps       net         oom_score_adj  root        smaps         status          timerslack_ns
auxv        coredump_filter  fdinfo   latency            mem        ns          pagemap        sched       smaps_rollup  syscall         uid_map
cgroup      cwd              gid_map  limits             mountinfo  numa_maps   patch_state    schedstat   stack         task            wchan
clear_refs  environ          io       loginuid           mounts     oom_adj     personality    sessionid   stat          timens_offsets
param@param-QEMU-Virtual-Machine:~/code/dir1/hol1/q2$ grep -E '^(Name|State|Pid|PPid|Uid|Gid|VmSize|Threads)' /proc/$PID/status
Name:	loop
State:	S (sleeping)
Pid:	6209
PPid:	3357
Uid:	1000	1000	1000	1000
Gid:	1000	1000	1000	1000
VmSize:	    2216 kB
Threads:	1


param@param-QEMU-Virtual-Machine:~/code/dir1/hol1/q2$ echo $$
3357
param@param-QEMU-Virtual-Machine:~/code/dir1/hol1/q2$ tr '\0' ' ' < /proc/$PID/cmdline; echo
./loop 
param@param-QEMU-Virtual-Machine:~/code/dir1/hol1/q2$ ls -l /proc/$PID/fd
total 0
lrwx------ 1 param param 64 Sep 20 17:25 0 -> /dev/pts/0
lrwx------ 1 param param 64 Sep 20 17:25 1 -> /dev/pts/0
lrwx------ 1 param param 64 Sep 20 17:25 2 -> /dev/pts/0
param@param-QEMU-Virtual-Machine:~/code/dir1/hol1/q2$ ls -l /proc/$PID/exe
lrwxrwxrwx 1 param param 0 Sep 20 16:23 /proc/6209/exe -> /home/param/code/dir1/hol1/q2/loop
param@param-QEMU-Virtual-Machine:~/code/dir1/hol1/q2$ ls -l /proc/$PID/cwd
lrwxrwxrwx 1 param param 0 Sep 20 16:23 /proc/6209/cwd -> /home/param/code/dir1/hol1/q2
param@param-QEMU-Virtual-Machine:~/code/dir1/hol1/q2$ cat /proc/$PID/maps
c15bcda00000-c15bcda01000 r-xp 00000000 fd:02 656925                     /home/param/code/dir1/hol1/q2/loop
c15bcda1f000-c15bcda20000 r--p 0000f000 fd:02 656925                     /home/param/code/dir1/hol1/q2/loop
c15bcda20000-c15bcda21000 rw-p 00010000 fd:02 656925                     /home/param/code/dir1/hol1/q2/loop
e6d085510000-e6d0856b9000 r-xp 00000000 fd:02 2230048                    /usr/lib/aarch64-linux-gnu/libc.so.6
e6d0856b9000-e6d0856cd000 ---p 001a9000 fd:02 2230048                    /usr/lib/aarch64-linux-gnu/libc.so.6
e6d0856cd000-e6d0856d0000 r--p 001ad000 fd:02 2230048                    /usr/lib/aarch64-linux-gnu/libc.so.6
e6d0856d0000-e6d0856d2000 rw-p 001b0000 fd:02 2230048                    /usr/lib/aarch64-linux-gnu/libc.so.6
e6d0856d2000-e6d0856de000 rw-p 00000000 00:00 0 
e6d0856fa000-e6d085724000 r-xp 00000000 fd:02 2230045                    /usr/lib/aarch64-linux-gnu/ld-linux-aarch64.so.1
e6d08572e000-e6d085732000 rw-p 00000000 00:00 0 
e6d085732000-e6d085736000 r--p 00000000 00:00 0                          [vvar]
e6d085736000-e6d085738000 r-xp 00000000 00:00 0                          [vdso]
e6d085738000-e6d08573a000 r--p 0002e000 fd:02 2230045                    /usr/lib/aarch64-linux-gnu/ld-linux-aarch64.so.1
e6d08573a000-e6d08573b000 rw-p 00030000 fd:02 2230045                    /usr/lib/aarch64-linux-gnu/ld-linux-aarch64.so.1
e6d08573b000-e6d08573c000 rw-p 00000000 00:00 0 
ffffeb0c6000-ffffeb0e7000 rw-p 00000000 00:00 0                          [stack]


param@param-QEMU-Virtual-Machine:~/code/dir1/hol1/q2$ tr '\0' '\n' < /proc/$PID/environ
SHELL=/bin/bash
QT_ACCESSIBILITY=1
COLORTERM=truecolor
XDG_CONFIG_DIRS=/etc/xdg/xdg-ubuntu:/etc/xdg
XDG_MENU_PREFIX=gnome-
GNOME_DESKTOP_SESSION_ID=this-is-deprecated
QT_IM_MODULES=wayland;ibus
PTYXIS_PROFILE=61e0288cc91660e64e66631f6aa5a54a
SSH_AUTH_SOCK=/run/user/1000/gcr/ssh
HISTTIMEFORMAT=%d/%m/%y %T
MEMORY_PRESSURE_WRITE=c29tZSAyMDAwMDAgMjAwMDAwMAA=
XMODIFIERS=@im=ibus
DESKTOP_SESSION=ubuntu
GTK_MODULES=gail:atk-bridge
DBUS_STARTER_BUS_TYPE=session
PWD=/home/param/code/dir1/hol1/q2
XDG_SESSION_DESKTOP=ubuntu
LOGNAME=param
XDG_SESSION_TYPE=wayland
GPG_AGENT_INFO=/run/user/1000/gnupg/S.gpg-agent:0:1
SYSTEMD_EXEC_PID=2056
XAUTHORITY=/run/user/1000/.mutter-Xwaylandauth.LRGQV3
HOME=/home/param
USERNAME=param
LANG=en_US.UTF-8
LS_COLORS=rs=0:di=01;34:ln=01;36:mh=00:pi=40;33:so=01;35:do=01;35:bd=40;33;01:cd=40;33;01:or=40;31;01:mi=00:su=37;41:sg=30;43:ca=00:tw=30;42:ow=34;42:st=37;44:ex=01;32:*.tar=01;31:*.tgz=01;31:*.arc=01;31:*.arj=01;31:*.taz=01;31:*.lha=01;31:*.lz4=01;31:*.lzh=01;31:*.lzma=01;31:*.tlz=01;31:*.txz=01;31:*.tzo=01;31:*.t7z=01;31:*.zip=01;31:*.z=01;31:*.dz=01;31:*.gz=01;31:*.lrz=01;31:*.lz=01;31:*.lzo=01;31:*.xz=01;31:*.zst=01;31:*.tzst=01;31:*.bz2=01;31:*.bz=01;31:*.tbz=01;31:*.tbz2=01;31:*.tz=01;31:*.deb=01;31:*.rpm=01;31:*.jar=01;31:*.war=01;31:*.ear=01;31:*.sar=01;31:*.rar=01;31:*.alz=01;31:*.ace=01;31:*.zoo=01;31:*.cpio=01;31:*.7z=01;31:*.rz=01;31:*.cab=01;31:*.wim=01;31:*.swm=01;31:*.dwm=01;31:*.esd=01;31:*.avif=01;35:*.jpg=01;35:*.jpeg=01;35:*.mjpg=01;35:*.mjpeg=01;35:*.gif=01;35:*.bmp=01;35:*.pbm=01;35:*.pgm=01;35:*.ppm=01;35:*.tga=01;35:*.xbm=01;35:*.xpm=01;35:*.tif=01;35:*.tiff=01;35:*.png=01;35:*.svg=01;35:*.svgz=01;35:*.mng=01;35:*.pcx=01;35:*.mov=01;35:*.mpg=01;35:*.mpeg=01;35:*.m2v=01;35:*.mkv=01;35:*.webm=01;35:*.webp=01;35:*.ogm=01;35:*.mp4=01;35:*.m4v=01;35:*.mp4v=01;35:*.vob=01;35:*.qt=01;35:*.nuv=01;35:*.wmv=01;35:*.asf=01;35:*.rm=01;35:*.rmvb=01;35:*.flc=01;35:*.avi=01;35:*.fli=01;35:*.flv=01;35:*.gl=01;35:*.dl=01;35:*.xcf=01;35:*.xwd=01;35:*.yuv=01;35:*.cgm=01;35:*.emf=01;35:*.ogv=01;35:*.ogx=01;35:*.aac=00;36:*.au=00;36:*.flac=00;36:*.m4a=00;36:*.mid=00;36:*.midi=00;36:*.mka=00;36:*.mp3=00;36:*.mpc=00;36:*.ogg=00;36:*.ra=00;36:*.wav=00;36:*.oga=00;36:*.opus=00;36:*.spx=00;36:*.xspf=00;36:*~=00;90:*#=00;90:*.bak=00;90:*.old=00;90:*.orig=00;90:*.part=00;90:*.rej=00;90:*.swp=00;90:*.tmp=00;90:*.dpkg-dist=00;90:*.dpkg-old=00;90:*.ucf-dist=00;90:*.ucf-new=00;90:*.ucf-old=00;90:*.rpmnew=00;90:*.rpmorig=00;90:*.rpmsave=00;90:
XDG_CURRENT_DESKTOP=ubuntu:GNOME
MEMORY_PRESSURE_WATCH=/sys/fs/cgroup/user.slice/user-1000.slice/user@1000.service/session.slice/dbus.service/memory.pressure
VTE_VERSION=8400
WAYLAND_DISPLAY=wayland-0
INVOCATION_ID=bc769e9092864f7990adf8d1b93669f9
MANAGERPID=2027
GNOME_SETUP_DISPLAY=unix:/tmp/.X11-unix/X1
LESSCLOSE=/usr/bin/lesspipe %s %s
XDG_SESSION_CLASS=user
TERM=xterm-256color
LESSOPEN=| /usr/bin/lesspipe %s
USER=param
DISPLAY=:0
SHLVL=0
QT_IM_MODULE=ibus
DBUS_STARTER_ADDRESS=unix:path=/run/user/1000/bus,guid=c0289fdbce806fad69daef356aaf8aef
MANAGERPIDFDID=1042
XDG_RUNTIME_DIR=/run/user/1000
DEBUGINFOD_URLS=https://debuginfod.ubuntu.com 
IM_CONFIG_ENTRY=profile
XDG_DATA_DIRS=/usr/share/ubuntu:/usr/share/gnome:/usr/local/share/:/usr/share/:/var/lib/snapd/desktop
PATH=/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/usr/games:/usr/local/games:/snap/bin:/snap/bin
GDMSESSION=ubuntu
XDG_SESSION_EXTRA_DEVICE_ACCESS=render:accel
DBUS_SESSION_BUS_ADDRESS=unix:path=/run/user/1000/bus,guid=c0289fdbce806fad69daef356aaf8aef
PTYXIS_VERSION=50.1
FLATPAK_TTY_PROGRESS=1
OLDPWD=/home/param/code/dir1/hol1
_=./loop
param@param-QEMU-Virtual-Machine:~/code/dir1/hol1/q2$ cat /proc/$PID/stat
6209 (loop) S 3357 6209 3357 34816 6645 4194304 344 0 0 0 14 18 0 0 20 0 1 0 1167765 2269184 217 18446744073709551615 212600035999744 212600036002020 281474625329552 0 0 0 0 0 0 1 0 0 17 1 0 0 0 0 0 212600036130192 212600036130832 212600882532352 281474625331644 281474625331651 281474625331651 281474625335281 0
param@param-QEMU-Virtual-Machine:~/code/dir1/hol1/q2$ cat /proc/$PID/limits
Limit                     Soft Limit           Hard Limit           Units     
Max cpu time              unlimited            unlimited            seconds   
Max file size             unlimited            unlimited            bytes     
Max data size             unlimited            unlimited            bytes     
Max stack size            8388608              unlimited            bytes     
Max core file size        0                    unlimited            bytes     
Max resident set          unlimited            unlimited            bytes     
Max processes             22419                22419                processes 
Max open files            1024                 524288               files     
Max locked memory         8388608              8388608              bytes     
Max address space         unlimited            unlimited            bytes     
Max file locks            unlimited            unlimited            locks     
Max pending signals       22419                22419                signals   
Max msgqueue size         819200               819200               bytes     
Max nice priority         0                    0                    
Max realtime priority     0                    0                    
Max realtime timeout      unlimited            unlimited            us        
param@param-QEMU-Virtual-Machine:~/code/dir1/hol1/q2$ ls -l /proc/$PID/status
-r--r--r-- 1 param param 0 Sep 20 16:23 /proc/6209/status
param@param-QEMU-Virtual-Machine:~/code/dir1/hol1/q2$ wc -c < /proc/$PID/status
1183
param@param-QEMU-Virtual-Machine:~/code/dir1/hol1/q2$ df /proc
Filesystem     1K-blocks  Used Available Use% Mounted on
proc                   0     0         0    - /proc
param@param-QEMU-Virtual-Machine:~/code/dir1/hol1/q2$ ps -o pid,stat,cmd -p $PID
    PID STAT CMD
   6209 S    ./loop
param@param-QEMU-Virtual-Machine:~/code/dir1/hol1/q2$ kill $PID
[1]+  Terminated                 ./loop
param@param-QEMU-Virtual-Machine:~/code/dir1/hol1/q2$ ls proc/$PID
ls: cannot access 'proc/6209': No such file or directory

*/

#include <unistd.h>

int main(void) {
    while (1) {
        sleep(1);
    }
    return 0;
}