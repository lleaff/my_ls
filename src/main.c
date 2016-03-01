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

/* DEBUG */
/*
int main(int argc, char **argv)
{
  printf("[%s]\n", concat_paths("yo", "man"));
  return (0);
}
*/

int main(int argc, char **argv)
{
  t_ll *args;
  t_opts *opts;

  if (check_help(argc, argv))
    return (0);
  if (!parse_args(&args, &opts, argc, argv))
    return (1);
  if (!my_ls(args, "./", opts))
    return (1);
  return (0);
}
