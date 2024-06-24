#include <stdio.h>

int main(int argc, char *argv[])
{
    FILE *ioFile = fopen("../data/hello.txt", "w+");
    if (ioFile == NULL)
    {
        printf("open file failed\n");
        return -1;
    }
    else
    {
        printf("open file success\n");
    }
    /* nt fputc (int __c, FILE *__stream);
    ** FILE *__stream: 打开的一个文件
    ** return: 成功: 返回写入的字符, 失败: 返回EOF
    ** int fputc(int __c, FILE *__stream)
    */
    int put_result = fputc('h', ioFile);
    if (put_result == EOF)
    {
        printf("write char failed\n");
    }
    else
    {
        printf("write char success\n");
    }
    /* int fputs (const char *__restrict __s, FILE *__restrict __stream);
    ** FILE *__stream: 打开的一个文件
    ** return: 成功: 返回写入的字符, 失败: 返回EOF
    */
    int puts_result = fputs("ello world", ioFile);
    if (puts_result == EOF)
    {
        printf("write string failed\n");
    }
    else
    {
        printf("write string success\n");
    }

    /* int fclose (FILE *__stream);
    ** return: 0: success
    **        -1: fail
    */
    int result = fclose(ioFile);
    if (result == 0)
    {
        printf("close file success\n");
    }
    else if (result == EOF)
    {
        printf("close file failed\n");
    }
    return 0;
}