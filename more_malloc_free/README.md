# Dynamic Memory Allocation in C

A collection of custom C functions that implement dynamic memory allocation and string manipulation using `malloc`.

---

## Functions

### `malloc_checked`
```c
void *malloc_checked(unsigned int b);
```
Allocates `b` bytes of memory. If `malloc` fails, the process exits with status code `98`.

---

### `_calloc`
```c
void *_calloc(unsigned int nmemb, unsigned int size);
```
Allocates memory for an array of `nmemb` elements of `size` bytes each, and initializes all bytes to zero.

- Returns `NULL` if `nmemb` or `size` is `0`
- Returns `NULL` if `malloc` fails

---

### `string_nconcat`
```c
char *string_nconcat(char *s1, char *s2, unsigned int n);
```
Concatenates two strings. Returns a newly allocated string containing `s1` followed by the first `n` bytes of `s2`.

- If `n >= strlen(s2)`, the entire `s2` is appended
- `NULL` arguments are treated as empty strings
- Returns `NULL` on failure

---

### `array_range`
```c
int *array_range(int min, int max);
```
Creates a newly allocated array of integers containing all values from `min` to `max` (inclusive), in order.

- Returns `NULL` if `min > max`
- Returns `NULL` if `malloc` fails

---

## Requirements

- Language: **C**
- Compiler: `gcc`
- Standard: `C89` / `C99`
- Dependencies: `<stdlib.h>`, `<string.h>`

---

## Compilation

```bash
gcc -Wall -Werror -Wextra -pedantic *.c -o memory_functions
```

---

## Usage Example

```c
#include <stdlib.h>
#include <stdio.h>

int main(void)
{
    /* Allocate 10 bytes, exit(98) on failure */
    void *ptr = malloc_checked(10);

    /* Allocate zeroed array of 5 ints */
    int *arr = _calloc(5, sizeof(int));

    /* Concatenate strings */
    char *str = string_nconcat("Hello, ", "World!", 5);

    /* Create integer range [1..5] */
    int *range = array_range(1, 5);

    free(ptr);
    free(arr);
    free(str);
    free(range);
    return (0);
}
```

---

## Author

> Chayetee Pour.
