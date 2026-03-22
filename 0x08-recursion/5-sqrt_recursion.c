#include "main.h"

/**
 * _sqrt_helper - helper function to find natural square root recursively
 * @n: the number
 * @i: current candidate for sqrt
 *
 * Return: natural square root of n, or -1 if none exists
 */
int _sqrt_helper(int n, int i)
{
    if (i * i == n)   /* Found exact square root */
        return i;
    if (i * i > n)    /* Overshot, no natural sqrt */
        return -1;
    return _sqrt_helper(n, i + 1);  /* Recur with next candidate */
}

/**
 * _sqrt_recursion - returns the natural square root of n
 * @n: number to find sqrt of
 *
 * Return: natural square root, or -1 if none exists
 */
int _sqrt_recursion(int n)
{
    if (n < 0)        /* Negative numbers have no natural sqrt */
        return -1;
    return _sqrt_helper(n, 0);  /* Start checking from 0 */
}
