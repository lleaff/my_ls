/*
** my_getnbr.c for my_getnbr in /home/hains-_l/Jour05C/my_getnbr/
** 
** Made by HAINS-FERLAND Lothaire
** Login   <hains-_l@etna-alternance.net>
** 
** Started on  Fri Oct  2 14:31:11 2015 HAINS-FERLAND Lothaire
** Last update Fri Oct  2 15:48:16 2015 HAINS-FERLAND Lothaire
*/

int   my_getnbr(char *str)
{
  int nbr;
  int sign;

  sign = 1;
  nbr = 0;
  while (*str)
    {
      if (*str == '-')
        {
          sign *= -1;
        }
      else if (*str >= '0' && *str <= '9')
        {
          nbr = (nbr * 10) + *str - '0';
        }
      else if (nbr)
        {
          return (nbr * sign);
        }
      str++;
    }
  return (nbr * sign);
}
