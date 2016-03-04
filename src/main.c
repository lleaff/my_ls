#include <stdlib.h>
#include "my_ls.h"

t_bool check_help(int argc, char **argv)
{
  int i;

  for (i = 1; i < argc; i++)
    if (!my_strcmp(argv[i], "--help"))
    {
      print_usage(false);
      return (true);
    }
  return (false);
}

t_opts *g_opts;

int main(int argc, char **argv)
{
  t_ll *args;

  if (check_help(argc, argv))
    return (0);
  if (!parse_args(&args, &g_opts, argc, argv))
    return (1);
  if (!my_ls(args, my_strnew("./")))
    return (1);
  return (0);
}
