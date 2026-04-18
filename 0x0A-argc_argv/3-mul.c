#include "main.h"
#include <stdlib.h>

/**
 * print_number - prints an integer using _putchar
 * @n: the integer to print
 */
void print_number(int n)
{
	long num;

	num = n;
	if (num < 0)
	{
		_putchar('-');
		num = -num;
	}
	if (num >= 10)
		print_number((int)(num / 10));
	_putchar('0' + (num % 10));
}

/**
 * main - multiplies two numbers passed as arguments
 * @argc: number of arguments
 * @argv: array of arguments
 *
 * Return: 0 on success, 1 on error
 */
int main(int argc, char *argv[])
{
	int a;
	int b;
	int result;

	if (argc != 3)
	{
		_putchar('E');
		_putchar('r');
		_putchar('r');
		_putchar('o');
		_putchar('r');
		_putchar('\n');
		return (1);
	}
	a = atoi(argv[1]);
	b = atoi(argv[2]);
	result = a * b;
	print_number(result);
	_putchar('\n');
	return (0);
}
