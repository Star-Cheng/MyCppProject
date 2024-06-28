#include <stdio.h>
#include <errno.h>
int main(int argc, char const *argv[])
{
    /* void perror (const char *__s);
    ** const char *__s: 自定义错误前缀
    */
    fopen("/opt","a+");
    printf("erorr: %d\n",errno);
    perror("open file failed");
    return 0;
}