# Compiler to use
CC = gcc

# Compiler flags
CFLAGS = -Wall -g

# Source files (add all .c files here)
SRC = main.c Board.c Move.c txtFiles.c

# Object files (these will be generated from the .c files)
OBJ = $(SRC:.c=.o)

# Executable name
EXEC = main

# Default target: compile and link everything
all: $(EXEC)

# Rule to create the executable from the object files
$(EXEC): $(OBJ)
	$(CC) $(OBJ) -o $(EXEC)

# Rule to compile .c files into .o files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean up object files and the executable
clean:
	rm -f $(OBJ) $(EXEC)

# Run the program (optional)
run: $(EXEC)
	./$(EXEC)
