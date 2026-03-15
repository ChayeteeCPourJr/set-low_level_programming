#include "main.h"

/**
 * _strcat - Concatenates two strings
 * @dest: The destination string to be appended to
 * @src: The source string to append
 *
 * Return: A pointer to the resulting string dest
 */
char *_strcat(char *dest, char *src)
{
	int i = 0;
	int j = 0;

	/* Move to the end of the dest string */
	while (dest[i] != '\0')
	{
		i++;
	}

	/* Append src to dest, overwriting dest's null byte */
	while (src[j] != '\0')
	{
		dest[i] = src[j];
		i++;
		j++;
	}

	/* Add the terminating null byte */
	dest[i] = '\0';

	return (dest);
}
