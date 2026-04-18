#include "main.h"

/**
 * main - prints the number of arguments passed
 * @argc: argument count
 * @argv: argument vector
 *
 * Return: 0
 */
int main(int argc, char *argv[])
{
	int n;

	(void)argv;

	n = argc - 1;

	if (n == 0)
	{
		_putchar('0');
	}
	else
	{
		if (n >= 10)
			_putchar((n / 10) + '0');

		_putchar((n % 10) + '0');
	}

	_putchar('\n');

	return (0);
}
