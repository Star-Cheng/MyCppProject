#include <stdio.h>

int main(int argc, char *argv[])
{
    FILE *ioFile = fopen("../../data/hello.txt", "w+");
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
    int puts_result = fputs("ello world\n", ioFile);
    if (puts_result == EOF)
    {
        printf("write string failed\n");
    }
    else
    {
        printf("write string success\n");
    }
    /*
    ** fprintf(FILE *__restrict __stream, const char *__restrict __fmt, ...)
    ** const char *__restrict __fmt: 带格式化的长字符串
    ** ...可变参数: 填入格式化的长字符串
    ** return: 成功: 返回写入的字符, 不包含换行符; 失败: 返回EOF
    */
    int printf_result = fprintf(ioFile, "hello world\n");
    if (printf_result == EOF)
    {
        printf("printf write string failed\n");
    }
    else
    {
        printf("printf write %d string success\n", printf_result);
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