# 0x09. Static Libraries

## Description

This project focuses on creating a static library in C (`libmy.a` / `liball.a`) containing custom implementations of common standard library functions.

All functions are written following **Betty coding style** and compiled using strict GCC flags.

---

## Requirements

* Allowed editors: `vi`, `vim`, `emacs`
* Compilation:

  ```
  gcc -Wall -Werror -Wextra -pedantic -std=gnu89
  ```
* All files end with a new line
* No global variables
* Maximum of 5 functions per file
* No use of `printf`, `puts`, etc.
* Only `_putchar` is allowed for output
* `_putchar.c` must not be pushed
* All prototypes are declared in `main.h`

---

## Files

### Header File

* `main.h` → Contains all function prototypes

### Source Files

Custom implementations of standard C functions, including:

* Character checks: `_islower`, `_isalpha`, `_isupper`, `_isdigit`
* String functions: `_strlen`, `_strcpy`, `_strcat`, `_strcmp`, etc.
* Memory functions: `_memset`, `_memcpy`
* Search functions: `_strchr`, `_strstr`, `_strpbrk`
* Utility functions: `_atoi`, `_abs`

---

## Static Library

### Create library manually:

```
gcc -c *.c
ar rcs libmy.a *.o
```

### Using script:

```
./create_static_lib.sh
```

---

## Script

* `create_static_lib.sh`
  Creates `liball.a` from all `.c` files in the current directory.

---

## Usage

Example:

```
gcc -std=gnu89 main.c -L. -lmy -o output
./output
```

---

## Author

Project completed as part of low-level programming training.

