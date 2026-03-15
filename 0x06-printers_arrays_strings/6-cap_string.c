#include "main.h"

/**
 * is_separator - checks if a character is a word separator
 * @c: character to check
 *
 * Return: 1 if separator, 0 otherwise
 */
int is_separator(char c)
{
	char sep[] = " \t\n,;.!?\"(){}";
	int i;

	for (i = 0; sep[i] != '\0'; i++)
	{
		if (c == sep[i])
			return (1);
	}
	return (0);
}

/**
 * cap_string - capitalizes all words of a string
 * @str: string to modify
 *
 * Return: pointer to the resulting string
 */
char *cap_string(char *str)
{
	int i = 0;

	/* Capitalize first character if it is a lowercase letter */
	if (str[0] >= 'a' && str[0] <= 'z')
		str[0] -= 32;

	i = 1;
	while (str[i] != '\0')
	{
		if (is_separator(str[i - 1]) && (str[i] >= 'a' && str[i] <= 'z'))
			str[i] -= 32;
		i++;
	}

	return (str);
}
