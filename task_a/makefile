FLAGS = -Wall -Werror -g 
CC = gcc
SUB1 = main1_1.c hello_ariel.c

SUB2 = main1_2.c ./hello_ariel.so
LDFALGS = -shared
RM = rm -rf

.PHONY: all
all: main1 main2

#SubTask1

main1: $(SUB1:.c=.o)
	$(CC) $(FLAGS) -o $@ $(SUB1:.c=.o) 

main1_1.o: main1_1.c 
	$(CC) $(FLAGS) -c $< 

hello_ariel.o: hello_ariel.c hello_ariel.h
	$(CC) $(FLAGS) -c $< 

#SubTask2

main2: hello_ariel.so 
	$(CC) $(FLAGS) -o $@ $(SUB2)  

hello_ariel.so: hello_ariel.o
	$(CC) -o $@ $(LDFALGS) -fPIC $<


.PHONY: clean 
clean:
	$(RM) *.o *.a *.so all