#include <stdio.h>

int main(int argc, char *argv[])
{
    // 1. 打开文件
    FILE *ioFile = fopen("../data/hello.txt", "r");
    FILE *ioData = fopen("../data/data.txt", "r");
    // 2. 读取文件类容
    // 2.1 fgetc读取一个字符
    // char c = fgetc(ioFile);
    // while (c != EOF)
    // {
    //     printf("%c", c);
    //     c = fgetc(ioFile);
    // }

    // 2.2 fgets读取一行
    /* fgets (char *__restrict __s, int __n, FILE *__restrict __stream)
    ** int __n: 接受数据的长度
    */
    char buf[2048];
    while (fgets(buf, 1024, ioFile) != NULL)
    {
        printf("%s", buf);
    }
    printf("\n");
    // 2.3 fscanf读取数据
    /* int fscanf (FILE *__restrict __stream, const char *__restrict __format, ...)
    ** int __format: 格式化字符串(固定格式接受)
    ** ...: 填写格式化的字符串(接受数据提前声明的变量)
    ** return: 成功返回读取到的数据个数, 失败返回0
    */
    char name[50];
    int age;
    char sex[10];
    int scanfR = fscanf(ioData, "%s %d %s", name, &age, sex);
    if (scanfR != EOF)
    {
        printf("成功匹配到的参数有%d个\n", scanfR);
        printf("%s %d %s\n", name, age, sex);
    }
    printf("循环读取数据\n");
    while (scanfR = fscanf(ioData, "%s %d %s", name, &age, sex) != EOF)
    {
        printf("%s %d %s\n", name, age, sex);
    }
    // 3. 关闭文件
    int closeR_hello = fclose(ioFile);
    int closeR_data = fclose(ioData);
    return 0;
}