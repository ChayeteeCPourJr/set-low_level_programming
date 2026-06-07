#include <stdlib.h>
#include "103-keygen.h"

/**
 * f5 - computes key[4] index from sum of squared username chars
 * @username: the username string
 * @n: length of the username
 * Return: index into charset
 */
int f5(const char *username, int n)
{
	int sum, i, v;

	sum = 0;
	for (i = 0; i < n; i++)
	{
		v = (int)username[i];
		sum += v * v;
	}
	sum = (sum & ~0xff) | ((sum & 0xff) ^ 0xef);
	return (sum & 0x3f);
}

/**
 * f6 - computes key[5] index by calling rand() username[0] times
 * Relies on rand state seeded by f4
 * @username: the username string
 * Return: index into charset
 */
int f6(const char *username)
{
	int n, last, i;

	n = (int)username[0];
	last = 0;
	for (i = 0; i < n; i++)
		last = rand();
	last = (last & ~0xff) | ((last & 0xff) ^ 0xe5);
	return (last & 0x3f);
}
