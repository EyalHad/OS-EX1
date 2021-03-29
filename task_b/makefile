CC = gcc
FLAGS = -Wall -Werror -g 
TARGET = main2_1 main2_2 main2_3
RM = rm -rf

.PHONY: all
all: $(TARGET)

main2_1: main2_1.c
	$(CC) $(FLAGS) -o $@ $<

main2_2: main2_2.c
	$(CC) $(FLAGS) -o $@ $<

main2_3: main2_3.c
	$(CC) $(FLAGS) -o $@ $<

.PHONY: clean
clean: $(RM) $(TARGET) 2>/dev/null			