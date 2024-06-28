#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    // 跳转之前
    char name[100] = "ming";
    printf("I am %s, PID = %d, parent PID = %d\n", name, getpid(), getppid());
    // 执行跳转
    /* int execve (const char *__path, char *const __argv[],char *const __envp[]) __THROW __nonnull ((1, 2));
    ** const char *__path: 执行程序的路径
    ** char *const __argv[]: 传入的参数 -> 对应执行程序main方法的第二个参数
                            1. argv[0] -> 程序名, 第一个参数
                            2. argv[1] -> 命令行参数, 第二个参数
                            3. 最后一个参数一定是NULL
    ** char *const __envp[]: 环境变量
                            1. 环境变量参数: key=value
                            2. 最后一个参数一定是NULL
    ** return: 成功根本没办法返回, 失败返回-1
    */
    // 执行跳转
    char *args[] = {(char *)"/home/gym/code/CppProject/build/MyCppProject/erlou", (char *)"ming", NULL};
    // char *const envs[] = {NULL};
    char *envs[] = {NULL};
    int result = execve(args[0], (char *const *)args, envs);
    if (result == -1)
    {
        perror("execve");
        exit(1);
    }
    return 0;
}
