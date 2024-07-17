#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define BUF_LEN 1024

char *buf;
// 读线程需要执行的代码逻辑
void *input_thread(void *arg)
{
    int i = 0;
    while (1)
    {
        // printf("请输入内容：");
        // fgets(buf, BUF_LEN, stdin);
        // printf("输入的内容是：%s\n", buf);
        char c = fgetc(stdin);
        if (c && c != '\n')
        {
            buf[i++] = c;
        }
        if (i >= BUF_LEN)
        {
            i = 0;
        }
    }
}
void *output_thread(void *arg)
{
    int i = 0;
    while (1)
    {
        // printf("请输入内容：");
        // fgets(buf, BUF_LEN, stdin);
        // printf("输入的内容是：%s\n", buf);
        if (buf[i])
        {
            fputc(buf[i], stdout);
            fputc('\n', stdout);
            buf[i++] = 0;
            // 读取数据道路最大下表
            if (i >= BUF_LEN)
            {
                i = 0;
            }
        }
        else
        {
            // 如果当前还没有写入数据
            sleep(1);
        }
    }
}
int main(int argc, char *argv[])
{
    // 分配缓冲区
    buf = (char *)malloc(BUF_LEN * sizeof(char));
    // 创建线程
    pthread_t pid_input;
    pthread_t pid_output;
    // 创建读线程
    pthread_create(&pid_input, NULL, input_thread, NULL);
    // 创建写线程
    pthread_create(&pid_output, NULL, output_thread, NULL);
    // 主线程等待读写线程结束
    pthread_join(pid_input, NULL);
    pthread_join(pid_output, NULL);
    free(buf);
    return 0;
}