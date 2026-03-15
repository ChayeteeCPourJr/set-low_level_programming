# 0x06. C - Pointers, Arrays and Strings

## Description

This project focuses on understanding and practicing how to use **pointers**, **arrays**, and **strings** in the C programming language.
The tasks require implementing common string manipulation functions without using standard library functions.

The goal is to strengthen knowledge of:

* Memory handling with pointers
* String manipulation
* Array traversal
* Writing clean and readable C code following **Betty coding style**

## Requirements

* Allowed editors: `vi`, `vim`, `emacs`
* All files compiled on **Ubuntu 20.04 LTS**
* Compilation flags: `-Wall -Werror -Wextra -pedantic -std=gnu89`
* All files must end with a new line
* No global variables
* Maximum of 5 functions per file
* Only `_putchar` allowed for output
* Follow **Betty style** guidelines
* All function prototypes stored in `main.h`

## Files

| File         | Description                                                                                      |
| ------------ | ------------------------------------------------------------------------------------------------ |
| `0-strcat.c` | Function that concatenates two strings by appending the source string to the destination string. |
| `main.h`     | Header file containing function prototypes used in the project.                                  |

## Example

```c
char s1[98] = "Hello ";
char s2[] = "World!\n";

_strcat(s1, s2);
```

Output:

```
Hello World!
```

## Author

Student - Low Level Programming Project
