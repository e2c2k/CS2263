CC = gcc
CFLAGS = -Wall -g
OBJFILES = main.o board.o move.o txtFiles.o
TARGET = main

# Rule to build the target executable
$(TARGET): $(OBJFILES)
	$(CC) $(OBJFILES) -o $(TARGET)

# Rule to compile main.o
main.o: main.c board.h move.h txtFiles.h
	$(CC) $(CFLAGS) -c main.c

# Rule to compile board.o
board.o: board.c board.h
	$(CC) $(CFLAGS) -c board.c

# Rule to compile move.o
move.o: move.c move.h board.h
	$(CC) $(CFLAGS) -c move.c

# Rule to compile txtFiles.o
txtFiles.o: txtFiles.c txtFiles.h
	$(CC) $(CFLAGS) -c txtFiles.c

# Clean up object files and target
clean:
	rm -f $(OBJFILES) $(TARGET)

