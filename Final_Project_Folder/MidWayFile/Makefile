
CC = gcc

# Compiler flags
CFLAGS = -Wall -g

# Source files
SRC = main.c board.c Move.c txtFiles.c

# Object files
OBJ = $(SRC:.c=.o)

# Executable name
EXEC = main

# Default target: compile and link everything
all: $(EXEC)

# Rule to create the executable
$(EXEC): $(OBJ)
	$(CC) $(OBJ) -o $(EXEC)

# Rule to compile .c files into .o files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean up the object files and the executable
clean:
	rm -f $(OBJ) $(EXEC)

# Run tests (if you have any test cases, add them here)
test:
	./$(EXEC)

