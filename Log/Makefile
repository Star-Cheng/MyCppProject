# Makefile内容通常一下三部分组成
# <目标名称>:<前置依赖>
#	\t<需要执行的命令>

# 定义变量 object
object := Log.o say_hello.o
# 目标是编译出mian文件, 依赖hello.o和main.o文件
Log: ${object}
	gcc ${object} -o Log

# 自动推导
# # 目标是Log.o, 依赖Log.cpp和say_hello.h文件
# Log.o: Log.cpp say_hello.h
# 	gcc -c Log.cpp -o Log.o
Log.o: say_hello.h

# say_hello.o: say_hello.cpp say_hello.h
# 	gcc -c say_hello.cpp -o say_hello.o
say_hello.o: say_hello.h

# 5. 声明为目标
.PHONY: clean
clean:
	rm -rf *.o Log
# -rm ${object} Log # # 6. 忽略错误

