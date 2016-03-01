#include "lib.h"

/**
 * Returns a heap-allocated string of the right size from another string.
 */
char *my_strnew(char *buffer)
{
  int len;
  char *str;

  len = my_strlen(buffer);
  if ((str = malloc(len + 1)) == NULL)
    return (NULL);
  my_memcpy(str, buffer, len);
  str[len] = '\0';
  return (str);
}

char *my_strnnew(char *buffer, int n)
{
  char *str;

  if ((str = malloc(n + 1)) == NULL)
    return (NULL);
  my_memcpy(str, buffer, n);
  str[n] = '\0';
  return (str);
}
