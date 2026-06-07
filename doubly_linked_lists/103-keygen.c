#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CHARSET "A-CHRDw87lNS0E9B2TibgpnMVys5XzvtOGJcYLU+4mjW6fxqZeF3Qa1rPhdKIouk"

/**
 * f1 - computes key[0] index from username length
 * @n: length of the username
 * Return: index into charset
 */
int f1(int n)
{
	return ((n ^ 0x3b) & 0x3f);
}

/**
 * f2 - computes key[1] index from sum of username chars
 * @u: the username string
 * @n: length of the username
 * Return: index into charset
 */
int f2(const char *u, int n)
{
	int sum, i;

	sum = 0;
	for (i = 0; i < n; i++)
		sum += (int)u[i];
	return ((sum ^ 0x4f) & 0x3f);
}

/**
 * f3 - computes key[2] index from product of username chars
 * @u: the username string
 * @n: length of the username
 * Return: index into charset
 */
int f3(const char *u, int n)
{
	int product, i;

	product = 1;
	for (i = 0; i < n; i++)
		product *= (int)u[i];
	return ((product ^ 0x55) & 0x3f);
}

/**
 * f4 - computes key[3] using srand(max_char ^ 0xe) then rand()
 * Seeds the global rand state consumed later for key[5]
 * @u: the username string
 * @n: length of the username
 * Return: index into charset
 */
int f4(const char *u, int n)
{
	int max_val, i;

	max_val = (int)u[0];
	for (i = 0; i < n; i++)
		if ((int)u[i] > max_val)
			max_val = (int)u[i];
	srand((unsigned int)(max_val ^ 0xe));
	return (rand() & 0x3f);
}

/**
 * main - prints the valid crackme5 key for the given username
 * @argc: argument count
 * @argv: argument vector
 * Return: 0 on success, 1 on wrong usage
 */
int main(int argc, char *argv[])
{
	const char *u;
	int n, sum, v, last, i;
	char key[7];

	if (argc != 2)
	{
		fprintf(stderr, "Usage: %s username\n", argv[0]);
		return (1);
	}
	u = argv[1];
	n = (int)strlen(u);
	key[0] = CHARSET[f1(n)];
	key[1] = CHARSET[f2(u, n)];
	key[2] = CHARSET[f3(u, n)];
	key[3] = CHARSET[f4(u, n)];
	sum = 0;
	for (i = 0; i < n; i++)
	{
		v = (int)u[i];
		sum += v * v;
	}
	sum = (sum & ~0xff) | ((sum & 0xff) ^ 0xef);
	key[4] = CHARSET[sum & 0x3f];
	last = 0;
	for (i = 0; i < (int)u[0]; i++)
		last = rand();
	last = (last & ~0xff) | ((last & 0xff) ^ 0xe5);
	key[5] = CHARSET[last & 0x3f];
	key[6] = '\0';
	printf("%s\n", key);
	return (0);
}
