# TPSysteme
CC = gcc
CFLAGS = -Wall -Wextra -Werror -c
EXEC = program

all : $(EXEC)

$(EXEC) : type.o matrix.o main.o
	$(CC) -o ./bin/$(EXEC) ./obj/*.o

type.o : ./src/type.c
	$(CC) $(CFLAGS) ./src/type.c -o ./obj/type.o -I ./include

matrix.o : ./src/matrix.c
	$(CC) $(CFLAGS) ./src/matrix.c -o ./obj/type.o -I ./include

main.o : ./src/main.c
	$(CC) $(CFLAGS) ./src/main.c -o ./obj/type.o -I ./include

run :
	./bin/$(EXEC)

clean : 
	rm ./obj/*.o
	rm ./bin/$(EXEC)