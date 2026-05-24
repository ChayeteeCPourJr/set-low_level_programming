# C - Singly Linked Lists

A project focused on understanding and implementing singly linked lists in C, and an introduction to 64-bit assembly programming.

## Learning Objectives

- When and why to use linked lists vs arrays
- How to build and use linked lists
- How to use `__attribute__((constructor))` and `__attribute__((destructor))`
- How to write 64-bit assembly with `nasm`

## Requirements

### C Files
- Compiled on Ubuntu 20.04 LTS using `gcc -Wall -Wextra -Werror -pedantic`
- Code follows the **Betty** style guide
- No global variables
- No more than 5 functions per file
- Only allowed C standard library functions: `malloc`, `free`, `exit`, `strdup`, `strlen`, `printf`

### Assembly Files
- Compiled using `nasm` and `gcc`
- 64-bit programs (`elf64`)

## Data Structure

```c
typedef struct list_s
{
    char *str;         /* malloc'ed string */
    unsigned int len;  /* length of the string */
    struct list_s *next; /* points to the next node */
} list_t;
```

## Files

| File | Prototype | Description |
|------|-----------|-------------|
| `0-print_list.c` | `size_t print_list(const list_t *h)` | Prints all elements of a list |
| `1-list_len.c` | `size_t list_len(const list_t *h)` | Returns number of elements in a list |
| `2-add_node.c` | `list_t *add_node(list_t **head, const char *str)` | Adds a new node at the beginning |
| `3-add_node_end.c` | `list_t *add_node_end(list_t **head, const char *str)` | Adds a new node at the end |
| `4-free_list.c` | `void free_list(list_t *head)` | Frees a list |
| `100-main_var.c` | `void before_main(void)` | Prints before `main` using constructor |
| `101-hello_alx.asm` | `main` | 64-bit assembly that prints `Hello, ALX` |

## Compilation

### C files
```bash
gcc -Wall -Wextra -Werror -pedantic 0-main.c 0-print_list.c -o print_list
```

### Assembly file
```bash
nasm -f elf64 101-hello_alx.asm -o 101-hello_alx.o
gcc -no-pie 101-hello_alx.o -o hello_alx
```

## Author

* **[Chayetee]** - [GitHub](https://github.com/ChayeteeCPourJr)
