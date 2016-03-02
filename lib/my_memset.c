#include <stdlib.h>

void *my_memset(void *ptr, char byte, size_t n)
{
  char *s;

  s = ptr;
  while (n--)
    s[n] = byte;
  return ptr;
}
