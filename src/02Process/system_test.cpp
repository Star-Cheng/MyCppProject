#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    // 使用标准库函数创建子进程
    /* int system (const char *__command) __wur;
    ** const char *__command: 使用Linux命令直接创建一个子进程
    ** return: 0: 成功
    */
    int sysR = system("ping -c 10 www.atguigu.com");
    if (sysR != 0)
    {
        perror("system");
        exit(EXIT_FAILURE);
    }
    return 0;
}