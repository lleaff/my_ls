#include "my_ls.h"

t_bool filter_name(char *name, t_opts *opts)
{
  if (!(opts->all || opts->almostall) && name[0] == '.')
    return (false);
  if (opts->almostall && (!my_strcmp(name, ".") || !my_strcmp(name, "..")))
    return (false);
  return (true);
}
