#include "main.h"

char *_strstr(char *haystack, char *needle)
{
    int i, j;

    if (!*needle)
        return (haystack);

    for (i = 0; haystack[i]; i++)
    {
        for (j = 0; needle[j]; j++)
        {
            if (haystack[i + j] != needle[j])
                break;
        }
        if (!needle[j])
            return (&haystack[i]);
    }

    return (0);
}
