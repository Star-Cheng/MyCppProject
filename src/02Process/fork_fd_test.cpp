#include <sys/stat.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    // fork之前
    int fd = open("../../data/fork_fd.txt", O_RDONLY | O_WRONLY | O_CREAT, 0644);
    if (fd == -1)
    {
        perror("open");
        exit(EXIT_FAILURE);
    }
    pid_t pid = fork();
    char buf[1024]; // 缓冲区存放写入的数据
    if (pid < 0)
    {
        perror("fork");
        exit(EXIT_FAILURE);
    }
    else if (pid == 0)
    {
        // 子进程
        // sleep(1);
        strcpy(buf, "child process data\n");
    }
    else
    {
        // 父进程
        sleep(1);
        strcpy(buf, "parent process data\n");
    }
    // 父子进程都要执行的代码
    ssize_t bytes_write = write(fd, buf, strlen(buf));
    if (bytes_write == -1)
    {
        perror("write");
        close(fd);
        exit(EXIT_FAILURE);
    }
    // 使用完毕之后关闭
    printf("write data succed\n");
    close(fd);
    if (pid == 0)
    {
        printf("child process writed and delete memory\n");
    }
    else
    {
        printf("parent process writed and delete memory\n");
    }

    return 0;
}