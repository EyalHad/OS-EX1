FLAGS = -Wall -g 
CC = gcc
TARGET = main1_1 main1_2 main1_3
HEADER = hello_ariel.h

SUB1 = main1_1.c hello_ariel.c

SUB2 = main1_2.c -L. -l Hello
LDFALGS = -shared

export LD_LIBRARY_PATH=.

RM = rm -rf


.PHONY: all
all: $(TARGET)

#SubTask1

main1_1: $(SUB1:.c=.o)
	$(CC) $(FLAGS) -o $@ $(SUB1:.c=.o) 

main1_1.o: main1_1.c $(HEADER)
	$(CC) $(FLAGS) -c $< 

hello_ariel.o: hello_ariel.c $(HEADER)
	$(CC) $(FLAGS) -c $< 

#SubTask2

main1_2: main1_2.c libHello.so $(HEADER)
	$(CC) $(FLAGS) $(SUB2) -o $@ 

libHello.so: hello_ariel.c $(HEADER)
	$(CC) -o $@ $(LDFALGS) -fPIC $<

#SubTask3

main1_3: main1_3.c $(HEADER)
	$(CC) $(FLAGS) $< -fPIC -ldl -o $@

.PHONY: clean 
clean:
	$(RM) *.o *.a *.so $(TARGET) 2>/dev/null