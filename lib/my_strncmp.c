/*
** my_strncmp.c for my_strncmp in /home/hains-_l/Jour04C/my_strncmp/
** 
** Made by HAINS-FERLAND Lothaire
** Login   <hains-_l@etna-alternance.net>
** 
** Started on  Thu Oct  1 11:09:18 2015 HAINS-FERLAND Lothaire
** Last update Thu Oct  1 11:12:24 2015 HAINS-FERLAND Lothaire
*/

int my_strncmp(char *s1, char *s2, int n)
{
  int i;

  i = 0;
  while (*s1 && *s2 && i++ < n)
    {
      if (*s1 > *s2)
        return (1);
      else if (*s1 < *s2)
        return (-1);
      s1++;
      s2++;
    }
  if ((!*s1 && !*s2) || *s1 == *s2)
    return (0);
  else if (*s1 > *s2)
    return (1);
  else
    return (-1);
}
