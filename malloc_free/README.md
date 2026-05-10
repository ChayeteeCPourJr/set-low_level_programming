# malloc, free

## Description
Functions that demonstrate dynamic memory allocation and deallocation in C using `malloc` and `free`.

## Files

| File | Prototype | Description |
|------|-----------|-------------|
| `0-create_array.c` | `char *create_array(unsigned int size, char c)` | Creates an array of chars initialized with a specific char |
| `1-strdup.c` | `char *_strdup(char *str)` | Returns a pointer to a newly allocated copy of a string |
| `2-str_concat.c` | `char *str_concat(char *s1, char *s2)` | Concatenates two strings into a newly allocated space |
| `3-alloc_grid.c` | `int **alloc_grid(int width, int height)` | Returns a pointer to a 2D array of integers initialized to 0 |
| `4-free_grid.c` | `void free_grid(int **grid, int height)` | Frees a 2D grid previously created by `alloc_grid` |
| `main.h` | — | Header file containing all function prototypes |

## Compilation
```bash
gcc -Wall -pedantic -Werror -Wextra -std=gnu89 <main_file.c> <function_file.c> -o <output>
```

## Examples
```bash
gcc -Wall -pedantic -Werror -Wextra -std=gnu89 0-main.c 0-create_array.c -o a && ./a
gcc -Wall -pedantic -Werror -Wextra -std=gnu89 1-main.c 1-strdup.c -o b && ./b
gcc -Wall -pedantic -Werror -Wextra -std=gnu89 2-main.c 2-str_concat.c -o c && ./c
gcc -Wall -pedantic -Werror -Wextra -std=gnu89 3-main.c 3-alloc_grid.c -o d && ./d
gcc -Wall -pedantic -Werror -Wextra -std=gnu89 4-main.c 3-alloc_grid.c 4-free_grid.c -o e && ./e
```

## Requirements
- Allowed editors: `vi`, `vim`, `emacs`
- Compiled on Ubuntu 20.04 LTS using `gcc`
- Code follows Betty style and documentation guidelines
- No global variables
- No more than 5 functions per file
- Only `malloc` and `free` from the standard library are used

## Author
Chayetee
