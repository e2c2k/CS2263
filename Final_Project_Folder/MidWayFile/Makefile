# Compiler to use
CC = gcc

# Compiler flags
CFLAGS = -Wall -g

# Source file (just main.c)
SRC = main.c

# Object files for the necessary .c files (board, move, txtFiles)
OBJ = board.o move.o txtFiles.o

# Executable name
EXEC = main

# Default target: compile and link everything
all: $(EXEC)

# Rule to create the executable from the object files
$(EXEC): $(SRC) $(OBJ)
	$(CC) $(SRC) $(OBJ) -o $(EXEC)

# Rule to compile .c files into .o files
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
