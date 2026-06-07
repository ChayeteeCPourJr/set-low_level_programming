#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * charset - the 64-character lookup table embedded in crackme5
 * Reconstructed from the 8 movabs constants in main()
 */
static const char charset[] = "A-CHRDw87lNS0E9B2TibgpnMVys5XzvtOGJcYLU+4mjW6fxqZeF3Qa1rPhdKIouk";

/**
 * f1 - computes key[0] index from username length
 * @n: length of the username
 * Return: index into charset
 */
static int f1(int n)
{
	return (n ^ 0x3b) & 0x3f;
}

/**
 * f2 - computes key[1] index from sum of username chars
 * @username: the username string
 * @n: length of the username
 * Return: index into charset
 */
static int f2(const char *username, int n)
{
	int sum, i;

	sum = 0;
	for (i = 0; i < n; i++)
		sum += (int)username[i];
	return (sum ^ 0x4f) & 0x3f;
}

/**
 * f3 - computes key[2] index from product of username chars
 * @username: the username string
 * @n: length of the username
 * Return: index into charset
 */
static int f3(const char *username, int n)
{
	int product, i;

	product = 1;
	for (i = 0; i < n; i++)
		product *= (int)username[i];
	return (product ^ 0x55) & 0x3f;
}

/**
 * f4 - computes key[3] index using srand(max_char ^ 0xe) + rand()
 * Seeds the global rand state used by f6
 * @username: the username string
 * @n: length of the username
 * Return: index into charset
 */
static int f4(const char *username, int n)
{
	int max_val, i;

	max_val = (int)username[0];
	for (i = 0; i < n; i++)
		if ((int)username[i] > max_val)
			max_val = (int)username[i];
	srand((unsigned int)(max_val ^ 0xe));
	return rand() & 0x3f;
}

/**
 * f5 - computes key[4] index from sum of squared username chars
 * @username: the username string
 * @n: length of the username
 * Return: index into charset
 */
static int f5(const char *username, int n)
{
	int sum, i, v;

	sum = 0;
	for (i = 0; i < n; i++)
	{
		v = (int)username[i];
		sum += v * v;
	}
	/* xor $0xef,%al — only the low byte is XORed */
	sum = (sum & ~0xff) | ((sum & 0xff) ^ 0xef);
	return sum & 0x3f;
}

/**
 * f6 - computes key[5] index by calling rand() username[0] times
 * Relies on rand state seeded by f4
 * @username: the username string
 * Return: index into charset
 */
static int f6(const char *username)
{
	int n, last, i;

	n = (int)username[0];
	last = 0;
	for (i = 0; i < n; i++)
		last = rand();
	/* xor $0xe5,%al — only the low byte is XORed */
	last = (last & ~0xff) | ((last & 0xff) ^ 0xe5);
	return last & 0x3f;
}

/**
 * main - entry point, prints the valid key for the given username
 * @argc: argument count
 * @argv: argument vector
 * Return: 0 on success, 1 on wrong usage
 */
int main(int argc, char *argv[])
{
	const char *username;
	int n;
	char key[7];

	if (argc != 2)
	{
		fprintf(stderr, "Usage: %s username\n", argv[0]);
		return (1);
	}

	username = argv[1];
	n = (int)strlen(username);

	/* Each key character is charset[fi(username)] */
	key[0] = charset[f1(n)];
	key[1] = charset[f2(username, n)];
	key[2] = charset[f3(username, n)];
	key[3] = charset[f4(username, n)];  /* seeds rand for f6 */
	key[4] = charset[f5(username, n)];
	key[5] = charset[f6(username)];     /* uses rand state from f4 */
	key[6] = '\0';

	printf("%s\n", key);
	return (0);
}
