#include <stdlib.h>
#include "lib.h"

char *last_n_chars(char *str, int n)
{
  int len;

  len = my_strlen(str);
  if (n > len)
    return (NULL);
  return (str + len - n);
}
