CC = clang
CFLAGS = -std=gnu99 -pedantic -Wall -Werror -fsanitize=address
TARGET = rotate-matrix

all: rotate-matrix

$(TARGET): rotate_better_solution.c
	$(CC) $(CFLAGS) -o rotate-matrix read-matrix.o rotate_better_solution.c

.PHONY: clean
clean:
	rm -f *~
