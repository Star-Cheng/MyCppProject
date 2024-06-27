#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

int main()
{
    /* (const char *__path, int __oflag, ...)
    ** char *__path: 打开文件的路径
    ** int __oflag: 打开文件的方式
    **            1. O_RDONLY: 只读方式打开
    **            2. O_WRONLY: 只写方式打开
    **            3. O_RDWR: 读写方式打开
    **            4. O_CREAT: 如果文件不存在则创建
    **            5. O_APPEND: 如果文件存在，写入时将文件指针移动到文件尾
    **            6. O_TRUNC: 如果文件存在，打开时清空文件
    ** ...可变参数: int __mode: 创建文件时指定文件的权限
    ** return: 成功返回文件描述符，失败返回-1, 同时设置全局变量errno便是对应的错误
    */
    // Linux操作系统有文件权限的保护: 默认创建的文件会被删除掉其他用户的写权限
    int fd = open("../../data/data.txt", O_RDONLY);
    if (fd == -1)
    {
        // printf("open file failed\n");
        perror("open ");
        _exit(1);
    }
    char buf[1024]; // 存放读取的数据
    /* (int __fd, void *__buf, size_t __nbytes)
    ** int __fd: 文件描述符
    ** void *__buf: 存放读取数据的缓冲区
    ** size_t __nbytes: 读取数据的大小
    ** return: 成功返回读取的字节数，失败返回-1
    */
    // read(fd, buf, sizeof(buf));
    size_t bytes_read;
    while ((bytes_read = read(fd, buf, sizeof(buf))) > 0)
    {
        // 文件描述符类型的 stdin -> 0
        // stdout -> 1   stderr -> 2
        // printf("%s", buf);
        write(STDOUT_FILENO, buf, bytes_read);
    }
    if (bytes_read == -1)
    {
        // printf("open file failed\n");
        perror("open ");
        _exit(1);
    }

    return 0;
}