# 0x07. Pointers, Arrays and Strings

## Description
This project focuses on understanding pointers, arrays, and strings in C.  
The tasks involve manipulating memory directly, recreating standard library
string functions, and working with multidimensional arrays.

Students implement functions manually to strengthen their understanding of
low-level memory operations and pointer behavior.

---

## Learning Objectives
At the end of this project, you should be able to:

- Understand what pointers are and how they work
- Manipulate memory using pointers
- Work with arrays and multidimensional arrays
- Implement common string functions manually
- Understand pointer to pointer concepts
- Write clean, readable, and well-documented C code

---

## Project Requirements

- Allowed editors: `vi`, `vim`, `emacs`
- All files compiled on **Ubuntu 20.04 LTS**
- Compilation flags:


- All files must end with a new line
- A `README.md` file is required
- Code must follow **Betty coding style**
- No global variables allowed
- Maximum **5 functions per file**
- Only `_putchar` is allowed for output
- Do not push `_putchar.c`
- All function prototypes must be in `main.h`

---

## Files

| File | Description |
|-----|-------------|
| `0-memset.c` | Function that fills memory with a constant byte |
| `main.h` | Header file containing function prototypes |

---

## Function Prototype

```c
char *_memset(char *s, char b, unsigned int n);
