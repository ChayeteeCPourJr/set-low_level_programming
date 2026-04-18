#!/bin/bash
for f in *.c; do gcc -c -Wall -Wextra "$f" 2>/dev/null; done
ar rcs liball.a *.o
