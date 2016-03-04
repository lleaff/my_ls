#include <unistd.h>
#include <getopt.h>
#include <stddef.h> /* offsetof() */
#include "my_ls.h"

t_opts *opts_new()
{
  t_opts *opts;

  if ((opts = malloc(sizeof(t_opts))) == NULL)
    return (fail_ptr("opts_new: \"opts\" malloc failed."));
  zeroify(opts);
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
    offsetof(struct s_opts, colorize),
    offsetof(struct s_opts, longlistgroup),
    offsetof(struct s_opts, nosort),
    offsetof(struct s_opts, filetypesymb),
    offsetof(struct s_opts, oneentperline),
    offsetof(struct s_opts, multicolumn),
    offsetof(struct s_opts, humanreadable),
    offsetof(struct s_opts, streamformat),
};

t_bool set_opt(char c, t_opts *opts)
{
    int i;

    if ((i = char_in_str(c, OPTION_LIST)) == -1)
        return (false);
    *((t_bool*)((char*)opts + g_opts_offsets[i])) = true;
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
    args = ll_append(args, ll_new(my_strnew(argv[i])));

  if (opts->longlistgroup)
      opts->longlist = true;
  if (opts->nosort)
      opts->all = true;
  *o_args = args;
  *o_opts = opts;
  return (true);
}
