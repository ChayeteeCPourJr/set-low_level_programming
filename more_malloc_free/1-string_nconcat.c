#include <stdlib.h>

/**
 * string_nconcat - concatenates two strings
 * @s1: first string
 * @s2: second string
 * @n: max bytes to use from s2
 *
 * Return: pointer to the newly allocated concatenated string, or NULL on fail
 */
char *string_nconcat(char *s1, char *s2, unsigned int n)
{
	char *result;
	unsigned int len1, len2, copy_len, i;

	s1 = (s1 == NULL) ? "" : s1;
	s2 = (s2 == NULL) ? "" : s2;

	for (len1 = 0; s1[len1]; len1++)
		;
	for (len2 = 0; s2[len2]; len2++)
		;

	copy_len = (n >= len2) ? len2 : n;

	result = malloc(len1 + copy_len + 1);
	if (result == NULL)
		return (NULL);

	for (i = 0; i < len1; i++)
		result[i] = s1[i];

	for (i = 0; i < copy_len; i++)
		result[len1 + i] = s2[i];

	result[len1 + copy_len] = '\0';

	return (result);
}
