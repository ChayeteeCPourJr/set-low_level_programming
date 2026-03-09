#include "main.h"

/**
 * puts_half - prints the second half of a string
 * @str: pointer to the string
 */
void puts_half(char *str)
{
    int len = 0;
    int i;

    /* Find string length */
    while (str[len] != '\0')
        len++;

    /* Determine starting index */
    if (len % 2 == 0)
        i = len / 2;
    else
        i = (len + 1) / 2;

    /* Print second half */
    while (i < len)
    {
        _putchar(str[i]);
        i++;
    }

    _putchar('\n');
}
