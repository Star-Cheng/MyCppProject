#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/wait.h>
#include <string.h>
#include <mqueue.h>
#include <time.h>
#include <sys/stat.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    // 创建消息队列
    struct mq_attr attr;
    // 有用的参数表示消息队列的容量
    attr.mq_flags = 0;
    attr.mq_maxmsg = 10;
    // 被忽略的消息在创建消息队列时候用不到
    attr.mq_msgsize = 100;
    attr.mq_curmsgs = 0;
    char *mq_name = (char *)"/father_son_mq";
    mqd_t mqdes = mq_open(mq_name, O_CREAT | O_RDWR, 0664, &attr);
    if (mqdes == (mqd_t)-1)
    {
        perror("mq_open");
        exit(EXIT_FAILURE);
    }
    // 创建父子进程
    pid_t pid = fork();
    if (pid < 0)
    {
        perror("fork");
        exit(EXIT_FAILURE);
    }
    if (pid == 0)
    {
        // 子进程, 等待接受消息队列中的消息
        char read_buf[100];
        struct timespec time_info;
        for (size_t i = 0; i < 10; i++)
        {
            // 清空接收数据的缓冲区
            memset(read_buf, 0, 100);
            // 获取当前的具体时间
            clock_gettime(CLOCK_REALTIME, &time_info);
            time_info.tv_sec += 5; // 在当前的具体时间上等待5秒
            // 接收消息
            // mq_receive(mqdes, read_buf, 100, NULL);
            if (mq_timedreceive(mqdes, read_buf, 100, NULL, &time_info) == -1)
            {
                perror("mq_timedreceive");
            }
            printf("son receive father message: %s\n", read_buf);
        }
    }
    else
    {
        // 父进程
        char send_buf[100];
        // 父进程向子进程发送消息
        struct timespec time_info;
        for (size_t i = 0; i < 10; i++)
        {
            memset(send_buf, 0, 100);
            sprintf(send_buf, "hello, son %ld\n", (i + 1));
            // 获取当前的具体时间
            clock_gettime(CLOCK_REALTIME, &time_info);
            time_info.tv_sec += 5; // 在当前的具体时间上等待5秒
            // 发送消息
            // mq_send(mqdes, send_buf, strlen(send_buf), 0);
            if (mq_timedsend(mqdes, send_buf, strlen(send_buf), 0, &time_info) == -1)
            {
                perror("mq_timedsend");
            }
            printf("father send son message, sleep 1s\n");
            sleep(1);
        }
    }
    // 不管是父进程还是子进程都需要释放消息队列的引用
    close(mqdes);
    // 清除消息队列只需要执行一次, 这里让父进程执行即可
    if (pid > 0)
    {
        mq_unlink(mq_name);
    }
    return 0;
}