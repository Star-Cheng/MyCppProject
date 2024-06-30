CC := gcc
CFLAGS := -g
LDFLAGS := -lrt


share_memory: share_memory.cpp -lrt
# g++ -o Temp Temp.cpp
# $@: 目标文件名
# $^: 依赖文件名
	-$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)
	-./$@ "test"
	-rm ./$@

pipe_write: pipe_write.cpp
	-$(CC) -o $@ $^
	-./$@
	-rm $@

pipe_read: pipe_read.cpp
	-$(CC) -o $@ $^
	-./$@
	-rm $@

mq_father_son: mq_father_son.cpp -lrt
# g++ -o Temp Temp.cpp
# $@: 目标文件名
# $^: 依赖文件名
	-$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)
	-./$@ "test"
	-rm ./$@

mq_producer: mq_producer.cpp -lrt
# g++ -o Temp Temp.cpp
# $@: 目标文件名
# $^: 依赖文件名
	-$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)
# -./$@ "test"
# -rm ./$@

mq_consumer: mq_consumer.cpp -lrt
# g++ -o Temp Temp.cpp
# $@: 目标文件名
# $^: 依赖文件名
	-$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)
# -./$@ "test"
# -rm ./$@