#include "main.h"

int _atoi(char *s)
{
    int i = 0, sign = 1;
    unsigned int num = 0;

    while (s[i] == ' ' || (s[i] >= 9 && s[i] <= 13))
        i++;

    if (s[i] == '-')
        sign = -1, i++;
    else if (s[i] == '+')
        i++;

    while (s[i] >= '0' && s[i] <= '9')
    {
        num = num * 10 + (s[i] - '0');
        i++;
    }

    return (num * sign);
}
