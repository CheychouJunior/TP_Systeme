# TPSysteme
CC = gcc
CFLAGS = -Wall -Wextra -Werror -c
EXEC = program

all : $(EXEC)

$(EXEC) : type.o matrix.o program.o
	$(CC) -o ./bin/$(EXEC) ./obj/*.o -I ./include

type.o : ./src/type.c
	$(CC) $(CFLAGS) ./src/type.c -o ./obj/type.o -I ./include

matrix.o : ./src/matrix.c
	$(CC) $(CFLAGS) ./src/matrix.c -o ./obj/matrix.o -I ./include

program.o : ./src/program.c
	$(CC) $(CFLAGS) ./src/program.c -o ./obj/program.o -I ./include

run :
	./bin/$(EXEC)

clean : 
	rm ./obj/*.o
	rm ./bin/$(EXEC)