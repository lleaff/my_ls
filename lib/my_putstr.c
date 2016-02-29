#include "lib.h"

int my_putstr(char* str)
{
    while (*str)
        my_putchar(*str++);
    return (0);
}

int my_putstrn(char* str, int n)
{
    int i;

    for (i = 0; i < n; n++)
        my_putchar(*(str + n));
    return(0);
}
