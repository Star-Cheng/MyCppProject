CC := gcc
CFLAGS := -g
LDFLAGS := -lrt

Temp: Temp.cpp -lrt
# g++ -o Temp Temp.cpp
# $@: 目标文件名
# $^: 依赖文件名
	-$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)
	-./$@ "test"
	-rm ./$@