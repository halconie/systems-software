/* 
param@param-QEMU-Virtual-Machine:~/code/dir1/hol1/q6$ vim copy.c
param@param-QEMU-Virtual-Machine:~/code/dir1/hol1/q6$ gcc -Wall copy.c 
param@param-QEMU-Virtual-Machine:~/code/dir1/hol1/q6$ ./a.out 
This is the test line to check the output.
This is the test line to check the output.
As you can see whatever is being typed here is then reflected back onto the stdout.
As you can see whatever is being typed here is then reflected back onto the stdout.
The terminal signals end of input, read returns 0, and the loop exits. If you press Ctrl-D in the middle of a line, read returns what you've typed so far without ending, so press it twice.
The terminal signals end of input, read returns 0, and the loop exits. If you press Ctrl-D in the middle of a line, read returns what you've typed so far without ending, so press it twice.
param@param-QEMU-Virtual-Machine:~/code/dir1/hol1/q6$ seq 1 100 > in.txt
param@param-QEMU-Virtual-Machine:~/code/dir1/hol1/q6$ ./a.out < in.txt > out.txt
param@param-QEMU-Virtual-Machine:~/code/dir1/hol1/q6$ cat in.txt 
1
2
3
4
5
6
7
8
9
10
11
12
13
14
15
16
17
18
19
20
21
22
23
24
25
26
27
28
29
30
31
32
33
34
35
36
37
38
39
40
41
42
43
44
45
46
47
48
49
50
51
52
53
54
55
56
57
58
59
60
61
62
63
64
65
66
67
68
69
70
71
72
73
74
75
76
77
78
79
80
81
82
83
84
85
86
87
88
89
90
91
92
93
94
95
96
97
98
99
100
param@param-QEMU-Virtual-Machine:~/code/dir1/hol1/q6$ cat out.txt 
1
2
3
4
5
6
7
8
9
10
11
12
13
14
15
16
17
18
19
20
21
22
23
24
25
26
27
28
29
30
31
32
33
34
35
36
37
38
39
40
41
42
43
44
45
46
47
48
49
50
51
52
53
54
55
56
57
58
59
60
61
62
63
64
65
66
67
68
69
70
71
72
73
74
75
76
77
78
79
80
81
82
83
84
85
86
87
88
89
90
91
92
93
94
95
96
97
98
99
100
param@param-QEMU-Virtual-Machine:~/code/dir1/hol1/q6$ diff in.txt out.txt 
param@param-QEMU-Virtual-Machine:~/code/dir1/hol1/q6$ wc -c in.txt out.txt 
292 in.txt
292 out.txt
584 total
param@param-QEMU-Virtual-Machine:~/code/dir1/hol1/q6$ ls | ./a.out 
a.out
copy.c
in.txt
out.txt
param@param-QEMU-Virtual-Machine:~/code/dir1/hol1/q6$ ls
a.out  copy.c  in.txt  out.txt

*/

#include <unistd.h>

int main(void) {
    char buf[100];
    ssize_t n;

    while ((n = read(0, buf, sizeof buf)) > 0) {
        write(1, buf, n);
    }

    if (n == -1) {
        write(2, "read error\n", 11);
        return 1;
    }
    return 0;
}