#include <unistd.h>
#include <getopt.h>
#include <stddef.h> /* offsetof() */
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

static size_t g_opts_offsets[] = {
    offsetof(struct s_opts, longlist),
    offsetof(struct s_opts, recursive),
    offsetof(struct s_opts, reverse),
    offsetof(struct s_opts, flat),
    offsetof(struct s_opts, sortmodtime),
    offsetof(struct s_opts, all),
    offsetof(struct s_opts, almostall),
    offsetof(struct s_opts, dereference),
};

t_bool set_opt(char c, t_opts *opts)
{
    int i;

    if ((i = char_in_str(c, OPTION_LIST)) == -1)
        return (false);
    *(t_bool*)(opts + g_opts_offsets[i]) = true;
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
  *o_opts = opts;
  return (true);
}

