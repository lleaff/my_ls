#include <unistd.h>
#include <stdlib.h>
#include "lib.h"

char *my_readnchars(int n)
{
  char *line;
  int i;

  line = my_readline();
  if (!line)
    return (line);
  for (i = 0; line[i] && i <= n; i++) ;
  line[i] = '\0';
  return (line);
}

/*
char *my_readnchars(int n)
{
  char *buff;
  int bytesread;

  if ((buff = malloc(n + 1)) == NULL)
    return (NULL);
  bytesread = read(1, buff, n + 1);
  if (bytesread == 0)
    {
      my_putchar('\n');
      return (NULL);
    }
  buff[bytesread - 1 >= 0 ? bytesread - 1 : 0] = '\0';
  buff[n] = '\0';
  return (buff);
}
*/
