#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

void sigint_handler(int signum)
{
    printf("received %d signal, stop process\n", signum);
    exit(signum);
}
int main(int argc, char *argv[])
{
    if (signal(SIGINT, sigint_handler) == SIG_ERR)
    {
        printf("can't catch SIGINT\n");
        return 1;
    }
    while (1)
    {
        sleep(1);
        printf("sleep 1 second\n");
    }
    return 0;
}