#include "main.h"

/**
 * check_prime - helper function to check for divisors
 * @n: number to check
 * @i: current divisor
 *
 * Return: 1 if prime, 0 otherwise
 */
int check_prime(int n, int i)
{
    if (i * i > n)      /* No divisor found */
        return 1;
    if (n % i == 0)     /* Divisor found */
        return 0;
    return check_prime(n, i + 1); /* Try next divisor */
}

/**
 * is_prime_number - checks if a number is prime
 * @n: number to check
 *
 * Return: 1 if prime, 0 otherwise
 */
int is_prime_number(int n)
{
    if (n <= 1)         /* 0, 1 and negatives are not prime */
        return 0;
    return check_prime(n, 2); /* Start checking from 2 */
}
