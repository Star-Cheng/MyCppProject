CC := gcc
CFLAGS := -g
LDFLAGS := -lpthread

create_thread: create_thread.cpp
# $@: 目标文件名
# $^: 依赖文件名
	-$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)
	-./$@
	-rm ./$@