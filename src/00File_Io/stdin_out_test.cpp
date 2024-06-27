#include <stdio.h>

int main()
{
    char ch[100];
    fgets(ch, 100, stdin);
    printf("%s", ch);
    // 标准输出
    fputs(ch, stdout);
    // 错误输出
    fputs(ch, stderr);
    return 0;
}