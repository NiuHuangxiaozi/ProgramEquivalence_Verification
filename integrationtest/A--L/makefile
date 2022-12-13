

src=$(wildcard  ./*.cpp)      # 等价于src=main.c fun1.c fun2.c sum.c，其中wildcard - 查找指定目录下的指定类型的文件
object=$(patsubst %.cpp,%.o,$(src))  # 等价于obj=main.o fun1.o fun2.o sum.o，其中，patsubst – 匹配替换
target=test
CC=g++
CPPFLAGS=-I./

$(target):$(src)
	$(CC) -w $(src) -lgtest -lpthread  -fprofile-arcs -ftest-coverage  -v -o  $(target)

.PHONY:clean
clean:
	-rm -f $(target) $(object) *.gcno *.gcda



