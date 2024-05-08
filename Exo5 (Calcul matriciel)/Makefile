# TPSysteme
CC = gcc
CFLAGS = -Wall -Wextra -Werror -c
EXEC = program

all : $(EXEC)

$(EXEC) : type.o matrix.o main.o
	$(CC) -o ./bin/$(EXEC) ./obj/*.o

type.o : ./src/type.c
	$(CC) $(LFLAGS) ./src/type.c -I ./include

matrix.o : ./src/matrix.c
	$(CC) $(LFLAGS) ./src/matrix.c -I ./include

main.o : ./src/main.c
	$(CC) $(LFLAGS) ./src/main.c -I ./include

run :
	./bin/$(EXEC)

clean : 
	rm ./obj/*.o
	rm ./bin/$(EXEC)