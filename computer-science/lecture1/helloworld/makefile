# Makefile

# Compiler
CC = gcc

# Compiler flags
CFLAGS = -Wall -Wextra -O2

# Target executable
TARGET = hello

# Default target
all: $(TARGET)

# Link the executable
$(TARGET): main.o
	$(CC) $(CFLAGS) -o $(TARGET) main.o

# Compile the source file
main.o: main.c
	$(CC) $(CFLAGS) -c main.c

# Clean up build files
clean:
	rm -f $(TARGET) main.o
