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
    char *mq_name = (char *)"/producer_comsumer_mq";
    mqd_t mqdes = mq_open(mq_name, O_CREAT | O_RDWR, 0664, &attr);
    if (mqdes == (mqd_t)-1)
    {
        perror("mq_open");
        exit(EXIT_FAILURE);
    }
    // 不断接受控制台中的数据, 发送到消息队列
    char write_buf[100];
    struct timespec time_info;
    while (1)
    {
        memset(write_buf, 0, 100); // 清空发送数据的缓冲区
        // 不断读取控制台数据
        ssize_t read_count = read(STDIN_FILENO, write_buf, 100);
        clock_gettime(CLOCK_REALTIME, &time_info);
        time_info.tv_sec += 5;
        // 如果出错就报错
        if (read_count == -1)
        {
            perror("read");
            continue;
        }
        else if (read_count == 0)
        {
            // ctrl + D 关闭控制台
            printf("EOF, exit...\n");
            char eof = EOF;
            // 将EOF当作一条新校发送到消息队列
            mq_timedsend(mqdes, &eof, 1, 0, &time_info);
            if (mq_close(mqdes) == -1)
            {
                perror("mq_close");
            }
            break;
        }
        // 正常接收到控制台的可读信息
        if (mq_timedsend(mqdes, write_buf, strlen(write_buf), 0, &time_info) == -1)
        {
            // 发送消息
            perror("mq_timedsend");
        }
        printf("received info form console, have sent info to message queue\n");
    }
    // 关闭消息队列描述符
    close(mqdes);
    // 清除消息队列只需要执行一次
    // mq_unlink(mq_name);
    return 0;
}