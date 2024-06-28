#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        printf("Few parameters\n");
        exit(1);
    }
    printf("I am %s, PID = %d, parent PID = %d\n", argv[1], getpid(), getppid());
    // 挂起进程
    // sleep(10); // 如果父进程提前结束,而子进程没有结束,则子进程会变成孤儿进程, 会被祖先自动领
    return 0;
}
