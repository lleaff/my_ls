#include "lib.h"

int my_putstr(char* str)
{
    while (*str)
        my_putchar(*str++);
    return (0);
}

#define FILL_CHAR ' '

int my_putstrn(char* str, int n)
{
    int i;
    char c;
    int end;

    for (i = 0, end = 0; i < n; i++)
    {
      if (!end)
        end = str[i] == '\0';
      c = !end ? str[i] : FILL_CHAR;
      my_putchar(c);
    }
    return(0);
}

/* Right-aligned my_putstrn */
int my_putstrnr(char* str, int n)
{
    int i;
    int len;
    char c;
    int offset;

    len = my_strlen(str);
    offset = n - len;
    for (i = 0; i < n; i++)
    {
      if (i < offset)
        c = FILL_CHAR;
      else
        c = str[i - offset];
      my_putchar(c);
    }
    return(0);
}
