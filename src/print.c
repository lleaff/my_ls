#include "my_ls.h"

t_bool print_usage(t_bool err)
{
  if (err)
    my_puterr(USAGE);
  else
    my_putstr(USAGE);
  
  return (false);
}

#define GUTTER_CHAR ' '

static char *_init_gutter_str(char *gutter)
{
  int i;

  gutter = malloc(GUTTER_SIZE + 1);
  for (i = 0; i < GUTTER_SIZE; i++)
    gutter[i] = GUTTER_CHAR;
  gutter[GUTTER_SIZE] = '\0';
  return (gutter);
}

void print_gutter()
{
  static char *gutter = NULL;
  
  if (gutter == NULL)
    gutter = _init_gutter_str(gutter);
  my_putstr(gutter);
}
