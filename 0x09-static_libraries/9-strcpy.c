#include "main.h"

char *_strcpy(char *dest, char *src)
{
    int i = 0;

    while ((dest[i] = src[i]))
        i++;

    return (dest);
}
