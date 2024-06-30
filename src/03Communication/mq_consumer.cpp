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
    char read_buf[100];
    struct timespec time_info;
    while (1)
    {
        memset(read_buf, 0, 100); // 清空发送数据的缓冲区
        clock_gettime(CLOCK_REALTIME, &time_info);
        time_info.tv_sec += 10;
        // 读取消息队列的一条数据
        if (mq_timedreceive(mqdes, read_buf, 100, NULL, &time_info) == -1)
        {
            perror("mq_timedreceive");
        }
        // 判断当前数据是否为结束信息
        if (read_buf[0] == EOF)
        {
            printf("received EOF...\n");
            break;
        }
        // 正常读取的消息队列的信息
        else
        {
            printf("received info from producer: %s\n", read_buf);
        }
    }
    // 关闭消息队列描述符
    close(mqdes);
    // 清除消息队列只需要执行一次
    mq_unlink(mq_name);
    return 0;
}