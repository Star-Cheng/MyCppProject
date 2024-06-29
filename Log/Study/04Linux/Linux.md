# Linux应用层开发

## C语言有参数的main函数

```C++
#include <stdio.h>
int main(int argc, char *argc[])
{
    return 0;
}
```

## 1 gcc

### 1.1 gcc预处理

```bash
gcc -E Log.cpp -o Log.i
```

### 1.2 gcc编译

```bash
gcc -S Log.cpp -o Log.s
```

### 1.3 gcc汇编

```bash
gcc -c Log.cpp -o Log.o
objdump -s Log.o # 查看main.o的section
objdump -d Log.o # 查看main.o的汇编代码
```

### 1.4 常见的section

+ 除了常见objdump -s Log.o 看到的集中section, 还有.data, .bss, .rodata
    1. .data: 包含初始化了的全局变量和静态变量
    2. .bss 包含未初始化的全局变量和静态变量
    3. .rodata: 包含只读数据

### 1.5 gcc链接

```bash
# 静态链接
gcc -static Log.o say_hello.o -o Log
# 动态链接
gcc Log.o say_hello.o -o Log
gcc -fPIC -shared say_hello.o -o libhello.so 
gcc Log.o -L ./ -lhello -o Log2
LD_LIBRARY_PATH=./ ./Log2
# 混合链接
ar crv libhello.a say_hello.o
gcc Log.o -L ./ -lhello -o Log3
# 同一个目录下既有动态库又有静态库, 默认调用动态库
./Log3
```

### 1.6 Makefile

```Makefile
# Makefile内容通常一下三部分组成
# <目标名称>:<前置依赖>
#\t<需要执行的命令>

# 定义变量 object
object := Log.o say_hello.o
# 目标是编译出mian文件, 依赖hello.o和main.o文件
Log: ${object}
    gcc ${object} -o Log

# 自动推导
# # 目标是Log.o, 依赖Log.cpp和say_hello.h文件
# Log.o: Log.cpp say_hello.h
#   gcc -c Log.cpp -o Log.o
Log.o: say_hello.h

# say_hello.o: say_hello.cpp say_hello.h
#   gcc -c say_hello.cpp -o say_hello.o
say_hello.o: say_hello.h

clean:
 rm -rf *.o Log
```

## 2 系统调用

### 2.1 常见系统调用

1. open
2. read
3. write
4. close
5. exit

## 3 进程处理

### 3.1 fork

```C++
#include <unistd.h>
pid_t pid = fork();
```

### 3.2 execve

```C++
#include <unistd.h>
#include <stdlib.h>
char new_name[100] = "new student";
char *args[] = {(char *)"/home/gym/code/CppProject/build/MyCppProject/erlou", new_name, NULL};
char *envs[] = {NULL};
int exR = execve(args[0], args, envs);
if (exR == -1)
{
    perror("execve error");
    exit(1);
}
```

### 3.3 waitpid

```C++
#include <sys/wait.h>
#include <unistd.h>
pid_t pid = fork();
waitpid(pid, NULL, 0);
```

## 4. 进程通信

+ 进程之间的内存是隔离的, 如果多个进程之间需要进行信息交换, 常用的方法有
    1. Unix Domain Socket IPC
    2. 管道(有名管道, 无名管道)
    3. 共享内存
    4. 消息队列
    5. 信号量

### 4.1 匿名管道(Pipe)

#### 4.1.1 库函数perror(), errno

```C++
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
```

#### 4.1.2 系统调用pipe()

```C++
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    pid_t cpid;
    int pipefd[2];
    // 将程序传递进来的第一个命令行参数通过管道传输给子进程
    if (argc != 2)
    {
        fprintf(stderr, "%s: please enter deliver info\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    // 创建管道
    if (pipe(pipefd) == -1)
    {
        perror("create pipe failed");
        exit(EXIT_FAILURE);
    }
    // 赋值父子进程
    cpid = fork();
    if (cpid == -1)
    {
        perror("invita");
        exit(EXIT_FAILURE);
    }
    if (cpid == 0)
    {
        // 子进程读取管道的数据, 打印到控制台
        close(pipefd[1]);
        char str[100] = {0};
        sprintf(str, "new student %d deliver info to old student\n", getpid());
        write(STDOUT_FILENO, str, sizeof(str));
        char buf;
        while (read(pipefd[0], &buf, 1) > 0)
        {
            write(STDOUT_FILENO, &buf, 1); // 输出到控制台
        }
        write(STDOUT_FILENO, "\n", 1);
        close(pipefd[0]);
        exit(EXIT_FAILURE);
    }
    else
    {
        // 父进程向管道写入数据, 提供给子进程读
        close(pipefd[0]);
        // 将数据写入到管道中
        printf("old student %d deliver info to new student\n", getpid());
        write(pipefd[1], argv[1], strlen(argv[1]));
        close(pipefd[1]);
        waitpid(cpid, NULL, 0);
        exit(EXIT_FAILURE);
    }
    return 0;
}
```

### 4.2 进程间通信
