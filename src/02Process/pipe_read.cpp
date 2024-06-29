#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <errno.h>
#include <fcntl.h>

int main(int argc, char *argv[])
{
    int fd;
    char *pipe_path = (char *)"myfifo";
    fd = open(pipe_path, O_RDONLY);
    if (fd == -1)
    {
        perror("open");
        exit(EXIT_FAILURE);
    }
    char buf[100];
    ssize_t read_num;
    // 读取管道信息写入控制台
    while ((read_num = read(fd, buf, 100)) > 0)
    {
        write(STDIN_FILENO, buf, read_num);
    }
    if (read_num < 0)
    {
        perror("read");
        close(fd);
        exit(EXIT_FAILURE);
    }
    printf("received data from pipe over\n");
    close(fd);
    return 0;
}