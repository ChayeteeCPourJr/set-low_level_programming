#include "main.h"

/**
 * print_most_numbers - prints numbers from 0 to 9 except 2 and 4
 *
 * Return: void
 */
void print_most_numbers(void)
{
	char *n = "01356789";

	while (*n)
	{
		_putchar(*n);
		n++;
	}
	_putchar('\n');
}
