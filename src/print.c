#include "my_ls.h"

#define USAGE "USAGE: my_ls [OPTION]... [FILE]...\n"

t_bool print_usage()
{
  my_putstr(USAGE);
  return (false);
}
