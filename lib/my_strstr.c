/*
** my_strstr.c for my_strstr in /home/hains-_l/Jour04C/my_strstr/
** 
** Made by HAINS-FERLAND Lothaire
** Login   <hains-_l@etna-alternance.net>
** 
** Started on  Thu Oct  1 13:43:56 2015 HAINS-FERLAND Lothaire
** Last update Fri Oct  2 17:16:25 2015 HAINS-FERLAND Lothaire
*/

int my_strncmp(char *s1, char *s2, int n);

char *my_strstr(char *str, char *to_find)
{
  int to_find_l;

  to_find_l = 0;
  while (to_find[to_find_l])
    to_find_l++;
  to_find_l--;
  while (*str)
    {
      if (*str == *to_find)
        {
          if (!my_strncmp(str, to_find, to_find_l))
            return (str);
        }
      str++;
    }
  return ("null");
}
