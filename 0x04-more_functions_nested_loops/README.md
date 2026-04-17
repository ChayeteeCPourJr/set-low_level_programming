# 0x04. More Functions, Nested Loops

This directory contains C functions that demonstrate basic programming concepts with **nested loops** and character checking. All functions are implemented in **Betty style**.

## Tasks

### 0. _isupper
- **File:** `0-isupper.c`
- **Prototype:** `int _isupper(int c);`
- **Description:** Checks if a character `c` is uppercase.
- **Returns:** `1` if `c` is uppercase, `0` otherwise.
- **Note:** Only `_putchar` is allowed for output (not used in this task).  

## Example Usage

```c
#include "main.h"
#include <stdio.h>

int main(void)
{
    char c = 'A';
    printf("%c: %d\n", c, _isupper(c));
    c = 'a';
    printf("%c: %d\n", c, _isupper(c));
    return (0);
}
