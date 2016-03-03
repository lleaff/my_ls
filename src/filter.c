#include "my_ls.h"

t_bool filter_name(char *name)
{
  if (!(g_opts->all || g_opts->almostall) && name[0] == '.')
    return (false);
  if (g_opts->almostall && (!my_strcmp(name, ".") || !my_strcmp(name, "..")))
    return (false);
  return (true);
}
