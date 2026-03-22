#include "main.h"

/**
 * _print_rev_recursion - Prints a string in reverse
 * @s: The string to print in reverse
 *
 * Description: This function uses recursion to print each character
 * of the string in reverse order.
 */
void _print_rev_recursion(char *s)
{
    if (*s == '\0')
        return;
    
    _print_rev_recursion(s + 1);
    _putchar(*s);
}
