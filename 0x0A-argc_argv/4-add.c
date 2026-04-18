#include "main.h"
#include <stdlib.h>

/**
 * is_number - checks if a string contains only digits
 * @s: string to check
 *
 * Return: 1 if valid, 0 otherwise
 */
int is_number(char *s)
{
	int i = 0;

	while (s[i] != '\0')
	{
		if (s[i] < '0' || s[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

/**
 * print_number - prints an integer
 * @n: number to print
 */
void print_number(int n)
{
	unsigned int num;

	if (n < 0)
	{
		_putchar('-');
		num = -n;
	}
	else
	{
		num = n;
	}

	if (num / 10)
		print_number(num / 10);

	_putchar((num % 10) + '0');
}

/**
 * main - adds positive numbers
 * @argc: argument count
 * @argv: argument vector
 *
 * Return: 0 on success, 1 on error
 */
int main(int argc, char *argv[])
{
	int i, sum = 0;

	if (argc == 1)
	{
		_putchar('0');
		_putchar('\n');
		return (0);
	}

	for (i = 1; i < argc; i++)
	{
		if (!is_number(argv[i]))
		{
			int j = 0;

			while ("Error"[j] != '\0')
			{
				_putchar("Error"[j]);
				j++;
			}
			_putchar('\n');
			return (1);
		}

		sum += atoi(argv[i]);
	}

	print_number(sum);
	_putchar('\n');

	return (0);
}
