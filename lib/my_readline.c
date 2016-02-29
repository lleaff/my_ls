#include <unistd.h>
#include <stdlib.h>
#include "lib.h"

#define BUFFSIZE 80

char *my_readline()
{
  char *buff;
  int bytesread;

  if ((buff = malloc(BUFFSIZE)) == NULL)
    return (NULL);
  bytesread = read(STDIN_FILENO, buff, BUFFSIZE);
  if (bytesread == 0)
  {
      my_putchar('\n');
      return (NULL);
  }
  buff[bytesread - 1 >= 0 ? bytesread - 1 : 0] = '\0';
  return (buff);
}
