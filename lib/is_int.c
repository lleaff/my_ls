int is_int(char *str)
{
  while (*str == '+' || *str == '-')
    str++;
  while (*str++)
    if (*(str - 1) < '0' || *(str - 1) > '9')
      return 0;
  return 1;
}
