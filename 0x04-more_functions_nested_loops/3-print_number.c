#include "main.h"

/**
 * print_numbers - prints numbers from 0 to 9
 *
 * Return: void
 */
void print_numbers(void)
{
	char *n = "0123456789";

	while (*n)
	{
		_putchar(*n);
		n++;
	}
	_putchar('\n');
}
