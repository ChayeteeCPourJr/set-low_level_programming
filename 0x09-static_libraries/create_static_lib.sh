#!/bin/bash
# Create a static library liball.a from all .c files

# Compile all .c files into .o files
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 -c *.c

# Create the static library
ar rcs liball.a *.o
