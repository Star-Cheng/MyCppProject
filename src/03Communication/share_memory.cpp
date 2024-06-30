#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/wait.h>
#include <string.h>

int main(int argc, char *argv[])
{
    // 1. 创建共享内存对象
    // char *shm_name = (char *)"letter";
    char shm_name[100] = {0};
    sprintf(shm_name, "/letter%d", getpid());
    int fd;
    fd = shm_open(shm_name, O_RDWR | O_CREAT, 0644);
    if (fd < 0)
    {
        perror("shm_open");
        exit(EXIT_FAILURE);
    }
    // 2. 设置共享内存大小
    ftruncate(fd, 1024);
    // 3. 内存映射
    char *share = (char *)mmap(NULL, 1024, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    if (share)
    {
        perror("mmap");
        exit(EXIT_FAILURE);
    }
    // 映射完成之后, 关闭fd连接, 不是释放
    close(fd);

    // 4. 使用内存映射实现进程间的通讯
    pid_t pid = fork();
    if (pid < 0)
    {
        perror("fork");
        exit(EXIT_FAILURE);
    }
    if (pid == 0)
    {
        // 子进程
        strcpy(share, "you are a good people\n");
        printf("new student %d complete reply\n", getpid());
    }
    else
    {
        // 父进程
        // sleep(1);
        waitpid(pid, NULL, 0);
        printf("old student %d received new student %d reply: %s\n", getpid(), pid, share);
    }
    // 释放映射区
    int re = munmap(share, 1024);
    if (re < 0)
    {
        perror("munmap");
        exit(EXIT_FAILURE);
    }

    // 6. 释放共享内粗对象
    shm_unlink(shm_name);
    return 0;
}