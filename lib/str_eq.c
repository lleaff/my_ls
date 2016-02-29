int str_eq(char *str1, char *str2)
{
  while (*str1)
    {
      if (*str1++ != *str2++)
        return (0);
    }
  if (*str2)
    return (0);
  return (1);
}
