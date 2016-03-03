#include <stdlib.h>

#define MAX(x, y) ((x) > (y) ? (x) : (y))

char *my_itoa(int n)
{
  int sign;
  int l;
  int m;
  char *str;

  sign = n >= 0 ? 1 : -1;
  for (l = 0, m = n; (sign >= 0 && m > 0) || m < 0; m /= 10)
    l++;
  if (sign == -1)
    l++;
  l = MAX(1, l);
  if ((str = malloc(sizeof(char) * (l + 1))) == NULL)
    return (NULL);
  str[l] = '\0';
  if (sign == -1)
    str[0] = '-';
  else if (n == 0)
    str[0] = '0';
  for (; (sign >= 0 && n > 0) || n < 0; n /= 10, l--)
    str[l - 1] = (n % 10) * sign + '0';
  return (str);
}

char *my_longlongtoa(long long n)
{
  int sign;
  long l;
  long m;
  char *str;

  sign = n >= 0 ? 1 : -1;
  for (l = 0, m = n; (sign >= 0 && m > 0) || m < 0; m /= 10)
    l++;
  if (sign == -1)
    l++;
  l = MAX(1, l);
  if ((str = malloc(sizeof(char) * (l + 1))) == NULL)
    return (NULL);
  str[l] = '\0';
  if (sign == -1)
    str[0] = '-';
  else if (n == 0)
    str[0] = '0';
  for (; (sign >= 0 && n > 0) || n < 0; n /= 10, l--)
    str[l - 1] = (n % 10) * sign + '0';
  return (str);
}
