# 0x06. C - Pointers, Arrays and Strings

## Description

This project focuses on understanding and practicing **pointers, arrays, and string manipulation in C**.
The tasks involve recreating common C library string functions and performing operations on arrays using low-level programming concepts.

The goal is to strengthen knowledge of:

* Pointers
* Arrays
* String manipulation
* Memory handling
* Writing clean C code using the **Betty coding style**

## Requirements

* Allowed editors: `vi`, `vim`, `emacs`
* All files compiled on **Ubuntu 20.04 LTS**
* Compilation flags:
  `gcc -Wall -Werror -Wextra -pedantic -std=gnu89`
* All files must end with a new line
* No global variables allowed
* Maximum of **5 functions per file**
* No use of standard output functions (`printf`, `puts`, etc.)
* Only `_putchar` is allowed for output
* Do **not push `_putchar.c`**
* All function prototypes must be declared in `main.h`
* All code must follow **Betty style guidelines**

## Files

| File                 | Description                                                       |
| -------------------- | ----------------------------------------------------------------- |
| `0-strcat.c`         | Concatenates two strings.                                         |
| `1-strncat.c`        | Concatenates two strings using at most `n` bytes from the source. |
| `2-strncpy.c`        | Copies a string using at most `n` bytes.                          |
| `3-strcmp.c`         | Compares two strings.                                             |
| `4-rev_array.c`      | Reverses the contents of an array of integers.                    |
| `5-string_toupper.c` | Converts all lowercase letters of a string to uppercase.          |
| `6-cap_string.c`     | Capitalizes the first letter of each word in a string.            |
| `7-leet.c`           | Encodes a string into 1337 (leet speak).                          |
| `main.h`             | Header file containing all function prototypes.                   |

## Compilation

Example:

```
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 0-main.c 0-strcat.c -o 0-strcat
```

## Example

```
Input:  Hello 
        World!

Output: Hello World!
```

## Author

ChayeteeCPourJr — Low Level Programming Project
