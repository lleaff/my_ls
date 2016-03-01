#include <unistd.h>
#include <getopt.h>
#include "my_ls.h"

t_opts *opts_new()
{
  t_opts *opts;

  if ((opts = malloc(sizeof(t_opts))) == NULL)
    return (fail_ptr("opts_new: \"opts\" malloc failed."));
  opts->longlist    = false;
  opts->recursive   = false;
  opts->reverse     = false;
  opts->flat        = false;
  opts->sortmodtime = false;
  opts->all         = false;
  opts->almostall   = false;
  opts->dereference = false;
  return (opts);
}

t_bool set_opt(char c, t_opts *opts)
{
  switch (c)
  {
    case 'l':
      opts->longlist = true;     break;
    case 'R':
      opts->recursive = true;    break;
    case 'r':
      opts->reverse = true;      break;
    case 'd':
      opts->flat = true;         break;
    case 't':
      opts->sortmodtime = true;  break;
    case 'a':
      opts->all = true;          break;
    case 'A':
      opts->almostall = true;    break;
    case 'L':
      opts->dereference = true;  break;
    default:
      return (false);
  }
  return (true);
}

t_bool unknown_opt_err(char c)
{
  my_puterr(FG_RED"Unknown option \"");
  my_putcharerr(optopt);
  my_puterr("\".\n"COLOR_RESET);
  return (false);
}

t_bool parse_args(t_ll **o_args, t_opts **o_opts, int argc, char **argv)
{
  t_opts * opts;
  t_ll* args;
  int i;
  int c;

  opterr = 0;
  opts = opts_new();
  while ((c = getopt (argc, argv, OPTION_LIST)) != -1)
    if (!set_opt(c, opts))
      return (unknown_opt_err(c) || print_usage(true));
  for (i = optind, args = NULL; i < argc; i++)
    args = ll_append(args, ll_new(argv[i]));
  *o_args = args;
  /*o_args = args != NULL ? args : ll_new("."); *//* Default to cwd */ 
  *o_opts = opts;
  return (true);
}

