#include <stdlib.h>
#include "my_ls.h"

int main(int argc, char **argv)
{
  t_ll *args;
  t_opts *opts;

  if (!parse_args(&args, &opts, argc, argv))
    return (1);
  if (!my_ls(args, opts))
    return (1);
  return (0);
}
