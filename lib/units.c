#include "lib.h"
#include "math.h" /* log() */

int nth_digit(long num, int n)
{
  if (n <= 0)
    return (-1);
  for (; n > 1; n--)
  {
    num /= 10;
    if (num == 0)
      return (-1);
  }
  return (num % 10);
}

char MEM_SIZE_SUFFIXES[] = {
  '\0',
  'K',
  'M',
  'G',
  'T'
};

#define SIZE_BS 1024

static char *_num_to_unit_suffixed(long n, char suffix)
{
  char buf[5];
  char unitstr[2];
  char *numstr;
  char *res;
  int len;
  
  unitstr[0] = suffix;
  unitstr[1] = '\0';
  len = int_length(n);
  numstr = my_itoa(n);
  if (len == 4)
  {
    res = my_strnew(numstr);
    res[3] = suffix;
  }
  else
  {
    buf[0] = numstr[0];
    buf[1] = ',';
    buf[2] = numstr[1];
    buf[3] = '\0';
    res = my_strcatnew(buf, unitstr);
  }
  free(numstr);
  return (res);
}

char *size_to_human_readable(long size)
{
  long exp;
  long res;
  char unit;

  if (size < SIZE_BS)
    return my_longlongtoa(size);
  exp = log(size) / log(SIZE_BS);
  res = size / pow(SIZE_BS, exp) * 10;
  unit = MEM_SIZE_SUFFIXES[exp];
  return (_num_to_unit_suffixed(res, unit));
}
