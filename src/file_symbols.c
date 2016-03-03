#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include "my_ls.h"

#define FILESYMBOLS_COUNT 6

static t_bool(*filetype_tests[FILESYMBOLS_COUNT])(t_finfo *finfo) = {
    finfo_is_link,
    finfo_is_socket,
    finfo_is_whiteout,
    finfo_is_fifo,
    finfo_is_dir,
    finfo_is_executable
};

static char filetype_symbols[FILESYMBOLS_COUNT] = {
    '@',
    '=',
    '%',
    '|',
    '/',
    '*'
};

char get_filetype_symbol(t_finfo *finfo)
{
  int i;

  for (i = 0; i < FILESYMBOLS_COUNT; i++)
      if (filetype_tests[i](finfo))
          return (filetype_symbols[i]);
  return (' ');
}

t_bool finfo_is_dir(t_finfo *finfo)
{
    return (finfo->isdir);
}
