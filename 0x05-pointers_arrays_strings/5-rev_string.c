#include "main.h"

/**
 * rev_string - reverses a string
 * @s: pointer to the string
 */
void rev_string(char *s)
{
    int i = 0, j;
    char temp;

    /* Find length of string */
    while (s[i] != '\0')
        i++;

    /* Swap characters from ends towards the middle */
    for (j = 0; j < i / 2; j++)
    {
        temp = s[j];
        s[j] = s[i - j - 1];
        s[i - j - 1] = temp;
    }
}
