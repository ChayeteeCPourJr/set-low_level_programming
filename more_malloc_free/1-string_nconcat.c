#include <stdlib.h>
#include <string.h>

char *string_nconcat(char *s1, char *s2, unsigned int n)
{
    char *result;
    unsigned int len1, len2, copy_len;

    s1 = (s1 == NULL) ? "" : s1;
    s2 = (s2 == NULL) ? "" : s2;

    len1 = strlen(s1);
    len2 = strlen(s2);

    copy_len = (n >= len2) ? len2 : n;

    result = malloc(len1 + copy_len + 1);
    if (result == NULL)
        return (NULL);

    memcpy(result, s1, len1);
    memcpy(result + len1, s2, copy_len);
    result[len1 + copy_len] = '\0';

    return (result);
}
