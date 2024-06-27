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
