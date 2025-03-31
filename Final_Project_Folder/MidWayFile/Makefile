CC = gcc
CFLAGS = -Wall -Wextra -std=c11

SRCS = main.c Move.c txtFiles.c
OBJS = $(SRCS:.c=.o)
EXEC = checkers

all: $(EXEC)

$(EXEC): $(OBJS)
	$(CC) $(CFLAGS) -o $(EXEC) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

test: $(EXEC)
	@echo "Running tests..."
	./$(EXEC) < test_input.txt > test_output.txt

clean:
	rm -f $(OBJS) $(EXEC) test_output.txt
