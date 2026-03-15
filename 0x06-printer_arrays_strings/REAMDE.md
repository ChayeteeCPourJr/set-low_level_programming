# 0x06. C - Pointers, Arrays and Strings

This project focuses on understanding pointers, arrays, and strings in C.

## Task 0 - strcat

Write a function that concatenates two strings.

Prototype:char *_strcat(char *dest, char *src);

Description:
- Appends the `src` string to the `dest` string.
- Overwrites the terminating null byte (`\0`) at the end of `dest`.
- Adds a new terminating null byte.
- Returns a pointer to the resulting string `dest`.

The implementation recreates the behavior of the standard C function `strcat`.
