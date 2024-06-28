#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(int argc, char const *argv[])
{
    // 邀请之前
    char name[100] = "old student";
    int subporcess_status;
    printf("%s %d is leaning on the first floor\n", name, getpid());
    // 邀请之后
    pid_t pid = fork();
    if (pid == -1)
    {
        perror("invate error");
        exit(1);
    }
    else if (pid == 0)
    {
        // Son
        char new_name[100] = "new student";
        char *args[] = {(char *)"/home/gym/code/CppProject/build/MyCppProject/erlou", new_name, NULL};
        char *envs[] = {NULL};
        int exR = execve(args[0], args, envs);
        if (exR == -1)
        {
            perror("execve error");
            exit(1);
        }
        // char *args2[] = {(char *)"/usr/bin/ping", (char *)"-c", (char *)"10", (char *)"www.atguigu.com", NULL};
        // char *envs2[] = {NULL};
        // execve(args2[0], args2, envs2);
    }
    else
    {
        // Parent
        // sleep(1); // 等待子进程执行完成, 但是不稳定
        waitpid(pid, &subporcess_status, 0); // 等待子进程执行完成
        printf("old student %d invate %d and learning on the first floor\n", getpid(), pid);
    }
    printf("old student wait new student succeed\n");
    pid_t pid2 = fork();
    if (pid2 == -1)
    {
        perror("invate error");
        exit(1);
    }
    else if (pid2 == 0)
    {
        // Son2
        char *args2[] = {(char *)"/usr/bin/ping", (char *)"-c", (char *)"3", (char *)"www.atguigu.com", NULL};
        char *envs2[] = {NULL};
        execve(args2[0], args2, envs2);
    }
    else
    {
        // Parent
        // sleep(1); // 等待子进程执行完成, 但是不稳定
        waitpid(pid2, NULL, 0); // 使用waitpid等待子进程执行完成
        printf("parent PID = %d, son2 PID = %d\n", getpid(), pid2);
        printf("parent wait son2 succeed\n");
        // 永久挂起, 等待输入任意一个字符停止
        printf("plead enter any string to end: ");
        // fgetc(stdin); // 可以使用pstree -p 查看进程
    }
    return 0;
}
