#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <errno.h>
#include <fstream>
#include <fcntl.h>

int main(int argc, char *argv[])
{
    int fd;
    char *pipe_path = (char *)"myfifo";
    if (mkfifo(pipe_path, 0664) != 0)
    {
        perror("mkfifo");
        exit(EXIT_FAILURE);
    }
    // 对又名管道的特殊文件创建fd
    fd = open(pipe_path, O_WRONLY);
    if (fd = -1)
    {
        perror("open");
        exit(EXIT_FAILURE);
    }
    char buf[100];
    ssize_t read_num;
    // 读取控制台数据写入管道当中
    while ((read_num = read(STDIN_FILENO, buf, 100)) > 0)
    {
        write(fd, buf, read_num);
    }
    if (read_num < 0)
    {
        perror("read");
        close(fd);
        exit(EXIT_FAILURE);
    }
    printf("sent data to pipe over\n");
    return 0;
}