FLAGS = -Wall -Werror -g 
CC = gcc
TARGET = main1 main2

SUB1 = main1_1.c hello_ariel.c

SUB2 = main1_2.c -L. -l Hello
LDFALGS = -shared
export LD_LIBARAR_PATH=.

RM = rm -rf


.PHONY: all
all: $(TARGET)

#SubTask1

main1: $(SUB1:.c=.o)
	$(CC) $(FLAGS) -o $@ $(SUB1:.c=.o) 

main1_1.o: main1_1.c 
	$(CC) $(FLAGS) -c $< 

hello_ariel.o: hello_ariel.c hello_ariel.h
	$(CC) $(FLAGS) -c $< 

#SubTask2

main2: libHello.so
	$(CC) $(FLAGS) $(SUB2) -o $@  

libHello.so: hello_ariel.c
	$(CC) -o $@ $(LDFALGS) -fPIC $<


.PHONY: clean 
clean:
	$(RM) *.o *.a *.so $(TARGET)