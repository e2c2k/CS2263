CC = gcc

CFLAGS = -Wall -g

SRC = main.c

OBJ = Board.o Move.o txtFiles.o

EXEC = main

all: $(EXEC)

$(EXEC): $(SRC) $(OBJ)
	$(CC) $(SRC) $(OBJ) -o $(EXEC)

board.o: board.c
	$(CC) $(CFLAGS) -c board.c -o board.o

move.o: move.c
	$(CC) $(CFLAGS) -c move.c -o move.o

txtFiles.o: txtFiles.c
	$(CC) $(CFLAGS) -c txtFiles.c -o txtFiles.o

# Clean up object files and the executable
clean:
	rm -f $(OBJ) $(EXEC)

# Run the program (optional)
run: $(EXEC)
	./$(EXEC)
