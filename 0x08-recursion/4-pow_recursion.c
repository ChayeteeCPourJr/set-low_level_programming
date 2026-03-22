#include "main.h"

/**
 * _pow_recursion - returns the value of x raised to the power of y
 * @x: the base
 * @y: the exponent
 *
 * Return: x^y, or -1 if y is negative
 */
int _pow_recursion(int x, int y)
{
    if (y < 0)       /* Error case: negative exponent */
        return -1;
    if (y == 0)      /* Base case: any number to the 0 is 1 */
        return 1;
    return x * _pow_recursion(x, y - 1); /* Recursive step */
}
