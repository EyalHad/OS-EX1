CC = gcc
FLAGS = -Wall -g 
TARGET = main2_1 main2_2 main2_3

.PHONY: all
all: $(TARGET) main2_4

main2_1: main2_1.c
	$(CC) $(FLAGS) -o $@ $<

main2_2: main2_2.c
	$(CC) $(FLAGS) -o $@ $<

main2_3: main2_3.c
	$(CC) $(FLAGS) -o $@ $<

main2_4: main2_4.c $(TARGET)
	$(CC) $(FLAGS) -o $@ $<	

.PHONY: clean
clean:
	rm -rf $(TARGET) 2>/dev/null			