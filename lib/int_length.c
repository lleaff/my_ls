#include "lib.h"

int    int_length_base(long n, int base)
{
  int sign;
  int l;
  long m;

  sign = n >= 0 ? 1 : -1;
  for (l = 0, m = n; (sign >= 0 && m > 0) || m < 0; m /= 10)
    l++;
  if (sign == -1)
    l++;
  l = MAX(1, l);
  return (l);
}

int    int_length(long n)
{
    return (int_length_base(n, 10));
}
